#if !defined(BUFFER_MANAGER_HPP)
#define BUFFER_MANAGER_HPP

#include "../common/common.hpp"

#include <string>
#include <vector>

class Block
{
private:
	const std::string & database_name;
	std::string table_name;
	int block_number;
	char * data;
	bool locked;
	bool dirty;
	friend class Buffer_Manager;
public:
	static int BLOCK_SIZE;
	static int BLOCK_HEAD_SIZE;

	Block(const std::string &, const std::string &, int);
	Block(const std::string &, const std::string &, int, char *);
	void load();
	void write_back();
	void lock();
	void unlock();
	bool is_hit(const std::string &, int);
	void datacpy(int, const void *, size_t);
	void zero(int begin = 0, int end = Block::BLOCK_SIZE);
	char * get_data(int);
	~Block();
};

class Buffer_Manager
{
private:
	const std::string & database_name;
	std::vector<Block *> block_pool;

public:
	static int BUFFER_SIZE;

	Buffer_Manager(const std::string &);

	Block * get_block(const std::string &, int);
	void put_block(Block *);

	Block * create_block(const std::string & table_name, int block_num);

	void clear();
	~Buffer_Manager();
};



#endif // BUFFER_MANAGER_HPP
