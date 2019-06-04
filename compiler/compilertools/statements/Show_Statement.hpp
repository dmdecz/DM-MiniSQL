#ifndef DM_SHOW_STATEMENT_HPP
#define DM_SHOW_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Show_Statement: public Statement
{
private:
	int content;

public:
	Show_Statement(int content);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Show_Statement();
};

#endif //DM_SHOW_STATEMENT_HPP
