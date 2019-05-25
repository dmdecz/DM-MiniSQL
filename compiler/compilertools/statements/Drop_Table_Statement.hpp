#if !defined(DROP_TABLE_STATEMENT_HPP)
#define DROP_TABLE_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Drop_Table_Statement: public Statement
{
private:
	std::string table_name;
public:
	Drop_Table_Statement(const std::string &);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Drop_Table_Statement();
};

#endif // DROP_TABLE_STATEMENT_HPP
