#include "DMType_Expression.hpp"

DMType_Expression::DMType_Expression(_DMType d)
	: data(d) {}

DMType_Expression::~DMType_Expression() {}

DMType DMType_Expression::values(int op) const
{
	return DMType(this->data);
}