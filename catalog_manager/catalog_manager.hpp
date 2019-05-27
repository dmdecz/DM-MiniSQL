#if !defined(CATALOG_MANAGER_HPP)
#define CATALOG_MANAGER_HPP

#include "../common/common.hpp"

#include <string>
#include <vector>
#include <map>

class Table_Message
{
private:
	std::string & database_name;
	std::string table_name;
	std::map<std::string, AttrType> attribute_list;
	std::string primary_key;
	bool dirty;
	static int ATTRIBUTE_SIZE;
	std::map<std::string, IndexType> index_list;
	int block_number;
	friend class Catalog_Manager;

public:
	Table_Message(std::string &, const std::string &);
	Table_Message(std::string &, const std::string &, std::map<std::string, AttrType> &, const std::string &);
	void load();
	void write_back();
	bool has_index(const std::string &);
	~Table_Message();
};

class Catalog_Manager
{
private:
	std::string database_name;
	std::map<std::string, Table_Message *> table_list;
	bool dirty;
	static int TABLE_NAME_SIZE;

public:
	Catalog_Manager();
	void use_database(const std::string &);
	void create_database(const std::string &);
	void drop_database(const std::string &);

	void create_table(const std::string &, std::map<std::string, AttrType> &, std::string &);
	void drop_table(const std::string &);

	bool has_table(const std::string &);
	bool has_index(const std::string &, const std::string &);
	int data_block_number(const std::string &);

	void clear();
	void drop();
	void write_back();
	~Catalog_Manager();
};



#endif // CATALOG_MANAGER_HPP
