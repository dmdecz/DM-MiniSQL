//
// Created by Zhuo Chen on 2019-06-01.
//

#ifndef DM_INDEX_MANAGER_HPP
#define DM_INDEX_MANAGER_HPP

#include "../common/common.hpp"

class Index_Manager
{
private:
	const std::string & database_name;
	Catalog_Manager * m_catalog;
	Buffer_Manager * m_buffer;
public:
	Index_Manager(const std::string & database_name, Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager);
	~Index_Manager();
};

#endif //DM_INDEX_MANAGER_HPP
