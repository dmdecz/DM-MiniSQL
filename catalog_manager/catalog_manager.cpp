#include "catalog_manager.hpp"
#include "../common/common.hpp"
#include "../buffer_manager/buffer_manager.hpp"

#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int Table_Message::ATTRIBUTE_SIZE = 12;
int Table_Message::RECORD_INFO_SIZE = sizeof(bool) + sizeof(int);

Table_Message::Table_Message(const std::string & database, const std::string & table)
	: database_name(database), table_name(table), dirty(false)
{
	this->load();
}

Table_Message::Table_Message(const std::string & database, const std::string & table, AttrInfo & attr)
	: database_name(database), table_name(table), attribute_list(attr), dirty(true), data_block_number(0)
{
	this->write_back();
	this->load();
}

void Table_Message::load()
{
	std::ifstream fp;
	std::string filename = this->database_name + "/" + this->table_name + "/table.info";

	fp.open(filename, std::ios::binary);

	// load record information
	int size = 0;
	fp.read((char*)&size, sizeof(int));
	char * buffer = new char[ATTRIBUTE_SIZE];
	AttrType type;
	int other_info;
	this->record_length = 0;
	for (int i = 0; i < size; i++)
	{
		fp.read(buffer, sizeof(char) * ATTRIBUTE_SIZE);
		fp.read((char*)&type, sizeof(AttrType));
		fp.read((char*)&other_info, sizeof(int));
		this->attribute_list[std::string(buffer)].first = type;
		this->attribute_list[std::string(buffer)].second = other_info;
		if (other_info == 2) {
			this->primary_key = buffer;
		}
		this->record_length += attrTypeLength(type);
	}
	this->record_length += Table_Message::RECORD_INFO_SIZE;

	// load index information
	fp.read((char*)&size, sizeof(int));
	IndexType index_type;
	int entry_block;
	for (int i = 0; i < size; i++)
	{
		fp.read(buffer, sizeof(char) * ATTRIBUTE_SIZE);
		fp.read((char*)&index_type, sizeof(IndexType));
		fp.read((char*)&entry_block, sizeof(int));
		this->index_list[std::string(buffer)].first = index_type;
		this->index_list[std::string(buffer)].second = entry_block;
		// std::cout << buffer << '\t' << index_type << std::endl;
	}
	// load fragment index block
	fp.read((char*)&size, sizeof(int));
	int fragment_block;
	for (int i = 0; i < size; i++)
	{
		fp.read((char*)&fragment_block, sizeof(int));
		this->index_fragment.push_back(fragment_block);
	}

	delete[] buffer;
	fp.close();

	// load number of data block
	std::string table_filename = this->database_name + "/" + table_name + "/data.dm";
	fp.open(table_filename, std::ios::binary);
	this->data_block_number = 0;
	if (fp.is_open())
	{
		fp.seekg(0, std::ios::end);
		this->data_block_number = fp.tellg() / Block::BLOCK_SIZE;
		fp.close();
	}

	// load number of index block
	std::string index_filename = this->database_name + "/" + table_name + "/index.dm";
	fp.open(index_filename, std::ios::binary);
	this->index_block_number = 0;
	if (fp.is_open())
	{
		fp.seekg(0, std::ios::end);
		this->index_block_number = fp.tellg() / Block::BLOCK_SIZE;
		fp.close();
	}
	this->dirty = false;
}

void Table_Message::write_back()
{
	if (!this->dirty || this->database_name.empty())
		return;
	std::ofstream fp;
	std::string filename = this->database_name + "/" + this->table_name + "/table.info";
	fp.open(filename, std::ios::binary);

	// write keys
	int size = this->attribute_list.size();
	fp.write((char*)&size, sizeof(int));
	for (auto & it : this->attribute_list) {
		fp.write(it.first.c_str(), sizeof(char) * ATTRIBUTE_SIZE);
		fp.write((char*)&it.second.first, sizeof(AttrType));
		fp.write((char*)&it.second.second, sizeof(int));
	}

	// write index
	size = this->index_list.size();
	fp.write((char*)&size, sizeof(int));
	for (auto & it : this->index_list) {
		fp.write(it.first.c_str(), sizeof(char) * ATTRIBUTE_SIZE);
		fp.write((char*)&it.second.first, sizeof(IndexType));
		fp.write((char*)&it.second.second, sizeof(int));
	}
	size = this->index_fragment.size();
	fp.write((char*)&size, sizeof(int));
	for (auto & it : this->index_fragment) {
		fp.write((char*)&it, sizeof(int));
	}
	fp.close();
	this->dirty = 0;
}

