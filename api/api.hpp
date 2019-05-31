#if !defined(API_HPP)
#define API_HPP

#include "../common/common.hpp"
#include "../catalog_manager/catalog_manager.hpp"
#include "../buffer_manager/buffer_manager.hpp"
#include "../record_manager/record_manager.hpp"

#include <vector>
#include <string>

class API
{
private:
	std::string database_name;
	Catalog_Manager * m_catalog;
	Buffer_Manager * m_buffer;
	Record_Manager * m_record;

public:
	API();
	
	int execute(Statement *);
	void execute_use_database(Statement *);
	void execute_create_database(Statement *);
	void execute_drop_database(Statement *);
	void execute_select(Statement *);
	void execute_create_table(Statement *);
	void execute_drop_table(Statement *);
	void execute_insert(Statement *);
	~API();
};


#endif // API_HPP
