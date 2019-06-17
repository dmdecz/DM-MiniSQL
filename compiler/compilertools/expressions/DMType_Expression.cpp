#include "DMType_Expression.hpp"

DMType_Expression::DMType_Expression(DMType d)
	: data(d) {}

DMType_Expression::~DMType_Expression() {}

DMType DMType_Expression::values(int op) const
{
	return this->data;
}