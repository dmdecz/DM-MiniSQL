#if !defined(CREATE_DATABASE_STATEMENT_HPP)
#define CREATE_DATABASE_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Create_Database_Statement: public Statement
{
private:
	std::string database_name;
public:
	Create_Database_Statement(const std::string &);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Create_Database_Statement();
};

#endif // CREATE_DATABASE_STATEMENT_HPP
