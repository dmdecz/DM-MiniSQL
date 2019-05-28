#if !defined(INSERT_STATEMENT_HPP)
#define INSERT_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Insert_Statement: public Statement
{
private:
	std::string table_name;
	ExpressionList * attribute_list;
	ExpressionList * value_list;
	
public:
	Insert_Statement(const std::string &, ExpressionList *, ExpressionList *);
	virtual ~Insert_Statement();
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
};

#endif // INSERT_STATEMENT_HPP
