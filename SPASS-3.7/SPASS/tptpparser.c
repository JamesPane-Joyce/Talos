/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse tptp_parse
#define yylex   tptp_lex
#define yyerror tptp_error
#define yylval  tptp_lval
#define yychar  tptp_char
#define yydebug tptp_debug
#define yynerrs tptp_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AMPERSAND = 258,
     COLON = 259,
     COMMA = 260,
     EQUALS = 261,
     EQUALS_GREATER = 262,
     EXCLAMATION = 263,
     EXCLAMATION_EQUALS = 264,
     LBRKT = 265,
     LESS_EQUALS = 266,
     LESS_EQUALS_GREATER = 267,
     LESS_TILDE_GREATER = 268,
     LPAREN = 269,
     PERIOD = 270,
     QUESTION = 271,
     RBRKT = 272,
     RPAREN = 273,
     TILDE = 274,
     TILDE_AMPERSAND = 275,
     TILDE_VLINE = 276,
     VLINE = 277,
     _DLR_cnf = 278,
     _DLR_fof = 279,
     _DLR_fot = 280,
     _LIT_cnf = 281,
     _LIT_fof = 282,
     _LIT_include = 283,
     comment_line = 284,
     distinct_object = 285,
     dollar_dollar_word = 286,
     dollar_word = 287,
     lower_word = 288,
     real = 289,
     signed_integer = 290,
     single_quoted = 291,
     unsigned_integer = 292,
     upper_word = 293,
     unrecognized = 294
   };
#endif
/* Tokens.  */
#define AMPERSAND 258
#define COLON 259
#define COMMA 260
#define EQUALS 261
#define EQUALS_GREATER 262
#define EXCLAMATION 263
#define EXCLAMATION_EQUALS 264
#define LBRKT 265
#define LESS_EQUALS 266
#define LESS_EQUALS_GREATER 267
#define LESS_TILDE_GREATER 268
#define LPAREN 269
#define PERIOD 270
#define QUESTION 271
#define RBRKT 272
#define RPAREN 273
#define TILDE 274
#define TILDE_AMPERSAND 275
#define TILDE_VLINE 276
#define VLINE 277
#define _DLR_cnf 278
#define _DLR_fof 279
#define _DLR_fot 280
#define _LIT_cnf 281
#define _LIT_fof 282
#define _LIT_include 283
#define comment_line 284
#define distinct_object 285
#define dollar_dollar_word 286
#define dollar_word 287
#define lower_word 288
#define real 289
#define signed_integer 290
#define single_quoted 291
#define unsigned_integer 292
#define upper_word 293
#define unrecognized 294




/* Copy the first part of user declarations.  */
#line 2 "tptpparser.y"

  /*-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "foldfg.h"
#include "symbol.h"
#include "term.h"
/* *  This program is free software; you can redistribute   * */
/* *  it and/or modify it under the terms of the FreeBSD    * */
/* *  Licence.                                              * */
/* *                                                        * */
/* *  This program is distributed in the hope that it will  * */
/* *  be useful, but WITHOUT ANY WARRANTY; without even     * */
/* *  the implied warranty of MERCHANTABILITY or FITNESS    * */
/* *  FOR A PARTICULAR PURPOSE.  See the LICENCE file       * */
/* *  for more details.                                     * */
#include "misc.h"
#include "list.h"
#include "strings.h"

