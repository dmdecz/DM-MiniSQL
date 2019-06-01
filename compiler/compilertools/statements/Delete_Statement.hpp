//
// Created by Zhuo Chen on 2019-06-01.
//

#ifndef DM_DELETE_STATEMENT_HPP
#define DM_DELETE_STATEMENT_HPP

#include "../../../common/common.hpp"

class Delete_Statement: public Statement
{
	std::string table_name;
	ExpressionList * delete_cond;
public:
	Delete_Statement(const std::string & table_name, ExpressionList * delete_condition);
	virtual StatementType type() const;
	virtual DMType args(int op = 0) const;
	virtual ~Delete_Statement();
};

#endif //DM_DELETE_STATEMENT_HPP
