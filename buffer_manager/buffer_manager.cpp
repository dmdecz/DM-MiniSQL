#include "buffer_manager.hpp"
#include "../common/common.hpp"

#include <fstream>
#include <iostream>

Block::Block(const std::string & database, const std::string & table, int number)
	: database_name(database), table_name(table), block_number(number), dirty(0), locked(0)
{
	this->load();
}

Block::Block(const std::string & database, const std::string & table, int number, char * buf)
	: database_name(database), table_name(table), block_number(number), dirty(1), locked(0), data(buf) {}

void Block::load()
{
	std::ifstream fp;
	std::string filename = this->database_name + "/" + this->table_name + "/data.dm";
	fp.open(filename, std::ios::binary);
	fp.seekg(Buffer_Manager::BLOCK_SIZE * this->block_number, std::ios::beg);
	this->data = new char[Buffer_Manager::BLOCK_SIZE];
	fp.read(this->data, sizeof(char) * Buffer_Manager::BLOCK_SIZE);
}

void Block::write_back()
{
	std::cout << this->database_name << " " << this->table_name << " " << this->dirty << std::endl;
	if (this->database_name.empty() || !this->dirty)
		return;
	std::ofstream fp;
	std::string filename = this->database_name + "/" + this->table_name + "/data.dm";
	fp.open(filename, std::ios::binary);
	fp.seekp(Buffer_Manager::BLOCK_SIZE * this->block_number, std::ios::beg);
	fp.write(this->data, sizeof(char) * Buffer_Manager::BLOCK_SIZE);
}

void Block::lock()
{
	this->locked = 1;
}

void Block::unlock()
{
	this->locked = 0;
}

bool Block::is_hit(const std::string & table, int number)
{
	return this->table_name == table && this->block_number == number;
}

Block::~Block()
{
	std::cout << "~Block" << std::endl;
	this->write_back();
	delete this->data;
}

int Buffer_Manager::BUFFER_SIZE = 64;
int Buffer_Manager::BLOCK_SIZE = 4096;

Buffer_Manager::Buffer_Manager(const std::string & database)
	: database_name(database) {}

Block * Buffer_Manager::get_block(const std::string & table_name, int block_num)
{
	Block * ret = nullptr;
	for (size_t i = 0; i < this->block_pool.size(); i++)
	{
		if (this->block_pool[i]->is_hit(table_name, block_num))
		{
			ret = this->block_pool[i];
			break;
		}
	}
	if (!ret)
	{
		ret = new Block(this->database_name, table_name, block_num);
		this->block_pool.push_back(ret);
	}
	return ret;
}

void Buffer_Manager::put_block(Block * block)
{
	this->block_pool.push_back(block);
}

void Buffer_Manager::clear()
{
	delete_ptr_in_vector(this->block_pool);
}

Buffer_Manager::~Buffer_Manager()
{
	std::cout << "~Buffer_Manager" << std::endl;
	std::cout << this->block_pool.size() << std::endl;
	this->clear();
}