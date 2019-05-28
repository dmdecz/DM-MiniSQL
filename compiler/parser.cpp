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
#line 23 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"

# include "compiler.hpp"
# include "compilertools/compilertools.hpp"

#line 50 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"


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
#line 144 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"


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
      case 50: // exp
      case 53: // attribute_exp
      case 56: // constrain_exp
        value.YY_MOVE_OR_COPY< Expression * > (YY_MOVE (that.value));
        break;

      case 39: // attr_list
      case 40: // value_list
      case 47: // select_list
      case 48: // table_list
      case 49: // select_condition
      case 52: // attribute_list
      case 55: // constrain_list
        value.YY_MOVE_OR_COPY< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 37: // statement
      case 38: // insert_statement
      case 41: // drop_table_statement
      case 42: // drop_db_statement
      case 43: // use_statement
      case 44: // create_db_statement
      case 46: // select_statement
      case 51: // create_table_statement
        value.YY_MOVE_OR_COPY< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 54: // variant_type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 32: // STRING
      case 33: // FILENAME
      case 45: // source_statement
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
      case 50: // exp
      case 53: // attribute_exp
      case 56: // constrain_exp
        value.move< Expression * > (YY_MOVE (that.value));
        break;

      case 39: // attr_list
      case 40: // value_list
      case 47: // select_list
      case 48: // table_list
      case 49: // select_condition
      case 52: // attribute_list
      case 55: // constrain_list
        value.move< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 37: // statement
      case 38: // insert_statement
      case 41: // drop_table_statement
      case 42: // drop_db_statement
      case 43: // use_statement
      case 44: // create_db_statement
      case 46: // select_statement
      case 51: // create_table_statement
        value.move< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 54: // variant_type
        value.move< int > (YY_MOVE (that.value));
        break;

      case 32: // STRING
      case 33: // FILENAME
      case 45: // source_statement
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
      case 50: // exp
      case 53: // attribute_exp
      case 56: // constrain_exp
        value.move< Expression * > (that.value);
        break;

      case 39: // attr_list
      case 40: // value_list
      case 47: // select_list
      case 48: // table_list
      case 49: // select_condition
      case 52: // attribute_list
      case 55: // constrain_list
        value.move< ExpressionList * > (that.value);
        break;

      case 37: // statement
      case 38: // insert_statement
      case 41: // drop_table_statement
      case 42: // drop_db_statement
      case 43: // use_statement
      case 44: // create_db_statement
      case 46: // select_statement
      case 51: // create_table_statement
        value.move< Statement * > (that.value);
        break;

      case 3: // NUMBER
      case 54: // variant_type
        value.move< int > (that.value);
        break;

      case 32: // STRING
      case 33: // FILENAME
      case 45: // source_statement
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
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < int > (); }
#line 439 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 32: // STRING
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 445 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 33: // FILENAME
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 451 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 37: // statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 457 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 38: // insert_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 463 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 39: // attr_list
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 469 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 40: // value_list
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 475 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 41: // drop_table_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 481 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 42: // drop_db_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 487 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 43: // use_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 493 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 44: // create_db_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 499 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 45: // source_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 505 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 46: // select_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 511 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 47: // select_list
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 517 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 48: // table_list
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 523 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 49: // select_condition
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 529 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 50: // exp
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 535 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 51: // create_table_statement
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 541 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 52: // attribute_list
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 547 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 53: // attribute_exp
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 553 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 54: // variant_type
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < int > (); }
#line 559 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 55: // constrain_list
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 565 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
        break;

      case 56: // constrain_exp
