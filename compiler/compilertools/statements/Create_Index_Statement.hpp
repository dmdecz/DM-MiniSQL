#ifndef DM_CREATE_INDEX_STATEMENT_HPP
#define DM_CREATE_INDEX_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Create_Index_Statement: public Statement
{
private:
	std::string table_name;
	std::string key_name;

public:
	Create_Index_Statement(const std::string & table_name, const std::string & key_name);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Create_Index_Statement();
};

#endif //DM_CREATE_INDEX_STATEMENT_HPP
