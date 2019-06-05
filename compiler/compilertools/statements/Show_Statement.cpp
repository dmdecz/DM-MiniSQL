#include "Show_Statement.hpp"

Show_Statement::Show_Statement(int _content)
	: content(_content) {}

StatementType Show_Statement::type(void) const
{
	return SHOW_TYPE;
}

DMType Show_Statement::args(int op) const
{
	return DMType(this->content);
}

Show_Statement::~Show_Statement() = default;