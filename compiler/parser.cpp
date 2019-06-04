// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hpp"


// Unqualified %code blocks.
#line 23 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"

# include "compiler.hpp"
# include "compilertools/compilertools.hpp"

#line 50 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 144 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Compiler& drv_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 64: // select_condition_exp
      case 66: // exp
      case 69: // attribute_exp
      case 72: // constrain_exp
        value.YY_MOVE_OR_COPY< Expression * > (YY_MOVE (that.value));
        break;

      case 52: // attr_list
      case 53: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        value.YY_MOVE_OR_COPY< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 47: // statement
      case 48: // show_statement
      case 49: // create_index_statement
      case 50: // drop_index_statement
      case 51: // insert_statement
      case 54: // drop_table_statement
      case 55: // drop_db_statement
      case 56: // use_statement
      case 57: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        value.YY_MOVE_OR_COPY< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 70: // variant_type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 43: // STRING
      case 44: // FILENAME
      case 58: // source_statement
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 64: // select_condition_exp
      case 66: // exp
      case 69: // attribute_exp
      case 72: // constrain_exp
        value.move< Expression * > (YY_MOVE (that.value));
        break;

      case 52: // attr_list
      case 53: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        value.move< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 47: // statement
      case 48: // show_statement
      case 49: // create_index_statement
      case 50: // drop_index_statement
      case 51: // insert_statement
      case 54: // drop_table_statement
      case 55: // drop_db_statement
      case 56: // use_statement
      case 57: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        value.move< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 70: // variant_type
        value.move< int > (YY_MOVE (that.value));
        break;

      case 43: // STRING
      case 44: // FILENAME
      case 58: // source_statement
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 64: // select_condition_exp
      case 66: // exp
      case 69: // attribute_exp
      case 72: // constrain_exp
        value.move< Expression * > (that.value);
        break;

      case 52: // attr_list
      case 53: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        value.move< ExpressionList * > (that.value);
        break;

      case 47: // statement
      case 48: // show_statement
      case 49: // create_index_statement
      case 50: // drop_index_statement
      case 51: // insert_statement
      case 54: // drop_table_statement
      case 55: // drop_db_statement
      case 56: // use_statement
      case 57: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        value.move< Statement * > (that.value);
        break;

      case 3: // NUMBER
      case 70: // variant_type
        value.move< int > (that.value);
        break;

      case 43: // STRING
      case 44: // FILENAME
      case 58: // source_statement
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 3: // NUMBER
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < int > (); }
#line 457 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 43: // STRING
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 463 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 44: // FILENAME
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 469 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 47: // statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 475 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 48: // show_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 481 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 49: // create_index_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 487 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 50: // drop_index_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 493 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 51: // insert_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 499 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 52: // attr_list
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 505 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 53: // value_list
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 511 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 54: // drop_table_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 517 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 55: // drop_db_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 523 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 56: // use_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 529 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 57: // create_db_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 535 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 58: // source_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 541 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 59: // select_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 547 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 60: // select_list
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 553 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 61: // table_list
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 559 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 62: // select_condition
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 565 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 63: // select_condition_list
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 571 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 64: // select_condition_exp
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 577 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 65: // delete_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 583 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 66: // exp
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 589 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 67: // create_table_statement
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 595 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 68: // attribute_list
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 601 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 69: // attribute_exp
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 607 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 70: // variant_type
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < int > (); }
#line 613 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 71: // constrain_list
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 619 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 72: // constrain_exp
#line 65 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 625 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 64: // select_condition_exp
      case 66: // exp
      case 69: // attribute_exp
      case 72: // constrain_exp
        yylhs.value.emplace< Expression * > ();
        break;

      case 52: // attr_list
      case 53: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        yylhs.value.emplace< ExpressionList * > ();
        break;

      case 47: // statement
      case 48: // show_statement
      case 49: // create_index_statement
      case 50: // drop_index_statement
      case 51: // insert_statement
      case 54: // drop_table_statement
      case 55: // drop_db_statement
      case 56: // use_statement
      case 57: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        yylhs.value.emplace< Statement * > ();
        break;

      case 3: // NUMBER
      case 70: // variant_type
        yylhs.value.emplace< int > ();
        break;

      case 43: // STRING
      case 44: // FILENAME
      case 58: // source_statement
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 70 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 909 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 3:
#line 71 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 915 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 4:
#line 75 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 921 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 5:
#line 76 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 927 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 6:
#line 77 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 933 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 7:
#line 78 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; Compiler::file = yystack_[1].value.as < std::string > (); return 0; }
#line 939 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 8:
#line 79 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 945 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 9:
#line 80 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 951 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 10:
#line 81 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Quit_Statement; drv.execute_statement(yylhs.value.as < Statement * > ()); return -1; }
#line 957 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 11:
#line 82 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 963 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 12:
#line 83 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 969 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 13:
#line 84 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 975 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 14:
#line 85 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 981 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 15:
#line 86 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 987 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 16:
#line 87 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 993 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 17:
#line 88 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 999 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 18:
#line 89 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 1005 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 19:
#line 93 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Show_Statement(0); }
#line 1011 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 20:
#line 94 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Show_Statement(1); }
#line 1017 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 21:
#line 98 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Create_Index_Statement(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1025 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 22:
#line 104 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Drop_Index_Statement(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1033 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 23:
#line 110 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		yylhs.value.as < Statement * > () = new Insert_Statement(yystack_[7].value.as < std::string > (), yystack_[5].value.as < ExpressionList * > (), yystack_[1].value.as < ExpressionList * > ());
	}
