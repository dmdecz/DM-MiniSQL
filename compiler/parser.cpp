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
#line 27 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"

# include "compiler.hpp"
# include "compilertools/compilertools.hpp"


#line 51 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"


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
#line 145 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"


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

      case 53: // attr_list
      case 54: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        value.YY_MOVE_OR_COPY< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 48: // statement
      case 49: // show_statement
      case 50: // create_index_statement
      case 51: // drop_index_statement
      case 52: // insert_statement
      case 55: // drop_table_statement
      case 56: // drop_db_statement
      case 57: // use_statement
      case 58: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        value.YY_MOVE_OR_COPY< Statement * > (YY_MOVE (that.value));
        break;

      case 4: // DECIMAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 70: // variant_type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 44: // STRING
      case 45: // FILENAME
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 47: // statement_list
        value.YY_MOVE_OR_COPY< std::vector<Statement*> > (YY_MOVE (that.value));
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

      case 53: // attr_list
      case 54: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        value.move< ExpressionList * > (YY_MOVE (that.value));
        break;

      case 48: // statement
      case 49: // show_statement
      case 50: // create_index_statement
      case 51: // drop_index_statement
      case 52: // insert_statement
      case 55: // drop_table_statement
      case 56: // drop_db_statement
      case 57: // use_statement
      case 58: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        value.move< Statement * > (YY_MOVE (that.value));
        break;

      case 4: // DECIMAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 70: // variant_type
        value.move< int > (YY_MOVE (that.value));
        break;

      case 44: // STRING
      case 45: // FILENAME
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 47: // statement_list
        value.move< std::vector<Statement*> > (YY_MOVE (that.value));
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

      case 53: // attr_list
      case 54: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        value.move< ExpressionList * > (that.value);
        break;

      case 48: // statement
      case 49: // show_statement
      case 50: // create_index_statement
      case 51: // drop_index_statement
      case 52: // insert_statement
      case 55: // drop_table_statement
      case 56: // drop_db_statement
      case 57: // use_statement
      case 58: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        value.move< Statement * > (that.value);
        break;

      case 4: // DECIMAL
        value.move< double > (that.value);
        break;

      case 3: // NUMBER
      case 70: // variant_type
        value.move< int > (that.value);
        break;

      case 44: // STRING
      case 45: // FILENAME
        value.move< std::string > (that.value);
        break;

      case 47: // statement_list
        value.move< std::vector<Statement*> > (that.value);
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
    YYUSE (yytype);
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

      case 53: // attr_list
      case 54: // value_list
      case 60: // select_list
      case 61: // table_list
      case 62: // select_condition
      case 63: // select_condition_list
      case 68: // attribute_list
      case 71: // constrain_list
        yylhs.value.emplace< ExpressionList * > ();
        break;

      case 48: // statement
      case 49: // show_statement
      case 50: // create_index_statement
      case 51: // drop_index_statement
      case 52: // insert_statement
      case 55: // drop_table_statement
      case 56: // drop_db_statement
      case 57: // use_statement
      case 58: // create_db_statement
      case 59: // select_statement
      case 65: // delete_statement
      case 67: // create_table_statement
        yylhs.value.emplace< Statement * > ();
        break;

      case 4: // DECIMAL
        yylhs.value.emplace< double > ();
        break;

      case 3: // NUMBER
      case 70: // variant_type
        yylhs.value.emplace< int > ();
        break;

      case 44: // STRING
      case 45: // FILENAME
        yylhs.value.emplace< std::string > ();
        break;

      case 47: // statement_list
        yylhs.value.emplace< std::vector<Statement*> > ();
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
#line 75 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 760 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 3:
#line 76 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 766 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 4:
#line 77 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { return 1; }
#line 772 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 5:
#line 81 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 778 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 6:
#line 82 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 784 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 7:
#line 83 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Source_Statement(yystack_[1].value.as < std::string > ()); }
#line 790 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 8:
#line 84 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 796 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 9:
#line 85 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 802 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 10:
#line 86 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Quit_Statement; }
#line 808 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 11:
#line 87 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 814 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 12:
#line 88 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 820 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 13:
#line 89 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 826 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 14:
#line 90 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 832 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 15:
#line 91 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 838 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 16:
#line 92 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 844 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 17:
#line 93 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 850 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 18:
#line 94 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 856 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 19:
#line 98 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Show_Statement(0); }
#line 862 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 20:
#line 99 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Show_Statement(1); }
#line 868 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 21:
#line 103 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Create_Index_Statement(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 876 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 22:
#line 109 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Drop_Index_Statement(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 884 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 23:
#line 115 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		yylhs.value.as < Statement * > () = new Insert_Statement(yystack_[7].value.as < std::string > (), yystack_[5].value.as < ExpressionList * > (), yystack_[1].value.as < ExpressionList * > ());
	}
