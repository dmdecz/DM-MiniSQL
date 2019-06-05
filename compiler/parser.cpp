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
      case 63: // select_condition_exp
      case 65: // exp
      case 68: // attribute_exp
      case 71: // constrain_exp
        value.YY_MOVE_OR_COPY< Expression * > (YY_MOVE (that.value));
        break;

      case 52: // attr_list
      case 53: // value_list
      case 59: // select_list
      case 60: // table_list
      case 61: // select_condition
      case 62: // select_condition_list
      case 67: // attribute_list
      case 70: // constrain_list
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
      case 58: // select_statement
      case 64: // delete_statement
      case 66: // create_table_statement
        value.YY_MOVE_OR_COPY< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 69: // variant_type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 43: // STRING
      case 44: // FILENAME
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 46: // statement_list
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
      case 63: // select_condition_exp
      case 65: // exp
      case 68: // attribute_exp
      case 71: // constrain_exp
        value.move< Expression * > (YY_MOVE (that.value));
        break;

      case 52: // attr_list
      case 53: // value_list
      case 59: // select_list
      case 60: // table_list
      case 61: // select_condition
      case 62: // select_condition_list
      case 67: // attribute_list
      case 70: // constrain_list
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
      case 58: // select_statement
      case 64: // delete_statement
      case 66: // create_table_statement
        value.move< Statement * > (YY_MOVE (that.value));
        break;

      case 3: // NUMBER
      case 69: // variant_type
        value.move< int > (YY_MOVE (that.value));
        break;

      case 43: // STRING
      case 44: // FILENAME
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 46: // statement_list
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
      case 63: // select_condition_exp
      case 65: // exp
      case 68: // attribute_exp
      case 71: // constrain_exp
        value.move< Expression * > (that.value);
        break;

      case 52: // attr_list
      case 53: // value_list
      case 59: // select_list
      case 60: // table_list
      case 61: // select_condition
      case 62: // select_condition_list
      case 67: // attribute_list
      case 70: // constrain_list
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
      case 58: // select_statement
      case 64: // delete_statement
      case 66: // create_table_statement
        value.move< Statement * > (that.value);
        break;

      case 3: // NUMBER
      case 69: // variant_type
        value.move< int > (that.value);
        break;

      case 43: // STRING
      case 44: // FILENAME
        value.move< std::string > (that.value);
        break;

      case 46: // statement_list
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
      case 63: // select_condition_exp
      case 65: // exp
      case 68: // attribute_exp
      case 71: // constrain_exp
        yylhs.value.emplace< Expression * > ();
        break;

      case 52: // attr_list
      case 53: // value_list
      case 59: // select_list
      case 60: // table_list
      case 61: // select_condition
      case 62: // select_condition_list
      case 67: // attribute_list
      case 70: // constrain_list
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
      case 58: // select_statement
      case 64: // delete_statement
      case 66: // create_table_statement
        yylhs.value.emplace< Statement * > ();
        break;

      case 3: // NUMBER
      case 69: // variant_type
        yylhs.value.emplace< int > ();
        break;

      case 43: // STRING
      case 44: // FILENAME
        yylhs.value.emplace< std::string > ();
        break;

      case 46: // statement_list
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
#line 74 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 744 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 3:
#line 75 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { drv.execute_statement(yystack_[0].value.as < Statement * > ()); }
#line 750 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 4:
#line 76 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { return 1; }
#line 756 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 5:
#line 80 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = nullptr; }
#line 762 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 6:
#line 81 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 768 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 7:
#line 82 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Source_Statement(yystack_[1].value.as < std::string > ()); }
#line 774 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 8:
#line 83 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 780 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 9:
#line 84 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 786 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 10:
#line 85 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Quit_Statement; }
#line 792 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 11:
#line 86 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 798 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 12:
#line 87 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 804 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 13:
#line 88 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 810 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 14:
#line 89 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 816 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 15:
#line 90 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 822 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 16:
#line 91 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 828 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 17:
#line 92 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 834 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 18:
#line 93 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = yystack_[1].value.as < Statement * > (); }
#line 840 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 19:
#line 97 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Show_Statement(0); }
#line 846 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 20:
#line 98 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Show_Statement(1); }
#line 852 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 21:
#line 102 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Create_Index_Statement(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 860 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 22:
#line 108 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Drop_Index_Statement(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 868 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 23:
#line 114 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		yylhs.value.as < Statement * > () = new Insert_Statement(yystack_[7].value.as < std::string > (), yystack_[5].value.as < ExpressionList * > (), yystack_[1].value.as < ExpressionList * > ());
	}
