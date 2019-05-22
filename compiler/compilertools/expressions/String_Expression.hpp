#if !defined(STRING_EXPRESSION_HPP)
#define STRING_EXPRESSION_HPP

#include "../compilertool.hpp"

class String_Expression: public Expression
{
private:
	std::string exp;
public:
	String_Expression(const std::string &);
	virtual ~String_Expression(void);

	virtual DMType values(int op = 0) const;
};

#endif // STRING_EXPRESSION_HPP
