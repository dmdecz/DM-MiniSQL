#include "compiler.hpp"

std::string Compiler::file = "";

void Compiler::execute_statement(Statement * s)
{
	if (s)
	{
		std::cout << s->type() << std::endl;
		std::cout << s->args(0) << std::endl;
		std::cout << s->args(1) << std::endl;
		std::cout << s->args(2) << std::endl;
		delete s;
	}		
}

Compiler::~Compiler(void) {}

Compiler::Compiler ()
	: trace_parsing (false), trace_scanning (false) {}

int
Compiler::parse()
{
	location.initialize(&file);
	scan_begin();
	yy::parser parse(*this);
	parse.set_debug_level(trace_parsing);
	int res = parse();
	scan_end();
	if (!file.empty())
		res = this->parse();

	return res;
}