#line 876 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 24:
#line 120 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 882 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 25:
#line 121 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 888 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 26:
#line 125 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 894 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 27:
#line 126 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 900 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 28:
#line 130 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Table_Statement(yystack_[0].value.as < std::string > ()); }
#line 906 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 29:
#line 134 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Drop_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 912 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 30:
#line 138 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Use_Statement(yystack_[0].value.as < std::string > ()); }
#line 918 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 31:
#line 142 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Statement * > () = new Create_Database_Statement(yystack_[0].value.as < std::string > ()); }
#line 924 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 32:
#line 146 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Select_Statement * select = new Select_Statement;
		select->set_select(yystack_[3].value.as < ExpressionList * > ());
		select->set_table(yystack_[1].value.as < ExpressionList * > ());
		select->set_condition(yystack_[0].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = select;
	}
#line 936 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 33:
#line 156 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression("*")); }
#line 942 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 34:
#line 157 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 948 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 35:
#line 158 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 954 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 36:
#line 162 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 960 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 37:
#line 163 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(new String_Expression(yystack_[0].value.as < std::string > ())); }
#line 966 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 38:
#line 167 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 972 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 39:
#line 168 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[0].value.as < ExpressionList * > (); }
#line 978 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 40:
#line 172 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList; yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 984 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 41:
#line 173 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 990 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 42:
#line 177 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), EQUAL, yystack_[0].value.as < Expression * > ()->values()); }
#line 996 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 43:
#line 178 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), LESS, yystack_[0].value.as < Expression * > ()->values()); }
#line 1002 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 44:
#line 179 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), LARGE, yystack_[0].value.as < Expression * > ()->values()); }
#line 1008 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 45:
#line 180 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Condition_Expression(yystack_[2].value.as < std::string > (), NOT, yystack_[0].value.as < Expression * > ()->values()); }
#line 1014 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 46:
#line 184 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
        yylhs.value.as < Statement * > () = new Delete_Statement(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionList * > ());
    }
#line 1022 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 47:
#line 190 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(std::string(yystack_[0].value.as < std::string > ())); }
#line 1028 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 48:
#line 191 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new DMType_Expression(yystack_[0].value.as < int > ()); }
#line 1034 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 49:
#line 196 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    {
		Create_Table_Statement * create = new Create_Table_Statement(yystack_[4].value.as < std::string > ());
		create->set_attribute(yystack_[2].value.as < ExpressionList * > ());
		create->set_constrain(yystack_[1].value.as < ExpressionList * > ());
		yylhs.value.as < Statement * > () = create;
	}
#line 1045 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 50:
#line 205 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1051 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 51:
#line 206 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1057 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 52:
#line 210 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > (), 0); }
#line 1063 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 53:
#line 211 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Attribute_Expression(yystack_[2].value.as < std::string > (), yystack_[1].value.as < int > (), 1); }
#line 1069 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 54:
#line 215 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -1; }
#line 1075 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 55:
#line 216 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = -2; }
#line 1081 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 56:
#line 217 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 1087 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 57:
#line 221 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = nullptr; }
#line 1093 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 58:
#line 222 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < ExpressionList * > () = new ExpressionList(); yylhs.value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); }
#line 1099 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 59:
#line 223 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yystack_[2].value.as < ExpressionList * > ()->push_back(yystack_[0].value.as < Expression * > ()); yylhs.value.as < ExpressionList * > () = yystack_[2].value.as < ExpressionList * > (); }
#line 1105 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 60:
#line 227 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(0, yystack_[1].value.as < std::string > ()); }
#line 1111 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;

  case 61:
#line 228 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"
    { yylhs.value.as < Expression * > () = new Constrain_Expression(1, yystack_[1].value.as < std::string > ()); }
#line 1117 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"
    break;