#include "tptp.h"
#include "tptpparser.h" /*generated by bison - only include it as a last thing*/

  /*-----------------------------------------------------------------------------*/

  /*flex/bison extern things*/
  extern int tptp_lineno;
  extern char* tptp_text;
  extern FILE* tptp_in;

  int yyparse(void);
  void yyerror(const char*);
  int  yylex(void);		  /* Defined in dfgscanner.l */

  /*-----------------------------------------------------------------------------*/

  typedef enum {
    TPTP_ORDINARY, TPTP_DEFINED, TPTP_SYSTEM
  } TPTP_SYMBOLKIND;

  typedef enum {
    TPTP_UNDEF, TPTP_FOF, TPTP_CNF
  } TPTP_FORMULATYPE;

  static LIST tptp_VARLIST;

  static PRECEDENCE tptp_PRECEDENCE;

  static FILE* tptp_output = NULL; /* for outputting comments */

  static BOOL  tptp_TranslateIdents = TRUE;

  static LIST tptp_Axioms;
  static LIST tptp_Conjectures;
  static LIST tptp_Includes;

  static TPTP_FORMULATYPE tptp_LastFormulaType;

  static BOOL tptp_StatusRead;
  static BOOL tptp_DomainRead;
  static BOOL tptp_ProblemRead;
  static BOOL tptp_EnglishRead;
  static BOOL tptp_EnglishReading;

  static DFGDESCRIPTION tptp_Description;

  static SYMBOL tptp_GetSymbol(char *, int, TPTP_SYMBOLKIND);
  static TERM tptp_TermCreate(SYMBOL, LIST);

  static void tptp_CheckArguments(TERM Term);
  static TERM   tptp_VarTermCreate(char*);
  static void   tptp_RestartVarList(void);
  static SYMBOL tptp_VarLookup(char*);

  static char* tptp_StripQuotes(char *);

  static void tptp_HandleComments(char *);
  static TERM tptp_HandleAtomic(TERM);
  static void tptp_HandleInclude(char*,LIST);
  static TERM tptp_NormalizeLiterals(TERM, BOOL);
  static void tptp_HandleFormula(char*, char*, TERM, BOOL);
  static TERM tptp_CheckClosedness(TERM, BOOL);

  /*-----------------------------------------------------------------------------*/

  

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 91 "tptpparser.y"
{  
  char*     string;
  SYMBOL    symbol;
  TERM      term;
  LIST      list;
  BOOL      bool;
}
/* Line 187 of yacc.c.  */
#line 279 "tptpparser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 292 "tptpparser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      29,    40,    44,    46,    48,    50,    52,    54,    56,    60,
      62,    64,    68,    72,    76,    80,    82,    84,    86,    90,
      97,    99,   103,   106,   110,   112,   114,   118,   120,   123,
     125,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   147,   149,   151,   153,   155,   159,   161,   163,   165,
     167,   169,   171,   173,   175,   177,   182,   184,   186,   188,
     190,   192,   194,   196,   198,   203,   205,   207,   209,   214,
     216,   218,   220,   222,   226,   228,   231,   233,   235,   242,
     247,   249,   251,   255,   257,   261,   263,   265,   270,   272,
     274,   276,   278,   283,   288,   293,   296,   300,   302,   306,
     308,   310,   312,   314,   316,   318,   320,   322,   324,   326
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,   104,    -1,    41,    42,    -1,    43,    -1,
      90,    -1,    29,    -1,    44,    -1,    45,    -1,    27,    14,
      98,     5,    47,     5,    48,    46,    18,    15,    -1,    26,
      14,    98,     5,    47,     5,    58,    46,    18,    15,    -1,
       5,    87,    88,    -1,   104,    -1,    33,    -1,    49,    -1,
      54,    -1,    50,    -1,    51,    -1,    54,    62,    54,    -1,
      52,    -1,    53,    -1,    54,    22,    54,    -1,    54,    22,
      52,    -1,    54,     3,    54,    -1,    54,     3,    53,    -1,
      55,    -1,    57,    -1,    64,    -1,    14,    48,    18,    -1,
      61,    10,    56,    17,     4,    54,    -1,    85,    -1,    85,
       5,    56,    -1,    63,    54,    -1,    14,    59,    18,    -1,
      59,    -1,    60,    -1,    60,    22,    59,    -1,    64,    -1,
      19,    64,    -1,     8,    -1,    16,    -1,    12,    -1,     7,
      -1,    11,    -1,    13,    -1,    21,    -1,    20,    -1,    19,
      -1,    65,    -1,    66,    -1,    70,    -1,    73,    -1,    67,
      -1,    68,    -1,    79,    -1,    71,    69,    71,    -1,     6,
      -1,     9,    -1,    82,    -1,    72,    -1,    85,    -1,    73,
      -1,    76,    -1,    82,    -1,    74,    -1,    75,    14,    86,
      18,    -1,    75,    -1,    99,    -1,    77,    -1,    78,    -1,
     102,    -1,    30,    -1,    79,    -1,    80,    -1,    81,    14,
      86,    18,    -1,    81,    -1,   100,    -1,    83,    -1,    84,
      14,    86,    18,    -1,    84,    -1,   101,    -1,    38,    -1,
      71,    -1,    71,     5,    86,    -1,    93,    -1,     5,    89,
      -1,   104,    -1,    96,    -1,    28,    14,   103,    91,    18,
      15,    -1,     5,    10,    92,    17,    -1,   104,    -1,    98,
      -1,    98,     5,    92,    -1,    94,    -1,    94,     4,    93,
      -1,    96,    -1,    99,    -1,    99,    14,    97,    18,    -1,
      85,    -1,   102,    -1,    30,    -1,    95,    -1,    24,    14,
      48,    18,    -1,    23,    14,    58,    18,    -1,    25,    14,
      71,    18,    -1,    10,    17,    -1,    10,    97,    17,    -1,
      93,    -1,    93,     5,    97,    -1,    99,    -1,    37,    -1,
      33,    -1,    36,    -1,    32,    -1,    31,    -1,    34,    -1,
      35,    -1,    37,    -1,    99,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   166,   170,   171,   172,   176,   177,   181,
     187,   193,   196,   200,   204,   205,   209,   210,   214,   220,
     221,   225,   226,   230,   231,   235,   236,   237,   238,   242,
     248,   249,   253,   257,   258,   262,   263,   267,   268,   273,
     274,   278,   279,   280,   281,   282,   283,   287,   293,   296,
     299,   305,   309,   310,   314,   318,   324,   325,   329,   333,
     334,   338,   339,   340,   344,   345,   351,   357,   361,   364,
     368,   369,   373,   377,   378,   384,   390,   394,   395,   401,
     407,   411,   415,   416,   422,   426,   427,   431,   435,   441,
     442,   446,   447,   453,   454,   455,   459,   460,   461,   462,
     463,   464,   468,   469,   470,   474,   475,   479,   480,   484,
     485,   489,   490,   494,   498,   502,   503,   504,   508,   512
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPERSAND", "COLON", "COMMA", "EQUALS",
  "EQUALS_GREATER", "EXCLAMATION", "EXCLAMATION_EQUALS", "LBRKT",
  "LESS_EQUALS", "LESS_EQUALS_GREATER", "LESS_TILDE_GREATER", "LPAREN",
  "PERIOD", "QUESTION", "RBRKT", "RPAREN", "TILDE", "TILDE_AMPERSAND",
  "TILDE_VLINE", "VLINE", "_DLR_cnf", "_DLR_fof", "_DLR_fot", "_LIT_cnf",
  "_LIT_fof", "_LIT_include", "comment_line", "distinct_object",
  "dollar_dollar_word", "dollar_word", "lower_word", "real",
  "signed_integer", "single_quoted", "unsigned_integer", "upper_word",
  "unrecognized", "$accept", "TPTP_file", "TPTP_input",
  "annotated_formula", "fof_annotated", "cnf_annotated", "annotations",
  "formula_role", "fof_formula", "binary_formula", "nonassoc_binary",
  "assoc_binary", "or_formula", "and_formula", "unitary_formula",
  "quantified_formula", "variable_list", "unary_formula", "cnf_formula",
  "disjunction", "literal", "quantifier", "binary_connective",
  "unary_connective", "atomic_formula", "plain_atomic_formula",
  "defined_atomic_formula", "defined_plain_formula",
  "defined_infix_formula", "defined_infix_pred", "system_atomic_formula",
  "term", "function_term", "plain_term", "constant", "functor",
  "defined_term", "defined_atom", "defined_atomic_term",
  "defined_plain_term", "defined_constant", "defined_functor",
  "system_term", "system_constant", "system_functor", "variable",
  "arguments", "source", "optional_info", "useful_info", "include",
  "formula_selection", "name_list", "general_term", "general_data",
  "formula_data", "general_list", "general_terms", "name", "atomic_word",
  "atomic_defined_word", "atomic_system_word", "number", "file_name",
  "null", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    43,    43,    44,
      45,    46,    46,    47,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    55,
      56,    56,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    63,    64,    64,
      64,    65,    66,    66,    67,    68,    69,    69,    70,    71,
      71,    72,    72,    72,    73,    73,    74,    75,    76,    76,
      77,    77,    78,    79,    79,    80,    81,    82,    82,    83,
      84,    85,    86,    86,    87,    88,    88,    89,    90,    91,
      91,    92,    92,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   101,   102,   102,   102,   103,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,    10,
      10,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     3,     3,     3,     1,     1,     1,     3,     6,
       1,     3,     2,     3,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     6,     4,
       1,     1,     3,     1,     3,     1,     1,     4,     1,     1,
       1,     1,     4,     4,     4,     2,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     119,     0,     2,     1,     0,     0,     0,     6,     3,     4,
       7,     8,     5,     0,     0,     0,   111,   112,   110,     0,
     109,     0,   118,   119,     0,     0,     0,     0,    90,    13,
       0,     0,     0,     0,     0,     0,     0,    91,    88,     0,
       0,    71,   114,   113,   115,   116,   117,    81,   119,    34,
      35,    37,    48,    49,    52,    53,    50,     0,    59,    51,
      64,    66,    62,    68,    69,    54,    73,    75,    58,    77,
      79,    60,    67,    76,    80,    70,    39,     0,    40,    47,
     119,    14,    16,    17,    19,    20,    15,    25,    26,     0,
       0,    27,    89,     0,     0,    38,     0,     0,    12,     0,
      56,    57,     0,     0,     0,     0,     0,     0,     0,    42,
      43,    41,    44,    46,    45,     0,     0,     0,    32,    92,
      33,     0,     0,     0,     0,   100,    98,   119,    84,    93,
     101,    95,    96,    99,     0,    36,    55,    61,    72,    63,
      82,     0,     0,     0,    28,     0,    24,    23,    22,    21,
      18,     0,    30,   105,   107,     0,     0,     0,     0,     0,
      11,    86,     0,     0,    10,     0,    65,    74,    78,     9,
       0,     0,     0,   106,     0,     0,     0,    85,    87,    94,
       0,    83,     0,    31,   108,   103,   102,   104,    97,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     8,     9,    10,    11,    97,    30,    80,    81,
      82,    83,    84,    85,    86,    87,   151,    88,    48,    49,
      50,    89,   116,    90,    91,    52,    53,    54,    55,   102,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   141,   127,   160,   177,
      12,    27,    36,   154,   129,   130,   131,   155,    37,    72,
      73,    74,    75,    23,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
    -153,    32,  -153,  -153,     2,    15,    20,  -153,  -153,  -153,
    -153,  -153,  -153,   -15,   -15,    -9,  -153,  -153,  -153,    12,
    -153,    36,  -153,    61,    34,    34,    60,    53,  -153,  -153,
      67,    70,   -15,    62,   165,   104,    59,    79,  -153,   174,
     203,  -153,  -153,  -153,  -153,  -153,  -153,  -153,    80,  -153,
      68,  -153,  -153,  -153,  -153,  -153,  -153,    19,  -153,    29,
    -153,    75,  -153,  -153,  -153,    30,  -153,    78,    56,  -153,
      81,  -153,  -153,  -153,  -153,  -153,  -153,   104,  -153,  -153,
      80,  -153,  -153,  -153,  -153,  -153,   210,  -153,  -153,    83,
     104,  -153,  -153,   -15,    76,  -153,   153,    82,  -153,   174,
    -153,  -153,   203,   203,   203,   203,    85,    86,   104,  -153,
    -153,  -153,  -153,  -153,  -153,   104,   104,    58,  -153,  -153,
    -153,   137,    87,    93,    97,  -153,  -153,    94,  -153,   110,
    -153,  -153,   101,  -153,   106,  -153,  -153,  -153,  -153,  -153,
     111,   107,   109,   113,  -153,   114,  -153,   116,  -153,   100,
    -153,   115,   119,  -153,   123,   126,   165,   104,   203,   134,
    -153,  -153,   153,   153,  -153,   203,  -153,  -153,  -153,  -153,
     129,    58,   153,  -153,   127,   128,   130,  -153,  -153,  -153,
     133,  -153,   104,  -153,  -153,  -153,  -153,  -153,  -153,  -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,  -153,  -153,  -153,    72,   131,   -71,  -153,
    -153,  -153,    38,    47,   -85,  -153,   -14,  -153,     8,   -31,
    -153,  -153,  -153,  -153,   -30,  -153,  -153,  -153,  -153,  -153,
    -153,   -60,  -153,   -56,  -153,  -153,  -153,  -153,  -153,   -52,
    -153,  -153,   -48,  -153,  -153,   -84,   -91,  -153,  -153,  -153,
    -153,  -153,    65,   -89,  -153,  -153,     6,  -152,    50,   -13,
    -153,  -153,   -81,  -153,     3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -73
