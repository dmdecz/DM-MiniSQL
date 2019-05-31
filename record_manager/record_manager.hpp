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
	std::map<std::string, AttrType> & type;
	std::map<std::string, DMType> value;
public:
	Record(std::map<std::string, AttrType> & type);
	void get_value(char * data);
	DMType operator[](const std::string &);
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
	void select(const std::string &, std::vector<std::string> &);
	void insert(const std::string &, std::map<std::string, DMType> &);
	void insert_to_new_block(const std::string &, std::map<std::string, DMType> &, int);
	int insert_to_old_block(const std::string &, std::map<std::string, DMType> &, int);
	~Record_Manager();
};


#endif // RECORD_MANAGER_HPP
