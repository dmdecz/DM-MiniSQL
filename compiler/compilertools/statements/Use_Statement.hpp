#if !defined(USE_STATEMENT_HPP)
#define USE_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Use_Statement: public Statement
{
private:
	std::string database_name;
public:
	Use_Statement(const std::string &);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Use_Statement();
};

#endif // USE_STATEMENT_HPP
