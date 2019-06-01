//
// Created by Zhuo Chen on 2019-06-01.
//

#include "index_manager.hpp"

Index_Manager::Index_Manager(const std::string &_database_name, Catalog_Manager *catalog_manager, Buffer_Manager *buffer_manager)
	: database_name(_database_name), m_catalog(catalog_manager), m_buffer(buffer_manager) {}

Index_Manager::~Index_Manager() = default;
