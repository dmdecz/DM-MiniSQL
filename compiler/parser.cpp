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
      case 56: // select_condition_exp
      case 57: // exp
      case 60: // attribute_exp
      case 63: // constrain_exp
        value.YY_MOVE_OR_COPY< Expression * > (YY_MOVE (that.value));
        break;

      case 44: // attr_list
      case 45: // value_list
      case 52: // select_list
      case 53: // table_list
      case 54: // select_condition
      case 55: // select_condition_list
      case 59: // attribute_list
      case 62: // constrain_list
        value.YY_MOVE_OR_COPY< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 42: // statement
      case 43: // insert_statement
      case 46: // drop_table_statement
      case 47: // drop_db_statement
      case 48: // use_statement
      case 49: // create_db_statement
      case 51: // select_statement
      case 58: // create_table_statement
        value.YY_MOVE_OR_COPY< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 61: // variant_type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 38: // STRING
      case 39: // FILENAME
      case 50: // source_statement
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
      case 56: // select_condition_exp
      case 57: // exp
      case 60: // attribute_exp
      case 63: // constrain_exp
        value.move< Expression * > (YY_MOVE (that.value));
        break;

      case 44: // attr_list
      case 45: // value_list
      case 52: // select_list
      case 53: // table_list
      case 54: // select_condition
      case 55: // select_condition_list
      case 59: // attribute_list
      case 62: // constrain_list
        value.move< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 42: // statement
      case 43: // insert_statement
      case 46: // drop_table_statement
      case 47: // drop_db_statement
      case 48: // use_statement
      case 49: // create_db_statement
      case 51: // select_statement
      case 58: // create_table_statement
        value.move< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 61: // variant_type
        value.move< int > (YY_MOVE (that.value));
        break;

      case 38: // STRING
      case 39: // FILENAME
      case 50: // source_statement
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
      case 56: // select_condition_exp
      case 57: // exp
      case 60: // attribute_exp
      case 63: // constrain_exp
        value.move< Expression * > (that.value);
        break;

      case 44: // attr_list
      case 45: // value_list
      case 52: // select_list
      case 53: // table_list
      case 54: // select_condition
      case 55: // select_condition_list
      case 59: // attribute_list
      case 62: // constrain_list
        value.move< ExpressionList * > (that.value);
        break;

      case 42: // statement
      case 43: // insert_statement
      case 46: // drop_table_statement
      case 47: // drop_db_statement
      case 48: // use_statement
      case 49: // create_db_statement
      case 51: // select_statement
      case 58: // create_table_statement
        value.move< Statement * > (that.value);
        break;

      case 3: // NUMBER
      case 61: // variant_type
        value.move< int > (that.value);
        break;

      case 38: // STRING
      case 39: // FILENAME
      case 50: // source_statement
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
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < int > (); }
#line 445 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 38: // STRING
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 451 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 39: // FILENAME
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 457 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 42: // statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 463 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 43: // insert_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 469 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 44: // attr_list
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 475 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 45: // value_list
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 481 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 46: // drop_table_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 487 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 47: // drop_db_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 493 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 48: // use_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 499 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 49: // create_db_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 505 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 50: // source_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 511 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 51: // select_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 517 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 52: // select_list
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 523 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 53: // table_list
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 529 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 54: // select_condition
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 535 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 55: // select_condition_list
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 541 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 56: // select_condition_exp
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 547 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 57: // exp
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 553 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 58: // create_table_statement
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Statement * > (); }
#line 559 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 59: // attribute_list
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 565 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 60: // attribute_exp
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 571 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 61: // variant_type
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < int > (); }
#line 577 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 62: // constrain_list
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 583 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
        break;

      case 63: // constrain_exp
#line 64 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
        { yyo << yysym.value.template as < Expression * > (); }
