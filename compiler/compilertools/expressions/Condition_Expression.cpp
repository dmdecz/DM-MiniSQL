//
// Created by Zhuo Chen on 2019-05-31.
//

#include "Condition_Expression.hpp"

Condition_Expression::Condition_Expression(const std::string & _attribute_name, CmpType _compare, DMType _value)
	: attribute_name(_attribute_name), compare(_compare), value(_value) {}

Condition_Expression::~Condition_Expression() = default;

DMType Condition_Expression::values(int op) const
{
	switch (op) {
		case 0:
			return this->attribute_name;
		case 1:
			return this->compare;
		case 2:
			return this->value;
		default:
			return this->attribute_name;
	}
}