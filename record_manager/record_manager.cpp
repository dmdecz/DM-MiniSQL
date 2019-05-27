#include "record_manager.hpp"

#include <iostream>

Record_Manager::Record_Manager(Catalog_Manager * catalog, Buffer_Manager * buf)
	: m_catalog(catalog), m_buffer(buf) {}

void Record_Manager::select(const std::string & table_name)
{
	int size = this->m_catalog->data_block_number(table_name);
	// std::cout << "Block: " << size << std::endl;

}

void Record_Manager::insert(const std::string & table_name, std::map<std::string, DMType> & attr_list)
{
	int size = this->m_catalog->data_block_number(table_name);
	
}