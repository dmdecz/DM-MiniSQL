#include "common.hpp"

#include <string>

size_t ExpressionList::size(void) const
{
	return this->list.size();
}

void ExpressionList::push_back(Expression * e)
{
	this->list.push_back(e);
}

Expression * ExpressionList::operator[](int index) const
{
	return this->list[index];
}

void ExpressionList::clear(void)
{
	this->list.clear();
}

ExpressionList::~ExpressionList(void)
{
	delete_ptr_in_vector(this->list);
}