#line 589 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
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
      case 56: // select_condition_exp
      case 57: // exp
      case 60: // attribute_exp
      case 63: // constrain_exp
        yylhs.value.emplace< Expression * > ();
        break;

      case 44: // attr_list
      case 45: // value_list
      case 52: // select_list
      case 53: // table_list
      case 54: // select_condition
      case 55: // select_condition_list
      case 59: // attribute_list
      case 62: // constrain_list
        yylhs.value.emplace< ExpressionList * > ();
        break;

      case 42: // statement
      case 43: // insert_statement
      case 46: // drop_table_statement
      case 47: // drop_db_statement
      case 48: // use_statement
      case 49: // create_db_statement
      case 51: // select_statement
      case 58: // create_table_statement
        yylhs.value.emplace< Statement * > ();
        break;

      case 3: // NUMBER
      case 61: // variant_type
        yylhs.value.emplace< int > ();
        break;

      case 38: // STRING
      case 39: // FILENAME
      case 50: // source_statement
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
#line 69 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 869 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 3:
#line 70 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 875 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 4:
#line 74 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 881 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 5:
#line 75 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 887 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 6:
#line 76 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 893 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 7:
#line 77 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; Compiler::file = yystack_[1].value.as < std::string > (); return 0; }
#line 899 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 8:
#line 78 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 905 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 9:
#line 79 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 911 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 10:
#line 80 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Quit_Statement; drv.execute_statement(yylhs.value.as < Statement * > ()); return -1; }
#line 917 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 11:
#line 81 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 923 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 12:
#line 82 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 929 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 13:
#line 83 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 935 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 14:
#line 84 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 941 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 15:
#line 88 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		yylhs.value.as < Statement * > () = new Insert_Statement(yystack_[7].value.as < std::string > (), yystack_[5].value.as < ExpressionList * > (), yystack_[1].value.as < ExpressionList * > ());
	}
#line 949 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 16:
#line 94 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 955 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 17:
#line 95 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 961 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 18:
#line 99 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 967 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 19:
#line 100 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 973 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 20:
#line 104 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Table_Statement(yystack_[0].value.as < std::string > ()); }
#line 979 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 21:
#line 108 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 985 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 22:
#line 112 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Use_Statement(yystack_[0].value.as < std::string > ()); }
#line 991 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 23:
#line 116 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Create_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 997 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 24:
#line 120 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1003 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 25:
#line 124 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Select_Statement * select = new Select_Statement;
		select->set_select(yystack_[3].value.as < ExpressionList * > ());
		select->set_table(yystack_[1].value.as < ExpressionList * > ());
		select->set_condition(yystack_[0].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = select;
	}
#line 1015 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 26:
#line 134 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression("*")); }
#line 1021 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 27:
#line 135 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1027 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 28:
#line 136 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1033 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 29:
#line 140 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1039 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 30:
#line 141 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 1045 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 31:
#line 145 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1051 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 32:
#line 146 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[0].value.as < ExpressionList * > (); }
#line 1057 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 33:
#line 150 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1063 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 34:
#line 151 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1069 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 35:
#line 155 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), 0, yystack_[0].value.as < Expression * > ()->values()); }
#line 1075 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 36:
#line 156 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), 1, yystack_[0].value.as < Expression * > ()->values()); }
#line 1081 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 37:
#line 157 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), 2, yystack_[0].value.as < Expression * > ()->values()); }
#line 1087 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 38:
#line 158 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), 3, yystack_[0].value.as < Expression * > ()->values()); }
#line 1093 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 39:
#line 162 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(std::string(yystack_[0].value.as < std::string > ())); }
#line 1099 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 40:
#line 163 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(yystack_[0].value.as < int > ()); }
#line 1105 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 41:
#line 168 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Create_Table_Statement * create = new Create_Table_Statement(yystack_[4].value.as < std::string > ());
		create->set_attribute(yystack_[2].value.as < ExpressionList * > ());
		create->set_constrain(yystack_[1].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = create;
	}
#line 1116 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 42:
#line 177 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1122 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 43:
#line 178 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1128 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 44:
#line 182 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > ()); }
#line 1134 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 45:
#line 186 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -1; }
#line 1140 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 46:
#line 187 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -2; }
#line 1146 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 47:
#line 188 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 1152 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 48:
#line 192 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1158 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 49:
#line 193 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1164 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 50:
#line 194 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1170 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 51:
#line 198 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(0, yystack_[1].value.as < std::string > ()); }
#line 1176 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 52:
#line 199 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(1, yystack_[1].value.as < std::string > ()); }
#line 1182 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;


