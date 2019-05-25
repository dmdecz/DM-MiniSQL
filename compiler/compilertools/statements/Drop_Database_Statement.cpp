#include "Drop_Database_Statement.hpp"

Drop_Database_Statement::Drop_Database_Statement(const std::string & str)
	: database_name(str) {}

StatementType Drop_Database_Statement::type(void) const
{
	return DROP_DB_TYPE;
}

DMType Drop_Database_Statement::args(int op) const
{
	return this->database_name;
}

Drop_Database_Statement::~Drop_Database_Statement() {}