static const yytype_int16 yytable[] =
{
      20,    20,    22,     2,    51,   118,   106,   128,    94,    51,
      95,   180,   126,   142,   143,   133,    13,    24,    16,    20,
     184,    17,    18,   147,    16,   100,    28,    17,   101,    14,
     149,   150,     3,   152,    15,   -61,   -72,   126,   -61,   -72,
     133,    25,   136,   140,   140,   140,   137,   137,   137,   137,
     138,   138,   138,   138,   139,   139,   139,   139,     4,     5,
       6,     7,   -63,    19,    21,   -63,    26,    29,   135,    51,
      32,    33,    34,   179,   181,    35,    92,    38,   126,   126,
      20,   133,   133,   132,    93,    96,   175,   152,   126,   103,
      99,   133,   104,   117,   120,   105,    47,   189,   176,   159,
     134,   156,   137,   144,   145,   140,   138,   157,   132,   137,
     139,   158,    76,   138,   162,   163,   165,   139,    77,   108,
      78,   164,   115,    79,   171,   166,    51,   167,   172,   169,
     161,   168,   170,   182,    41,    42,    43,    16,    44,    45,
      17,    46,    47,   173,   121,   185,   186,   121,   187,   132,
     132,   188,   107,   148,   153,   146,    31,   183,   119,   132,
     122,   123,   124,   121,   174,   178,     0,   125,     0,     0,
      16,    44,    45,    17,    46,    47,   122,   123,   124,    39,
       0,     0,     0,   125,    40,     0,    16,    44,    45,    17,
      46,    47,     0,    40,     0,    41,    42,    43,    16,    44,
      45,    17,    46,    47,    41,    42,    43,    16,    44,    45,
      17,    46,    47,   108,     0,     0,     0,   109,     0,     0,
       0,   110,   111,   112,     0,     0,     0,     0,     0,     0,
     113,   114,   115,    41,    42,    43,    16,    44,    45,    17,
      46,    47
};

