#include "Drop_Index_Statement.hpp"

Drop_Index_Statement::Drop_Index_Statement(const std::string & _table_name, const std::string & _key_name)
		: table_name(_table_name), key_name(_key_name) {}

StatementType Drop_Index_Statement::type(void) const
{
	return DROP_INDEX_TYPE;
}

DMType Drop_Index_Statement::args(int op) const
{
	switch (op) {
		case 0:
			return DMType(this->table_name);
		case 1:
			return DMType(this->key_name);
		default:
			return DMType(this->table_name);
	}
}

Drop_Index_Statement::~Drop_Index_Statement() = default;