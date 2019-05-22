#include "api.hpp"

#include <iostream>

API::API(void) {}

void API::excute(Statement * s)
{
	switch (s->type())
	{
	case SELECT_TYPE: this->excute_select(s); break;
	case CREATE_TABLE_TYPE: this->excute_table(s); break;
	default: break;
	}
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

void API::excute_table(Statement * s)
{
	std::string table_name = std::get<std::string>(s->args());
	ExpressionList * attribute_list = std::get<ExpressionList *>(s->args(1));
	ExpressionList * constrain_list = std::get<ExpressionList *>(s->args(2));

	std::cout << table_name << std::endl;
	if (attribute_list)
		for (size_t i = 0; i < attribute_list->size(); i++)
		{
			std::string name = std::get<std::string>(((*attribute_list)[i])->values(0));
			int type = std::get<int>(((*attribute_list)[i])->values(1));
			std::cout << name << '\t' << type << std::endl;
		}
	
	// if (constrain_list)
	// 	for (size_t i = 0; i < constrain_list->size(); i++)
	// 	{
	// 		std::string name = std::get<std::string>(((*constrain_list)[i])->values(1));
	// 		int type = std::get<int>(((*constrain_list)[i])->values(0));
	// 		std::cout << type << '\t' << name << std::endl;
	// 	}

}

API::~API(void) {}