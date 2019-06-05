//
// Created by Zhuo Chen on 2019-06-01.
//

#include "Delete_Statement.hpp"

Delete_Statement::Delete_Statement(const std::string & _table_name, ExpressionList * delete_condition)
	: table_name(_table_name), delete_cond(delete_condition) {}

StatementType Delete_Statement::type() const
{
	return DELETE_TYPE;
}

DMType Delete_Statement::args(int op) const
{
	switch (op) {
		case 0:
			return DMType(this->table_name);
		case 1:
			return DMType(this->delete_cond);
		default:
			return DMType(this->table_name);
	}
}

Delete_Statement::~Delete_Statement() = default;