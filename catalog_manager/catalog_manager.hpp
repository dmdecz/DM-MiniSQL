#if !defined(CATALOG_MANAGER_HPP)
#define CATALOG_MANAGER_HPP

#include "../common/common.hpp"

#include <string>
#include <vector>
#include <map>

class Table_Message
{
private:
	const std::string & database_name;
	std::string table_name;
	std::map<std::string, AttrType> attribute_list;
	int record_length;
	std::string primary_key;
	bool dirty;
	static int ATTRIBUTE_SIZE;
	std::map<std::string, IndexType> index_list;
	int block_number;
	friend class Catalog_Manager;

public:
	Table_Message(const std::string &, const std::string &);
	Table_Message(const std::string &, const std::string &, std::map<std::string, AttrType> &, const std::string &);
	void load();
	void write_back();
	bool has_attribute(const std::string &);
	AttrType get_attribute_type(const std::string &);
    std::map<std::string, AttrType> & get_attributes();
	bool has_index(const std::string &);
	~Table_Message();
};

class Catalog_Manager
{
private:
	const std::string & database_name;
	std::map<std::string, Table_Message *> table_list;
	bool dirty;
	static int TABLE_NAME_SIZE;

public:
	Catalog_Manager(const std::string &);
	void load();
	void create_database(const std::string &);

	void create_table(const std::string &, std::map<std::string, AttrType> &, std::string &);
	void drop_table(const std::string &);

	bool has_table(const std::string &);
	bool has_attribute(const std::string &, const std::string &);
	AttrType get_attribute_type(const std::string &, const std::string &);
	bool has_index(const std::string &, const std::string &);
	int data_block_number(const std::string &);
	void add_data_block(const std::string &);
    std::map<std::string, AttrType> & get_attributes(const std::string &);
	int get_record_length(const std::string &);

	void clear();
	void write_back();
	~Catalog_Manager();
};



#endif // CATALOG_MANAGER_HPP
