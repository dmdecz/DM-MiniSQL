#include "record_manager.hpp"
#include "../error/error.h"

#include "../table/CppConsoleTable.hpp"
using ConsoleTable = samilton::ConsoleTable;

#include <iostream>
#include <cstring>

Record::Record(AttrInfo & _type)
		: type (_type) {}

Record::Record(AttrInfo & _type, CmpInfo & _condition)
	: type (_type), condition(_condition) {}

Record::Record(AttrInfo & _type, std::map<std::string, DMType> & _value, bool _empty, int _next_offset)
	: type(_type), value(_value), empty(_empty), next_offset(_next_offset) {}


void Record::get_value(char * data)
{
	for (auto & it : this->type) {
		this->value[it.first] = DMType(data, it.second.first);
		data += attrTypeLength(it.second.first);
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
			case EQUAL:
				ret = ret && (this->value[attr.first] == attr.second.second);
				break;
			case LESS:
				ret = ret && (this->value[attr.first] < attr.second.second);
				break;
			case LARGE:
				ret = ret && (this->value[attr.first] > attr.second.second);
				break;
			case NOT:
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
	for (auto & it : this->type) {
		int length = attrTypeLength(it.second.first);
		block->datacpy(offset, this->value[it.first], sizeof(char) * length);
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
	this->empty = true;
	this->next_offset = _next_offset;
}

void Record::clear()
{
	this->value.clear();
}

Record::~Record() = default;


Record_Manager::Record_Manager(const std::string & database, Catalog_Manager * catalog, Buffer_Manager * buf)
	: database_name(database), m_catalog(catalog), m_buffer(buf) {}

void Record_Manager::select_record(const std::string & table_name, std::vector<std::string> & list, CmpInfo & cond)
{
	ConsoleTable table(samilton::Alignment::centre);
	ConsoleTable::TableChars chars;
	chars.topDownSimple = '-';
	chars.leftRightSimple = '|';
	chars.centreSeparation = '+';
	chars.leftSeparation = '+';
	chars.rightSeparation = '+';
	chars.topSeparation = '+';
	chars.topLeft = '+';
	chars.topRight = '+';
	chars.downSeparation = '+';
	chars.downLeft = '+';
	chars.downRight = '+';
	table.setTableChars(chars);

	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);

	table.addRow(list);

	int size = this->m_catalog->data_block_number(table_name);
	int record_length = this->m_catalog->get_record_length(table_name);
	int total = 0;

	Record * tuple = new Record(attribute_list, cond);
	for (int i = 1; i <= size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				std::vector<std::string> row;
				for (auto & it : list) {
					row.push_back((*tuple)[it].to_string());
				}
				table.addRow(row);
				total ++;
			}
			begin += record_length;
		}
	}
	if (total) {
		std::cout << table;
	}
	std::cout << "Query OK, " <<  total << " in set." << std::endl;
}

void Record_Manager::select_record(const std::string & table_name, std::vector<std::string> & list, CmpInfo & cond, int block_number)
{
	ConsoleTable table(samilton::Alignment::centre);
	ConsoleTable::TableChars chars;
	chars.topDownSimple = '-';
	chars.leftRightSimple = '|';
	chars.centreSeparation = '+';
	chars.leftSeparation = '+';
	chars.rightSeparation = '+';
	chars.topSeparation = '+';
	chars.topLeft = '+';
	chars.topRight = '+';
	chars.downSeparation = '+';
	chars.downLeft = '+';
	chars.downRight = '+';
	table.setTableChars(chars);

	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	table.addRow(list);

	int record_length = this->m_catalog->get_record_length(table_name);
	int total = 0;
	Record * tuple = new Record(attribute_list, cond);
	if (block_number) {
		Block *block = this->m_buffer->get_block(table_name, block_number);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int *) block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				std::vector<std::string> row;
				for (auto & it : list) {
					row.push_back((*tuple)[it].to_string());
				}
				table.addRow(row);
				total ++;
			}
			begin += record_length;
		}
	}
	if (total) {
		std::cout << table;
	}
	std::cout << "Query OK, " <<  total << " in set." << std::endl;
}

int Record_Manager::insert_record(const std::string & table_name, std::map<std::string, DMType> & attr_list)
{
	int ret = 0;
	int size = this->m_catalog->data_block_number(table_name);

	if (size == 0) {
		ret = this->insert_to_new_block(table_name, attr_list, size);
	} else {
		int insert_done = this->insert_to_old_block(table_name, attr_list, size);
		if (!insert_done) {
			ret = this->insert_to_new_block(table_name, attr_list, size);
		} else {
			ret = insert_done;
		}
	}
	std::cout << "Query OK, 1 row(s) affected." << std::endl;
	return ret;
}

int Record_Manager::insert_to_new_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size)
{
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	int offset = Block::BLOCK_HEAD_SIZE;
	Block * block = this->m_buffer->create_block(table_name, size + 1);
	Record record(attribute_list, attr_list);
	offset = record.write_to_block(block, offset);
	block->datacpy(0, &offset, sizeof(int));
	block->datacpy(4, &offset, sizeof(int));

	this->m_catalog->add_data_block(table_name);
	return size + 1;
}

int Record_Manager::insert_to_old_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size)
{
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	int TotalLength = this->m_catalog->get_record_length(table_name);
	for (int i = 1; i <= size; ++i) {
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
		return i;
	}
	return 0;
}

std::map<std::string, std::vector<DMType>> Record_Manager::delete_record(const std::string & table_name, CmpInfo & cond)
{
	std::map<std::string, std::vector<DMType>> ret;
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);

	int size = this->m_catalog->data_block_number(table_name);
	int record_length = this->m_catalog->get_record_length(table_name);
	int total = 0;
	Record * tuple = new Record(attribute_list, cond);
	for (int i = 1; i <= size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				for (auto & it : attribute_list) {
					ret[it.first].push_back((*tuple)[it.first]);
				}
				tuple->delete_record(*(int*)block->get_data(4));
				tuple->write_to_block(block, begin);
				block->datacpy(4, &begin, sizeof(int));
				total ++;
			}
			begin += record_length;
		}
	}
	std::cout << "Query OK, " << total << " row(s) affected." << std::endl;
	return ret;
}

std::map<std::string, std::vector<DMType>> Record_Manager::delete_record(const std::string & table_name, CmpInfo & cond, int block_number)
{
	std::map<std::string, std::vector<DMType>> ret;
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);

	int record_length = this->m_catalog->get_record_length(table_name);
	int total = 0;
	Record * tuple = new Record(attribute_list, cond);
	if (block_number) {
		Block * block = this->m_buffer->get_block(table_name, block_number);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				for (auto & it : attribute_list) {
					ret[it.first].push_back((*tuple)[it.first]);
				}
				tuple->delete_record(*(int*)block->get_data(4));
				tuple->write_to_block(block, begin);
				block->datacpy(4, &begin, sizeof(int));
				total ++;
			}
			begin += record_length;
		}
	}
	std::cout << "Query OK, " << total << " row(s) affected." << std::endl;
	return ret;
}

int Record_Manager::search_key(const std::string & table_name, const std::string & key_name, DMType & key)
{
	int ret = 0;
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);

	int size = this->m_catalog->data_block_number(table_name);
	int record_length = this->m_catalog->get_record_length(table_name);
	CmpInfo cond;
	cond[key_name] = std::make_pair(EQUAL, key);
	Record * tuple = new Record(attribute_list, cond);
	for (int i = 1; i <= size; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				ret = i;
				return ret;
			}
			begin += record_length;
		}
	}
	return ret;
}

Record_Manager::~Record_Manager() = default;