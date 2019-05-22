%language "c++" /* -*- C++ -*- */
%require "3.3.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include "compilertools/compilertools.hpp"
  #include <string>
  class Compiler;
}

// The parsing context.
%param { Compiler& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
# include "compiler.hpp"
# include "compilertools/compilertools.hpp"
}

%define api.token.prefix {TOK_}

%token <int> NUMBER;
%token SELECT FROM WHERE QUIT SOURCE CREATE TABLE
%token
	BLANK
	END			"eof"
	ENDL		";"
	MINUS		"-"
	PLUS	 	"+"
	STAR	 	"*"
	SLASH	 	"/"
	LPAREN		"("
	RPAREN		")"
	COMMA	 	","
	INT			"int"
	DOUBLE		"double"
	CHAR		"char"
	PRIMARY_KEY	"primary key"
	FOREIGN_KEY	"foreign key"
;
%token <std::string> STRING FILENAME

%type <int> variant_type
%type <std::string> source_statement
%type <Expression *> exp attribute_exp constrain_exp
%type <ExpressionList *> select_list table_list select_condition attribute_list constrain_list
%type <Statement *> statement select_statement create_table_statement

%printer { yyo << $$; } <*>;

%%

statement_list:
	statement { drv.execute_statement($1); }
	| statement_list statement { drv.execute_statement($2); }
	;

statement:
	END { $$ = nullptr; }
	| ENDL { $$ = nullptr; }
	| select_statement ENDL { $$ = $1; }
	| source_statement ENDL { $$ = nullptr; Compiler::file = $1; return 0; }
	| create_table_statement ENDL { $$ = $1; }
	| QUIT ENDL { std::cout << "Bye" << std::endl; return -1; }
	;

source_statement:
	SOURCE FILENAME { $$ = $2; }
	;

select_statement:
	SELECT select_list FROM table_list select_condition {
		Select_Statement * select = new Select_Statement;
		select->set_select($2);
		select->set_table($4);
		select->set_condition($5);
		$$ = select;
	}
	;

select_list:
	exp { $$ = new ExpressionList; $$->push_back($1); }
	| select_list ',' exp { $$->push_back($3); }
	;

table_list:
	exp { $$ = new ExpressionList; $$->push_back($1); }
	| table_list ',' exp { $$->push_back($3); }
	;

select_condition:
	%empty { $$ = nullptr; }
	| WHERE exp { $$ = new ExpressionList; $$->push_back($2); }
	;

exp:
	STRING { $$ = new String_Expression($1); }
	;

create_table_statement:
	CREATE TABLE STRING
	"(" attribute_list "," constrain_list ")" {
		Create_Table_Statement * create = new Create_Table_Statement($3);
		create->set_attribute($5);
		create->set_constrain($7);
		$$ = create;
	}
	;

attribute_list:
	attribute_exp { $$ = new ExpressionList(); $$->push_back($1); }
	| attribute_list "," attribute_exp { $1->push_back($3); $$ = $1; }
	;

attribute_exp:
	STRING variant_type { $$ = new Attribute_Expression($1, $2); }
	;

variant_type:
	"int" { $$ = -1; }
	| "double" { $$ = -2; }
	| "char" "(" NUMBER ")" { $$ = $3; }
	;

constrain_list:
	constrain_exp { $$ = new ExpressionList(); $$->push_back($1); }
	| constrain_list "," constrain_exp { $1->push_back($3); $$ = $1; }
	;

constrain_exp:
	PRIMARY_KEY "(" STRING ")" { $$ = new Constrain_Expression(0, $3); }
	| FOREIGN_KEY "(" STRING ")" { $$ = new Constrain_Expression(1, $3); }
	;

%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}