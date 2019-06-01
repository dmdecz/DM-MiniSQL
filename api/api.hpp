#if !defined(API_HPP)
#define API_HPP

#include "../common/common.hpp"
#include "../catalog_manager/catalog_manager.hpp"
#include "../buffer_manager/buffer_manager.hpp"
#include "../record_manager/record_manager.hpp"
#include "../index_manager/index_manager.cpp"

#include <vector>
#include <string>

class API
{
private:
	std::string database_name;
	Catalog_Manager * m_catalog;
	Buffer_Manager * m_buffer;
	Record_Manager * m_record;
	Index_Manager * m_index;

public:
	API();
	
	int execute(Statement * s);
	void execute_use_database(Statement * s);
	void execute_create_database(Statement * s);
	void execute_drop_database(Statement * s);
	void execute_select(Statement * s);
	void execute_create_table(Statement * s);
	void execute_drop_table(Statement * s);
	void execute_insert(Statement * s);
	void execute_delete(Statement * s);
	~API();
};


#endif // API_HPP
