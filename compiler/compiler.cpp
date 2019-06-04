#include "compiler.hpp"

std::string Compiler::file = "";

void Compiler::execute_statement(Statement * s)
{
	result = this->api->execute(s);
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
	int res = 0;
	try {
		res = parse();
	} catch (Error & e) {
		e.diagnose();
		res = 0;
	}
	scan_end();
	if (!file.empty())
		res = this->parse();
	return res;
}
