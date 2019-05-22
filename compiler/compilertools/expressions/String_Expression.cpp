#include "String_Expression.hpp"

String_Expression::String_Expression(const std::string & s)
	: exp(s) {}

String_Expression::~String_Expression(void) {}

DMType String_Expression::values(int) const
{
	return this->exp;
}