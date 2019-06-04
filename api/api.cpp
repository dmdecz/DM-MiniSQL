#include "api.hpp"
#include "../error/error.h"

#include <iostream>
#include <fstream>
#include <map>

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

API::API()
{
	this->database_name.clear();
	this->m_catalog = new Catalog_Manager(this->database_name);
	this->m_buffer = new Buffer_Manager(this->database_name);
	this->m_record = new Record_Manager(this->database_name, this->m_catalog, this->m_buffer);
	this->m_index = new Index_Manager(this->database_name, this->m_catalog, this->m_buffer);
}

int API::execute(Statement * s)
{
	if (!s)
		return -1;
	int ret = 1;
	try {
		if (s->type() == QUIT_TYPE) {
			std::cout << "Bye" << std::endl;
			ret = -1;
		} else if (s->type() == USE_TYPE) {
			this->execute_use_database(s);
		} else if (s->type() == CREATE_DB_TYPE) {
			this->execute_create_database(s);
		} else if (s->type() == DROP_DB_TYPE) {
			this->execute_drop_database(s);
		} else {
			if (this->database_name.empty()) {
				throw Error(7, "Please use database first.");
			}
			int begin = clock();
			switch (s->type()) {
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
				case DELETE_TYPE:
					this->execute_delete(s);
					break;
				default:
					break;
			}
			int end = clock();
			std::cout << "Query cost " << (double)(end - begin) / CLOCKS_PER_SEC << "s." << std::endl;
		}
		delete s;
	} catch (Error & e) {
		e.diagnose();
	}

	std::cout << std::endl;
	return ret;
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
	std::cout << "Database changed." << std::endl;
}

void API::execute_create_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	this->m_catalog->create_database(database_name);
	std::cout << "Query OK, 0 row(s) affected." << std::endl;
}

void API::execute_drop_database(Statement * s)
{
	std::string database_name = std::get<std::string>(s->args());
	if (opendir(database_name.c_str())) {
		if (database_name == this->database_name)
		{
			this->database_name.clear();
			this->m_catalog->clear();
			this->m_buffer->clear();
		}
		std::string cmd = "rm -rf " + database_name;
		system(cmd.c_str());
	} else {
		throw Error(1, "No database named '" + database_name + "'.");
	}
	std::cout << "Database '" + database_name + "' has been deleted." << std::endl;
}

