%language "c++" /* -*- C++ -*- */
%require "3.3.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include "compilertools/compilertools.hpp"
  #include "../error/error.h"

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
%token SELECT FROM WHERE QUIT SOURCE CREATE TABLE USE DATABASE DROP INSERT INTO VALUES DELETE INDEX UNIQUE ON SHOW
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
	EQUAL       "="
	LESS        "<"
	LARGE       ">"
	NOT         "<>"
	AND         "and"
	OR          "or"
	PRIMARY_KEY	"primary key"
	FOREIGN_KEY	"foreign key"
;
%token <std::string> STRING FILENAME

%type <int> variant_type

%type <Expression *> exp attribute_exp constrain_exp select_condition_exp
%type <ExpressionList *> select_list table_list select_condition attribute_list constrain_list attr_list value_list select_condition_list
%type <std::vector<Statement*>> statement_list
%type <Statement *> statement use_statement create_db_statement drop_db_statement
%type <Statement *> select_statement drop_table_statement create_table_statement insert_statement delete_statement
%type <Statement *> create_index_statement drop_index_statement show_statement

%%

statement_list:
    statement_list statement { drv.execute_statement($2); }
	| statement { drv.execute_statement($1); }
	| statement_list END { return 1; }
	;

statement:
	ENDL { $$ = nullptr; }
	| select_statement ENDL { $$ = $1; }
	| SOURCE FILENAME ENDL { $$ = new Source_Statement($2); }
	| create_table_statement ENDL { $$ = $1; }
	| drop_table_statement ENDL { $$ = $1; }
	| QUIT ENDL { $$ = new Quit_Statement; }
	| use_statement ENDL { $$ = $1; }
	| create_db_statement ENDL { $$ = $1; }
	| drop_db_statement ENDL { $$ = $1; }
	| insert_statement ENDL { $$ = $1; }
	| delete_statement ENDL { $$ = $1; }
	| create_index_statement ENDL { $$ = $1; }
	| drop_index_statement ENDL { $$ = $1; }
	| show_statement ENDL { $$ = $1; }
	;

show_statement:
    SHOW TABLE { $$ = new Show_Statement(0); }
    | SHOW INDEX { $$ = new Show_Statement(1); }
    ;

create_index_statement:
    CREATE INDEX ON STRING STRING {
        $$ = new Create_Index_Statement($4, $5);
    }
    ;

drop_index_statement:
    DROP INDEX STRING STRING {
        $$ = new Drop_Index_Statement($3, $4);
    }
    ;

insert_statement:
	INSERT INTO STRING "(" attr_list ")" VALUES "("  value_list ")" {
		$$ = new Insert_Statement($3, $5, $9);
	}
	;

attr_list:
	STRING { $$ = new ExpressionList; $$->push_back(new String_Expression($1)); }
	| attr_list "," STRING { $$ = $1; $$->push_back(new String_Expression($3)); }
	;

value_list:
	exp { $$ = new ExpressionList; $$->push_back($1); }
	| value_list "," exp { $$ = $1; $$->push_back($3); }
	;

drop_table_statement:
	DROP TABLE STRING { $$ = new Drop_Table_Statement($3); }
	;

drop_db_statement:
	DROP DATABASE STRING { $$ = new Drop_Database_Statement($3); }
	;

use_statement:
	USE STRING { $$ = new Use_Statement($2); }
	;

create_db_statement:
	CREATE DATABASE STRING { $$ = new Create_Database_Statement($3); }
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
    STAR { $$ = new ExpressionList; $$->push_back(new String_Expression("*")); }
	| STRING { $$ = new ExpressionList; $$->push_back(new String_Expression($1)); }
    | select_list "," STRING { $$ = $1; $$->push_back(new String_Expression($3)); }
    ;

table_list:
	STRING { $$ = new ExpressionList; $$->push_back(new String_Expression($1)); }
    | table_list "," STRING { $$ = $1; $$->push_back(new String_Expression($3)); }
    ;

select_condition:
	%empty { $$ = nullptr; }
	| WHERE select_condition_list { $$ = $2; }
	;

select_condition_list:
    select_condition_exp { $$ = new ExpressionList; $$->push_back($1); }
    | select_condition_list "and" select_condition_exp { $$ = $1; $$->push_back($3); }
    ;

select_condition_exp:
    STRING "=" exp { $$ = new Condition_Expression($1, EQUAL, $3->values()); }
    | STRING "<" exp { $$ = new Condition_Expression($1, LESS, $3->values()); }
    | STRING ">" exp { $$ = new Condition_Expression($1, LARGE, $3->values()); }
    | STRING "<>" exp { $$ = new Condition_Expression($1, NOT, $3->values()); }
    ;

delete_statement:
    DELETE FROM STRING WHERE select_condition_list {
        $$ = new Delete_Statement($3, $5);
    }
    ;

exp:
	STRING { $$ = new DMType_Expression(std::string($1)); }
	| NUMBER { $$ = new DMType_Expression($1); }
	;

create_table_statement:
	CREATE TABLE STRING
	"(" attribute_list constrain_list ")" {
		Create_Table_Statement * create = new Create_Table_Statement($3);
		create->set_attribute($5);
		create->set_constrain($6);
		$$ = create;
	}
	;

attribute_list:
	attribute_exp { $$ = new ExpressionList(); $$->push_back($1); }
	| attribute_list "," attribute_exp { $1->push_back($3); $$ = $1; }
	;

attribute_exp:
	STRING variant_type { $$ = new Attribute_Expression($1, $2, 0); }
	| STRING variant_type UNIQUE { $$ = new Attribute_Expression($1, $2, 1); }
	;

variant_type:
	"int" { $$ = -1; }
	| "double" { $$ = -2; }
	| "char" "(" NUMBER ")" { $$ = $3; }
	;

constrain_list:
	%empty { $$ = nullptr; }
	| "," constrain_exp { $$ = new ExpressionList(); $$->push_back($2); }
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
    throw Error(0, "Syntax Error: " + m);
}


