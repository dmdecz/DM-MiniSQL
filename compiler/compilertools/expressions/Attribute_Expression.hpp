#if !defined(ATTRIBUTE_EXPRESSION_HPP)
#define ATTRIBUTE_EXPRESSION_HPP

#include "../compilertool.hpp"

#include <string>

class Attribute_Expression: public Expression
{
private:
	std::string name;
	int type;
	
public:
	Attribute_Expression(const std::string, int);
	virtual ~Attribute_Expression(void);

	virtual DMType values(int op = 0) const;
};



#endif // ATTRIBUTE_EXPRESSION_HPP
