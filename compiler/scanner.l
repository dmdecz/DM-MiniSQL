%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <readline/readline.h>
# include <readline/history.h>
# include "compiler.hpp"
# include "parser.hpp"

#define YY_INPUT(buf,result,max_size) result = mygetinput(buf, max_size);


char getLastNotSpace(const char * s)
{
	const char * p = s + strlen(s);
	while (p != s && *--p == ' ');
	return *p;
}

char * getCmd(int size)
{
	char * str = readline("DM> ");
	while (!str || strlen(str) == 0) {
		str = readline("DM> ");
	}
	
	char * ret = (char*)malloc(sizeof(char)*size);
	strcpy(ret, str);
	add_history(str);

	while (getLastNotSpace(str) != ';' && strlen(ret) < size) {
		free(str);
		str = readline("  > ");
		strcat(ret, " ");
		strcat(ret, str);
		add_history(str);
	}
	free(str);
	// printf("string: %s\n", ret);
	return ret;
}

char * getFile(std::string & f)
{
	std::ifstream in(f);
	if(!in) {
		std::cerr << "ERROR\nCannot open file ''" << f << "'': " << strerror(errno) << '\n';
	}
	f.clear();
	std::ostringstream tmp;
	tmp << in.rdbuf();
	std::string ret = tmp.str();
	char * buf = (char *)malloc(sizeof(char) * (ret.size()+2));
	char endl[] = ";";
	strcpy(buf, ret.c_str());
	strcat(buf, endl);
	return buf;
}

static int mygetinput(char *buf, int size) {
	// printf("***input***\n");
	char * line;
	if (feof(yyin))  return YY_NULL;
	if (Compiler::file.empty())
		line = getCmd(size);
	else
		line = getFile(Compiler::file);
	if(!line)	return YY_NULL;
	sprintf(buf,"%s\n",line);
	free(line);
	return strlen(buf);
}

%}

%{
// Pacify warnings in yy_init_buffer (observed with Flex 2.6.4)
// and GCC 6.4.0, 7.3.0.
#if defined __GNUC__ && !defined __clang__ && 6 <= __GNUC__
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

// Of course, when compiling C as C++, expect warnings about NULL.
#if defined __clang__
# pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#elif defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
# pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

#define FLEX_VERSION (YY_FLEX_MAJOR_VERSION * 100 + YY_FLEX_MINOR_VERSION)

// Old versions of Flex (2.5.35) generate an incomplete documentation comment.
//
//  In file included from src/scan-code-c.c:3:
//  src/scan-code.c:2198:21: error: empty paragraph passed to '@param' command
//        [-Werror,-Wdocumentation]
//   * @param line_number
//     ~~~~~~~~~~~~~~~~~^
//  1 error generated.
#if FLEX_VERSION < 206 && defined __clang__
# pragma clang diagnostic ignored "-Wdocumentation"
#endif

// Old versions of Flex (2.5.35) use 'register'.  Warnings introduced in
// GCC 7 and Clang 6.
#if FLEX_VERSION < 206
# if defined __clang__ && 6 <= __clang_major__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
# elif defined __GNUC__ && 7 <= __GNUC__
#  pragma GCC diagnostic ignored "-Wregister"
# endif
#endif

#if FLEX_VERSION < 206
# if defined __clang__
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wdocumentation"
#  pragma clang diagnostic ignored "-Wshorten-64-to-32"
#  pragma clang diagnostic ignored "-Wsign-conversion"
# elif defined __GNUC__
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wsign-conversion"
# endif
#endif
%}

%option noyywrap nounput noinput batch debug

%{
	// A number symbol corresponding to the value in S.
	yy::parser::symbol_type
	make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
%}

int				[0-9]+
blank			[ \t\r]
string		[A-Z_a-z][a-zA-Z_0-9]*
filename	[a-zA-Z_0-9]+\.[a-zA-Z_0-9]+

%{
	// Code run each time a pattern is matched.
	# define YY_USER_ACTION  loc.columns (yyleng);
%}

%%
%{
	// A handy shortcut to the location held by the driver.
	yy::location& loc = drv.location;
	// Code run each time yylex is called.
	loc.step ();
%}
{blank}+   			loc.step ();
\n+        			loc.lines (yyleng); loc.step ();
{int}				return make_NUMBER (yytext, loc);
";"					return yy::parser::make_ENDL  (loc);
"SELECT"|"select"	return yy::parser::make_SELECT(loc);
"DROP"|"drop"		return yy::parser::make_DROP(loc);
"FROM"|"from"		return yy::parser::make_FROM  (loc);
"WHERE"|"where"		return yy::parser::make_WHERE (loc);
"QUIT"|"quit"		return yy::parser::make_QUIT  (loc);
"SOURCE"|"source"	return yy::parser::make_SOURCE(loc);
"CREATE"|"create"	return yy::parser::make_CREATE(loc);
"TABLE"|"table"		return yy::parser::make_TABLE (loc);
"USE"|"use"			return yy::parser::make_USE (loc);
"DATABASE"|"database" return yy::parser::make_DATABASE (loc);
"INT"|"int"			return yy::parser::make_INT (loc);
"DOUBLE"|"double"	return yy::parser::make_DOUBLE (loc);
"CHAR"|"char"		return yy::parser::make_CHAR (loc);
"primary key"		return yy::parser::make_PRIMARY_KEY (loc);
"foreign key"		return yy::parser::make_FOREIGN_KEY (loc);
"-"					return yy::parser::make_MINUS  (loc);
"+"					return yy::parser::make_PLUS   (loc);
"*"					return yy::parser::make_STAR   (loc);
"/"					return yy::parser::make_SLASH  (loc);
"("					return yy::parser::make_LPAREN (loc);
")"					return yy::parser::make_RPAREN (loc);
","					return yy::parser::make_COMMA (loc);
{filename}			return yy::parser::make_FILENAME(std::string(yytext), loc);
{string}			return yy::parser::make_STRING(std::string(yytext), loc);
.					/*std::cout << loc << ": invalid character: " + std::string(yytext) << std::endl*/;
<<EOF>>				return yy::parser::make_END (loc);
%%

yy::parser::symbol_type
make_NUMBER (const std::string &s, const yy::parser::location_type& loc)
{
	errno = 0;
	long n = strtol (s.c_str(), NULL, 10);
	// if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
	// 	throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
	return yy::parser::make_NUMBER ((int) n, loc);
}

void
Compiler::scan_begin ()
{
	yy_flex_debug = trace_scanning;
    yyin = stdin;
}

void
Compiler::scan_end ()
{
	YY_FLUSH_BUFFER;
}