#line 58 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 571 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
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
      case 50: // exp
      case 53: // attribute_exp
      case 56: // constrain_exp
        yylhs.value.emplace< Expression * > ();
        break;

      case 39: // attr_list
      case 40: // value_list
      case 47: // select_list
      case 48: // table_list
      case 49: // select_condition
      case 52: // attribute_list
      case 55: // constrain_list
        yylhs.value.emplace< ExpressionList * > ();
        break;

      case 37: // statement
      case 38: // insert_statement
      case 41: // drop_table_statement
      case 42: // drop_db_statement
      case 43: // use_statement
      case 44: // create_db_statement
      case 46: // select_statement
      case 51: // create_table_statement
        yylhs.value.emplace< Statement * > ();
        break;

      case 3: // NUMBER
      case 54: // variant_type
        yylhs.value.emplace< int > ();
        break;

      case 32: // STRING
      case 33: // FILENAME
      case 45: // source_statement
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
#line 63 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 849 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 3:
#line 64 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 855 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 4:
#line 68 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 861 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 5:
#line 69 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 867 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 6:
#line 70 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 873 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 7:
#line 71 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; Compiler::file = yystack_[1].value.as < std::string > (); return 0; }
#line 879 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 8:
#line 72 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 885 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 9:
#line 73 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 891 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 10:
#line 74 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; drv.execute_statement(yylhs.value.as < Statement * > ()); return -1; }
#line 897 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 11:
#line 75 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 903 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 12:
#line 76 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 909 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 13:
#line 77 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 915 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 14:
#line 78 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 921 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 15:
#line 82 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    {
		yylhs.value.as < Statement * > () = new Insert_Statement(yystack_[7].value.as < std::string > (), yystack_[5].value.as < ExpressionList * > (), yystack_[1].value.as < ExpressionList * > ());
	}
#line 929 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 16:
#line 88 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 935 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 17:
#line 89 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 941 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 18:
#line 93 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 947 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 19:
#line 94 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 953 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 20:
#line 98 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Table_Statement(yystack_[0].value.as < std::string > ()); }
#line 959 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 21:
#line 102 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 965 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 22:
#line 106 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Use_Statement(yystack_[0].value.as < std::string > ()); }
#line 971 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 23:
#line 110 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Create_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 977 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 24:
#line 114 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 983 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 25:
#line 118 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    {
		Select_Statement * select = new Select_Statement;
		select->set_select(yystack_[3].value.as < ExpressionList * > ());
		select->set_table(yystack_[1].value.as < ExpressionList * > ());
		select->set_condition(yystack_[0].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = select;
	}
#line 995 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 26:
#line 128 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1001 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 27:
#line 129 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1007 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 28:
#line 133 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1013 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 29:
#line 134 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1019 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 30:
#line 138 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1025 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 31:
#line 139 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1031 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 32:
#line 143 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new String_Expression(yystack_[0].value.as < std::string > ()); }
#line 1037 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 33:
#line 144 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(yystack_[0].value.as < int > ()); }
#line 1043 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 34:
#line 149 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    {
		Create_Table_Statement * create = new Create_Table_Statement(yystack_[4].value.as < std::string > ());
		create->set_attribute(yystack_[2].value.as < ExpressionList * > ());
		create->set_constrain(yystack_[1].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = create;
	}
#line 1054 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 35:
#line 158 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1060 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 36:
#line 159 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1066 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 37:
#line 163 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > ()); }
#line 1072 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 38:
#line 167 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -1; }
#line 1078 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 39:
#line 168 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -2; }
#line 1084 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 40:
#line 169 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 1090 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 41:
#line 173 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1096 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 42:
#line 174 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1102 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 43:
#line 175 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1108 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 44:
#line 179 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(0, yystack_[1].value.as < std::string > ()); }
#line 1114 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;

  case 45:
#line 180 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(1, yystack_[1].value.as < std::string > ()); }
#line 1120 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"
    break;


