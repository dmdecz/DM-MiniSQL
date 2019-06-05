#include "Insert_Statement.hpp"

Insert_Statement::Insert_Statement(const std::string & table, ExpressionList * al, ExpressionList * vl)
	: table_name(table), attribute_list(al), value_list(vl) {}

Insert_Statement::~Insert_Statement()
{
	delete this->attribute_list;
	delete this->value_list;
}

StatementType Insert_Statement::type(void) const
{
	return INSERT_TYPE;
}

DMType Insert_Statement::args(int op) const
{
	switch (op)
	{
	case 0: return DMType(this->table_name);
	case 1: return DMType(this->attribute_list);
	case 2: return DMType(this->value_list);
	default: return DMType(this->table_name);
	}
}