//
// Created by Zhuo Chen on 2019-05-30.
//

#include "Quit_Statement.hpp"

Quit_Statement::Quit_Statement() {}

Quit_Statement::~Quit_Statement() = default;

StatementType Quit_Statement::type(void) const
{
	return QUIT_TYPE;
}

DMType Quit_Statement::args(int op) const
{
	return DMType(0);
}