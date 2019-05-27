#if !defined(RECORD_MANAGER_HPP)
#define RECORD_MANAGER_HPP

#include "../buffer_manager/buffer_manager.hpp"
#include "../catalog_manager/catalog_manager.hpp"
#include "../common/common.hpp"

#include <string>
#include <map>

class Record_Manager
{
private:
	Catalog_Manager * m_catalog;
	Buffer_Manager * m_buffer;

public:
	Record_Manager(Catalog_Manager *, Buffer_Manager *);
	void select(const std::string &);
	void insert(const std::string &, std::map<std::string, DMType> &);
	~Record_Manager();
};


#endif // RECORD_MANAGER_HPP
