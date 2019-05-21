#if !defined(__COMPILER_HPP__)
#define __COMPILER_HPP__

#include "compilertools/compilertools.hpp"
#include "parser.hpp"

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex (Compiler& drv)
// ... and declare it for the parser's sake.
YY_DECL;

class Compiler
{
public:
	static std::string file;

	Compiler();
	void execute_statement(Statement *);
	virtual ~Compiler();

	int result;
	int parse ();
	bool trace_parsing;
	void scan_begin ();
  	void scan_end ();
 	bool trace_scanning;
  	yy::location location;
};

#endif // __COMPILER_HPP__
