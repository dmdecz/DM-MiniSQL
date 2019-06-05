#include "Create_Database_Statement.hpp"

Create_Database_Statement::Create_Database_Statement(const std::string & str)
	: database_name(str) {}

StatementType Create_Database_Statement::type(void) const
{
	return CREATE_DB_TYPE;
}

DMType Create_Database_Statement::args(int op) const
{
	return DMType(this->database_name);
}

Create_Database_Statement::~Create_Database_Statement() {}

