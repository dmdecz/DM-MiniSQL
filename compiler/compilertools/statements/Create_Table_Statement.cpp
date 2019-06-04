#include "Create_Table_Statement.hpp"

Create_Table_Statement::Create_Table_Statement(const std::string & str)
	: table_name(str), attribute_list(nullptr), constrain_list(nullptr) {}

void Create_Table_Statement::set_attribute(ExpressionList * el)
{
	this->attribute_list = el;
}

void Create_Table_Statement::set_constrain(ExpressionList * el)
{
	this->constrain_list = el;
}

StatementType Create_Table_Statement::type(void) const
{
	return CREATE_TABLE_TYPE;
}

DMType Create_Table_Statement::args(int op) const
{
	switch (op)
	{
	case 0: return this->table_name;
	case 1: return this->attribute_list;
	case 2: return this->constrain_list;
	default: return this->attribute_list;
	}
}

Create_Table_Statement::~Create_Table_Statement(void)
{
	delete this->attribute_list;
	delete this->constrain_list;
}
