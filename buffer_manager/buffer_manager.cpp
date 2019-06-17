#include "buffer_manager.hpp"
#include "../common/common.hpp"

#include <fstream>
#include <iostream>
#include <cstring>

int Block::BLOCK_SIZE = 4096;
int Block::BLOCK_HEAD_SIZE = sizeof(int) * 2;

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
	std::string filename;
	if (block_number > 0) {
		filename = this->database_name + "/" + this->table_name + "/data.dm";
	} else {
		filename = this->database_name + "/" + this->table_name + "/index.dm";
	}
	fp.open(filename, std::ios::binary);
	int offset = abs(this->block_number) - 1;
	fp.seekg(Block::BLOCK_SIZE * offset, std::ios::beg);
	this->data = new char[Block::BLOCK_SIZE];
	fp.read(this->data, sizeof(char) * Block::BLOCK_SIZE);
	fp.close();
}

void Block::write_back()
{
	if (this->database_name.empty() || !this->dirty || !this->block_number)
		return;
	std::fstream fp;
	std::string filename;
	if (block_number > 0) {
		filename = this->database_name + "/" + this->table_name + "/data.dm";
	} else {
		filename = this->database_name + "/" + this->table_name + "/index.dm";
	}

	fp.open(filename, std::ios::binary | std::ios::out | std::ios::in);
	if (!fp.is_open()) {
		fp.open(filename, std::ios::binary | std::ios::out);
	}
	int offset = abs(this->block_number) - 1;
	fp.seekp(Block::BLOCK_SIZE * offset, std::ios::beg);
	fp.write(this->data, sizeof(char) * Block::BLOCK_SIZE);
	fp.close();
	this->dirty = false;
}

void Block::datacpy(int offset, const void * s, size_t length)
{
	memcpy(this->data + offset, s, length);
	this->dirty = true;
}

void Block::zero(int begin, int end)
{
	memset(this->data + begin, 0, sizeof(char) * (end - begin));
	this->dirty = true;
}

char * Block::get_data(int offset)
{
	return this->data + offset;
}

void Block::lock()
{
	this->locked = true;
}

void Block::unlock()
{
	this->locked = false;
}

bool Block::is_hit(const std::string & table, int number)
{
	return this->table_name == table && this->block_number == number;
}

Block::~Block()
{
	this->write_back();
	delete[] this->data;
}

int Buffer_Manager::BUFFER_SIZE = 3;

Buffer_Manager::Buffer_Manager(const std::string & database)
	: database_name(database) {}

Block * Buffer_Manager::get_block(const std::string & table_name, int block_num)
{
	Block * ret = nullptr;
	if (block_num == 0) {
		return ret;
	}

	for (size_t i = 0; i < this->block_pool.size(); i++)
	{
		if (this->block_pool[i]->is_hit(table_name, block_num))
		{
			ret = this->block_pool[i];
			this->block_pool.erase(this->block_pool.begin() + i);
			this->block_pool.insert(this->block_pool.begin(), ret);
			break;
		}
	}
	if (!ret)
	{
		ret = new Block(this->database_name, table_name, block_num);
		this->put_block(ret);
	}

	return ret;
}

void Buffer_Manager::put_block(Block * block)
{
	if (this->block_pool.size() == Buffer_Manager::BUFFER_SIZE) {
		delete this->block_pool[BUFFER_SIZE - 1];
		this->block_pool.pop_back();
	}
	this->block_pool.insert(this->block_pool.begin(), block);
}

void Buffer_Manager::clear()
{
	delete_ptr_in_vector(this->block_pool);
}

Block * Buffer_Manager::create_block(const std::string & table_name, int block_num)
{
	char * buffer = new char[Block::BLOCK_SIZE];
	Block * ret = new Block(this->database_name, table_name, block_num, buffer);
	this->put_block(ret);
	ret->zero();
	return ret;
}

Buffer_Manager::~Buffer_Manager()
{
	this->clear();
}