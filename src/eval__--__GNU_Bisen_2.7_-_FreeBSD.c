/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 11 "eval.y"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disasm.h"
#include "estruct.h"
#include "etc.h"
#include "fpconv.h"
#include "generate.h"	/* symset */
#include "global.h"
#include "hex.h"	/* strend */
#include "label.h"
#include "labelfile.h"
#include "offset.h"	/* depend_address */
#include "table.h"


/*
#define	YYDEBUG	1
*/
#ifdef SELF
extern int	yydebug;
#endif

parse_mode	ParseMode;
char*		Lexptr;
int		Eval_Value;
address		Eval_TableTop;
opesize		Eval_ID;
address		Eval_PC;
int		Eval_Bytes;
char		Eval_ResultString[256];
int		Eval_Break;
int		Eval_Count;

typedef struct {
    boolean	isvalue;
    boolean	registed;
    address	value;
    char*	bufptr;
} expbuf;

static int		yylex (void);
static void		yyerror (char*);
static void		tabledesc (int, opesize);
static unsigned long	peek (address, opesize);
static unsigned long	extend (unsigned long, opesize);
static expbuf*		storestr (char*);
static expbuf*		storeexp (address, int);
static expbuf*		store (expbuf*);
static void		breakjob (unsigned long);
static void		itoxd_by_size (char*, ULONG, opesize);


#define	EXPSTACKSIZE	32
static expbuf*		ExpStack[EXPSTACKSIZE];
static int		ExpStackCounter = 0;



/* Line 371 of yacc.c  */
#line 131 "eval.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _STRING = 258,
     SIZEID = 259,
     FSIZEID = 260,
     NUMBER = 261,
     PEEKB = 262,
     PEEKW = 263,
     PEEKL = 264,
     BREAK = 265,
     EXTW = 266,
     EXTL = 267,
     NOTEQU = 268,
     EQUEQU = 269,
     GE = 270,
     LE = 271,
     OROR = 272,
     ANDAND = 273,
     UNARYMINUS = 274
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 79 "eval.y"

	unsigned long	val;
	char*		str;
	expbuf*		exp;


