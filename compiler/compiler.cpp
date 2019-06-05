#include "compiler.hpp"

#include <fstream>

#include <readline/readline.h>
#include <readline/history.h>
#include <cstring>
#include <sstream>

char getLastNotSpace(const char * s);
char * getCmd();

void Compiler::execute_statement(Statement * s)
{
	if (s) {
		if (s->type() == SOURCE_TYPE) {
			file = s->args().to_string();
			delete s;
			result = 1;
		} else {
			result = this->api->execute(s);
			file.clear();
		}
	}
}

void Compiler::execute_statement(std::vector<Statement *> & s)
{
	for (auto & it : s) {
		result = this->api->execute(it);
		if (result == -1) {
			break;
		}
	}
}

Compiler::~Compiler(void) = default;

Compiler::Compiler(API * a)
	: api(a), trace_parsing (false), trace_scanning (false) {}

Compiler::Compiler(API * a, const std::string & file_name)
		: api(a), trace_parsing (false), trace_scanning (false), file(file_name) {}

int Compiler::parse()
{
	this->scan_string();
	FILE * fp = fopen(".log", "w");
	fprintf(fp, "%s", this->instructions.c_str());
	fclose(fp);
	fp = fopen(".log", "r");

	location.initialize (&file);
	scan_begin(fp);
	yy::parser parse (*this);
	parse.set_debug_level (trace_parsing);
	int res = parse ();
	scan_end();
	return res;
}

void Compiler::scan_string()
{
	if (file.empty()) {
		this->instructions = getCmd();
	} else {
		std::ifstream fp(file);
		if (fp.is_open()) {
			std::stringstream buffer;
			buffer << fp.rdbuf();
			this->instructions = buffer.str();
		}
	}
}

bool Compiler::quit()
{
	return result == -1;
}

char getLastNotSpace(const char * s)
{
	const char * p = s + strlen(s);
	while (p != s && *--p == ' ');
	return *p;
}

char * getCmd()
{
	char * str = readline("DM> ");
	while (!str || strlen(str) == 0) {
		str = readline("DM> ");
	}

	char * ret = (char*)malloc(sizeof(char)*4096);
	strcpy(ret, str);
	add_history(str);

	while (getLastNotSpace(str) != ';' && strlen(ret) < 4096) {
		free(str);
		str = readline("  > ");
		strcat(ret, " ");
		strcat(ret, str);
		add_history(str);
	}
	free(str);
	return ret;
}