#line 1186 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -74;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      29,    -8,    -4,   -20,    34,   -17,    43,    14,   -74,   -74,
       9,   -74,    20,    26,    44,    45,    46,    47,    48,    49,
     -74,   -74,     0,   -74,   -74,     3,    16,   -74,    24,    32,
      33,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,    36,    37,    52,   -74,   -74,   -74,    53,   -74,    -2,
     -74,    40,    41,    42,    50,   -74,   -21,    55,   -74,   -74,
       6,    19,    38,   -74,   -74,   -74,   -74,    58,   -74,   -26,
      31,    57,    51,    -3,    -3,    -3,    -3,    42,    66,    59,
      60,   -74,   -74,   -74,    22,    61,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,    62,    54,    56,   -74,    -3,   -74,
      65,    68,    35,   -74,   -74,   -74,   -74,    -3,   -74
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,     0,    10,    24,     0,     0,    22,     0,     0,
       0,     1,     3,    14,     9,    13,    11,    12,     7,     6,
       8,     0,     0,     0,    23,    20,    21,     0,    29,    31,
      28,     0,     0,     0,     0,    25,     0,    48,    42,    16,
       0,     0,    32,    33,    30,    45,    46,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    49,    41,     0,     0,    17,    40,    39,    35,
      36,    37,    38,    34,     0,     0,     0,    50,     0,    47,
       0,     0,     0,    18,    51,    52,    15,     0,    19
  };

  const signed char
  parser::yypgoto_[] =
  {
     -74,   -74,    76,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,    18,   -73,   -74,   -74,
      27,   -74,   -74,     7
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    10,    11,    12,    60,   102,    13,    14,    15,    16,
      17,    18,    22,    49,    55,    62,    63,    89,    19,    57,
      58,    68,    70,    82
  };

  const unsigned char
  parser::yytable_[] =
  {
      87,    90,    91,    92,    53,    41,    65,    66,    67,    31,
      79,    80,    56,     1,    20,    23,     2,     3,     4,    24,
       5,    27,     6,     7,    54,   103,    42,     8,     9,    30,
      21,    71,    72,     1,   108,    88,     2,     3,     4,    33,
       5,    43,     6,     7,    25,    34,    26,     8,     9,    73,
      74,    75,    76,    28,    44,    29,    83,    84,    79,    80,
     106,   107,    45,    35,    36,    37,    38,    39,    40,    94,
      46,    47,    77,    85,    48,    50,    51,    52,    56,    59,
      61,    69,    78,    95,    96,    98,    32,    99,    64,    86,
     104,    97,   100,   105,   101,    93,    81
  };

  const unsigned char
  parser::yycheck_[] =
  {
       3,    74,    75,    76,     6,     5,    27,    28,    29,     0,
      36,    37,    38,     4,    22,    19,     7,     8,     9,    39,
      11,    38,    13,    14,    26,    98,    26,    18,    19,    15,
      38,    25,    26,     4,   107,    38,     7,     8,     9,    19,
      11,    38,    13,    14,    10,    19,    12,    18,    19,    30,
      31,    32,    33,    10,    38,    12,    25,    26,    36,    37,
      25,    26,    38,    19,    19,    19,    19,    19,    19,     3,
      38,    38,    34,    16,    38,    38,    24,    24,    38,    38,
      38,    26,    24,    24,    24,    24,    10,    25,    38,    38,
      25,    84,    38,    25,    38,    77,    69
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     7,     8,     9,    11,    13,    14,    18,    19,
      41,    42,    43,    46,    47,    48,    49,    50,    51,    58,
      22,    38,    52,    19,    39,    10,    12,    38,    10,    12,
      15,     0,    42,    19,    19,    19,    19,    19,    19,    19,
      19,     5,    26,    38,    38,    38,    38,    38,    38,    53,
      38,    24,    24,     6,    26,    54,    38,    59,    60,    38,
      44,    38,    55,    56,    38,    27,    28,    29,    61,    26,
      62,    25,    26,    30,    31,    32,    33,    34,    24,    36,
      37,    60,    63,    25,    26,    16,    38,     3,    38,    57,
      57,    57,    57,    56,     3,    24,    24,    63,    24,    25,
      38,    38,    45,    57,    25,    25,    25,    26,    57
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    40,    41,    41,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    43,    44,    44,    45,    45,
      46,    47,    48,    49,    50,    51,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    57,
      57,    58,    59,    59,    60,    61,    61,    61,    62,    62,
      62,    63,    63
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    10,     1,     3,     1,     3,
       3,     3,     2,     3,     2,     5,     1,     1,     3,     1,
       3,     0,     2,     1,     3,     3,     3,     3,     3,     1,
       1,     7,     1,     3,     2,     1,     1,     4,     0,     2,
       3,     4,     4
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
  "\"=\"", "\"<\"", "\">\"", "\"<>\"", "\"and\"", "\"or\"",
  "\"primary key\"", "\"foreign key\"", "STRING", "FILENAME", "$accept",
  "statement_list", "statement", "insert_statement", "attr_list",
  "value_list", "drop_table_statement", "drop_db_statement",
  "use_statement", "create_db_statement", "source_statement",
  "select_statement", "select_list", "table_list", "select_condition",
  "select_condition_list", "select_condition_exp", "exp",
  "create_table_statement", "attribute_list", "attribute_exp",
  "variant_type", "constrain_list", "constrain_exp", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    69,    69,    70,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    88,    94,    95,    99,   100,
     104,   108,   112,   116,   120,   124,   134,   135,   136,   140,
     141,   145,   146,   150,   151,   155,   156,   157,   158,   162,
     163,   167,   177,   178,   182,   186,   187,   188,   192,   193,
     194,   198,   199
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
#line 1642 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

#line 202 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}
