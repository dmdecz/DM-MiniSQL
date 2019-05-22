#include "compiler.hpp"

std::string Compiler::file = "";

void Compiler::execute_statement(Statement * s)
{
	if (s)
	{
		this->api->excute(s);
		delete s;
	}		
}

Compiler::~Compiler(void) {}

Compiler::Compiler(API * a)
	: api(a), trace_parsing (false), trace_scanning (false) {}

int Compiler::parse()
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