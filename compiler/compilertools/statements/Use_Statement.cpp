#include "Use_Statement.hpp"

Use_Statement::Use_Statement(const std::string & str)
	: database_name(str) {}

StatementType Use_Statement::type(void) const
{
	return USE_TYPE;
}

DMType Use_Statement::args(int op) const
{
	return this->database_name;
}

Use_Statement::~Use_Statement() {}