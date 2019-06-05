#if !defined(DMTYPE_EXPRESSION_HPP)
#define DMTYPE_EXPRESSION_HPP

#include "../../../common/common.hpp"

class DMType_Expression: public Expression
{
private:
	_DMType data;

public:
	DMType_Expression(_DMType);
	virtual ~DMType_Expression();

	virtual DMType values(int op = 0) const;
};

#endif // DMTYPE_EXPRESSION_HPP
