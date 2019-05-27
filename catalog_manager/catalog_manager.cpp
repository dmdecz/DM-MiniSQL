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

Table_Message::Table_Message(std::string & database, const std::string & table)
	: database_name(database), table_name(table), dirty(0)
{
	this->load();
}

Table_Message::Table_Message(std::string & database, const std::string & table, std::map<std::string, AttrType> & attr, const std::string & primary_key)
	: database_name(database), table_name(table), attribute_list(attr), dirty(1), block_number(0)
{
	this->index_list[primary_key] = BPLUSTREE;
	this->write_back();
}

void Table_Message::load()
{
	std::ifstream fp;
	std::string filename = this->database_name + "/" + this->table_name + "/table.info";

	fp.open(filename, std::ios::binary);

	int size = 0;
	fp.read((char*)&size, sizeof(int));
	char * buffer = new char[ATTRIBUTE_SIZE];
	AttrType type;
	for (int i = 0; i < size; i++)
	{
		fp.read(buffer, sizeof(char) * ATTRIBUTE_SIZE);
		fp.read((char*)&type, sizeof(AttrType));
		this->attribute_list[std::string(buffer)] = type;
		// std::cout << buffer << '\t' << type << std::endl;
	}

	fp.seekg(516, std::ios::beg);
	fp.read((char*)&size, sizeof(int));
	IndexType index_type;
	for (int i = 0; i < size; i++)
	{
		fp.read(buffer, sizeof(char) * ATTRIBUTE_SIZE);
		fp.read((char*)&index_type, sizeof(IndexType));
		this->index_list[std::string(buffer)] = index_type;
		// std::cout << buffer << '\t' << index_type << std::endl;
	}

	delete buffer;
	fp.close();

	std::string table_filename = this->database_name + "/" + table_name + "/data.dm";
	fp.open(table_filename, std::ios::binary);
	this->block_number = 0;
	if (fp.is_open())
	{
		fp.seekg(0, std::ios::end);
		this->block_number = fp.tellg() / Buffer_Manager::BLOCK_SIZE + 1;
		fp.close();
	}
	this->dirty = 0;
}

void Table_Message::write_back()
{
	if (!this->dirty)
		return;
	std::ofstream fp;
	std::string filename = this->database_name + "/" + this->table_name + "/table.info";
	fp.open(filename, std::ios::binary);
	int size = this->attribute_list.size();
	char * buffer = new char[ATTRIBUTE_SIZE];
	memset(buffer, 0, sizeof(char) * ATTRIBUTE_SIZE);
	int zero = 0;
	fp.write((char*)&size, sizeof(int));
	for (std::map<std::string, AttrType>::iterator it = this->attribute_list.begin(); it != this->attribute_list.end(); it++)
	{
		fp.write(it->first.c_str(), sizeof(char) * ATTRIBUTE_SIZE);
		fp.write((char*)&it->second, sizeof(AttrType));
	}
	for (size_t i = 0; i < 32 - size; i++)
	{
		fp.write(buffer, sizeof(char) * ATTRIBUTE_SIZE);
		fp.write((char*)&zero, sizeof(AttrType));
	}

	size = this->index_list.size();
	std::cout << "::" << size << std::endl;
	fp.write((char*)&size, sizeof(int));
	for (std::map<std::string, IndexType>::iterator it = this->index_list.begin(); it != this->index_list.end(); it++)
	{
		std::cout << "index: \n" << it->first.c_str() << std::endl;
		fp.write(it->first.c_str(), sizeof(char) * ATTRIBUTE_SIZE);
		fp.write((char*)&it->second, sizeof(IndexType));
	}
	for (size_t i = 0; i < 32 - size; i++)
	{
		fp.write(buffer, sizeof(char) * ATTRIBUTE_SIZE);
		fp.write((char*)&zero, sizeof(AttrType));
	}
	fp.close();
	this->dirty = 0;
}

bool Table_Message::has_index(const std::string & attr_name)
{
	return this->index_list.find(attr_name) != this->index_list.end();
}

Table_Message::~Table_Message() {}

int Catalog_Manager::TABLE_NAME_SIZE = 12;

Catalog_Manager::Catalog_Manager()
	: dirty(0)
{
	this->clear();
}

void Catalog_Manager::use_database(const std::string & str)
{
	this->clear();
	DIR * database_dir = opendir(str.c_str());
	// std::cout << database_dir << std::endl;
	if (database_dir)
	{
		this->database_name = str;
		std::ifstream fp(str + "/tables.list", std::ios::binary);
		// std::cout << fp.is_open() << std::endl;
		int num;
		char * buffer = new char[TABLE_NAME_SIZE];
		fp.read((char*)&num, sizeof(int));
		for (int i = 0; i < num; i++)
		{
			fp.read(buffer, sizeof(char) * TABLE_NAME_SIZE);
			std::string table_name = std::string(buffer);
			std::cout << table_name << std::endl;
			this->table_list[table_name] = new Table_Message(this->database_name, table_name);
		}
		delete buffer;
		fp.close();
		std::cout << "table number = " << num << std::endl;
		this->dirty = 0;
	}
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

void Catalog_Manager::drop_database(const std::string & str)
{
	if (opendir(str.c_str()))
	{
		if (str == this->database_name)
			this->drop();
		std::string cmd = "rm -rf " + str;
		system(cmd.c_str());
	}
}

void Catalog_Manager::clear()
{
	this->write_back();
	delete_ptr_in_map(this->table_list);
}

void Catalog_Manager::drop()
{
	this->database_name.clear();
	delete_ptr_in_map(this->table_list);
}

void Catalog_Manager::write_back()
{
	for (std::map<std::string, Table_Message *>::iterator it = this->table_list.begin(); it != this->table_list.end(); it++)
		it->second->write_back();
	if (!this->dirty || this->database_name.empty())
		return;
	std::ofstream fp;
	std::string filename = this->database_name + "/tables.list";
	fp.open(filename, std::ios::binary);
	int size = this->table_list.size();
	fp.write((char*)&size, sizeof(int));
	for (std::map<std::string, Table_Message *>::iterator it = this->table_list.begin(); it != this->table_list.end(); it++)
	{
		fp.write(it->first.c_str(), sizeof(char) * TABLE_NAME_SIZE);
	}
	fp.close();
	this->dirty = 0;
	// std::cout << "write back done." << std::endl;
}

Catalog_Manager::~Catalog_Manager()
{
	this->clear();
}

void Catalog_Manager::create_table(const std::string & table_name, std::map<std::string, AttrType> & attr_list, std::string & primary_key)
{
	std::string table_dir_name = this->database_name + "/" + table_name;
	std::cout << table_dir_name << std::endl;
	if (this->database_name.empty() || this->table_list.find(table_name) != this->table_list.end())
		return;
	mkdir(table_dir_name.c_str(), S_IRWXU);
	this->table_list[table_name] = new Table_Message(this->database_name, table_name, attr_list, primary_key);
	this->dirty = 1;
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
	this->dirty = 1;
}

bool Catalog_Manager::has_table(const std::string & table_name)
{
	return this->table_list.find(table_name) != this->table_list.end();
}

bool Catalog_Manager::has_index(const std::string & table_name, const std::string & attr_name)
{
	return this->has_table(table_name) && this->table_list[table_name]->has_index(attr_name);
}

int Catalog_Manager::data_block_number(const std::string & table_name)
{
	int ret = 0;
	if (this->has_table(table_name))
		ret = this->table_list[table_name]->block_number;
	return ret;
}