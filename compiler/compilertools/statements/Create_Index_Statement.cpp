#include "Create_Index_Statement.hpp"

Create_Index_Statement::Create_Index_Statement(const std::string & _table_name, const std::string & _key_name)
	: table_name(_table_name), key_name(_key_name) {}

StatementType Create_Index_Statement::type(void) const
{
	return CREATE_INDEX_TYPE;
}

DMType Create_Index_Statement::args(int op) const
{
	switch (op) {
		case 0:
			return this->table_name;
		case 1:
			return this->key_name;
		default:
			return this->table_name;
	}
}

Create_Index_Statement::~Create_Index_Statement() = default;