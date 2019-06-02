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
	Record_Manager(const std::string &, Catalog_Manager *, Buffer_Manager *);
	void select(const std::string &, std::vector<std::string> &, CmpInfo &);
	void insert(const std::string &, std::map<std::string, DMType> &);
	void insert_to_new_block(const std::string &, std::map<std::string, DMType> &, int);
	int insert_to_old_block(const std::string &, std::map<std::string, DMType> &, int);
	void delete_record(const std::string & table_name, CmpInfo & cond);
	~Record_Manager();
};


#endif // RECORD_MANAGER_HPP