/* Line 387 of yacc.c  */
#line 197 "eval.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 225 "eval.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNRULES -- Number of states.  */
#define YYNSTATES  89

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    35,     2,     2,
      19,    20,    28,    26,    23,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      13,     2,    14,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    15,    16,
      17,    18,    24,    25,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    13,    16,    22,    24,    29,
      31,    34,    36,    39,    41,    45,    47,    49,    53,    55,
      59,    61,    65,    67,    71,    75,    77,    81,    85,    89,
      93,    95,    99,   103,   105,   109,   113,   117,   120,   123,
     125,   129,   131,   136,   141,   146,   151
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    10,    42,    -1,    38,    -1,    38,    32,
      42,    33,    -1,    38,    40,    -1,    38,    32,    42,    33,
      40,    -1,    39,    -1,    39,    32,    42,    33,    -1,     4,
      -1,    34,     4,    -1,     5,    -1,    34,     5,    -1,    41,
      -1,    40,    23,    41,    -1,     3,    -1,    42,    -1,    21,
      42,    22,    -1,    43,    -1,    42,    24,    43,    -1,    44,
      -1,    43,    25,    44,    -1,    45,    -1,    44,    16,    45,
      -1,    44,    15,    45,    -1,    46,    -1,    45,    13,    46,
      -1,    45,    18,    46,    -1,    45,    14,    46,    -1,    45,
      17,    46,    -1,    47,    -1,    46,    26,    47,    -1,    46,
      27,    47,    -1,    48,    -1,    47,    28,    48,    -1,    47,
      29,    48,    -1,    47,    35,    48,    -1,    27,    48,    -1,
      30,    48,    -1,    49,    -1,    19,    42,    20,    -1,     6,
      -1,     7,    19,    42,    20,    -1,     8,    19,    42,    20,
      -1,     9,    19,    42,    20,    -1,    11,    19,    42,    20,
      -1,    12,    19,    42,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   105,   105,   106,   107,   108,   109,   110,   111,   114,
     115,   118,   119,   122,   123,   126,   127,   128,   131,   132,
     135,   136,   139,   140,   141,   144,   145,   146,   147,   148,
     151,   152,   153,   156,   157,   158,   159,   162,   163,   164,
     167,   168,   169,   170,   171,   172,   173
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_STRING", "SIZEID", "FSIZEID", "NUMBER",
  "PEEKB", "PEEKW", "PEEKL", "BREAK", "EXTW", "EXTL", "'<'", "'>'",
  "NOTEQU", "EQUEQU", "GE", "LE", "'('", "')'", "'{'", "'}'", "','",
  "OROR", "ANDAND", "'+'", "'-'", "'*'", "'/'", "'!'", "UNARYMINUS", "'['",
  "']'", "'@'", "'%'", "$accept", "tabledesc", "sizeid", "fsizeid",
  "exprstring", "str_or_exp", "expr", "logical_AND_expr", "equality_expr",
  "relational_expr", "additive_expr", "mul_expr", "factor", "element", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    60,    62,   268,   269,   270,   271,    40,
      41,   123,   125,    44,   272,   273,    43,    45,    42,    47,
      33,   274,    91,    93,    64,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    37,    38,
      38,    39,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    43,    44,    44,    44,    45,    45,    45,    45,    45,
      46,    46,    46,    47,    47,    47,    47,    48,    48,    48,
      49,    49,    49,    49,    49,    49,    49
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     2,     5,     1,     4,     1,
       2,     1,     2,     1,     3,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     2,     2,     1,
       3,     1,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    11,     0,     0,     0,     3,     7,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     2,    18,    20,
      22,    25,    30,    33,    39,    10,    12,     1,    15,     0,
       0,     5,    13,    16,     0,     0,     0,     0,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    19,    21,    24,    23,
      26,    28,    29,    27,    31,    32,    34,    35,    36,    17,
       4,    14,     8,    42,    43,    44,    45,    46,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    31,    32,    33,    18,    19,    20,
      21,    22,    23,    24
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -21
static const yytype_int8 yypact[] =
{
      -2,   -21,   -21,    78,    29,     9,    44,   -10,   -21,    38,
      47,    62,    64,    75,    78,    78,    78,    -7,    70,    -9,
       2,    22,   -17,   -21,   -21,   -21,   -21,   -21,   -21,    78,
      78,    73,   -21,    -7,    78,    78,    78,    78,    78,    78,
       3,   -21,   -21,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    53,   -20,    61,   -19,
       4,     5,     6,    11,    34,   -21,    70,    -9,     2,     2,
      22,    22,    22,    22,   -17,   -17,   -21,   -21,   -21,   -21,
      61,   -21,   -21,   -21,   -21,   -21,   -21,   -21,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,   -21,    18,    42,     7,    56,    57,    33,
      12,    41,   -15,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    42,     1,     2,    43,    43,    45,    46,     3,    27,
      17,    53,    54,    80,    82,    47,    48,    43,    55,    49,
      50,    40,    34,    65,    83,    84,    85,    43,    43,    43,
      43,    86,     4,    25,    26,    43,    56,    57,    76,    77,
      78,    59,    60,    61,    62,    63,    64,    28,    51,    52,
       8,     9,    10,    11,    87,    12,    13,    35,    43,    70,
      71,    72,    73,    14,    28,    29,    36,     8,     9,    10,
      11,    15,    12,    13,    16,    79,    30,    43,    68,    69,
      14,    37,    29,    38,     8,     9,    10,    11,    15,    12,
      13,    16,    74,    75,    39,    44,    58,    14,    88,    66,
      81,    67,     0,     0,     0,    15,     0,     0,    16
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-21)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      15,    16,     4,     5,    24,    24,    15,    16,    10,     0,
       3,    28,    29,    33,    33,    13,    14,    24,    35,    17,
      18,    14,    32,    20,    20,    20,    20,    24,    24,    24,
      24,    20,    34,     4,     5,    24,    29,    30,    53,    54,
      55,    34,    35,    36,    37,    38,    39,     3,    26,    27,
       6,     7,     8,     9,    20,    11,    12,    19,    24,    47,
      48,    49,    50,    19,     3,    21,    19,     6,     7,     8,
       9,    27,    11,    12,    30,    22,    32,    24,    45,    46,
      19,    19,    21,    19,     6,     7,     8,     9,    27,    11,
      12,    30,    51,    52,    19,    25,    23,    19,    80,    43,
      58,    44,    -1,    -1,    -1,    27,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    34,    37,    38,    39,     6,     7,
       8,     9,    11,    12,    19,    27,    30,    42,    43,    44,
      45,    46,    47,    48,    49,     4,     5,     0,     3,    21,
      32,    40,    41,    42,    32,    19,    19,    19,    19,    19,
      42,    48,    48,    24,    25,    15,    16,    13,    14,    17,
      18,    26,    27,    28,    29,    35,    42,    42,    23,    42,
      42,    42,    42,    42,    42,    20,    43,    44,    45,    45,
      46,    46,    46,    46,    47,    47,    48,    48,    48,    22,
      33,    41,    33,    20,    20,    20,    20,    20,    40
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
/* Line 1792 of yacc.c  */
#line 105 "eval.y"
    { breakjob ((yyvsp[(2) - (2)].val)); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 106 "eval.y"
    { tabledesc ( 1, (yyvsp[(1) - (1)].val)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 107 "eval.y"
    { tabledesc ((yyvsp[(3) - (4)].val), (yyvsp[(1) - (4)].val)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 108 "eval.y"
    { tabledesc ( 1, (yyvsp[(1) - (2)].val)); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 109 "eval.y"
    { tabledesc ((yyvsp[(3) - (5)].val), (yyvsp[(1) - (5)].val)); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 110 "eval.y"
    { tabledesc ( 1, (yyvsp[(1) - (1)].val)); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 111 "eval.y"
    { tabledesc ((yyvsp[(3) - (4)].val), (yyvsp[(1) - (4)].val)); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 114 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 115 "eval.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 118 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 119 "eval.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 122 "eval.y"
    { store ((yyvsp[(1) - (1)].exp)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 123 "eval.y"
    { store ((yyvsp[(3) - (3)].exp)); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 126 "eval.y"
    { (yyval.exp) = storestr ((yyvsp[(1) - (1)].str)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 127 "eval.y"
    { (yyval.exp) = storeexp ((address) (yyvsp[(1) - (1)].val), 0); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 128 "eval.y"
    { (yyval.exp) = storeexp ((address) (yyvsp[(2) - (3)].val), 1); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 131 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 132 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) || (yyvsp[(3) - (3)].val); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 135 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 136 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) && (yyvsp[(3) - (3)].val); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 139 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 140 "eval.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) == (yyvsp[(3) - (3)].val)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 141 "eval.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) != (yyvsp[(3) - (3)].val)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 144 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 145 "eval.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) <  (yyvsp[(3) - (3)].val)); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 146 "eval.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) <= (yyvsp[(3) - (3)].val)); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 147 "eval.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) >  (yyvsp[(3) - (3)].val)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 148 "eval.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) >= (yyvsp[(3) - (3)].val)); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 151 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 152 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 153 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 156 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 157 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) * (yyvsp[(3) - (3)].val); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 158 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) / (yyvsp[(3) - (3)].val); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 159 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) % (yyvsp[(3) - (3)].val); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 162 "eval.y"
    { (yyval.val) = - (yyvsp[(2) - (2)].val); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 163 "eval.y"
    { (yyval.val) = ! (yyvsp[(2) - (2)].val); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 164 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 167 "eval.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 168 "eval.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 169 "eval.y"
    { (yyval.val) = peek ((address) (yyvsp[(3) - (4)].val), BYTESIZE); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 170 "eval.y"
    { (yyval.val) = peek ((address) (yyvsp[(3) - (4)].val), WORDSIZE); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 171 "eval.y"
    { (yyval.val) = peek ((address) (yyvsp[(3) - (4)].val), LONGSIZE); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 172 "eval.y"
    { (yyval.val) = extend ((unsigned) (yyvsp[(3) - (4)].val), WORDSIZE); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 173 "eval.y"
    { (yyval.val) = extend ((unsigned) (yyvsp[(3) - (4)].val), LONGSIZE); }
    break;


/* Line 1792 of yacc.c  */
#line 1757 "eval.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 175 "eval.y"


/*

	End of Grammer

*/

static int
get_token_id (const char* token)
{

    /* SIZEID, FSIZEID */
    {
	struct idpair {
	    char idstr[8];
	    int  idnum;
	} idbuf[] = {
	    { "dc.b"  , BYTESIZE },
	    { "dc.w"  , WORDSIZE },
	    { "dc.l"  , LONGSIZE },
	    { "dc"    , WORDSIZE },
	    { "byte"  , BYTEID },
	    { "even"  , EVENID },
	    { "cr"    , CRID },
	    { "asciz" , ASCIIZID },
	    { "asciiz", ASCIIZID },
	    { "ascii" , ASCIIID },
	    { "lascii", LASCIIID },
#if 0
	    { "long"  , LONGID },
	    { "word"  , WORDID },
#endif
	    { "dc.s"  , SINGLESIZE },
	    { "dc.d"  , DOUBLESIZE },
	    { "dc.x"  , EXTENDSIZE },
	    { "dc.p"  , PACKEDSIZE },
	    { ""      , 0 }		/* end of list */
	};
	struct idpair* idptr;
	const char* t = token;

	if (*t == (char)'.')
	    t++;			/* 先頭のピリオドは無視 */
	for (idptr = idbuf; idptr->idstr[0]; idptr++) {
	    if (strcasecmp (t, idptr->idstr) == 0) {
		yylval.val = (unsigned long) idptr->idnum;
		return (SINGLESIZE <= idptr->idnum) ? FSIZEID : SIZEID;
	    }
	}
    }

    /* NUMBER */
    if (strcasecmp (token, "tabletop") == 0) {
	yylval.val = (unsigned long) Eval_TableTop;
	return NUMBER;
    }
    if (strcasecmp (token, "pc") == 0) {
	yylval.val = (unsigned long) Eval_PC;
	return NUMBER;
    }

    /* BREAK, PEEK*, EXT* */
    if (strcasecmp (token, "break")  == 0)	return BREAK;
    if (strcasecmp (token, "peek.b") == 0)	return PEEKB;
    if (strcasecmp (token, "peek.w") == 0)	return PEEKW;
    if (strcasecmp (token, "peek.l") == 0)	return PEEKL;
    if (strcasecmp (token, "ext.w")  == 0)	return EXTW;
    if (strcasecmp (token, "ext.l")  == 0)	return EXTL;

    /* トークンではなかった */
    return -1;
}


static int
yylex (void)
{
    unsigned char c;

    while ((c = *Lexptr++) == ' ' || c == '\t' || c == '\n')
	;
    if (c == '\0')
	return 0;

    /* 16 進数 */
    if (c == '$' || (c == '0' && (char) tolower (*(unsigned char*)Lexptr) == 'x')) {
	char* p;

	if (c == '0')
	    Lexptr++;
	p = Lexptr;
	yylval.val = 0;
	while ((c = *Lexptr++), isxdigit (c))
	    yylval.val = (yylval.val << 4)
		       + (toupper (c) >= 'A' ? toupper (c) - 'A' + 10 : c - '0');
	return (--Lexptr == p) ? 1 : NUMBER;
    }
    /* 10 進数 */
    else if (isdigit (c)) {
	yylval.val = c - '0';
	while ((c = *Lexptr++), isdigit (c))
	    yylval.val = yylval.val * 10 + c - '0';
	Lexptr--;
	return NUMBER;
    }

    if (c == '"') {
	char* term;

	if ((term = strchr (Lexptr, '"')) == NULL)
	    return 1;
	yylval.str = Malloc (term - Lexptr + 1);
	strncpy (yylval.str, Lexptr, term - Lexptr);
	yylval.str[term - Lexptr] = '\0';
	Lexptr = term + 1;
	return _STRING;
    }
    if (c == '<') {
	if (*Lexptr == '=') {
	    Lexptr++;
	    return LE;
	}
	return c;
    }
    if (c == '>') {
	if (*Lexptr == '=') {
	    Lexptr++;
	    return GE;
	}
	return c;
    }
    if (c == '|') {
	if (*Lexptr == '|') {
	    Lexptr++;
	    return OROR;
	}
	return c;
    }
    if (c == '&') {
	if (*Lexptr == '&') {
	    Lexptr++;
	    return ANDAND;
	}
	return c;
    }
    if (c == '=') {
	if (*Lexptr == '=') {
	    Lexptr++;
	    return EQUEQU;
	}
	return c;
    }
    if (c == '!') {
	if (*Lexptr == '=') {
	    Lexptr++;
	    return NOTEQU;
	}
	return c;
    }

    if (isalpha (c) || c == '.') {
	char* token = --Lexptr;
	unsigned char c;
	char next;
	int ret;

	while ((c = *Lexptr++), isalnum (c) || c == '.')
	    ;
	next = *--Lexptr;
	*Lexptr = '\0';			/* トークンを切り出す */
	ret = get_token_id (token);
	*Lexptr = next;

	if (ret >= 0)
	    return ret;

	/* トークンではなかった */
	Lexptr = token + 1;
    }

    return c;
}


static void
yyerror (char* s)
{
    eprintf ("%s\n", s);
}


static void
fpconv_by_size (char* buf, address ptr, opesize size)
{
    unsigned long val[3];

    val[0] = PEEK_LONG (ptr);
    if (size == SINGLESIZE) {
	fpconv_s (buf, (float*) (void*) &val);
	return;
    }

    ptr += 4;
    val[1] = PEEK_LONG (ptr);
    if (size == DOUBLESIZE) {
	fpconv_d (buf, (double*) (void*) &val);
	return;
    }

    ptr += 4;
    val[2] = PEEK_LONG (ptr);
    if (size == EXTENDSIZE)
	fpconv_x (buf, (long double*) (void*) &val);
    else /* if (size == PACKEDSIZE) */
	fpconv_p (buf, (packed_decimal*) &val);
}


static void
tabledesc (int num, opesize id)
{
    int i;

    Eval_ID = id;
    if (Eval_Count == 0) {		/* easy trick ? */
	if (id == ASCIIID || id == BYTEID
#if 0
	 || id == WORDID || id == LONGID
#endif
	) {
	    Eval_Count = 1;
	    Eval_Bytes = num;
	} else
	    Eval_Count = num;
    }


    if (ExpStackCounter == 0 && ParseMode == PARSE_GENERATING) {
	char* bufptr = strend (Eval_ResultString);

	switch (id) {
	case LONGSIZE:
	    if (depend_address (Eval_PC))
		make_proper_symbol (bufptr, (address) PEEK_LONG (Eval_PC));
	    else
		itoxd_by_size (bufptr, PEEK_LONG (Eval_PC), id);
	    break;
	case WORDSIZE:
	    itoxd_by_size (bufptr, PEEK_WORD (Eval_PC), id);
	    break;
	case BYTESIZE:
	    itoxd_by_size (bufptr, PEEK_BYTE (Eval_PC), id);
	    break;

	case SINGLESIZE:
	case DOUBLESIZE:
	case EXTENDSIZE:
	case PACKEDSIZE:
	    fpconv_by_size (bufptr, Eval_PC, id);
	    break;

	default:	/* reduce warning message */
	    break;
	}
    }
    for (i = 0; i < ExpStackCounter; i++) {
	switch (ParseMode) {
	case PARSE_ANALYZING:
	    if (ExpStack[i]->isvalue == FALSE)
		free (ExpStack[i]->bufptr);	/* 文字列バッファを解放 */
	    free (ExpStack[i]);
	    break;
	case PARSE_GENERATING:
	    if (ExpStack[i]->isvalue) {
		char* bufptr = strend (Eval_ResultString);
		address val = ExpStack[i]->value;

		if (ExpStack[i]->registed)
		    make_proper_symbol (bufptr, val);
		else
		    itoxd_by_size (bufptr, (ULONG) val, Eval_ID);
	    } else {
		strcat (Eval_ResultString, ExpStack[i]->bufptr);
		free (ExpStack[i]->bufptr);
	    }
	    free (ExpStack[i]);
	    break;
	}
    }
    ExpStackCounter = 0;
}


static expbuf*
storestr (char* s)
{
    expbuf* exp = Malloc (sizeof (expbuf));

    exp->bufptr = s;
    exp->isvalue = FALSE;

    return exp;
}


static expbuf*
storeexp (address v, int mode)
{
    expbuf* exp = Malloc (sizeof (expbuf));

    exp->value = v;
    exp->isvalue = TRUE;

    if (mode == 1) {
	exp->registed = TRUE;
	if (ParseMode == PARSE_ANALYZING
	 && !regist_label (v, DATLABEL | UNKNOWN))
	    printf ("??? address %x\n", (unsigned int) v);
    } else
	exp->registed = FALSE;

    return exp;
}


static expbuf*
store (expbuf* exp)
{

#if 0	/* debug */
    if (exp->isvalue == TRUE)
	printf ("値 = %d\n", exp->value);
    else
	printf ("文字列 = %s\n", exp->bufptr);
#endif

    if (ExpStackCounter == EXPSTACKSIZE)
	err ("式評価スタックがあふれました\n");
    ExpStack[ExpStackCounter++] = exp;

    return exp;
}


static void
itoxd_by_size (char* buf, ULONG n, opesize size)
{
    itoxd (buf, n, (size == LONGSIZE) ? 8 :
		   (size == WORDSIZE) ? 4 : 2);
}


static void
peek_warning (address adrs, int size)
{
    if ((int)adrs & 1)
	eprintf ("Warning: peek.%c の引数が奇数アドレス(%x)です\n", size, adrs);
}

static unsigned long
peek (address adrs, opesize size)
{
    unsigned long rc;

    switch (size) {
    case BYTESIZE:
	rc = PEEK_BYTE (adrs);
	break;
    case WORDSIZE:
	peek_warning (adrs, 'w');
	rc = PEEK_WORD (adrs);
	break;
    case LONGSIZE:
	peek_warning (adrs, 'l');
	rc = PEEK_LONG (adrs);
	break;
    default:
	rc = 0;
	break;
    }
    /*
	printf ("peek.%d(%x) = %x\n", size, (unsigned int)adrs, rc);
    */
    return rc;
}



static unsigned long
extend (unsigned long arg, opesize size)
{
    if (size == WORDSIZE)
	return (unsigned short)(signed char)arg;
    else /* if (size == LONGSIZE) */
	return (unsigned long)(signed short)arg;
}


static void
breakjob (unsigned long value)
{
    if (Eval_Count == 0)			/* easy trick ? */
	Eval_Count = 1;
    Eval_ID = BREAKID;
    Eval_Break = value;
}


#ifdef SELF
int
main (void)
{
    char buf[256];

    yydebug = 0;
    while (fgets (buf, sizeof buf, stdin)) {
	char* p = strchr (buf, '\n');
	if (p)
	    *p = '\n';
	Lexptr = buf;
	yyparse ();
    }
    return 0;
}
#endif /* SELF */


/* EOF */
