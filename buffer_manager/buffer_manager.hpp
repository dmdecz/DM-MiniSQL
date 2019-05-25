#if !defined(BUFFER_MANAGER_HPP)
#define BUFFER_MANAGER_HPP

#include <string>
#include <vector>

class Block
{
private:
	int table_number;
	int block_number;
	char * data;
	bool lock;
	bool dirty;

public:
	Block();
	void load();
	void write_back();
	~Block();
};

class Buffer_Manager
{
private:
	std::string database_name;
	std::vector<Block *> block_pool;
	const int BUFFER_SIZE;
	const int BLOCK_SIZE;

public:
	Buffer_Manager();
	Buffer_Manager(int, int);

	Block * get_block(int, int);

	void clear();
	~Buffer_Manager();
};



#endif // BUFFER_MANAGER_HPP
