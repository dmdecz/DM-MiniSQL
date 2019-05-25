#include "buffer_manager.hpp"
#include "../common/common.hpp"

Buffer_Manager::Buffer_Manager()
	: BUFFER_SIZE(64), BLOCK_SIZE(4096) {}

Buffer_Manager::Buffer_Manager(int buffer_size, int block_size)
	: BUFFER_SIZE(buffer_size), BLOCK_SIZE(block_size) {}

void Buffer_Manager::clear()
{
	delete_ptr_in_vector(this->block_pool);
}

Buffer_Manager::~Buffer_Manager()
{
	this->clear();
}