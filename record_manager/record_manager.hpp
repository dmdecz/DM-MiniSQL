#if !defined(RECORD_MANAGER_HPP)
#define RECORD_MANAGER_HPP

#include "../buffer_manager/buffer_manager.hpp"
#include "../catalog_manager/catalog_manager.hpp"
#include "../common/common.hpp"

#include <string>
#include <map>

class Record
{
private:
	AttrInfo & type;
	CmpInfo condition;
	std::map<std::string, DMType> value;
	bool empty;
	int next_offset;

public:
	Record(AttrInfo & type);
	Record(AttrInfo & type, CmpInfo & condition);
	Record(AttrInfo & type, std::map<std::string, DMType> & value, bool empty = 0, int next_offset = 0);
	void get_value(char * data);
	DMType operator[](const std::string &);
	bool is_valid();
	int write_to_block(Block * block, int offset);
	void delete_record(int next_offset);
	void clear();
	~Record();
};

class Record_Manager
{
private:
	const std::string & database_name;
	Catalog_Manager * m_catalog;
	Buffer_Manager * m_buffer;

public:
	Record_Manager(const std::string & database_name, Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager);
	void select_record(const std::string & table_name, std::vector<std::string> & list, CmpInfo & cond);
	void select_record(const std::string & table_name, std::vector<std::string> & list, CmpInfo & cond, int block_number);
	int insert_record(const std::string & table_name, std::map<std::string, DMType> & attr_list);
	int insert_to_new_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size);
	int insert_to_old_block(const std::string & table_name, std::map<std::string, DMType> & attr_list, int size);
	std::map<std::string, std::vector<DMType>> delete_record(const std::string & table_name, CmpInfo & cond);
	std::map<std::string, std::vector<DMType>> delete_record(const std::string & table_name, CmpInfo & cond, int block_number);

	int search_key(const std::string & table_name, const std::string & key_name, DMType & key);

	~Record_Manager();
};


#endif // RECORD_MANAGER_HPP
