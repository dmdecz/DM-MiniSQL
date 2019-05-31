//
// Created by Zhuo Chen on 2019-05-30.
//

#ifndef DM_QUIT_STATEMENT_HPP
#define DM_QUIT_STATEMENT_HPP

#include "../../../common/common.hpp"

class Quit_Statement: public Statement
{
public:
	Quit_Statement();
	virtual ~Quit_Statement();
	virtual StatementType type(void) const;
	virtual DMType args(int op = 0) const;
};

#endif //DM_QUIT_STATEMENT_HPP
