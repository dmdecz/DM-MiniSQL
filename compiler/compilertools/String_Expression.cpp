#include "String_Expression.hpp"

String_Expression::String_Expression(const std::string s)
	: exp(s) {}

const std::string & String_Expression::value(void) const
{
	return this->exp;
}