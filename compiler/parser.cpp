// A Bison parser, made by GNU Bison 3.3.2.

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
#line 23 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:435

# include "compiler.hpp"
# include "compilertools/compilertools.hpp"

#line 50 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:435


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
#line 145 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:510

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
      case 36: // create_db_statement
        value.YY_MOVE_OR_COPY< Create_Database_Statement * > (YY_MOVE (that.value));
        break;

      case 35: // exp
      case 38: // attribute_exp
        value.YY_MOVE_OR_COPY< Expression * > (YY_MOVE (that.value));
        break;

      case 32: // select_list
      case 33: // table_list
      case 34: // select_condition
      case 37: // attribute_list
        value.YY_MOVE_OR_COPY< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 31: // select_statement
        value.YY_MOVE_OR_COPY< Select_Statement * > (YY_MOVE (that.value));
        break;

      case 29: // statement
        value.YY_MOVE_OR_COPY< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 39: // variant_type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 24: // STRING
      case 25: // FILENAME
      case 30: // source_statement
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
      case 36: // create_db_statement
        value.move< Create_Database_Statement * > (YY_MOVE (that.value));
        break;

      case 35: // exp
      case 38: // attribute_exp
        value.move< Expression * > (YY_MOVE (that.value));
        break;

      case 32: // select_list
      case 33: // table_list
      case 34: // select_condition
      case 37: // attribute_list
        value.move< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 31: // select_statement
        value.move< Select_Statement * > (YY_MOVE (that.value));
        break;

      case 29: // statement
        value.move< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 39: // variant_type
        value.move< int > (YY_MOVE (that.value));
        break;

      case 24: // STRING
      case 25: // FILENAME
      case 30: // source_statement
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
      case 36: // create_db_statement
        value.move< Create_Database_Statement * > (that.value);
        break;

      case 35: // exp
      case 38: // attribute_exp
        value.move< Expression * > (that.value);
        break;

      case 32: // select_list
      case 33: // table_list
      case 34: // select_condition
      case 37: // attribute_list
        value.move< ExpressionList * > (that.value);
        break;

      case 31: // select_statement
        value.move< Select_Statement * > (that.value);
        break;

      case 29: // statement
        value.move< Statement * > (that.value);
        break;

      case 3: // NUMBER
      case 39: // variant_type
        value.move< int > (that.value);
        break;

      case 24: // STRING
      case 25: // FILENAME
      case 30: // source_statement
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
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < int > (); }
#line 430 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 24: // STRING
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < std::string > (); }
#line 436 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 25: // FILENAME
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < std::string > (); }
#line 442 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 29: // statement
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < Statement * > (); }
#line 448 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 30: // source_statement
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < std::string > (); }
#line 454 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 31: // select_statement
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < Select_Statement * > (); }
#line 460 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 32: // select_list
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 466 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 33: // table_list
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 472 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 34: // select_condition
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 478 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 35: // exp
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < Expression * > (); }
#line 484 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 36: // create_db_statement
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < Create_Database_Statement * > (); }
#line 490 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 37: // attribute_list
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < ExpressionList * > (); }
#line 496 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 38: // attribute_exp
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < Expression * > (); }
#line 502 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
        break;

      case 39: // variant_type
#line 54 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:676
        { yyo << yysym.value.template as < int > (); }
#line 508 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:676
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
      case 36: // create_db_statement
        yylhs.value.emplace< Create_Database_Statement * > ();
        break;

      case 35: // exp
      case 38: // attribute_exp
        yylhs.value.emplace< Expression * > ();
        break;

      case 32: // select_list
      case 33: // table_list
      case 34: // select_condition
      case 37: // attribute_list
        yylhs.value.emplace< ExpressionList * > ();
        break;

      case 31: // select_statement
        yylhs.value.emplace< Select_Statement * > ();
        break;

      case 29: // statement
        yylhs.value.emplace< Statement * > ();
        break;

      case 3: // NUMBER
      case 39: // variant_type
        yylhs.value.emplace< int > ();
        break;

      case 24: // STRING
      case 25: // FILENAME
      case 30: // source_statement
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
#line 59 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 783 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 3:
#line 60 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 789 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 4:
#line 64 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < Statement * > () = nullptr; }
#line 795 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 5:
#line 65 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < Statement * > () = nullptr; }
#line 801 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 6:
#line 66 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Select_Statement * > (); }
#line 807 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 7:
#line 67 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < Statement * > () = nullptr; Compiler::file = yystack_[1].value.as < std::string > (); return 0; }
#line 813 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 8:
#line 68 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Create_Database_Statement * > (); }
#line 819 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 9:
#line 69 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { std::cout << "Bye" << std::endl; return -1; }
#line 825 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 10:
#line 73 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 831 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 11:
#line 77 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    {
		yylhs.value.as < Select_Statement * > () = new Select_Statement;
		yylhs.value.as < Select_Statement * > ()->set_select(yystack_[3].value.as < ExpressionList * > ());
		// std::cout << $2 << std::endl;
		yylhs.value.as < Select_Statement * > ()->set_table(yystack_[1].value.as < ExpressionList * > ());
		// std::cout << $4 << std::endl;
		yylhs.value.as < Select_Statement * > ()->set_condition(yystack_[0].value.as < ExpressionList * > ());
		// std::cout << $5 << std::endl;
	}