bool Table_Message::has_attribute(const std::string & attr_name)
{
	return this->attribute_list.find(attr_name) != this->attribute_list.end();
}

AttrType Table_Message::get_attribute_type(const std::string & attr_name)
{
	AttrType ret = 0;
	if (this->has_attribute(attr_name))
		ret = this->attribute_list[attr_name].first;
	return ret;
}

AttrInfo & Table_Message::get_attributes()
{
    return this->attribute_list;
}

bool Table_Message::has_index(const std::string & attr_name)
{
	return this->index_list.find(attr_name) != this->index_list.end();
}

Table_Message::~Table_Message()
{
	this->write_back();
}

int Catalog_Manager::TABLE_NAME_SIZE = 12;

Catalog_Manager::Catalog_Manager(const std::string & database)
	: database_name(database), dirty(0)
{
	this->clear();
}

void Catalog_Manager::load()
{
	std::ifstream fp(this->database_name + "/tables.list", std::ios::binary);
	// std::cout << fp.is_open() << std::endl;
	int num;
	char * buffer = new char[TABLE_NAME_SIZE];
	fp.read((char*)&num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		fp.read(buffer, sizeof(char) * TABLE_NAME_SIZE);
		std::string table_name = std::string(buffer);
//		std::cout << table_name << std::endl;
		this->table_list[table_name] = new Table_Message(this->database_name, table_name);
	}
	delete[] buffer;
	fp.close();
//	std::cout << "table number = " << num << std::endl;
	this->dirty = false;
}

void Catalog_Manager::create_database(const std::string & str)
{
	if (!opendir(str.c_str()))
	{
		mkdir(str.c_str(), S_IRWXU);
		std::ofstream fp;
		fp.open(str + "/tables.list", std::ios::binary);
		int num = 0;
		fp.write((char*)&num, sizeof(int));
		fp.close();
	}
}

void Catalog_Manager::clear()
{
	this->write_back();
	delete_ptr_in_map(this->table_list);
}

void Catalog_Manager::write_back()
{
	for (auto & it : this->table_list) {
		it.second->write_back();
	}
	if (!this->dirty || this->database_name.empty())
		return;
	std::ofstream fp;
	std::string filename = this->database_name + "/tables.list";
	fp.open(filename, std::ios::binary);
	int size = this->table_list.size();
	fp.write((char*)&size, sizeof(int));
	for (auto & it : this->table_list) {
		fp.write(it.first.c_str(), sizeof(char) * TABLE_NAME_SIZE);
	}
	fp.close();
	this->dirty = false;
	// std::cout << "write back done." << std::endl;
}

Catalog_Manager::~Catalog_Manager()
{
	this->clear();
}

void Catalog_Manager::create_table(const std::string & table_name, AttrInfo & attr_list)
{
	std::string table_dir_name = this->database_name + "/" + table_name;
	if (this->database_name.empty() || this->table_list.find(table_name) != this->table_list.end())
		return;
	mkdir(table_dir_name.c_str(), S_IRWXU);
	this->table_list[table_name] = new Table_Message(this->database_name, table_name, attr_list);
	this->dirty = true;
}

void Catalog_Manager::drop_table(const std::string & table_name)
{
	std::string table_dir_name = this->database_name + "/" + table_name;
	if (this->database_name.empty() || this->table_list.find(table_name) == this->table_list.end())
		return;
	std::string cmd = "rm -rf " + table_dir_name;
	system(cmd.c_str());
	delete this->table_list[table_name];
	this->table_list.erase(table_name);
	this->dirty = true;
}