#line 1124 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -43;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      31,    -1,    14,   -16,    17,   -13,    18,    26,   -43,   -43,
       7,   -43,    29,    32,    36,    37,    38,    39,    40,    41,
     -43,   -43,    -2,   -43,   -43,   -43,    30,    33,   -43,    34,
      35,    42,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,    -1,    -1,    44,   -43,   -43,   -43,    45,     0,
     -43,   -43,    43,    46,    -1,    -1,   -43,   -19,    47,   -43,
     -43,   -21,   -43,   -43,   -43,   -43,    48,   -43,    -8,    11,
      54,    49,    58,    52,    53,   -43,   -43,   -43,    16,    55,
     -43,    57,    51,    56,   -43,    -1,   -43,    59,    60,    28,
     -43,   -43,   -43,   -43,    -1,   -43
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    32,     0,    26,    10,    24,     0,     0,    22,     0,
       0,     0,     1,     3,    14,     9,    13,    11,    12,     7,
       6,     8,     0,     0,     0,    23,    20,    21,     0,    30,
      28,    27,     0,     0,     0,     0,    25,     0,    41,    35,
      16,     0,    31,    29,    38,    39,     0,    37,     0,     0,
       0,     0,     0,     0,     0,    36,    42,    34,     0,     0,
      17,     0,     0,     0,    43,     0,    40,     0,     0,     0,
      18,    44,    45,    15,     0,    19
  };

  const signed char
  parser::yypgoto_[] =
  {
     -43,   -43,    61,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -42,   -43,   -43,    -5,   -43,
     -43,   -14
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    10,    11,    12,    61,    89,    13,    14,    15,    16,
      17,    18,    22,    49,    56,    23,    19,    58,    59,    67,
      69,    76
  };

  const unsigned char
  parser::yytable_[] =
  {
      50,    51,    20,    42,    70,    71,    54,    32,    64,    65,
      66,     1,    62,    63,     2,     3,     4,    25,     5,    28,
       6,     7,    73,    74,    57,     8,     9,    26,    29,    27,
      30,    21,    43,    24,    55,     1,    77,    78,     2,     3,
       4,    31,     5,    90,     6,     7,    73,    74,    34,     8,
       9,    35,    95,    93,    94,    36,    37,    38,    39,    40,
      41,    81,    44,    75,    84,    45,    46,    47,    52,    53,
      79,    33,    72,    68,    48,    57,    82,    83,    60,    85,
       0,    80,    86,    87,    91,    92,     0,     0,    88
  };

  const signed char
  parser::yycheck_[] =
  {
      42,    43,     3,     5,    25,    26,     6,     0,    27,    28,
      29,     4,    54,    55,     7,     8,     9,    33,    11,    32,
      13,    14,    30,    31,    32,    18,    19,    10,    10,    12,
      12,    32,    34,    19,    34,     4,    25,    26,     7,     8,
       9,    15,    11,    85,    13,    14,    30,    31,    19,    18,
      19,    19,    94,    25,    26,    19,    19,    19,    19,    19,
      19,     3,    32,    68,    78,    32,    32,    32,    24,    24,
      16,    10,    24,    26,    32,    32,    24,    24,    32,    24,
      -1,    32,    25,    32,    25,    25,    -1,    -1,    32
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     7,     8,     9,    11,    13,    14,    18,    19,
      36,    37,    38,    41,    42,    43,    44,    45,    46,    51,
       3,    32,    47,    50,    19,    33,    10,    12,    32,    10,
      12,    15,     0,    37,    19,    19,    19,    19,    19,    19,
      19,    19,     5,    34,    32,    32,    32,    32,    32,    48,
      50,    50,    24,    24,     6,    34,    49,    32,    52,    53,
      32,    39,    50,    50,    27,    28,    29,    54,    26,    55,
      25,    26,    24,    30,    31,    53,    56,    25,    26,    16,
      32,     3,    24,    24,    56,    24,    25,    32,    32,    40,
      50,    25,    25,    25,    26,    50
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    38,    39,    39,    40,    40,
      41,    42,    43,    44,    45,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    52,    52,    53,    54,    54,
      54,    55,    55,    55,    56,    56
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    10,     1,     3,     1,     3,
       3,     3,     2,     3,     2,     5,     1,     3,     1,     3,
       0,     2,     1,     1,     7,     1,     3,     2,     1,     1,
       4,     0,     2,     3,     4,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMBER", "SELECT", "FROM", "WHERE",
  "QUIT", "SOURCE", "CREATE", "TABLE", "USE", "DATABASE", "DROP", "INSERT",
  "INTO", "VALUES", "BLANK", "\"eof\"", "\";\"", "\"-\"", "\"+\"", "\"*\"",
  "\"/\"", "\"(\"", "\")\"", "\",\"", "\"int\"", "\"double\"", "\"char\"",
  "\"primary key\"", "\"foreign key\"", "STRING", "FILENAME", "','",
  "$accept", "statement_list", "statement", "insert_statement",
  "attr_list", "value_list", "drop_table_statement", "drop_db_statement",
  "use_statement", "create_db_statement", "source_statement",
  "select_statement", "select_list", "table_list", "select_condition",
  "exp", "create_table_statement", "attribute_list", "attribute_exp",
  "variant_type", "constrain_list", "constrain_exp", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    63,    63,    64,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    82,    88,    89,    93,    94,
      98,   102,   106,   110,   114,   118,   128,   129,   133,   134,
     138,   139,   143,   144,   148,   158,   159,   163,   167,   168,
     169,   173,   174,   175,   179,   180
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
#line 1570 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp"

#line 183 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}
