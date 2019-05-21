#if !defined(CREATE_TABLE_STATEMENT_HPP)
#define CREATE_TABLE_STATEMENT_HPP

#include "compilertool.hpp"

class Create_Database_Statement: public Statement
{
private:
	ExpressionList * attribute_list;
	ExpressionList * constrain_list;
public:
	Create_Database_Statement(void);
	void set_attribute(ExpressionList *);
	void set_constrain(ExpressionList *);
	virtual StatementType type(void) const;
	virtual const ExpressionList * args(int) const;
	virtual ~Create_Database_Statement();
};


#endif // CREATE_TABLE_STATEMENT_HPP