bool Catalog_Manager::has_table(const std::string & table_name)
{
	return this->table_list.find(table_name) != this->table_list.end();
}

bool Catalog_Manager::has_attribute(const std::string & table_name, const std::string & attr_name)
{
	return this->has_table(table_name) && this->table_list[table_name]->has_attribute(attr_name);
}

AttrType Catalog_Manager::get_attribute_type(const std::string & table_name, const std::string & attr_name)
{
	AttrType ret = 0;
	if (this->has_attribute(table_name, attr_name))
		ret = this->table_list[table_name]->get_attribute_type(attr_name);
	return ret;
}

bool Catalog_Manager::has_index(const std::string & table_name, const std::string & attr_name)
{
	return this->has_table(table_name) && this->table_list[table_name]->has_index(attr_name);
}

int Catalog_Manager::data_block_number(const std::string & table_name)
{
	int ret = 0;
	if (this->has_table(table_name))
		ret = this->table_list[table_name]->data_block_number;
	return ret;
}

void Catalog_Manager::add_data_block(const std::string & table_name)
{
	if (this->has_table(table_name))
		this->table_list[table_name]->data_block_number++;
}

AttrInfo & Catalog_Manager::get_attributes(const std::string & table_name)
{
    return this->table_list[table_name]->get_attributes();
}

int Catalog_Manager::get_record_length(const std::string & table_name)
{
	int ret = 0;
	if (this->has_table(table_name))
		ret = this->table_list[table_name]->record_length;
	return ret;
}

std::string Catalog_Manager::get_primary_key(const std::string & table_name)
{
	std::string ret;
	if (this->has_table(table_name))
		ret = this->table_list[table_name]->primary_key;
	return ret;
}

void Catalog_Manager::create_index(const std::string &table_name, const std::string &key_name, IndexType index_type, int entry)
{
	if (this->has_attribute(table_name, key_name)) {
		this->table_list[table_name]->index_list[key_name].first = BPLUSTREE;
		this->table_list[table_name]->index_list[key_name].second = entry;
		this->table_list[table_name]->dirty = true;
	}
}

void Catalog_Manager::drop_index(const std::string & table_name, const std::string & key_name)
{
	if (this->has_index(table_name, key_name)) {
		this->table_list[table_name]->index_list.erase(key_name);
		this->table_list[table_name]->dirty = true;
	}
}

int Catalog_Manager::index_block_number(const std::string & table_name)
{
	int ret = 0;
	if (this->has_table(table_name))
		ret = this->table_list[table_name]->index_block_number;
	return ret;
}

void Catalog_Manager::add_index_block(const std::string & table_name)
{
	if (this->has_table(table_name)) {
		this->table_list[table_name]->index_block_number++;
		this->table_list[table_name]->dirty = true;
	}
}

int Catalog_Manager::get_index_fragment(const std::string & table_name)
{
	int ret = 0;
	if (this->has_table(table_name)) {
		int size = this->table_list[table_name]->index_fragment.size();
		if (size) {
			ret = this->table_list[table_name]->index_fragment[size];
			this->table_list[table_name]->index_fragment.erase(this->table_list[table_name]->index_fragment.end());
			this->table_list[table_name]->dirty = true;
		}
	}
	return ret;
}

void Catalog_Manager::add_index_fragment(const std::string & table_name, int fragment_block_number)
{
	this->table_list[table_name]->index_fragment.push_back(fragment_block_number);
	this->table_list[table_name]->dirty = true;
}

IndexInfo & Catalog_Manager::get_index(const std::string & table_name)
{
	return this->table_list[table_name]->index_list;
}

void Catalog_Manager::update_index_entry(const std::string & table_name, const std::string & key_name, int entry)
{
	if (this->table_list[table_name]->index_list[key_name].second != entry) {
		this->table_list[table_name]->index_list[key_name].second = entry;
		this->table_list[table_name]->dirty = true;
	}
}