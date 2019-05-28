#include "record_manager.hpp"

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
	if (size == 0)
	{
		char * buffer = new char[Buffer_Manager::BLOCK_SIZE];
		char * ptr = buffer;
		memset(buffer, 0, sizeof(char) * Buffer_Manager::BLOCK_SIZE);
		// for (MapIterator<std::string, DMType> it = attr_list.begin(); it != attr_list.end(); it++)
		// {
		// 	AttrType type = this->m_catalog->get_attribute_type(table_name, it->first);
		// 	int length = type > 0 ? type : (type * -4);
		// 	std::cout << it->first << " length = " << length << std::endl;
		// 	// memcpy(ptr, it->first.c_str(), sizeof(char) * 12);
		// 	// ptr += length;
		// }

		Block * block = new Block(this->database_name, table_name, size, buffer);
		this->m_buffer->put_block(block);
	}
	else
	{
		
	}
	
}

Record_Manager::~Record_Manager() {}