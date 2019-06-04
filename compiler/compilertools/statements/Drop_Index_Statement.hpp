#ifndef DM_DROP_INDEX_STATEMENT_HPP
#define DM_DROP_INDEX_STATEMENT_HPP

#include "../../../common/common.hpp"

#include <string>

class Drop_Index_Statement: public Statement
{
private:
	std::string table_name;
	std::string key_name;

public:
	Drop_Index_Statement(const std::string & table_name, const std::string & key_name);
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
	virtual ~Drop_Index_Statement();
};

#endif //DM_DROP_INDEX_STATEMENT_HPP
