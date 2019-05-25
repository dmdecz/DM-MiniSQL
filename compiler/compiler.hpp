#if !defined(__COMPILER_HPP__)
#define __COMPILER_HPP__

#include "../common/common.hpp"
#include "parser.hpp"
#include "../api/api.hpp"

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex (Compiler& drv)
// ... and declare it for the parser's sake.
YY_DECL;

class Compiler
{
public:
	static std::string file;

	bool trace_scanning;
  	yy::location location;

	API * api;

	Compiler(API *);
	void execute_statement(Statement *);
	virtual ~Compiler();

	// parser
	int parse ();
	bool trace_parsing;
	void scan_begin ();
  	void scan_end ();
};

#endif // __COMPILER_HPP__
