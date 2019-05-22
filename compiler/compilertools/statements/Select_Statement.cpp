#include "Select_Statement.hpp"

Select_Statement::Select_Statement(void)
	: select_list(nullptr), table_list(nullptr), select_cond(nullptr) {}

void Select_Statement::set_select(ExpressionList * e)
{
	this->select_list = e;
}

void Select_Statement::set_table(ExpressionList * e)
{
	this->table_list = e;
}

void Select_Statement::set_condition(ExpressionList * e)
{
	this->select_cond = e;
}

StatementType Select_Statement::type(void) const
{
	return SELECT_TYPE;
}

DMType Select_Statement::args(int op) const
{
	switch (op)
	{
	case 0: return this->select_list;
	case 1: return this->table_list;
	case 2: return this->select_cond;
	default: return this->select_list;
	}
}

Select_Statement::~Select_Statement(void)
{
	delete this->select_list;
	delete this->table_list;
	delete this->select_cond;
}
