#if !defined(BUFFER_MANAGER_HPP)
#define BUFFER_MANAGER_HPP

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

public:
	Block(const std::string &, const std::string &, int);
	Block(const std::string &, const std::string &, int, char *);
	void load();
	void write_back();
	void lock();
	void unlock();
	bool is_hit(const std::string &, int);
	~Block();
};

class Buffer_Manager
{
private:
	std::string database_name;
	std::vector<Block *> block_pool;

public:
	static int BUFFER_SIZE;
	static int BLOCK_SIZE;

	Buffer_Manager();

	Block * get_block(const std::string &, int);

	void use_database(const std::string &);
	void drop_database(const std::string &);
	void clear();
	~Buffer_Manager();
};



#endif // BUFFER_MANAGER_HPP
