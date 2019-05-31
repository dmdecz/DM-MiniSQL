#include "record_manager.hpp"
#include "../error/error.h"

#include <iostream>
#include <cstring>

Record::Record(std::map<std::string, AttrType> & _type)
	: type (_type) {}

void Record::get_value(char * data)
{
	for (MapIterator<std::string, AttrType> it = this->type.begin(); it != this->type.end(); ++it) {
		this->value[it->first] = void_pointer_to_DMType(data, it->second);
		data += attrTypeLength(it->second);
//		std::cout << this->value[it->first] << std::endl;
	}
}

DMType Record::operator[](const std::string & name)
{
	return this->value[name];
}

void Record::clear()
{
	this->value.clear();
}

Record::~Record() = default;


Record_Manager::Record_Manager(const std::string & database, Catalog_Manager * catalog, Buffer_Manager * buf)
	: database_name(database), m_catalog(catalog), m_buffer(buf) {}

void Record_Manager::select(const std::string & table_name, std::vector<std::string> & list)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);
	for (int i = 0; i < list.size(); ++i) {
		if (list[i] == "*") {
			list.erase(list.begin() + i);
			for (MapIterator<std::string, AttrType> it = attribute_list.begin(); it != attribute_list.end(); ++it) {
				list.insert(list.begin() + i, it->first);
			}
		}
		if (attribute_list.find(list[i]) == attribute_list.end())
			throw Error(701, "Table '" + table_name + "' has no attribute '" + list[i] + "'.");
		std::cout << '\t' << list[i];
	}
	std::cout << std::endl;

	int size = this->m_catalog->data_block_number(table_name);
	int record_length = this->m_catalog->get_record_length(table_name);
	int total = 0;
	Record * tuple = new Record(attribute_list);
	for (int i = 0; i < size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			for (int k = 0; k < list.size(); ++k) {
				DMType value = (*tuple)[list[k]];
				std::cout << '\t' << value;
			}
			std::cout << std::endl;
			begin += record_length;
			total ++;
		}
	}
	std::cout << total << " have found." << std::endl;
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
		std::cout << "insert_done " << insert_done << std::endl;
		if (!insert_done) {
			this->insert_to_new_block(table_name, attr_list, size);
		}
	}
}

void Record_Manager::insert_to_new_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);
	char * buffer = new char[Block::BLOCK_SIZE];
	int offset = Block::BLOCK_HEAD_SIZE;
	char * ptr = buffer + offset;
	memset(buffer, 0, sizeof(char) * Block::BLOCK_SIZE);
	for (MapIterator<std::string, AttrType> it = attribute_list.begin(); it != attribute_list.end() ; ++it) {
		int length = attrTypeLength(it->second);
		memcpy(ptr, DMType_to_void_pointer(attr_list[it->first]), sizeof(char) * length);
		ptr += length;
	}
	offset = ptr - buffer;
	memcpy(buffer, &offset, sizeof(int));

	Block * block = new Block(this->database_name, table_name, size, buffer);
	this->m_buffer->put_block(block);
	this->m_catalog->add_data_block(table_name);
}

int Record_Manager::insert_to_old_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);
	int TotalLength = this->m_catalog->get_record_length(table_name);
	for (int i = 0; i < size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int offset = *(int*)block->get_data(0);
		if ( offset + TotalLength > Block::BLOCK_SIZE ) {
			continue;
		}
		for (MapIterator<std::string, AttrType> it = attribute_list.begin(); it != attribute_list.end() ; ++it) {
			int length = attrTypeLength(it->second);
			block->datacpy(offset, DMType_to_void_pointer(attr_list[it->first]), sizeof(char) * length);
			offset += length;
		}
		block->datacpy(0, &offset, sizeof(int));
		return i + 1;
	}
	return 0;
}

Record_Manager::~Record_Manager() = default;