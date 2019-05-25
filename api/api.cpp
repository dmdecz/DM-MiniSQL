#include "api.hpp"

#include <iostream>
#include <fstream>
#include <map>

API::API(void)
{
	this->m_catalog = new Catalog_Manager;
}

void API::excute(Statement * s)
{
	if (s->type() == USE_TYPE)
		this->excute_use_database(s);
	else if (s->type() == CREATE_DB_TYPE)
		this->excute_create_database(s);
	else if (s->type() == DROP_DB_TYPE)
		this->excute_drop_database(s);
	else
		switch (s->type())
		{
		case SELECT_TYPE: this->excute_select(s); break;
		case CREATE_TABLE_TYPE: this->excute_create_table(s); break;
		case DROP_TABLE_TYPE: this->excute_drop_table(s); break;
		default: break;
		}
	std::cout << std::endl;
}

void API::excute_use_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	this->m_catalog->use_database(database_name);
}

void API::excute_create_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	this->m_catalog->create_database(database_name);
}

void API::excute_drop_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	this->m_catalog->drop_database(database_name);
}

void API::excute_select(Statement * s)
{
	ExpressionList * select_list = std::get<ExpressionList *>(s->args(0));
	ExpressionList * table_list = std::get<ExpressionList *>(s->args(1));
	ExpressionList * select_cond = std::get<ExpressionList *>(s->args(2));
	// if (select_list)
	// 	for (size_t i = 0; i < select_list->size(); i++)
	// 		std::cout << std::get<std::string>(((*select_list)[i])->values()) << std::endl;
	// if (table_list)
	// 	for (size_t i = 0; i < table_list->size(); i++)
	// 		std::cout << std::get<std::string>(((*table_list)[i])->values()) << std::endl;
	// if (select_cond)
	// 	for (size_t i = 0; i < select_cond->size(); i++)
	// 		std::cout << std::get<std::string>(((*select_cond)[i])->values()) << std::endl;
	
}

void API::excute_create_table(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args());
	ExpressionList * attribute_list = std::get<ExpressionList *>(s->args(1));
	ExpressionList * constrain_list = std::get<ExpressionList *>(s->args(2));

	std::cout << table_name << std::endl;
	std::map<std::string, AttrType> attrlist;
	if (attribute_list)
		for (size_t i = 0; i < attribute_list->size(); i++)
		{
			std::string name = std::get<std::string>(((*attribute_list)[i])->values(0));
			AttrType type = std::get<int>(((*attribute_list)[i])->values(1));
			attrlist[name] = type;
			// std::cout << name << '\t' << type << std::endl;
		}
	std::vector<std::string> primary_keys;
	this->m_catalog->create_table(table_name, attrlist, primary_keys);
	// if (constrain_list)
	// 	for (size_t i = 0; i < constrain_list->size(); i++)
	// 	{
	// 		std::string name = std::get<std::string>(((*constrain_list)[i])->values(1));
	// 		int type = std::get<int>(((*constrain_list)[i])->values(0));
	// 		std::cout << type << '\t' << name << std::endl;
	// 	}

}

void API::excute_drop_table(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args());
	this->m_catalog->drop_table(table_name);
}

API::~API(void)
{
	delete this->m_catalog;
}