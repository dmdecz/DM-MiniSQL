#include "api.hpp"
#include "../error/error.h"

#include <iostream>
#include <fstream>
#include <map>

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

API::API(void)
{
	this->database_name.clear();
	this->m_catalog = new Catalog_Manager(this->database_name);
	this->m_buffer = new Buffer_Manager(this->database_name);
	this->m_record = new Record_Manager(this->database_name, this->m_catalog, this->m_buffer);
}

int API::execute(Statement * s)
{
	if (!s)
		return -1;
	try {
		switch (s->type())
		{
			case QUIT_TYPE:
				std::cout << "Bye" << std::endl;
				return -1;
			case USE_TYPE:
				this->execute_use_database(s);
				break;
			case CREATE_DB_TYPE:
				this->execute_create_database(s);
				break;
			case DROP_DB_TYPE:
				this->execute_drop_database(s);
				break;
			case SELECT_TYPE:
				this->execute_select(s);
				break;
			case CREATE_TABLE_TYPE:
				this->execute_create_table(s);
				break;
			case DROP_TABLE_TYPE:
				this->execute_drop_table(s);
				break;
			case INSERT_TYPE:
				this->execute_insert(s);
				break;
			default:
				break;
		}
		delete s;
	} catch (Error & e) {
		e.diagnose();
	}

	std::cout << std::endl;
	return 1;
}

void API::execute_use_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	if (database_name == this->database_name)
		return;
	if (!opendir(database_name.c_str()))
		throw Error(1, "No database named '" + database_name + "'.");
	this->m_catalog->clear();
	this->m_buffer->clear();

	this->database_name = database_name;

	this->m_catalog->load();
}

void API::execute_create_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	this->m_catalog->create_database(database_name);
}

void API::execute_drop_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	if (opendir(database_name.c_str()))
	{
		if (database_name == this->database_name)
		{
			this->database_name.clear();
			this->m_catalog->clear();
			this->m_buffer->clear();
		}
		std::string cmd = "rm -rf " + database_name;
		system(cmd.c_str());
	}
}

void API::execute_select(Statement * s)
{
	ExpressionList * select_list = std::get<ExpressionList *>(s->args(0));
	ExpressionList * table_list = std::get<ExpressionList *>(s->args(1));
	ExpressionList * select_cond = std::get<ExpressionList *>(s->args(2));
	std::string table_name = std::get<std::string>(((*table_list)[0])->values());
	std::vector<std::string> list;
	for (int i = 0; i < select_list->size(); ++i) {
		std::string str = std::get<std::string>((*select_list)[i]->values());
		list.push_back(str);
	}
	if (select_cond) {
		for (size_t i = 0; i < select_cond->size(); i++) {
			std::cout << std::get<std::string>(((*select_cond)[i])->values()) << std::endl;

		}
	}
	if (this->m_catalog->has_table(table_name)) {
		this->m_record->select(table_name, list);
	} else {
		throw Error(700, "No table named '" + table_name + "'.");
	}

}

void API::execute_insert(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args(0));
	ExpressionList * attribute_list = std::get<ExpressionList *>(s->args(1));
	ExpressionList * value_list = std::get<ExpressionList *>(s->args(2));
	std::map<std::string, DMType> attr_value;
	if (attribute_list->size() != value_list->size())
		return;
	for (size_t i = 0; i < attribute_list->size(); i++)
	{
		std::string attr = std::get<std::string>((*attribute_list)[i]->values());
		attr_value[attr] = (*value_list)[i]->values();
//		std::cout << attr << std::endl;
	}

	this->m_record->insert(table_name, attr_value);

}

void API::execute_create_table(Statement * s)
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
		}
	std::string primary_key = std::get<std::string>(((*constrain_list)[0])->values(1));
	this->m_catalog->create_table(table_name, attrlist, primary_key);
}

void API::execute_drop_table(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args());
	this->m_catalog->drop_table(table_name);
}

API::~API(void)
{
//	std::cout << "~API" << std::endl;
	delete this->m_catalog;
	delete this->m_buffer;
	delete this->m_record;
}
