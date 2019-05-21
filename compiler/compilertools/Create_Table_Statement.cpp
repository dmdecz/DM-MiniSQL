#include "Create_Database_Statement.hpp"

Create_Database_Statement::Create_Database_Statement(void)
	: attribute_list(nullptr), constrain_list(nullptr) {}

void Create_Database_Statement::set_attribute(ExpressionList * el)
{
	this->attribute_list = el;
}

void Create_Database_Statement::set_constrain(ExpressionList * el)
{
	this->constrain_list = el;
}

StatementType Create_Database_Statement::type(void) const
{
	return CREATE_DB_TYPE;
}

const ExpressionList * Create_Database_Statement::args(int op) const
{
	switch (op)
	{
	case 0: return this->attribute_list;
	case 1: return this->constrain_list;
	default: return this->attribute_list;
	}
}

Create_Database_Statement::~Create_Database_Statement(void)
{
	delete this->attribute_list;
	delete this->constrain_list;
}
