#include "Constrain_Expression.hpp"

Constrain_Expression::Constrain_Expression(int type, const std::string & str)
	: constrain_type(type), constrain_name(str) {}

Constrain_Expression::~Constrain_Expression(void) {}

DMType Constrain_Expression::values(int op) const
{
	switch (op)
	{
	case 0: return this->constrain_type;
	case 1: return this->constrain_name;
	default: return this->constrain_type;
	}
}