void API::execute_select(Statement * s)
{
	ExpressionList * select_list = std::get<ExpressionList *>(s->args(0));
	ExpressionList * table_list = std::get<ExpressionList *>(s->args(1));
	ExpressionList * select_cond = std::get<ExpressionList *>(s->args(2));
	std::string table_name = std::get<std::string>(((*table_list)[0])->values());
	std::vector<std::string> list;
	CmpInfo cond;
	for (int i = 0; i < select_list->size(); ++i) {
		std::string str = std::get<std::string>((*select_list)[i]->values());
		list.push_back(str);
	}
	if (select_cond) {
		for (size_t i = 0; i < select_cond->size(); i++) {
			std::string str = std::get<std::string>(((*select_cond)[i])->values(0));
			cond[str] = std::make_pair(std::get<int>(((*select_cond)[i])->values(1)), ((*select_cond)[i])->values(2));
		}
	}
	if (this->m_catalog->has_table(table_name)) {
		AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
		for (int i = 0; i < list.size(); ++i) {
			if (list[i] == "*") {
				list.erase(list.begin() + i);
				for (auto & it : attribute_list) {
					list.insert(list.begin() + i, it.first);
				}
			}
			if (attribute_list.find(list[i]) == attribute_list.end())
				throw Error(701, "Table '" + table_name + "' has no attribute '" + list[i] + "'.");
		}
		int block_number = 0;
		bool index = false;
		for (auto & attr : cond) {
			if (attribute_list.find(attr.first) == attribute_list.end()) {
				throw Error(701, "Table '" + table_name + "' has no attribute '" + attr.first + "'.");
			}
			if (attr.second.first == EQUAL && this->m_catalog->has_index(table_name, attr.first)) {
				index = true;
				int temp_block_number = this->m_index->search_key(table_name, attr.first, attr.second.second);
				if (temp_block_number == 0) {
					block_number = 0;
					break;
				} else if (block_number == 0) {
					block_number = temp_block_number;
				} else if (block_number != temp_block_number) {
					block_number = 0;
					break;
				}
			}
		}
//		std::cout << block_number << std::endl;
		if (index) {
			this->m_record->select_record(table_name, list, cond, block_number);
		} else {
			this->m_record->select_record(table_name, list, cond);
		}
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
	if (!this->m_catalog->has_table(table_name)) {
		throw Error(700, "No table named '" + table_name + "'.");
	}
	if (attribute_list->size() != value_list->size())
		throw Error(756, "The values are incompleted.");
	for (size_t i = 0; i < attribute_list->size(); i++)
	{
		std::string attr = std::get<std::string>((*attribute_list)[i]->values());
		attr_value[attr] = (*value_list)[i]->values();
	}

	AttrInfo & key_list = this->m_catalog->get_attributes(table_name);
	IndexInfo & indices = this->m_catalog->get_index(table_name);
	std::vector<std::string> check_list;
	for (auto & it : key_list) {
		if (attr_value.find(it.first) == attr_value.end()) {
			throw Error(757, "Part of attributes.");
		}
		if (!type_match(it.second.first, attr_value[it.first])) {
			throw Error(758, "Attributes don't match.");
		}
		int search = 0;
		if (this->m_catalog->has_index(table_name, it.first)) {
			search = this->m_index->search_key(table_name, it.first, attr_value[it.first]);
		} else if (it.second.second > 0) {
			search = this->m_record->search_key(table_name, it.first, attr_value[it.first]);
		}
		if (search) {
			throw Error(102, "Duplicated value of " + it.first);
		}
	}

	int block_number = this->m_record->insert_record(table_name, attr_value);
	this->m_index->insert_key(table_name, attr_value, block_number);

}

void API::execute_delete(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args(0));
	ExpressionList * delete_cond = std::get<ExpressionList *>(s->args(1));
	if (!this->m_catalog->has_table(table_name)) {
		throw Error(700, "No table named '" + table_name + "'.");
	}

	CmpInfo cond;
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	IndexInfo & indices = this->m_catalog->get_index(table_name);

	for (size_t i = 0; i < delete_cond->size(); i++) {
		std::string str = std::get<std::string>(((*delete_cond)[i])->values(0));
		cond[str] = std::make_pair(std::get<int>(((*delete_cond)[i])->values(1)), ((*delete_cond)[i])->values(2));
	}
	int block_number = 0;
	bool index = false;
	std::map<std::string, std::vector<DMType>> keys_to_be_deleted;
	for (auto & it : cond) {
		if (attribute_list.find(it.first) == attribute_list.end()) {
			throw Error(701, "Table '" + table_name + "' has no attribute '" + it.first + "'.");
		}
		if (this->m_catalog->has_index(table_name, it.first) && it.second.first == EQUAL) {
			index = true;
			int temp_block_number = this->m_index->search_key(table_name, it.first, it.second.second);
			if (temp_block_number == 0) {
				block_number = 0;
				break;
			} else if (block_number == 0) {
				block_number = temp_block_number;
			} else if (block_number != temp_block_number) {
				block_number = 0;
				break;
			}
		}
	}

	if (index) {
		keys_to_be_deleted = this->m_record->delete_record(table_name, cond, block_number);
	} else {
		keys_to_be_deleted = this->m_record->delete_record(table_name, cond);
	}

	for (auto & it : keys_to_be_deleted) {
		if (this->m_catalog->has_index(table_name, it.first)) {
//			std::cout << "delete index " << it.first << std::endl;
			this->m_index->delete_key(table_name, it.first, it.second);
		}
	}
}

void API::execute_create_table(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args());
	ExpressionList * attribute_list = std::get<ExpressionList *>(s->args(1));
	ExpressionList * constrain_list = std::get<ExpressionList *>(s->args(2));

	AttrInfo attrlist;
	if (attribute_list) {
		for (size_t i = 0; i < attribute_list->size(); i++) {
			std::string name = std::get<std::string>(((*attribute_list)[i])->values(0));
			AttrType type = std::get<int>(((*attribute_list)[i])->values(1));
			int other_info = std::get<int>(((*attribute_list)[i])->values(2));
			attrlist[name].first = type;
			attrlist[name].second = other_info;
		}
	}

	std::string primary_key;
	if (constrain_list) {
		primary_key = std::get<std::string>(((*constrain_list)[0])->values(1));
		attrlist[primary_key].second = 2;
	}
	this->m_catalog->create_table(table_name, attrlist);

	if (!primary_key.empty()) {
		this->m_index->create_index(table_name, primary_key);
	}
	std::cout << "Query OK, 0 row(s) affected." << std::endl;
}

void API::execute_drop_table(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args());
	if (!this->m_catalog->has_table(table_name)) {
		throw Error(700, "No table named '" + table_name + "'.");
	}
	this->m_catalog->drop_table(table_name);
	std::cout << "Table '" + table_name + "' has been deleted." << std::endl;
}

API::~API()
{
//	std::cout << "~API" << std::endl;
	delete this->m_catalog;
	delete this->m_buffer;
	delete this->m_record;
	delete this->m_index;
}
