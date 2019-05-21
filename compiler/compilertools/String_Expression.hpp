#if !defined(STRING_EXPRESSION_HPP)
#define STRING_EXPRESSION_HPP

#include "compilertool.hpp"

class String_Expression: public Expression
{
private:
	std::string exp;
public:
	String_Expression(const std::string);
	const std::string & value(void) const;
	virtual ~String_Expression(void) {}
};

#endif // STRING_EXPRESSION_HPP
