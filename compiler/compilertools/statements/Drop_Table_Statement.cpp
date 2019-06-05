#include "Drop_Table_Statement.hpp"

Drop_Table_Statement::Drop_Table_Statement(const std::string & str)
	: table_name(str) {}

StatementType Drop_Table_Statement::type(void) const
{
	return DROP_TABLE_TYPE;
}

DMType Drop_Table_Statement::args(int op) const
{
	return DMType(this->table_name);
}

Drop_Table_Statement::~Drop_Table_Statement() {}

