#if !defined(SELECT_STATEMENT_HPP)
#define SELECT_STATEMENT_HPP

#include "../../../common/common.hpp"

class Select_Statement: public Statement
{
	ExpressionList * select_list;
	ExpressionList * table_list;
	ExpressionList * select_cond;
public:
	Select_Statement(void);
	void set_select(ExpressionList *);
	void set_table(ExpressionList *);
	void set_condition(ExpressionList *);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Select_Statement(void);
};

#endif // SELECT_STATEMENT_HPP
