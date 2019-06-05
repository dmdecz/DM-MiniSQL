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
private:
	std::string file;
	std::string instructions;

	bool trace_scanning;

	API * api;

	int result;

public:
	yy::location location;

	explicit Compiler(API *);
	Compiler(API *, const std::string & file_name);
	void execute_statement(Statement *);
	void execute_statement(std::vector<Statement *> &);
	virtual ~Compiler();

	// parser
	int parse ();
	bool trace_parsing;
	void scan_begin(FILE * fp);
  	void scan_end();
  	void scan_string();

  	bool quit();
};

#endif // __COMPILER_HPP__
