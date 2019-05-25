#if !defined(DROP_DATABASE_STATEMENT_HPP)
#define DROP_DATABASE_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Drop_Database_Statement: public Statement
{
private:
	std::string database_name;
public:
	Drop_Database_Statement(const std::string &);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Drop_Database_Statement();
};

#endif // DROP_DATABASE_STATEMENT_HPP
