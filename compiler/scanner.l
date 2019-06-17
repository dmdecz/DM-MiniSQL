%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

# include "compiler.hpp"
# include "parser.hpp"

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

	yy::parser::symbol_type
    make_DECIMAL (const std::string &s, const yy::parser::location_type& loc);
%}

int				[\-]?[0-9]+
decimal			[\-]?[0-9]+\.[0-9]+
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
{decimal}			return make_DECIMAL (yytext, loc);
";"					return yy::parser::make_ENDL  (loc);
"SHOW"|"show"	    return yy::parser::make_SHOW(loc);
"SELECT"|"select"	return yy::parser::make_SELECT(loc);
"INSERT"|"insert"	return yy::parser::make_INSERT(loc);
"DELETE"|"delete"	return yy::parser::make_DELETE(loc);
"INTO"|"into"		return yy::parser::make_INTO(loc);
"INDEX"|"index"		return yy::parser::make_INDEX(loc);
"ON"|"on"	    	return yy::parser::make_ON(loc);
"UNIQUE"|"unique"	return yy::parser::make_UNIQUE(loc);
"VALUES"|"values"	return yy::parser::make_VALUES(loc);
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
"="					return yy::parser::make_EQUAL (loc);
"<"					return yy::parser::make_LESS  (loc);
">"					return yy::parser::make_LARGE (loc);
"<>"				return yy::parser::make_NOT   (loc);
"and"				return yy::parser::make_AND   (loc);
"or"				return yy::parser::make_OR    (loc);
{filename}			return yy::parser::make_FILENAME(std::string(yytext), loc);
{string}			return yy::parser::make_STRING(std::string(yytext), loc);
.					/*std::cout << loc << ": invalid character: " + std::string(yytext) << std::endl*/;
<<EOF>>				return yy::parser::make_END (loc);
%%

yy::parser::symbol_type
make_NUMBER (const std::string &s, const yy::parser::location_type& loc)
{
	std::istringstream i(s);
    int x;
    if (!(i >> x))
       return yy::parser::make_NUMBER ((int) 0, loc);
    return yy::parser::make_NUMBER ((int) x, loc);
}

yy::parser::symbol_type
make_DECIMAL (const std::string &s, const yy::parser::location_type& loc)
{
	std::istringstream i(s);
    double x;
    if (!(i >> x))
       return yy::parser::make_DECIMAL ((int) 0, loc);
    return yy::parser::make_DECIMAL ((int) x, loc);
}

void
Compiler::scan_begin (FILE * fp)
{
  yy_flex_debug = trace_scanning;
  yyin = fp;
}

void
Compiler::scan_end ()
{
  fclose (yyin);
}