#line 892 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 24:
#line 121 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 898 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 25:
#line 122 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 904 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 26:
#line 126 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 910 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 27:
#line 127 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 916 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 28:
#line 131 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Table_Statement(yystack_[0].value.as < std::string > ()); }
#line 922 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 29:
#line 135 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 928 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 30:
#line 139 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Use_Statement(yystack_[0].value.as < std::string > ()); }
#line 934 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 31:
#line 143 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Create_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 940 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 32:
#line 147 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Select_Statement * select = new Select_Statement;
		select->set_select(yystack_[3].value.as < ExpressionList * > ());
		select->set_table(yystack_[1].value.as < ExpressionList * > ());
		select->set_condition(yystack_[0].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = select;
	}
#line 952 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 33:
#line 157 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression("*")); }
#line 958 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 34:
#line 158 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 964 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 35:
#line 159 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 970 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 36:
#line 163 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 976 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 37:
#line 164 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 982 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 38:
#line 168 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 988 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 39:
#line 169 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[0].value.as < ExpressionList * > (); }
#line 994 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 40:
#line 173 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1000 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 41:
#line 174 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1006 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 42:
#line 178 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), EQUAL, yystack_[0].value.as < Expression * > ()->values()); }
#line 1012 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 43:
#line 179 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), LESS, yystack_[0].value.as < Expression * > ()->values()); }
#line 1018 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 44:
#line 180 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), LARGE, yystack_[0].value.as < Expression * > ()->values()); }
#line 1024 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 45:
#line 181 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), NOT, yystack_[0].value.as < Expression * > ()->values()); }
#line 1030 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 46:
#line 185 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Delete_Statement(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionList * > ());
    }
#line 1038 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 47:
#line 191 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(DMType(yystack_[0].value.as < std::string > ())); }
#line 1044 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 48:
#line 192 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(DMType(yystack_[0].value.as < int > ())); }
#line 1050 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 49:
#line 193 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(DMType(yystack_[0].value.as < double > ())); }
#line 1056 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 50:
#line 198 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Create_Table_Statement * create = new Create_Table_Statement(yystack_[4].value.as < std::string > ());
		create->set_attribute(yystack_[2].value.as < ExpressionList * > ());
		create->set_constrain(yystack_[1].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = create;
	}
#line 1067 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 51:
#line 207 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1073 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 52:
#line 208 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1079 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 53:
#line 212 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > (), 0); }
#line 1085 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 54:
#line 213 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[2].value.as < std::string > (), yystack_[1].value.as < int > (), 1); }
#line 1091 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 55:
#line 217 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -1; }
#line 1097 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 56:
#line 218 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -2; }
#line 1103 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 57:
#line 219 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 1109 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 58:
#line 223 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1115 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 59:
#line 224 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1121 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 60:
#line 225 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1127 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 61:
#line 229 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(0, yystack_[1].value.as < std::string > ()); }
#line 1133 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 62:
#line 230 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(1, yystack_[1].value.as < std::string > ()); }
#line 1139 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;


