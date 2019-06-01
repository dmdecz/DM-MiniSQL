#include "record_manager.hpp"
#include "../error/error.h"

#include <iostream>
#include <cstring>

Record::Record(std::map<std::string, AttrType> & _type, std::map<std::string, std::pair<int, DMType>> & _condition)
	: type (_type), condition(_condition) {}

Record::Record(std::map<std::string, AttrType> & _type, std::map<std::string, DMType> & _value, bool _empty, int _next_offset)
	: type(_type), value(_value), empty(_empty), next_offset(_next_offset) {}


void Record::get_value(char * data)
{
	for (MapIterator<std::string, AttrType> it = this->type.begin(); it != this->type.end(); ++it) {
		this->value[it->first] = void_pointer_to_DMType(data, it->second);
		data += attrTypeLength(it->second);
	}
	this->empty = *(bool*)data;
	data += sizeof(bool);
	this->next_offset = *(int*)data;
}

bool Record::is_valid()
{
	bool ret = this->empty == 0;
	for (auto & attr : this->condition) {
		switch (attr.second.first) {
			case 0:
				ret = ret && (this->value[attr.first] == attr.second.second);
				break;
			case 1:
				ret = ret && (this->value[attr.first] < attr.second.second);
				break;
			case 2:
				ret = ret && (this->value[attr.first] > attr.second.second);
				break;
			case 3:
				ret = ret && (this->value[attr.first] != attr.second.second);
				break;
		}
		if (!ret)
			break;
	}
	return ret;
}

DMType Record::operator[](const std::string & name)
{
	return this->value[name];
}

int Record::write_to_block(Block * block, int offset)
{
	for (MapIterator<std::string, AttrType> it = this->type.begin(); it != this->type.end() ; ++it) {
		int length = attrTypeLength(it->second);
		block->datacpy(offset, DMType_to_void_pointer(this->value[it->first]), sizeof(char) * length);
		offset += length;
	}
	block->datacpy(offset, &this->empty, sizeof(bool));
	offset += sizeof(bool);
	block->datacpy(offset, &this->next_offset, sizeof(int));
	offset += sizeof(int);
	return offset;
}

void Record::delete_record(int _next_offset)
{
	this->empty = 1;
	this->next_offset = _next_offset;
}

void Record::clear()
{
	this->value.clear();
}

Record::~Record() = default;


Record_Manager::Record_Manager(const std::string & database, Catalog_Manager * catalog, Buffer_Manager * buf)
	: database_name(database), m_catalog(catalog), m_buffer(buf) {}

void Record_Manager::select(const std::string & table_name, std::vector<std::string> & list, std::map<std::string, std::pair<int, DMType>> & cond)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);
	for (auto & v : list) {
		std::cout << '\t' << v;
	}
	std::cout << std::endl;

	int size = this->m_catalog->data_block_number(table_name);
	int record_length = this->m_catalog->get_record_length(table_name);
	int total = 0;
	Record * tuple = new Record(attribute_list, cond);
	for (int i = 0; i < size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				for (int k = 0; k < list.size(); ++k) {
					DMType value = (*tuple)[list[k]];
					std::cout << '\t' << value;
				}
				std::cout << std::endl;
				total ++;
			}
			begin += record_length;
		}
	}
	std::cout << "Query OK, " <<  total << " in set." << std::endl;
}

void Record_Manager::insert(const std::string & table_name, std::map<std::string, DMType> & attr_list)
{
	int size = this->m_catalog->data_block_number(table_name);
    std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);

	for (MapIterator<std::string, AttrType> it = attribute_list.begin(); it != attribute_list.end(); ++it) {
		if (attr_list.find(it->first) == attr_list.end()) {
			throw Error(757, "Part of attributes.");
		}
		if (!type_match(it->second, attr_list[it->first])) {
			throw Error(758, "Attributes don't match.");
		}
	}

	if (size == 0) {
		this->insert_to_new_block(table_name, attr_list, size);
	} else {
		int insert_done = this->insert_to_old_block(table_name, attr_list, size);
		if (!insert_done) {
			this->insert_to_new_block(table_name, attr_list, size);
		}
	}
	std::cout << "Query OK, 1 row(s) affected." << std::endl;
}

void Record_Manager::insert_to_new_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);
	char * buffer = new char[Block::BLOCK_SIZE];
	int offset = Block::BLOCK_HEAD_SIZE;
	memset(buffer, 0, sizeof(char) * Block::BLOCK_SIZE);
	Block * block = new Block(this->database_name, table_name, size, buffer);
	Record record(attribute_list, attr_list);
	offset = record.write_to_block(block, offset);
	block->datacpy(0, &offset, sizeof(int));
	block->datacpy(4, &offset, sizeof(int));

	this->m_buffer->put_block(block);
	this->m_catalog->add_data_block(table_name);
}

int Record_Manager::insert_to_old_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);
	int TotalLength = this->m_catalog->get_record_length(table_name);
	for (int i = 0; i < size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int total_offset = *(int*)block->get_data(0);
		int offset = *(int*)block->get_data(4);
		if ( offset + TotalLength > Block::BLOCK_SIZE ) {
			continue;
		}
		int next_offset = *(int*)block->get_data(offset + TotalLength - sizeof(int));
		Record record(attribute_list, attr_list);
		record.write_to_block(block, offset);

		if (offset == total_offset) {
			next_offset = offset + TotalLength;
			block->datacpy(0, &next_offset, sizeof(int));
		}
		block->datacpy(4, &next_offset, sizeof(int));
		return i + 1;
	}
	return 0;
}

void Record_Manager::delete_record(const std::string & table_name, std::map<std::string, std::pair<int, DMType>> & cond)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);

	int size = this->m_catalog->data_block_number(table_name);
	int record_length = this->m_catalog->get_record_length(table_name);
	int total = 0;
	Record * tuple = new Record(attribute_list, cond);
	for (int i = 0; i < size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				tuple->delete_record(*(int*)block->get_data(4));
				tuple->write_to_block(block, begin);
				block->datacpy(4, &begin, sizeof(int));
//				std::cout << '\t' << *(int*)block->get_data(4) << '\t' << *(bool*)block->get_data(begin + record_length - 5) << '\t' << *(int*)block->get_data(begin + record_length - 4) << std::endl;
				total ++;
			}
			begin += record_length;
		}
	}
	std::cout << "Query OK, " << total << " row(s) affected." << std::endl;
}

Record_Manager::~Record_Manager() = default;