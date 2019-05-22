#include "Attribute_Expression.hpp"

Attribute_Expression::Attribute_Expression(const std::string str, int d)
	: name(str), type(d) {}

Attribute_Expression::~Attribute_Expression(void) {}

DMType Attribute_Expression::values(int op) const 
{
	switch (op)
	{
	case 0: return this->name;
	case 1: return this->type;
	default: return this->name;
	}
}