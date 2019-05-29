#include "record_manager.hpp"
#include "../error/error.h"

#include <iostream>
#include <cstring>

Record_Manager::Record_Manager(const std::string & database, Catalog_Manager * catalog, Buffer_Manager * buf)
	: database_name(database), m_catalog(catalog), m_buffer(buf) {}

void Record_Manager::select(const std::string & table_name)
{
	int size = this->m_catalog->data_block_number(table_name);
	// std::cout << "Block: " << size << std::endl;

}

void Record_Manager::insert(const std::string & table_name, std::map<std::string, DMType> & attr_list)
{
	int size = this->m_catalog->data_block_number(table_name);
    std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);

	for (MapIterator<std::string, AttrType> it = attribute_list.begin(); it != attribute_list.end() ; ++it) {
		if (attr_list.find(it->first) == attr_list.end()) {
			throw Error(757, "Part of attributes.");
		}
		if (!typeMatch(it->second, attr_list[it->first])) {
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
}

void Record_Manager::insert_to_new_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size)
{
	std::map<std::string, AttrType> & attribute_list = this->m_catalog->get_attributes(table_name);
	char * buffer = new char[Buffer_Manager::BLOCK_SIZE];
	int offset = 4;
	char * ptr = buffer + offset;
	memset(buffer, 0, sizeof(char) * Buffer_Manager::BLOCK_SIZE);
	for (MapIterator<std::string, AttrType> it = attribute_list.begin(); it != attribute_list.end() ; ++it) {
		int length = attrTypeLength(it->second);
		memcpy(ptr, VoidPtrToDMType(attr_list[it->first]), sizeof(char) * length);
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
		if ( offset + TotalLength > Buffer_Manager::BLOCK_SIZE )
			continue;
		for (MapIterator<std::string, AttrType> it = attribute_list.begin(); it != attribute_list.end() ; ++it) {
			int length = attrTypeLength(it->second);
			block->datacpy(offset, VoidPtrToDMType(attr_list[it->first]), sizeof(char) * length);
			offset += length;
		}
		block->datacpy(0, &offset, sizeof(int));
		return i + 1;
	}
	return 0;
}

Record_Manager::~Record_Manager() {}