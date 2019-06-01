#include "Attribute_Expression.hpp"

Attribute_Expression::Attribute_Expression(const std::string str, int d, int _info)
	: name(str), type(d), info(_info) {}

Attribute_Expression::~Attribute_Expression(void) {}

DMType Attribute_Expression::values(int op) const 
{
	switch (op)
	{
	case 0: return this->name;
	case 1: return this->type;
	case 2: return this->info;
	default: return this->name;
	}
}