#line 845 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 12:
#line 89 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 851 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 13:
#line 90 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 857 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 14:
#line 94 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 863 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 15:
#line 95 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 869 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 16:
#line 99 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 875 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 17:
#line 100 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 881 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 18:
#line 104 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < Expression * > () = new String_Expression(yystack_[0].value.as < std::string > ()); }
#line 887 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 19:
#line 109 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    {
		yylhs.value.as < Create_Database_Statement * > () = new Create_Database_Statement();
		yylhs.value.as < Create_Database_Statement * > ()->set_attribute(yystack_[1].value.as < ExpressionList * > ());
		yylhs.value.as < Create_Database_Statement * > ()->set_constrain(nullptr);
	}
#line 897 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 20:
#line 117 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 903 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 21:
#line 118 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 909 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 22:
#line 122 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > ()); }
#line 915 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 23:
#line 126 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < int > () = -1; }
#line 921 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 24:
#line 127 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < int > () = -2; }
#line 927 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;

  case 25:
#line 128 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:919
    { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 933 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
    break;


#line 937 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:919
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


  const signed char parser::yypact_ninf_ = -18;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      16,   -15,   -18,     7,   -18,    -8,     5,     1,   -18,    12,
      17,    25,   -18,    -5,   -18,   -18,   -18,    15,   -18,   -18,
     -18,   -18,   -18,   -15,   -15,    10,    -4,   -18,   -18,     8,
     -16,   -18,   -15,   -15,   -18,   -18,   -18,    18,   -18,   -18,
      10,   -18,   -18,    32,   -18,    19,   -18
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     5,     0,     4,     0,     0,     0,     2,     0,
       0,     0,    18,     0,    12,     9,    10,     0,     1,     3,
       7,     6,     8,     0,     0,     0,    16,    14,    13,     0,
       0,    20,     0,     0,    11,    23,    24,     0,    22,    19,
       0,    17,    15,     0,    21,     0,    25
  };

  const signed char
  parser::yypgoto_[] =
  {
     -18,   -18,    30,   -18,   -18,   -18,   -18,   -18,   -17,   -18,
     -18,    -1,   -18
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     7,     8,     9,    10,    13,    26,    34,    14,    11,
      30,    31,    38
  };

  const unsigned char
  parser::yytable_[] =
  {
      23,    18,    32,    39,    40,     1,    27,    28,     2,    12,
       3,     4,     5,     6,    15,    41,    42,    16,    17,    20,
       1,    24,    33,     2,    21,     3,     4,     5,     6,    35,
      36,    37,    22,    25,    29,    45,    43,    19,    46,    44
  };

  const unsigned char
  parser::yycheck_[] =
  {
       5,     0,     6,    19,    20,     4,    23,    24,     7,    24,
       9,    10,    11,    12,     7,    32,    33,    25,    13,     7,
       4,    26,    26,     7,     7,     9,    10,    11,    12,    21,
      22,    23,     7,    18,    24,     3,    18,     7,    19,    40
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     7,     9,    10,    11,    12,    28,    29,    30,
      31,    36,    24,    32,    35,     7,    25,    13,     0,    29,
       7,     7,     7,     5,    26,    18,    33,    35,    35,    24,
      37,    38,     6,    26,    34,    21,    22,    23,    39,    19,
      20,    35,    35,    18,    38,     3,    19
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    27,    28,    28,    29,    29,    29,    29,    29,    29,
      30,    31,    32,    32,    33,    33,    34,    34,    35,    36,
      37,    37,    38,    39,    39,    39
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     2,     2,     2,     2,
       2,     5,     1,     3,     1,     3,     0,     2,     1,     5,
       1,     3,     2,     1,     1,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMBER", "SELECT", "FROM", "WHERE",
  "ENDL", "BLANK", "QUIT", "END", "SOURCE", "CREATE", "TABLE", "\"-\"",
  "\"+\"", "\"*\"", "\"/\"", "\"(\"", "\")\"", "\",\"", "\"int\"",
  "\"double\"", "\"char\"", "STRING", "FILENAME", "','", "$accept",
  "statement_list", "statement", "source_statement", "select_statement",
  "select_list", "table_list", "select_condition", "exp",
  "create_db_statement", "attribute_list", "attribute_exp", "variant_type", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    59,    59,    60,    64,    65,    66,    67,    68,    69,
      73,    77,    89,    90,    94,    95,    99,   100,   104,   108,
     117,   118,   122,   126,   127,   128
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
#line 1346 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.cpp" // lalr1.cc:1242
#line 131 "/Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/compiler/parser.y" // lalr1.cc:1243


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}
