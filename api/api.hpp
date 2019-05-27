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
	API(void);
	
	void excute(Statement *);
	void excute_use_database(Statement *);
	void excute_create_database(Statement *);
	void excute_drop_database(Statement *);
	void excute_select(Statement *);
	void excute_create_table(Statement *);
	void excute_drop_table(Statement *);
	~API(void);
};


#endif // API_HPP