#line 1121 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -96;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       3,   -22,   -11,   -16,    33,   -21,    40,    22,    36,     5,
     -96,    25,   -96,    20,    23,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   -96,   -96,    -1,   -96,    54,    14,
      38,    59,   -96,    39,    41,    42,    43,    44,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,    55,    56,   -96,    60,   -96,    57,
     -96,   -96,    58,    61,    74,   -96,     0,   -96,    62,    63,
     -96,    64,    65,    65,    66,   -96,    27,    71,   -96,   -96,
     -96,   -12,    18,    72,   -96,    72,   -96,   -96,   -96,    67,
      69,    21,    35,    75,    70,    -3,    -3,    -3,    -3,    65,
      80,   -96,    68,    81,   -96,   -96,   -96,   -33,    83,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,    73,    76,    77,
     -96,    -3,   -96,    84,    85,    37,   -96,   -96,   -96,   -96,
      -3,   -96
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
      22,     0,     0,     0,     0,    32,     0,    57,    50,    21,
      24,     0,     0,    46,    40,    39,    37,    54,    55,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    51,    58,    49,     0,     0,    25,
      48,    47,    42,    43,    44,    45,    41,     0,     0,     0,
      59,     0,    56,     0,     0,     0,    26,    60,    61,    23,
       0,    27
  };

  const signed char
  parser::yypgoto_[] =
  {
     -96,   -96,    82,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,    19,    -5,   -96,
     -95,   -96,   -96,     4,   -96,   -96,     9
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    11,    12,    13,    14,    15,    16,    81,   125,    17,
      18,    19,    20,    21,    26,    66,    75,    83,    84,    22,
     112,    23,    77,    78,    90,    92,   105
  };

  const unsigned char
  parser::yytable_[] =
  {
     110,   113,   114,   115,    54,    24,    73,     1,   102,   103,
       2,     3,     4,    27,     5,    38,     6,     7,    93,    94,
       8,    25,    32,    39,     9,    40,   126,    10,    28,     1,
      55,    74,     2,     3,     4,   131,     5,    36,     6,     7,
     111,    37,     8,    29,    43,    30,     9,    44,    41,    10,
      33,    31,    34,    95,    96,    97,    98,    57,    35,    87,
      88,    89,   102,   103,    76,   106,   107,   129,   130,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    56,    59,
      72,    58,    60,   117,    61,    62,    63,    64,   101,    68,
      71,   108,    85,    42,   116,   104,   100,   118,    65,    67,
      69,    70,    91,   122,     0,    76,    79,    80,    82,    86,
     119,    99,   121,   109,   127,   128,   120,     0,     0,   123,
     124
  };

  const short
  parser::yycheck_[] =
  {
       3,    96,    97,    98,     5,    27,     6,     4,    41,    42,
       7,     8,     9,    24,    11,    10,    13,    14,    30,    31,
      17,    43,    43,    18,    21,     0,   121,    24,    44,     4,
      31,    31,     7,     8,     9,   130,    11,    15,    13,    14,
      43,     5,    17,    10,    24,    12,    21,    24,    23,    24,
      10,    18,    12,    35,    36,    37,    38,    43,    18,    32,
      33,    34,    41,    42,    43,    30,    31,    30,    31,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    20,
       6,    43,    43,     3,    43,    43,    43,    43,    19,    29,
      29,    16,    73,    11,    99,    91,    29,    29,    43,    43,
      43,    43,    31,    30,    -1,    43,    43,    43,    43,    43,
      29,    39,    29,    43,    30,    30,   107,    -1,    -1,    43,
      43
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     7,     8,     9,    11,    13,    14,    17,    21,
      24,    46,    47,    48,    49,    50,    51,    54,    55,    56,
      57,    58,    64,    66,    27,    43,    59,    24,    44,    10,
      12,    18,    43,    10,    12,    18,    15,     5,    10,    18,
       0,    23,    47,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,     5,    31,    24,    43,    43,    20,
      43,    43,    43,    43,    43,    43,    60,    43,    29,    43,
      43,    29,     6,     6,    31,    61,    43,    67,    68,    43,
      43,    52,    43,    62,    63,    62,    43,    32,    33,    34,
      69,    31,    70,    30,    31,    35,    36,    37,    38,    39,
      29,    19,    41,    42,    68,    71,    30,    31,    16,    43,
       3,    43,    65,    65,    65,    65,    63,     3,    29,    29,
      71,    29,    30,    43,    43,    53,    65,    30,    30,    30,
      31,    65
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    45,    46,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      48,    49,    50,    51,    52,    52,    53,    53,    54,    55,
      56,    57,    58,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    64,    65,    65,    66,
      67,    67,    68,    68,    69,    69,    69,    70,    70,    70,
      71,    71
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     2,     1,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     4,    10,     1,     3,     1,     3,     3,     3,
       2,     3,     5,     1,     1,     3,     1,     3,     0,     2,
       1,     3,     3,     3,     3,     3,     5,     1,     1,     7,
       1,     3,     2,     3,     1,     1,     4,     0,     2,     3,
       4,     4
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
  "select_statement", "select_list", "table_list", "select_condition",
  "select_condition_list", "select_condition_exp", "delete_statement",
  "exp", "create_table_statement", "attribute_list", "attribute_exp",
  "variant_type", "constrain_list", "constrain_exp", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    74,    74,    75,    76,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    97,
      98,   102,   108,   114,   120,   121,   125,   126,   130,   134,
     138,   142,   146,   156,   157,   158,   162,   163,   167,   168,
     172,   173,   177,   178,   179,   180,   184,   190,   191,   195,
     205,   206,   210,   211,   215,   216,   217,   221,   222,   223,
     227,   228
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
#line 1596 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.cpp"

#line 231 "/Users/chenzhuo/Desktop/Working/DM/compiler/parser.y"


void
yy::parser::error (const location_type& l, const std::string& m)
{
    Error e(0, "Syntax Error: " + m);
    e.diagnose();
}