#line 1041 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 24:
#line 116 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1047 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 25:
#line 117 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1053 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 26:
#line 121 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1059 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 27:
#line 122 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1065 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 28:
#line 126 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Table_Statement(yystack_[0].value.as < std::string > ()); }
#line 1071 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 29:
#line 130 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 1077 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 30:
#line 134 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Use_Statement(yystack_[0].value.as < std::string > ()); }
#line 1083 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 31:
#line 138 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Create_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 1089 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 32:
#line 142 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1095 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 33:
#line 146 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Select_Statement * select = new Select_Statement;
		select->set_select(yystack_[3].value.as < ExpressionList * > ());
		select->set_table(yystack_[1].value.as < ExpressionList * > ());
		select->set_condition(yystack_[0].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = select;
	}
#line 1107 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 34:
#line 156 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression("*")); }
#line 1113 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 35:
#line 157 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1119 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 36:
#line 158 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1125 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 37:
#line 162 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1131 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 38:
#line 163 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1137 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 39:
#line 167 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1143 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 40:
#line 168 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[0].value.as < ExpressionList * > (); }
#line 1149 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 41:
#line 172 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1155 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 42:
#line 173 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1161 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 43:
#line 177 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), EQUAL, yystack_[0].value.as < Expression * > ()->values()); }
#line 1167 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 44:
#line 178 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), LESS, yystack_[0].value.as < Expression * > ()->values()); }
#line 1173 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 45:
#line 179 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), LARGE, yystack_[0].value.as < Expression * > ()->values()); }
#line 1179 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 46:
#line 180 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), NOT, yystack_[0].value.as < Expression * > ()->values()); }
#line 1185 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 47:
#line 184 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Delete_Statement(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionList * > ());
    }
#line 1193 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 48:
#line 190 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(std::string(yystack_[0].value.as < std::string > ())); }
#line 1199 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 49:
#line 191 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(yystack_[0].value.as < int > ()); }
#line 1205 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 50:
#line 196 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Create_Table_Statement * create = new Create_Table_Statement(yystack_[4].value.as < std::string > ());
		create->set_attribute(yystack_[2].value.as < ExpressionList * > ());
		create->set_constrain(yystack_[1].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = create;
	}
