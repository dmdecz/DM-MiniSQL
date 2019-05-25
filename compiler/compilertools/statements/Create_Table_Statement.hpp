#if !defined(CREATE_TABLE_STATEMENT_HPP)
#define CREATE_TABLE_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Create_Table_Statement: public Statement
{
private:
	std::string table_name;
	ExpressionList * attribute_list;
	ExpressionList * constrain_list;

public:
	Create_Table_Statement(const std::string &);
	void set_attribute(ExpressionList *);
	void set_constrain(ExpressionList *);
	virtual StatementType type(void) const;
	const std::string & args() const;
	virtual DMType args(int op = 0) const;
	virtual ~Create_Table_Statement();
};


#endif // CREATE_TABLE_STATEMENT_HPP