static const yytype_int16 yycheck[] =
{
      13,    14,    15,     0,    34,    90,    77,    96,    39,    39,
      40,   163,    96,   104,   105,    96,    14,     5,    33,    32,
     172,    36,    37,   108,    33,     6,    23,    36,     9,    14,
     115,   116,     0,   117,    14,     6,     6,   121,     9,     9,
     121,     5,   102,   103,   104,   105,   102,   103,   104,   105,
     102,   103,   104,   105,   102,   103,   104,   105,    26,    27,
      28,    29,     6,    13,    14,     9,     5,    33,    99,    99,
      10,    18,     5,   162,   165,     5,    17,    15,   162,   163,
      93,   162,   163,    96,     5,     5,   157,   171,   172,    14,
      22,   172,    14,    10,    18,    14,    38,   182,   158,     5,
      18,    14,   158,    18,    18,   165,   158,    14,   121,   165,
     158,    14,     8,   165,     4,    14,     5,   165,    14,     3,
      16,    15,    22,    19,     5,    18,   156,    18,     5,    15,
     127,    18,    17,     4,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    17,    10,    18,    18,    10,    18,   162,
     163,    18,    80,   115,    17,   108,    25,   171,    93,   172,
      23,    24,    25,    10,   156,   159,    -1,    30,    -1,    -1,
      33,    34,    35,    36,    37,    38,    23,    24,    25,    14,
      -1,    -1,    -1,    30,    19,    -1,    33,    34,    35,    36,
      37,    38,    -1,    19,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     3,    -1,    -1,    -1,     7,    -1,    -1,
      -1,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    30,    31,    32,    33,    34,    35,    36,
      37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,   104,     0,    26,    27,    28,    29,    42,    43,
      44,    45,    90,    14,    14,    14,    33,    36,    37,    98,
      99,    98,    99,   103,     5,     5,     5,    91,   104,    33,
      47,    47,    10,    18,     5,     5,    92,    98,    15,    14,
      19,    30,    31,    32,    34,    35,    37,    38,    58,    59,
      60,    64,    65,    66,    67,    68,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    99,   100,   101,   102,     8,    14,    16,    19,
      48,    49,    50,    51,    52,    53,    54,    55,    57,    61,
      63,    64,    17,     5,    59,    64,     5,    46,   104,    22,
       6,     9,    69,    14,    14,    14,    48,    46,     3,     7,
      11,    12,    13,    20,    21,    22,    62,    10,    54,    92,
      18,    10,    23,    24,    25,    30,    85,    87,    93,    94,
      95,    96,    99,   102,    18,    59,    71,    73,    79,    82,
      71,    86,    86,    86,    18,    18,    53,    54,    52,    54,
      54,    56,    85,    17,    93,    97,    14,    14,    14,     5,
      88,   104,     4,    14,    15,     5,    18,    18,    18,    15,
      17,     5,     5,    17,    58,    48,    71,    89,    96,    93,
      97,    86,     4,    56,    97,    18,    18,    18,    18,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 172 "tptpparser.y"
    { tptp_HandleComments((yyvsp[(1) - (1)].string)); ;}
    break;

  case 9:
#line 181 "tptpparser.y"
    {
  tptp_HandleFormula((yyvsp[(3) - (10)].string),(yyvsp[(5) - (10)].string),tptp_CheckClosedness((yyvsp[(7) - (10)].term),FALSE),FALSE);
;}
    break;

  case 10:
#line 187 "tptpparser.y"
    {                  
  tptp_HandleFormula((yyvsp[(3) - (10)].string),(yyvsp[(5) - (10)].string),tptp_CheckClosedness((yyvsp[(7) - (10)].term),TRUE),TRUE);
;}
    break;

  case 11:
#line 193 "tptpparser.y"
    {                
  misc_UserWarning("Nonempty anntotation encountered near line %d and ignored!\n",tptp_lineno);
;}
    break;

  case 12:
#line 196 "tptpparser.y"
    { ;}
    break;

  case 13:
#line 200 "tptpparser.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 14:
#line 204 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 15:
#line 205 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 16:
#line 209 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 17:
#line 210 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 18:
#line 214 "tptpparser.y"
    {
  (yyval.term) = term_Create((yyvsp[(2) - (3)].symbol),list_Cons((yyvsp[(1) - (3)].term),list_List((yyvsp[(3) - (3)].term))));
;}
    break;

  case 19:
#line 220 "tptpparser.y"
    { (yyval.term) = term_Create(fol_Or(),(yyvsp[(1) - (1)].list)); ;}
    break;

  case 20:
#line 221 "tptpparser.y"
    { (yyval.term) = term_Create(fol_And(),(yyvsp[(1) - (1)].list)); ;}
    break;

  case 21:
#line 225 "tptpparser.y"
    { (yyval.list) = list_Cons((yyvsp[(1) - (3)].term),list_List((yyvsp[(3) - (3)].term))); ;}
    break;

  case 22:
#line 226 "tptpparser.y"
    { (yyval.list) = list_Cons((yyvsp[(1) - (3)].term),(yyvsp[(3) - (3)].list)); ;}
    break;

  case 23:
#line 230 "tptpparser.y"
    { (yyval.list) = list_Cons((yyvsp[(1) - (3)].term),list_List((yyvsp[(3) - (3)].term))); ;}
    break;

  case 24:
#line 231 "tptpparser.y"
    { (yyval.list) = list_Cons((yyvsp[(1) - (3)].term),(yyvsp[(3) - (3)].list)); ;}
    break;

  case 25:
#line 235 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 26:
#line 236 "tptpparser.y"
    {  (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 27:
#line 237 "tptpparser.y"
    { (yyval.term) = tptp_NormalizeLiterals((yyvsp[(1) - (1)].term),FALSE); ;}
    break;

  case 28:
#line 238 "tptpparser.y"
    { (yyval.term) = (yyvsp[(2) - (3)].term); ;}
    break;

  case 29:
#line 242 "tptpparser.y"
    {
  (yyval.term) = fol_CreateQuantifier((yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].list), list_List((yyvsp[(6) - (6)].term)));              
;}
    break;

  case 30:
#line 248 "tptpparser.y"
    { (yyval.list) = list_List((yyvsp[(1) - (1)].term)); ;}
    break;

  case 31:
#line 249 "tptpparser.y"
    { (yyval.list) = list_Cons((yyvsp[(1) - (3)].term),(yyvsp[(3) - (3)].list)); ;}
    break;

  case 32:
#line 253 "tptpparser.y"
    { (yyval.term) = term_Create((yyvsp[(1) - (2)].symbol),list_List((yyvsp[(2) - (2)].term))); ;}
    break;

  case 33:
#line 257 "tptpparser.y"
    { (yyval.term) = term_Create(fol_Or(),(yyvsp[(2) - (3)].list)); ;}
    break;

  case 34:
#line 258 "tptpparser.y"
    { (yyval.term) = term_Create(fol_Or(),(yyvsp[(1) - (1)].list)); ;}
    break;

  case 35:
#line 262 "tptpparser.y"
    { (yyval.list) = list_List((yyvsp[(1) - (1)].term)); ;}
    break;

  case 36:
#line 263 "tptpparser.y"
    { (yyval.list) = list_Cons((yyvsp[(1) - (3)].term),(yyvsp[(3) - (3)].list)); ;}
    break;

  case 37:
#line 267 "tptpparser.y"
    { (yyval.term) = tptp_NormalizeLiterals((yyvsp[(1) - (1)].term),FALSE); ;}
    break;

  case 38:
#line 268 "tptpparser.y"
    { (yyval.term) = tptp_NormalizeLiterals((yyvsp[(2) - (2)].term),TRUE); ;}
    break;

  case 39:
#line 273 "tptpparser.y"
    { (yyval.symbol) = fol_All(); ;}
    break;

  case 40:
#line 274 "tptpparser.y"
    { (yyval.symbol) = fol_Exist(); ;}
    break;

  case 41:
#line 278 "tptpparser.y"
    { (yyval.symbol) = fol_Equiv(); ;}
    break;

  case 42:
#line 279 "tptpparser.y"
    { (yyval.symbol) = fol_Implies(); ;}
    break;

  case 43:
#line 280 "tptpparser.y"
    { (yyval.symbol) = fol_Implied(); ;}
    break;

  case 44:
#line 281 "tptpparser.y"
    { (yyval.symbol) = fol_Xor(); ;}
    break;

  case 45:
#line 282 "tptpparser.y"
    { (yyval.symbol) = fol_Nor(); ;}
    break;

  case 46:
#line 283 "tptpparser.y"
    { (yyval.symbol) = fol_Nand(); ;}
    break;

  case 47:
#line 287 "tptpparser.y"
    {
  (yyval.symbol) = fol_Not();
;}
    break;

  case 48:
#line 293 "tptpparser.y"
    {
  (yyval.term) = tptp_HandleAtomic((yyvsp[(1) - (1)].term));
;}
    break;

  case 49:
#line 296 "tptpparser.y"
    {
  (yyval.term) = tptp_HandleAtomic((yyvsp[(1) - (1)].term));
;}
    break;

  case 50:
#line 299 "tptpparser.y"
    {
  (yyval.term) = tptp_HandleAtomic((yyvsp[(1) - (1)].term));
;}
    break;

  case 51:
#line 305 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 52:
#line 309 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 53:
#line 310 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 54:
#line 314 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 55:
#line 318 "tptpparser.y"
    {
  (yyval.term) = term_Create((yyvsp[(2) - (3)].symbol),list_Cons((yyvsp[(1) - (3)].term),list_List((yyvsp[(3) - (3)].term))));
;}
    break;

  case 56:
#line 324 "tptpparser.y"
    { (yyval.symbol) = fol_Equality(); ;}
    break;

  case 57:
#line 325 "tptpparser.y"
    { (yyval.symbol) = fol_NonEquality(); ;}
    break;

  case 58:
#line 329 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 59:
#line 333 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 60:
#line 334 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 61:
#line 338 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 62:
#line 339 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 63:
#line 340 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 64:
#line 344 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 65:
#line 345 "tptpparser.y"
    {			  
  (yyval.term) = tptp_TermCreate(tptp_GetSymbol((yyvsp[(1) - (4)].string),list_Length((yyvsp[(3) - (4)].list)),TPTP_ORDINARY),(yyvsp[(3) - (4)].list));
;}
    break;

  case 66:
#line 351 "tptpparser.y"
    {		     
  (yyval.term) = tptp_TermCreate(tptp_GetSymbol((yyvsp[(1) - (1)].string),0,TPTP_ORDINARY),list_Nil());
;}
    break;

  case 67:
#line 357 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 68:
#line 361 "tptpparser.y"
    {
  (yyval.term) = tptp_TermCreate(tptp_GetSymbol((yyvsp[(1) - (1)].string),0,TPTP_DEFINED),list_Nil());
;}
    break;

  case 69:
#line 364 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 70:
#line 368 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 71:
#line 369 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 72:
#line 373 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 73:
#line 377 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 74:
#line 378 "tptpparser.y"
    {			 
  (yyval.term) = tptp_TermCreate(tptp_GetSymbol((yyvsp[(1) - (4)].string),list_Length((yyvsp[(3) - (4)].list)),TPTP_DEFINED),(yyvsp[(3) - (4)].list));
;}
    break;

  case 75:
#line 384 "tptpparser.y"
    {
  (yyval.term) = tptp_TermCreate(tptp_GetSymbol((yyvsp[(1) - (1)].string),0,TPTP_DEFINED),list_Nil());					 	                
;}
    break;

  case 76:
#line 390 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 77:
#line 394 "tptpparser.y"
    { (yyval.term) = (yyvsp[(1) - (1)].term); ;}
    break;

  case 78:
#line 395 "tptpparser.y"
    {
  (yyval.term) = tptp_TermCreate(tptp_GetSymbol((yyvsp[(1) - (4)].string),list_Length((yyvsp[(3) - (4)].list)),TPTP_SYSTEM),(yyvsp[(3) - (4)].list));
;}
    break;

  case 79:
#line 401 "tptpparser.y"
    {
  (yyval.term) = tptp_TermCreate(tptp_GetSymbol((yyvsp[(1) - (1)].string),0,TPTP_SYSTEM),list_Nil()); 
;}
    break;

  case 80:
#line 407 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 81:
#line 411 "tptpparser.y"
    { (yyval.term) = tptp_VarTermCreate((yyvsp[(1) - (1)].string));	;}
    break;

  case 82:
#line 415 "tptpparser.y"
    { (yyval.list) = list_List((yyvsp[(1) - (1)].term)); ;}
    break;

  case 83:
#line 416 "tptpparser.y"
    {
  (yyval.list) = list_Cons((yyvsp[(1) - (3)].term), (yyvsp[(3) - (3)].list));
;}
    break;

  case 84:
#line 422 "tptpparser.y"
    { /*unsupported yet*/ ;}
    break;

  case 85:
#line 426 "tptpparser.y"
    { /*unsupported yet*/;}
    break;

  case 86:
#line 427 "tptpparser.y"
    { /*unsupported yet*/;}
    break;

  case 87:
#line 431 "tptpparser.y"
    { /*unsupported yet*/;}
    break;

  case 88:
#line 435 "tptpparser.y"
    {
  tptp_HandleInclude((yyvsp[(3) - (6)].string),(yyvsp[(4) - (6)].list)); /*Handling is also responsible for freeing the strings, so we have nothing to pass on.*/
;}
    break;

  case 89:
#line 441 "tptpparser.y"
    { (yyval.list) = (yyvsp[(3) - (4)].list); ;}
    break;

  case 90:
#line 442 "tptpparser.y"
    { (yyval.list) = list_Nil(); ;}
    break;

  case 91:
#line 446 "tptpparser.y"
    { (yyval.list) = list_List((yyvsp[(1) - (1)].string)); ;}
    break;

  case 92:
#line 447 "tptpparser.y"
    {
  (yyval.list) = list_Cons((yyvsp[(1) - (3)].string),(yyvsp[(3) - (3)].list));
;}
    break;

  case 93:
#line 453 "tptpparser.y"
    { /*unsupported yet*/;}
    break;

  case 94:
#line 454 "tptpparser.y"
    { /*unsupported yet*/;}
    break;

  case 95:
#line 455 "tptpparser.y"
    { /*unsupported yet*/;}
    break;

  case 96:
#line 459 "tptpparser.y"
    { string_StringFree((yyvsp[(1) - (1)].string)); /*unsupported yet*/;}
    break;

  case 97:
#line 460 "tptpparser.y"
    { string_StringFree((yyvsp[(1) - (4)].string)); /*unsupported yet*/;}
    break;

  case 98:
#line 461 "tptpparser.y"
    { term_Delete((yyvsp[(1) - (1)].term)); /*unsupported yet*/;}
    break;

  case 99:
#line 462 "tptpparser.y"
    { string_StringFree((yyvsp[(1) - (1)].string)); /*unsupported yet*/;}
    break;

  case 100:
#line 463 "tptpparser.y"
    { string_StringFree((yyvsp[(1) - (1)].string)); /*unsupported yet*/;}
    break;

  case 101:
#line 464 "tptpparser.y"
    { /*unsupported yet*/;}
    break;

  case 102:
#line 468 "tptpparser.y"
    { term_Delete((yyvsp[(3) - (4)].term)); /*unsupported yet*/;}
    break;

  case 103:
#line 469 "tptpparser.y"
    { term_Delete((yyvsp[(3) - (4)].term)); /*unsupported yet*/;}
    break;

  case 104:
#line 470 "tptpparser.y"
    { term_Delete((yyvsp[(3) - (4)].term)); /*unsupported yet*/;}
    break;

  case 105:
#line 474 "tptpparser.y"
    {/*unsupported yet*/;}
    break;

  case 106:
#line 475 "tptpparser.y"
    {/*unsupported yet*/;}
    break;

  case 107:
#line 479 "tptpparser.y"
    {/*unsupported yet*/;}
    break;

  case 108:
#line 480 "tptpparser.y"
    {/*unsupported yet*/;}
    break;

  case 109:
#line 484 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 110:
#line 485 "tptpparser.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 111:
#line 489 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 112:
#line 490 "tptpparser.y"
    { (yyval.string) = tptp_StripQuotes((yyvsp[(1) - (1)].string));;}
    break;

  case 113:
#line 494 "tptpparser.y"
    {	(yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 114:
#line 498 "tptpparser.y"
    {	(yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 115:
#line 502 "tptpparser.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 116:
#line 503 "tptpparser.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 117:
#line 504 "tptpparser.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 118:
#line 508 "tptpparser.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string);;}
    break;

  case 119:
#line 512 "tptpparser.y"
    { ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2292 "tptpparser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 515 "tptpparser.y"


static HASHMAP tptp_dfg_reserved_speedup = NULL;

#define TPTP_DFG_RESERVED_SIZE (85)
static const char * const tptp_dfg_reserveds[TPTP_DFG_RESERVED_SIZE] = {
  /*BEGIN RESERVED*/
  "and",
  "author",				
  "axioms",				
  "begin_problem",
  "by",
  "box",
  "all",
  "clause",
  "cnf",
  "comp",
  "conjectures",
  "conv",
  "date",
  "description",
  "dia",
  "some",
  "div",
  "dnf",
  "domain",
  "domrestr",
  "eml",
  "EML",
  "DL",
  "end_of_list",
  "end_problem",
  "equal",
  "equiv",
  "exists",
  "false",
  "forall",
  "formula",
  "freely",
  "functions",
  "generated",
  "hypothesis",
  "id",
  "implied",
  "implies",
  "list_of_clauses",
  "list_of_declarations",
  "list_of_descriptions",
  "list_of_formulae",
  "list_of_general_settings",
  "list_of_proof",
  "list_of_settings",
  "list_of_special_formulae",
  "list_of_symbols",
  "list_of_terms",
  "list_of_includes",
  "include",
  "logic",
  "name",
  "not",
  "operators",
  "or",
  "prop_formula",
  "concept_formula",
  "predicate",
  "predicates",
  "quantifiers",
  "ranrestr",
  "range",
  "rel_formula",
  "role_formula",
  "satisfiable",
  "set_DomPred",
  "set_flag",
  "set_precedence",
  "set_ClauseFormulaRelation",
  "set_selection",
  "sort",
  "sorts",
  "status",
  "step",
  "subsort",
  "sum",
  "test",
  "translpairs",
  "true",
  "unknown",
  "unsatisfiable",
  "version",
  "xor",
  "nor",
  "nand"
  /*END RESERVED*/
};

void tptp_Init(void)
/**************************************************************
  EFFECT: Initializes the parsing module.
 (Prepares the table of dfg reserved words for future fast tests)
***************************************************************/
{  
  int i;
  
  tptp_dfg_reserved_speedup = hm_Create(7);
  
  for (i = 0; i < TPTP_DFG_RESERVED_SIZE; i++) {
    hm_Insert(tptp_dfg_reserved_speedup,(POINTER)i,hm_StringHash(tptp_dfg_reserveds[i]));
  }  
}
  
void tptp_Free(void)
/**************************************************************
  EFFECT: Deinitialized the parsing module.
 (Frees the memory used by the table of dfg reserved words)
***************************************************************/
{
  hm_Delete(tptp_dfg_reserved_speedup);
}

static BOOL tptp_VarTermsEqual(POINTER t1, POINTER t2) {
  return symbol_Equal(term_TopSymbol((TERM)t1),term_TopSymbol((TERM)t2));
}
	
static LIST tptp_GetFreeVars(TERM Term)
/**************************************************************
  INPUT:   A term.
  RETURNS: List of free variables of the given term
           (i.e. those not captured by any quantifier).
  DETAILS: 
  Returns list of variable terms as they occur somewhere in the term, 
  the list returned is created (should be freed by caller),
  but its content shouldn't be used to build other terms (sharing!).

  The term itself stays intact.
***************************************************************/
{  
  if (term_IsVariable(Term))
    return list_List(Term);

  if (fol_IsQuantifier(term_TopSymbol(Term))) {
    LIST quant_vars, vars_in_subterms;

    quant_vars       = fol_QuantifierVariables(Term);
    vars_in_subterms = tptp_GetFreeVars(term_SecondArgument(Term));

    return list_NDifference(vars_in_subterms,quant_vars,tptp_VarTermsEqual);
  }
   
  if (term_IsComplex(Term)) {
    LIST Scan, Result, Subresult;
    Result = list_Nil();
	  
    for (Scan=term_ArgumentList(Term);!list_Empty(Scan);Scan=list_Cdr(Scan)) {
      Subresult = tptp_GetFreeVars(list_Car(Scan));
      Result    = list_NUnion(Subresult,Result,tptp_VarTermsEqual);
    }

    return Result;
  }

  return list_Nil();
}

static POINTER tptp_CopyVarTerm(POINTER p) {
  return term_Create(term_TopSymbol((TERM)p),list_Nil());
}

static TERM tptp_CheckClosedness(TERM formula, BOOL repair) 
/**************************************************************
  INPUT:   A formula and a repair flag.
  RETURNS: The same formula (possilby modified).
  EFFECT: 
  Checks if a given formula is closed (every variable captured by a quantifier).
  If not, universal closure is returned (if repair flag is true)
      otherwise an error is reported!
***************************************************************/
{
  LIST free_vars;

  free_vars = tptp_GetFreeVars(formula);
  
  if (!list_Empty(free_vars)) {
    if (repair) {
      list_NMapCar(free_vars,tptp_CopyVarTerm);
      return fol_CreateQuantifier(fol_All(),free_vars,list_List(formula));
    } else {
      list_Delete(free_vars);
      misc_StartUserErrorReport();
      misc_UserErrorReport("Free variable occurence near line %d!\n",tptp_lineno);
      misc_FinishUserErrorReport();
    }
  }
  
  return formula;
}

static char* tptp_NewlinedAppend(char * first, const char * second) {
  char* res;

  res = memory_Malloc(strlen(first) + strlen(second) + 2);
   
  strcpy(res, first);
  strcat(res,"\n");
  strcat(res,second);

  string_StringFree(first);
		 
  return res;
}

static void tptp_HandleComments(char * Comment) 
/**************************************************************
  INPUT:   A comment string.
  RETURNS: void.
  SUMMARY:   
  Takes care of reading some useful information from the comments
    that appear in the file.
  MEMORY: Frees the given string.
***************************************************************/
{
  char* str;
	
  if (!(tptp_StatusRead) && strstr(Comment,"Status")) {
    if (strstr(Comment,"Unsatisfiable"))
      tptp_Description->status = DFG_UNSATISFIABLE;
    else if (strstr(Comment,"Satisfiable"))
      tptp_Description->status = DFG_SATISFIABLE;
    else if (strstr(Comment,"Theorem"))
      tptp_Description->status = DFG_UNSATISFIABLE;
    else
      tptp_Description->status = DFG_UNKNOWNSTATE;
  
    tptp_StatusRead = TRUE;
  }
  
  if (!(tptp_Description->name) && strstr(Comment,"Names")) {
    str = strstr(Comment,": ");
    if (str) {
      str += 2;
      tptp_Description->name = string_StringCopy(str);
    }
  }
  
  if (!(tptp_Description->author) && strstr(Comment,"Source")) {
    str = strstr(Comment,": ");
    if (str) {
      str += 2;
      tptp_Description->author = string_StringCopy(str);
    }	 
  }
   
  if (!(tptp_Description->version) && strstr(Comment,"Version")) {
    str = strstr(Comment,": ");
    if (str) {
      str += 2;
      tptp_Description->version = string_StringCopy(str);
    }	 
  }
  
  if (!tptp_DomainRead && strstr(Comment,"Domain")) {
    str = strstr(Comment,": ");
    if (str) {
      str += 2;

      if (!(tptp_Description->description)) {
        tptp_Description->description = string_StringCopy(str);
      } else {
        tptp_Description->description = tptp_NewlinedAppend(tptp_Description->description,str);
      }

      tptp_DomainRead = TRUE;
    }	 
  }
  
  if (!tptp_ProblemRead && strstr(Comment,"Problem")) {
    str = strstr(Comment,": ");
    if (str) {
      str += 2;

      if (!(tptp_Description->description)) {
	tptp_Description->description = string_StringCopy(str);
      } else {
	tptp_Description->description = tptp_NewlinedAppend(tptp_Description->description,str);
      }

      tptp_ProblemRead = TRUE;
    }	 
  }  
  
  if (tptp_EnglishReading) {
    if ((strlen(Comment) > 3) && (Comment[1] == ' ') && (Comment[2] == ' ') ) {
      int pos;

      pos = 3;
      while (Comment[pos] == ' ')
	pos++;
      tptp_Description->description = tptp_NewlinedAppend(tptp_Description->description,Comment+pos);
    } else {
      tptp_EnglishReading = FALSE;
      tptp_EnglishRead = TRUE;
    }
  }
    
  if (!tptp_EnglishRead && !tptp_EnglishReading && strstr(Comment,"English")) {
    str = strstr(Comment,": ");
    if (str) {
      str += 2;
	  
      if (!(tptp_Description->description)) {
	tptp_Description->description = string_StringCopy(str);
      } else { 
	tptp_Description->description = tptp_NewlinedAppend(tptp_Description->description,str);
      }	  			  
	  
      tptp_EnglishReading = TRUE;
    }	 
  }

  if (tptp_output) {
    fputs(Comment,tptp_output);
    fputs("\n",tptp_output);
  }

  string_StringFree(Comment);
}

static BOOL is_dfg_char(char c) 
/**************************************************************
  INPUT:   A character.
  RETURNS: Whether the given character can be part of dfg identifier.
***************************************************************/
{
  return (((c >= 'a') && (c <= 'z')) || 
	  ((c >= 'A') && (c <= 'Z')) ||
	  ((c >= '0') && (c <= '9')) ||
	  (c == '_'));
}
	
static const char* string_ToFind;
static BOOL tptp_DfgReservedLookupTest(POINTER p) {
  int idx;
  idx = (int)p;
  return string_Equal(string_ToFind,tptp_dfg_reserveds[idx]);  
}

static const char * const tptp_distinguisher = "__dfg";

static char * tptp_Identifierify(char * symbol) 
/**************************************************************
  INPUT:   A string.
  RETURNS: Transformed string.
  SUMMARY: 
  Transforms a string into a dfg identifier by handling unsupported characters
  and adding a special suffix so that the result isn't a dfg keyword accidentally.
  
  MEMORY:  The original string gets freed.
***************************************************************/
{
  POINTER LookupIdx;
  char c;
  int specials, len, big_len;
	
  char * result;	
  char * input;
  char * output;
	
  char tmpbuf[5];
		
  specials = 0;
  len = 0;

  /*count special characters*/
  input = symbol;
  while((c = *input++)) {
    len++;
    if (!is_dfg_char(c))
      specials++;
  }

  if ((len >= strlen(tptp_distinguisher)) &&
      (strstr(symbol + (len-strlen(tptp_distinguisher)),tptp_distinguisher) != NULL)) {
    misc_UserWarning("Symbol '%s' ends with '%s'. A possible ambiguity may arise!\n",symbol,tptp_distinguisher);
  }
	
  /*each special gets expanded by a factor of at most 5 and we also append the suffix in the end*/
  big_len = (len + 5*specials+6);
  result = (char*)memory_Malloc(big_len);
	
  input = symbol;
  output = result;

  while((c = *input++)) {
    if (is_dfg_char(c)) { /*just copy*/
      *output = c;
      output++;
    } else {
      if (output != result) { /*no underscore at the very beginning*/
	*output = '_';
	output++;
      }

      *output = 'a'; /*"a" stands for ascii */
      output++;

      sprintf(tmpbuf,"%d",(int)c);
      *output = '\0';
      strcat(output,tmpbuf);
      output += strlen(tmpbuf);

      *output = '_';
      output++;
    }
  }
	
  *output = '\0';

  string_ToFind = result;
  LookupIdx = hm_Retrieve(tptp_dfg_reserved_speedup,hm_StringHash(result),tptp_DfgReservedLookupTest);
  if (LookupIdx != HASHMAP_NO_RETRIEVE)
    strcat(output,tptp_distinguisher);
	
  string_StringFree(symbol);
	
  /*We probably overestimated the length,
    so lets rather copy again so that we return a string whose memory is just as long as needed*/
  output = result;
  result = string_StringCopy(output);
  memory_Free(output, big_len);

  return result;
}	

static void tptp_HandleFormula(char* name, char* role, TERM formula, BOOL cnf)
/**************************************************************
  INPUT:   Formula name, formula role, the actual formula,
           and boolean flag denoting if the formula is in cnf (a clause).
  RETURNS: Nothing.
  SUMMARY: 
  The formula is stored appropriately according to its tptp role
  and everything else is freed.
***************************************************************/
{
  LIST pair;
  TPTP_FORMULATYPE cur_type;

  cur_type = cnf ? TPTP_CNF : TPTP_FOF;

  if ((tptp_LastFormulaType != TPTP_UNDEF) && (tptp_LastFormulaType != cur_type)) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("File mixes clauses and general first order formulas near line %d!\n",tptp_lineno);
    misc_FinishUserErrorReport();
  }

  tptp_LastFormulaType = cur_type;

  if (tptp_TranslateIdents)
    name = tptp_Identifierify(name); /* so that the formula name doesn't conflict with dfg reserved words */
    
  /*TODO: place some emphasis on the hypothesis formulae or other?*/
  if (string_Equal(role,"axiom") || 
      /*
	%----"axiom"s are accepted, without proof. There is no guarantee that the
	%----axioms of a problem are consistent.
      */
      string_Equal(role,"hypothesis") ||
      /*
	%----"hypothesis"s are assumed to be true for a particular problem, and are
	%----used like "axiom"s.
      */
      string_Equal(role,"lemma" ) ||
      string_Equal(role,"theorem" ) || 
      /*
	"lemma"s and "theorem"s have been proven from the "axiom"s. They can be
	%----used like "axiom"s in problems, and a problem containing a non-redundant
	%----"lemma" or theorem" is ill-formed. They can also appear in derivations.
	%----"theorem"s are more important than "lemma"s from the user perspective.
      */
      string_Equal(role,"definition" ) ||
      /*
	%----"definition"s are used to define symbols, and are used like "axiom"s.
      */
      string_Equal(role,"assumption" )
      /*
	%----"assumption"s can be used like axioms, but must be discharged before a
	%----derivation is complete.
      */
      ) {
    pair        = list_PairCreate(name, formula);
    tptp_Axioms = list_Cons(pair,tptp_Axioms);

  } else if (!strcmp(role,"conjecture")) {
    pair = list_PairCreate(name, formula);

    if (cnf) {
      misc_UserWarning("Formula role 'conjecture' in CNF format - formula skipped near line %d.\n",tptp_lineno);

      string_StringFree(name);
      term_Delete(formula);

    } else {
      tptp_Conjectures = list_Cons(pair,tptp_Conjectures);
    }
   
  } else if (!strcmp(role,"negated_conjecture")){ /*handled exactly the same as "conjecture", but only in cnf mode*/

    if (cnf) {
      pair = list_PairCreate(name, formula);
      
      tptp_Conjectures = list_Cons(pair, tptp_Conjectures);
    } else {
      misc_UserWarning("Formula role 'negated_conjecture' in FOF format - formula skipped near line %d.\n",tptp_lineno);
      
      string_StringFree(name);
      term_Delete(formula);    
    }
  } else {
    misc_UserWarning("Unknown formula role: %s - formula skipped near line %d.\n",role,tptp_lineno);

    string_StringFree(name);
    term_Delete(formula);    
  }

  string_StringFree(role);

  tptp_RestartVarList();
}

static TERM tptp_NormalizeLiterals(TERM term, BOOL negate)
/**************************************************************
  INPUT: A term and a flag denoting if the term should be negated.
  RETURNS: The transformed term.
  SUMMARY: 
  Resolves the problem of having negated equality sign as atomic formula in tptp.
  When creating a literal we either delete double negation, or add only one.
  The resulting thing doesn't contain "nequal" any more.
***************************************************************/
{
  BOOL negated_inside;
  SYMBOL main_symbol;

  main_symbol = term_TopSymbol(term);
          
  if (symbol_Equal(main_symbol,fol_NonEquality())) { /*it is negated already*/
    negated_inside = TRUE;

    term_RplacTop(term,fol_Equality());
  } else {
    negated_inside = FALSE;
  }

  if ((negate && !negated_inside)||(!negate && negated_inside)) {
    return term_Create(fol_Not(),list_List(term));                    
  } else
    return term;
}

static TERM tptp_HandleAtomic(TERM Atom)
/**************************************************************
  INPUT: A term to become an atominc formula.
  RETURNS: The same term.
  SUMMARY: Ensures that the outermost symbol is a predicate symbol
    and the inner ones are function symbols. 
***************************************************************/
{
  SYMBOL s;

  s = term_TopSymbol(Atom);

  if (!symbol_IsPredicate(s)) {    
    if (symbol_Fixed(s)) {
      misc_StartUserErrorReport();
      misc_UserErrorReport("Parse error near line %d - '%s' is not a predicate!\n", tptp_lineno,symbol_Name(s));	  	      
      misc_FinishUserErrorReport();
    } else {
      /* First occurrence, so change it to a predicate */
      s = symbol_ChangeType(s, symbol_PREDICATE);      
      term_RplacTop(Atom, s);
    }
  }   

  return Atom;
}

static __inline__ void tptp_CheckArity(SYMBOL s, int ArgNum, const char* Name) {   
  if (symbol_Arity(s) != ArgNum) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("Symbol '%s/%d' used with different arity on line %d.\n", Name, symbol_Arity(s),tptp_lineno);
    misc_FinishUserErrorReport();
  }
}

static SYMBOL tptp_GetSymbol(char * Name, int ArgNum, TPTP_SYMBOLKIND Kind)
/**************************************************************
  INPUT: A string name (which might not be a valid dfg identifier),
         number of arguments,
         and a kind (denoting where it comes from in the parse tree).
  RETURNS: A symbol to represent the described object.
  MEMORY: The Name string gets freed.	
***************************************************************/
{
	
  SYMBOL s;
	
  if (Kind != TPTP_ORDINARY) { /*We have something special*/
    if (Kind == TPTP_DEFINED) {
      if (string_Equal(Name,"$true")) {
	s = fol_True();
	tptp_CheckArity(s,ArgNum,Name);
        string_StringFree(Name);
        return s;
      }

      if (string_Equal(Name,"$false")) {
	s = fol_False();
	tptp_CheckArity(s,ArgNum,Name);
        string_StringFree(Name);
        return s;
      }
			
      misc_UserWarning("defined_functor '%s' encountered near line %d - treated as normal one!\n", Name, tptp_lineno);			
    } else if (Kind == TPTP_SYSTEM) {
      misc_UserWarning("system_functor '%s' encountered near line %d - treated as normal one!\n", Name, tptp_lineno);			
    }			
  }

  if (tptp_TranslateIdents)
    Name = tptp_Identifierify(Name);

  if (Kind != TPTP_ORDINARY)
    misc_UserWarning("(translated to '%s')\n", Name);
	
  s = symbol_Lookup(Name);
  if (s == 0)
    s = symbol_CreateFunction(Name, ArgNum, symbol_STATLEX,
			      tptp_PRECEDENCE);

  tptp_CheckArity(s,ArgNum,Name);

  string_StringFree(Name);    /* was copied by symbol_CreateFunction */

  return s;
}

static TERM tptp_TermCreate(SYMBOL s, LIST Arguments)
{
  TERM   result;

  result = term_Create(s, Arguments);
  tptp_CheckArguments(result);
  
  return result;
}

static void tptp_HandleInclude(char * incl, LIST selection)
/**************************************************************
  INPUT: A string - file to include
         A list of strings - formula selection.         
  RETURNS: Nothing.
  EFFECT:
  Called when include section is resolved.
  A touple of the file name and the formula selection list
  is added to the includes list.
***************************************************************/
{
  LIST pair;

  pair          = list_PairCreate(incl,selection);
  tptp_Includes = list_Cons(pair,tptp_Includes);
}
	
  
static char * tptp_StripQuotes(char * str)
/**************************************************************
  INPUT: A string.
  RETURNS: A modifed string.
  EFFECT:
    Gets rid of leading and trailing qoutes of a string.
  MEMORY: Returns a newly allocated thing and frees the one destroyed.
***************************************************************/
{
  char * newstr;
  int len;

  len        = strlen(str);    
  str[len-1] = '\0'; /*one characer shorter from end*/

  newstr = string_StringCopy(str+1);    /*start duplicating from the second char*/

  memory_Free(str,len+1);

  return newstr;
}

void yyerror(const char *s )
/*Called by flex/bison when an error occurs*/
{ 
  misc_StartUserErrorReport();
  misc_UserErrorReport("%s on line %d at item \"%s\".\n", s, tptp_lineno, tptp_text);
  misc_FinishUserErrorReport();   
}

FILE* tptp_OpenFile(const char * FileName, char ** const DiscoveredName)
/**************************************************************
  INPUT: A string filename, and a pointer to char pointer
           to hold the fullpath name of the file 
           that was opened in the end (can be null).
  RETURNS: A opened file.
  EFFECT:
  Opens a file for reading.
  The file is searched for using the extended search mechanism
  wrt TPTP environment variable.
***************************************************************/
{
  return misc_OpenFileEnv(FileName,"r","TPTP",DiscoveredName);
}
 
static LIST tptp_TestList; /* list of strings used in nonmember tests */
	
static BOOL tptp_LabelFormulaPairIsNonmember(POINTER pair) {
  if (list_PairFirst(pair) == NULL)
    return TRUE;
	
  return !list_Member(tptp_TestList,list_PairFirst(pair),(BOOL (*)(POINTER, POINTER))string_Equal);
}

void tptp_DeleteLabelTermPair(POINTER pair) 
{
  term_Delete(list_PairSecond(pair));	
  if (list_PairFirst(pair) != NULL)
    string_StringFree(list_PairFirst(pair));  /* Free the label */
  list_PairFree(pair);  
}

LIST tptp_TPTPParser(FILE* File, FLAGSTORE Flags, PRECEDENCE Precedence, DFGDESCRIPTION Description,
		     LIST* Axioms, LIST* Conjectures, LIST* SortDecl,
		     LIST* UserDefinedPrecedence, LIST* UserDefinedSelection,
		     LIST* ClAxRelation, BOOL* HasPlainClauses)
/**************************************************************
  A stub around the real parser that takes care of following
  include directives.
  
  NOTE: This function is almost the same as dfg_DFGParser form dfgparser.y
    any change in its implementation should propably be also propagated there.
***************************************************************/
{
  LIST Includes, Clauses;
  LIST FilesRead;
  DFGDESCRIPTION description_dummy;
  TPTP_FORMULATYPE old_LastFormulaType;

  FilesRead = list_Nil();
  Includes = list_Nil();	

  Clauses = tptp_TPTPParserIncludesExplicit(File,Flags,Precedence,Description,Axioms,Conjectures,SortDecl,UserDefinedPrecedence,UserDefinedSelection,ClAxRelation,&Includes,HasPlainClauses);
	
  while (list_Exist(Includes)) {
    LIST pair;
    char* filename;
    LIST selection;

    pair      = list_Top(Includes);
    filename  = (char*)list_PairFirst(pair);
    selection = (LIST)list_PairSecond(pair);
    list_PairFree(pair);
    Includes = list_Pop(Includes);
		
    if (list_Member(FilesRead,filename,(BOOL (*)(POINTER, POINTER))string_Equal)) {
      misc_UserWarning("File %s already included, skipped!\n",filename);
      string_StringFree(filename);
    } else {
      LIST Axs, Conjs, Cls, UDS, CAR;
      BOOL HPC;
      FILE* FileToInclude;
				
      FileToInclude = tptp_OpenFile(filename,NULL);

      Axs = Conjs = UDS = CAR = list_Nil();

      old_LastFormulaType = tptp_LastFormulaType;

      description_dummy = desc_Create();
      Cls = tptp_TPTPParserIncludesExplicit(FileToInclude, Flags, Precedence, description_dummy, &Axs, &Conjs, SortDecl, UserDefinedPrecedence, &UDS, &CAR, &Includes, &HPC);
      desc_Delete(description_dummy);

      if ((old_LastFormulaType != TPTP_UNDEF) &&
          (tptp_LastFormulaType != TPTP_UNDEF) &&
          (old_LastFormulaType != tptp_LastFormulaType)) {
	misc_StartUserErrorReport();
	misc_ErrorReport("Clauses and general first order formulas mixed across includes!\n");
	misc_FinishUserErrorReport();
      }

      if (old_LastFormulaType != TPTP_UNDEF) { /*the last thing was more specific than current*/
        tptp_LastFormulaType = old_LastFormulaType; /*if we override non-undef then only with the same value that was there already*/
      }
          
      if (list_Exist(selection)) { /*use the selection to filter Axs and Conjs */
        dfg_FilterClausesBySelection(&Cls,&CAR,selection);
        
        /* filtering Axs and Conjs */
	tptp_TestList = selection;
	Axs = list_DeleteElementIfFree(Axs,tptp_LabelFormulaPairIsNonmember,tptp_DeleteLabelTermPair);
	Conjs = list_DeleteElementIfFree(Conjs,tptp_LabelFormulaPairIsNonmember,tptp_DeleteLabelTermPair);
      }

      Clauses = list_Nconc(Clauses, Cls);

      *Axioms = list_Nconc(*Axioms,Axs);
      *Conjectures = list_Nconc(*Conjectures,Conjs);

      /* "Summing up" UserDefinedSelection and ClAxRelation from all the files inluded. */
      *UserDefinedSelection = list_Nconc(*UserDefinedSelection, UDS);
      *ClAxRelation = list_Nconc(*ClAxRelation, CAR);

      /*The whole thing has plain clauses only if all the files have!*/			
      if (!HPC)
	*HasPlainClauses = FALSE;

      misc_CloseFile(FileToInclude,filename);
      FilesRead = list_Cons(filename,FilesRead);
    }

    list_DeleteWithElement(selection,(void (*)(POINTER))string_StringFree);		
  }
		
  list_DeleteWithElement(FilesRead,(void (*)(POINTER))string_StringFree);		
  return Clauses;
}

LIST tptp_TPTPParserIncludesExplicit(FILE* File, FLAGSTORE Flags, PRECEDENCE Precedence, DFGDESCRIPTION Description,
				     LIST* Axioms, LIST* Conjectures, LIST* SortDecl,
				     LIST* UserDefinedPrecedence, LIST* UserDefinedSelection,
				     LIST* ClAxRelation, LIST* Includes, BOOL* HasPlainClauses)
/**************************************************************
  INPUT:   The input file containing clauses or formulae in TPTP syntax,
           a flag store, a precedence used to memorize settings
	       from the file, and Description to store problem description.
           Axioms, Conjectures, SortDecl, UserDefinedPrecedence
           UserDefinedSelection, and ClAxRelation, and Includes are
	   pointers to lists used as return values.
           HasPlainClauses is a return value to indicate if
           the problem had clauses in the plain format.
  RETURNS: The list of clauses from File.
  EFFECT:  Reads formulae and clauses from the input file.
           The axioms, conjectures, sort declarations, user-defined
	   precedences, and includes are appended to the respective lists,
       the lists are not deleted!
	   The Includes list contains pairs (filename, selection),
	   where selection is a list of names of formulas chosen to include.
	   All lists contain pairs
	   (label, term), where <label> may be NULL, if no
	   label was specified for that term.
	   <UserDefinedPrecedence> contains symbols sorted by decreasing
	   precedence. This list will only be changed, if the precedence
	   is explicitly defined in the input file. This can be done
	   by the 'set_precedence' flag in the SPASS settings list in
	   the DFG input file.
           <UserDefinedSelection> is set to a list of predicates to be
           selected in clause inferences by the 'set_selection' flag
           <ClAxRelation> is set to a clause, axiom relation where the
           clauses are given by their number, the axioms by name (string)
  NOTE: This funtions reads a tptp file and returns things like if it read
        a dfg file. Results concerning features not supported in tptp are 
        returned via empty lists and so on.
***************************************************************/
{
  LIST Clauses;

  tptp_PRECEDENCE = Precedence;
  tptp_VARLIST    = list_Nil();  
    	  
  tptp_Description = Description;
  tptp_LastFormulaType = TPTP_UNDEF; /*No formula read yet.*/
	  
  /*For parsing comments.*/
  tptp_StatusRead     = FALSE;
  tptp_DomainRead     = FALSE;
  tptp_ProblemRead    = FALSE;
  tptp_EnglishRead    = FALSE;
  tptp_EnglishReading = FALSE;	  
	  
  tptp_Axioms      = list_Nil();
  tptp_Conjectures = list_Nil();
  tptp_Includes    = list_Nil();
    
  tptp_in = File;

  yyparse();

  tptp_output          = NULL;    /*keep it in a consistent state - preserve the dafault for next time*/
  tptp_TranslateIdents = TRUE;    /*keep it in a consistent state - preserve the dafault for next time*/
  
  /*Axioms and conjectures and includes are now in opposite order than in the original file - let's reverse them back*/
  tptp_Axioms = list_NReverse(tptp_Axioms);
  tptp_Conjectures = list_NReverse(tptp_Conjectures);
  tptp_Includes = list_NReverse(tptp_Includes);
  
  if (tptp_WasParsingCNF()) { 
    dfg_CreateClausesFromTerms(&tptp_Axioms,&tptp_Conjectures,ClAxRelation,TRUE,Flags,Precedence);
    Clauses = list_Nconc(tptp_Axioms, tptp_Conjectures);
    tptp_Axioms = list_Nil();
    tptp_Conjectures = list_Nil();
  } else
    Clauses = list_Nil();
      
  *Axioms = list_Nconc(*Axioms,tptp_Axioms);
  *Conjectures = list_Nconc(*Conjectures,tptp_Conjectures);
  *Includes = list_Nconc(*Includes,tptp_Includes);

  /* Cleanup */  
  tptp_RestartVarList();

  *HasPlainClauses = FALSE;  
  
  return Clauses;
}

BOOL tptp_WasParsingCNF(void)
/**************************************************************
  RETURNS:
    Whether the last parsing parsed only clauses (TRUE)
      or even first full order formulae (FALSE)      
***************************************************************/
{
  return (tptp_LastFormulaType == TPTP_CNF); /* else it was undef (and nothing was read) or fof*/
}

void tptp_SetParserOutput(FILE* output)
/**************************************************************
  INPUT:
   A opened file to be used for outputting comments.
  EFFECT:
  The parser will output encountered header comments to this file.
  This function need not be called
   - then the parser will not output anything.
***************************************************************/
{
  tptp_output = output;
}

void tptp_SetDoTranslateIdents(BOOL flag)
/**************************************************************
  INPUT:
   A boolean flag indicating whether the indentifiers should
    be translated to be "dfg complient".
  EFFECT:
   Sets up the the flag for the next parser invocation.
   By default, the indentifiers will get translated.  
***************************************************************/
{
  tptp_TranslateIdents = flag;
}

static TERM tptp_VarTermCreate(char* Name)
{
  SYMBOL s;

  s = tptp_VarLookup(Name);
  return term_Create(s, list_Nil());
}

static void tptp_CheckArguments(TERM Term)
{
  LIST scan;
  SYMBOL argsymbol;

  for (scan = term_ArgumentList(Term); !list_Empty(scan); scan = list_Cdr(scan)) {
    argsymbol = term_TopSymbol(list_Car(scan));
    if (symbol_IsPredicate(argsymbol)) {
      misc_StartUserErrorReport();
      misc_UserErrorReport("Term '%s' has predicate term '%s' as argument near line %d\n", 
			   symbol_Name(term_TopSymbol(Term)), symbol_Name(argsymbol), tptp_lineno);            
      misc_FinishUserErrorReport();
    }
    if (!symbol_IsVariable(argsymbol)) {
      symbol_SetFixed(argsymbol,TRUE); /*it is a function a it should remain one*/
    }
  }
}

/**************************************************************/
/* Functions for the Variable Table                           */
/**************************************************************/

typedef struct {
  char*  name;
  SYMBOL symbol;
} TPTP_VARENTRY, *TPTP_VARIABLE;

static __inline__ char* tptp_VarName(TPTP_VARIABLE Entry)
{
  return Entry->name;
}

static __inline__ SYMBOL tptp_VarSymbol(TPTP_VARIABLE Entry)
{
  return Entry->symbol;
}

static SYMBOL tptp_VarCreate(char* Name)
{
  TPTP_VARIABLE item;

  item         = (TPTP_VARIABLE) memory_Malloc(sizeof(TPTP_VARENTRY));
  item->name   = Name;
  item->symbol = symbol_CreateStandardVariable();
  tptp_VARLIST = list_Cons(item, tptp_VARLIST);

  return item->symbol;
}

static void tptp_VarFree(TPTP_VARIABLE Entry)
{
  string_StringFree(Entry->name);
  memory_Free(Entry, sizeof(TPTP_VARENTRY));
}

static void tptp_RestartVarList(void)
{
  list_DeleteWithElement(tptp_VARLIST, (void (*)(POINTER))tptp_VarFree);
  tptp_VARLIST = list_Nil();
  symbol_ResetStandardVarCounter();
}

static SYMBOL tptp_VarLookup(char* Name)
/**************************************************************
  INPUT:   A variable name.
  RETURNS: The corresponding variable symbol.
  EFFECT:  If the variable name occurred before, the corresponding
           symbol is returned and the <Name> is freed.
           If the variable name didn't occur
           a new variable is created.
	   Every occurrence of the special variable "_" generates
           a new variable symbol.
***************************************************************/
{
  LIST scan;

  if (!string_Equal(Name, "_")) {
    for (scan = tptp_VARLIST; !list_Empty(scan); scan = list_Cdr(scan)) {
      if (string_Equal(Name, tptp_VarName(list_Car(scan)))) {
	string_StringFree(Name);
	return tptp_VarSymbol(list_Car(scan));
      }
    }
  }
  /* Create a new variable */
  return tptp_VarCreate(Name);
}