#line 1216 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 51:
#line 205 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1222 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 52:
#line 206 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1228 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 53:
#line 210 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > (), 0); }
#line 1234 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 54:
#line 211 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[2].value.as < std::string > (), yystack_[1].value.as < int > (), 1); }
#line 1240 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 55:
#line 215 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -1; }
#line 1246 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 56:
#line 216 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -2; }
#line 1252 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 57:
#line 217 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 1258 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 58:
#line 221 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1264 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 59:
#line 222 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1270 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 60:
#line 223 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1276 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 61:
#line 227 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(0, yystack_[1].value.as < std::string > ()); }
#line 1282 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 62:
#line 228 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(1, yystack_[1].value.as < std::string > ()); }
#line 1288 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;


#line 1292 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -97;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      43,   -22,   -17,   -35,    -2,    -6,     1,    26,    40,     2,
     -97,   -97,    25,   -97,    29,    31,    34,    35,    41,    48,
      49,    50,    51,    52,    53,    54,   -97,   -97,    -1,   -97,
     -97,    36,    37,    61,   -97,    39,    42,    44,    45,    46,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,    47,    55,    57,   -97,
      56,   -97,   -97,    58,    62,    77,   -97,     0,   -97,    59,
      60,   -97,    63,    64,    64,    65,   -97,   -10,    66,   -97,
     -97,   -97,   -16,    33,    70,   -97,    70,   -97,   -97,   -97,
      67,    73,    20,   -13,    68,    69,    -3,    -3,    -3,    -3,
      64,    90,   -97,    71,    75,   -97,   -97,   -97,   -14,    76,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    80,    72,
      74,   -97,    -3,   -97,    81,    83,    13,   -97,   -97,   -97,
     -97,    -3,   -97
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,    10,
      32,     0,     0,     0,    30,     0,     0,     0,     0,     0,
      19,    20,     1,     3,    18,    16,    17,    14,     9,    13,
      11,    12,     7,     6,    15,     8,     0,     0,     0,    31,
       0,    28,    29,     0,     0,     0,    37,    39,    36,     0,
       0,    22,     0,     0,     0,     0,    33,     0,    58,    51,
      21,    24,     0,     0,    47,    41,    40,    38,    55,    56,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    52,    59,    50,     0,     0,
      25,    49,    48,    43,    44,    45,    46,    42,     0,     0,
       0,    60,     0,    57,     0,     0,     0,    26,    61,    62,
      23,     0,    27
  };

  const signed char
  parser::yypgoto_[] =
  {
     -97,   -97,    82,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    21,    14,
     -97,   -96,   -97,   -97,    24,   -97,   -97,    10
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,    82,   126,    18,
      19,    20,    21,    22,    23,    28,    67,    76,    84,    85,
      24,   113,    25,    78,    79,    91,    93,   106
  };

  const unsigned char
  parser::yytable_[] =
  {
     111,   114,   115,   116,    56,    26,    74,    29,    31,    30,
      32,    35,    40,    36,    94,    95,    33,   107,   108,    37,
      41,    27,    88,    89,    90,    42,   127,   103,   104,     1,
      57,    75,     2,     3,     4,   132,     5,    34,     6,     7,
     112,    38,     8,   130,   131,    39,     9,     1,    10,    11,
       2,     3,     4,    44,     5,    45,     6,     7,    46,    47,
       8,   103,   104,    77,     9,    48,    10,    11,    96,    97,
      98,    99,    49,    50,    51,    52,    53,    54,    55,    58,
      59,    60,    61,    73,   109,    62,    69,    63,    64,    65,
      66,    72,   102,   118,    43,    86,   101,    92,    68,    70,
     119,    71,    77,    80,   120,   122,    81,    83,    87,   100,
     123,   128,   110,   129,   117,   124,   105,   125,   121
  };

  const unsigned char
  parser::yycheck_[] =
  {
       3,    97,    98,    99,     5,    27,     6,    24,    10,    44,
      12,    10,    10,    12,    30,    31,    18,    30,    31,    18,
      18,    43,    32,    33,    34,     0,   122,    41,    42,     4,
      31,    31,     7,     8,     9,   131,    11,    43,    13,    14,
      43,    15,    17,    30,    31,     5,    21,     4,    23,    24,
       7,     8,     9,    24,    11,    24,    13,    14,    24,    24,
      17,    41,    42,    43,    21,    24,    23,    24,    35,    36,
      37,    38,    24,    24,    24,    24,    24,    24,    24,    43,
      43,    20,    43,     6,    16,    43,    29,    43,    43,    43,
      43,    29,    19,     3,    12,    74,    29,    31,    43,    43,
      29,    43,    43,    43,    29,    29,    43,    43,    43,    39,
      30,    30,    43,    30,   100,    43,    92,    43,   108
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     7,     8,     9,    11,    13,    14,    17,    21,
      23,    24,    46,    47,    48,    49,    50,    51,    54,    55,
      56,    57,    58,    59,    65,    67,    27,    43,    60,    24,
      44,    10,    12,    18,    43,    10,    12,    18,    15,     5,
      10,    18,     0,    47,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,     5,    31,    43,    43,
      20,    43,    43,    43,    43,    43,    43,    61,    43,    29,
      43,    43,    29,     6,     6,    31,    62,    43,    68,    69,
      43,    43,    52,    43,    63,    64,    63,    43,    32,    33,
      34,    70,    31,    71,    30,    31,    35,    36,    37,    38,
      39,    29,    19,    41,    42,    69,    72,    30,    31,    16,
      43,     3,    43,    66,    66,    66,    66,    64,     3,    29,
      29,    72,    29,    30,    43,    43,    53,    66,    30,    30,
      30,    31,    66
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      48,    49,    50,    51,    52,    52,    53,    53,    54,    55,
      56,    57,    58,    59,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    65,    66,    66,
      67,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      71,    72,    72
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     4,    10,     1,     3,     1,     3,     3,     3,
       2,     3,     2,     5,     1,     1,     3,     1,     3,     0,
       2,     1,     3,     3,     3,     3,     3,     5,     1,     1,
       7,     1,     3,     2,     3,     1,     1,     4,     0,     2,
       3,     4,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMBER", "SELECT", "FROM", "WHERE",
  "QUIT", "SOURCE", "CREATE", "TABLE", "USE", "DATABASE", "DROP", "INSERT",
  "INTO", "VALUES", "DELETE", "INDEX", "UNIQUE", "ON", "SHOW", "BLANK",
  "\"eof\"", "\";\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"(\"", "\")\"",
  "\",\"", "\"int\"", "\"double\"", "\"char\"", "\"=\"", "\"<\"", "\">\"",
  "\"<>\"", "\"and\"", "\"or\"", "\"primary key\"", "\"foreign key\"",
  "STRING", "FILENAME", "$accept", "statement_list", "statement",
  "show_statement", "create_index_statement", "drop_index_statement",
  "insert_statement", "attr_list", "value_list", "drop_table_statement",
  "drop_db_statement", "use_statement", "create_db_statement",
  "source_statement", "select_statement", "select_list", "table_list",
  "select_condition", "select_condition_list", "select_condition_exp",
  "delete_statement", "exp", "create_table_statement", "attribute_list",
  "attribute_exp", "variant_type", "constrain_list", "constrain_exp", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    70,    70,    71,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    93,
      94,    98,   104,   110,   116,   117,   121,   122,   126,   130,
     134,   138,   142,   146,   156,   157,   158,   162,   163,   167,
     168,   172,   173,   177,   178,   179,   180,   184,   190,   191,
     195,   205,   206,   210,   211,   215,   216,   217,   221,   222,
     223,   227,   228
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1765 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

#line 231 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}
