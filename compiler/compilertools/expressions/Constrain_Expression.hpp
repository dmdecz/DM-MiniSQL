#if !defined(CONSTRAIN_HPP)
#define CONSTRAIN_HPP

#include "../../../common/common.hpp"

#include <string>

class Constrain_Expression: public Expression
{
private:
	int constrain_type;
	std::string constrain_name;

public:
	Constrain_Expression(int, const std::string &);
	virtual ~Constrain_Expression();

	virtual DMType values(int op = 0) const;
};


#endif // CONSTRAIN_HPP