#line 1143 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -95;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      30,   -17,   -18,   -35,    38,   -32,    43,     3,     9,    -5,
     -95,     8,   -95,    -4,     4,    11,    18,    49,    50,    51,
      52,    53,    54,    55,   -95,   -95,    -1,   -95,    56,     6,
      19,    32,   -95,    39,    40,    42,    44,    45,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,    46,    47,   -95,    57,   -95,    48,
     -95,   -95,    58,    63,    75,   -95,     2,   -95,    59,    60,
     -95,    61,    62,    62,    64,   -95,    31,    65,   -95,   -95,
     -95,    -7,    22,    67,   -95,    67,   -95,   -95,   -95,    66,
      74,    25,    15,    68,    69,    -3,    -3,    -3,    -3,    62,
      92,   -95,    70,    71,   -95,   -95,   -95,    28,    79,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,    80,    72,
      73,   -95,    -3,   -95,    81,    83,    41,   -95,   -95,   -95,
     -95,    -3,   -95
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,     0,    10,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,    19,    20,
       1,     4,     2,    18,    16,    17,    14,     9,    13,    11,
      12,     6,    15,     8,     0,     0,     7,     0,    31,     0,
      28,    29,     0,     0,     0,    36,    38,    35,     0,     0,
      22,     0,     0,     0,     0,    32,     0,    58,    51,    21,
      24,     0,     0,    46,    40,    39,    37,    55,    56,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,    52,    59,    50,     0,     0,    25,
      48,    49,    47,    42,    43,    44,    45,    41,     0,     0,
       0,    60,     0,    57,     0,     0,     0,    26,    61,    62,
      23,     0,    27
  };

  const signed char
  parser::yypgoto_[] =
  {
     -95,   -95,    87,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,    26,    16,   -95,
     -94,   -95,   -95,    27,   -95,   -95,    12
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    11,    12,    13,    14,    15,    16,    81,   126,    17,
      18,    19,    20,    21,    26,    66,    75,    83,    84,    22,
     113,    23,    77,    78,    90,    92,   105
  };

  const unsigned char
  parser::yytable_[] =
  {
     110,   111,   114,   115,   116,    54,    38,    27,    40,    73,
      28,    24,    32,     1,    39,    37,     2,     3,     4,    36,
       5,    43,     6,     7,    93,    94,     8,    25,   127,    44,
       9,    55,    41,    10,    74,     1,    45,   132,     2,     3,
       4,   112,     5,    46,     6,     7,   106,   107,     8,    29,
      57,    30,     9,    59,    33,    10,    34,    31,    95,    96,
      97,    98,    35,    58,    87,    88,    89,   102,   103,    76,
     102,   103,   130,   131,    47,    48,    49,    50,    51,    52,
      53,    56,    72,    60,    61,   108,    62,    68,    63,    64,
      65,    67,    69,    71,   101,   118,   100,    91,    42,    85,
     119,   120,    70,    76,    79,    80,    82,    99,    86,   122,
       0,   123,   128,   109,   129,   117,   124,   125,   104,   121
  };

  const short
  parser::yycheck_[] =
  {
       3,     4,    96,    97,    98,     6,    11,    25,     0,     7,
      45,    28,    44,     5,    19,     6,     8,     9,    10,    16,
      12,    25,    14,    15,    31,    32,    18,    44,   122,    25,
      22,    32,    24,    25,    32,     5,    25,   131,     8,     9,
      10,    44,    12,    25,    14,    15,    31,    32,    18,    11,
      44,    13,    22,    21,    11,    25,    13,    19,    36,    37,
      38,    39,    19,    44,    33,    34,    35,    42,    43,    44,
      42,    43,    31,    32,    25,    25,    25,    25,    25,    25,
      25,    25,     7,    44,    44,    17,    44,    30,    44,    44,
      44,    44,    44,    30,    20,     3,    30,    32,    11,    73,
      30,    30,    44,    44,    44,    44,    44,    40,    44,    30,
      -1,    31,    31,    44,    31,    99,    44,    44,    91,   107
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     5,     8,     9,    10,    12,    14,    15,    18,    22,
      25,    47,    48,    49,    50,    51,    52,    55,    56,    57,
      58,    59,    65,    67,    28,    44,    60,    25,    45,    11,
      13,    19,    44,    11,    13,    19,    16,     6,    11,    19,
       0,    24,    48,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,     6,    32,    25,    44,    44,    21,
      44,    44,    44,    44,    44,    44,    61,    44,    30,    44,
      44,    30,     7,     7,    32,    62,    44,    68,    69,    44,
      44,    53,    44,    63,    64,    63,    44,    33,    34,    35,
      70,    32,    71,    31,    32,    36,    37,    38,    39,    40,
      30,    20,    42,    43,    69,    72,    31,    32,    17,    44,
       3,     4,    44,    66,    66,    66,    66,    64,     3,    30,
      30,    72,    30,    31,    44,    44,    54,    66,    31,    31,
      31,    32,    66
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    46,    47,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    50,    51,    52,    53,    53,    54,    54,    55,    56,
      57,    58,    59,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    64,    65,    66,    66,    66,
      67,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      71,    72,    72
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     2,     1,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     4,    10,     1,     3,     1,     3,     3,     3,
       2,     3,     5,     1,     1,     3,     1,     3,     0,     2,
       1,     3,     3,     3,     3,     3,     5,     1,     1,     1,
       7,     1,     3,     2,     3,     1,     1,     4,     0,     2,
       3,     4,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMBER", "DECIMAL", "SELECT", "FROM",
  "WHERE", "QUIT", "SOURCE", "CREATE", "TABLE", "USE", "DATABASE", "DROP",
  "INSERT", "INTO", "VALUES", "DELETE", "INDEX", "UNIQUE", "ON", "SHOW",
  "BLANK", "\"eof\"", "\";\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"(\"",
  "\")\"", "\",\"", "\"int\"", "\"double\"", "\"char\"", "\"=\"", "\"<\"",
  "\">\"", "\"<>\"", "\"and\"", "\"or\"", "\"primary key\"",
  "\"foreign key\"", "STRING", "FILENAME", "$accept", "statement_list",
  "statement", "show_statement", "create_index_statement",
  "drop_index_statement", "insert_statement", "attr_list", "value_list",
  "drop_table_statement", "drop_db_statement", "use_statement",
  "create_db_statement", "select_statement", "select_list", "table_list",
  "select_condition", "select_condition_list", "select_condition_exp",
  "delete_statement", "exp", "create_table_statement", "attribute_list",
  "attribute_exp", "variant_type", "constrain_list", "constrain_exp", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    75,    75,    76,    77,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    98,
      99,   103,   109,   115,   121,   122,   126,   127,   131,   135,
     139,   143,   147,   157,   158,   159,   163,   164,   168,   169,
     173,   174,   178,   179,   180,   181,   185,   191,   192,   193,
     197,   207,   208,   212,   213,   217,   218,   219,   223,   224,
     225,   229,   230
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
#line 1616 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

#line 233 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"


void
yy::parser::error (const location_type& l, const std::string& m)
{
    throw Error(0, "Syntax Error: " + m);
}


