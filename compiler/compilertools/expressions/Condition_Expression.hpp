//
// Created by Zhuo Chen on 2019-05-31.
//

#ifndef DM_CONDITION_EXPRESSION_HPP
#define DM_CONDITION_EXPRESSION_HPP

#include "../../../common/common.hpp"

#include <string>

class Condition_Expression: public Expression
{
private:
	std::string attribute_name;
	int compare;
	DMType value;
public:
	Condition_Expression(const std::string & attribute_name, int compare, DMType value);
	virtual ~Condition_Expression();

	virtual DMType values(int op = 0) const;
};

#endif //DM_CONDITION_EXPRESSION_HPP
