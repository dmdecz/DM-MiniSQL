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
	AttrInfo attribute_list;
	int record_length;
	std::string primary_key;
	bool dirty;

	IndexInfo index_list;
	std::vector<int> index_fragment;
	int index_block_number;
	int data_block_number;
	friend class Catalog_Manager;

public:
	static int ATTRIBUTE_SIZE;
	static int RECORD_INFO_SIZE;

	Table_Message(const std::string &, const std::string &);
	Table_Message(const std::string &, const std::string &, AttrInfo &);
	void load();
	void write_back();
	bool has_attribute(const std::string &);
	AttrType get_attribute_type(const std::string &);
	AttrInfo & get_attributes();
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

	void create_table(const std::string &, AttrInfo &);
	void drop_table(const std::string &);

	bool has_table(const std::string &);
	bool has_attribute(const std::string &, const std::string &);
	AttrType get_attribute_type(const std::string &, const std::string &);
	int data_block_number(const std::string &);
	void add_data_block(const std::string &);
    AttrInfo & get_attributes(const std::string &);
	int get_record_length(const std::string &);
	std::string get_primary_key(const std::string &);

	bool has_index(const std::string &, const std::string &);
	void create_index(const std::string &table_name, const std::string &key_name, IndexType index_type, int entry);
	void drop_index(const std::string & table_name, const std::string & key_name);
	int index_block_number(const std::string & table_name);
	void add_index_block(const std::string & table_name);
	int get_index_fragment(const std::string & table_name);
	IndexInfo & get_index(const std::string & table_name);

	void clear();
	void write_back();
	~Catalog_Manager();
};



#endif // CATALOG_MANAGER_HPP
