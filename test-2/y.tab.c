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



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEG = 258,
     END = 259,
     T_INT = 260,
     T_BOOL = 261,
     T_FLOAT = 262,
     READ = 263,
     WRITE = 264,
     BEGDECL = 265,
     ENDDECL = 266,
     DECL = 267,
     BREAK = 268,
     CONTINUE = 269,
     VAR = 270,
     NUM = 271,
     FLNUM = 272,
     IF = 273,
     THEN = 274,
     ELSE = 275,
     ENDIF = 276,
     LOGICAL_AND = 277,
     LOGICAL_NOT = 278,
     LOGICAL_OR = 279,
     EQUALEQUAL = 280,
     LESSTHANOREQUAL = 281,
     GREATERTHANOREQUAL = 282,
     NOTEQUAL = 283,
     WHILE = 284,
     DO = 285,
     ENDWHILE = 286,
     FOR = 287,
     T = 288,
     F = 289,
     MAIN = 290,
     RETURN = 291
   };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define T_FLOAT 262
#define READ 263
#define WRITE 264
#define BEGDECL 265
#define ENDDECL 266
#define DECL 267
#define BREAK 268
#define CONTINUE 269
#define VAR 270
#define NUM 271
#define FLNUM 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define LOGICAL_AND 277
#define LOGICAL_NOT 278
#define LOGICAL_OR 279
#define EQUALEQUAL 280
#define LESSTHANOREQUAL 281
#define GREATERTHANOREQUAL 282
#define NOTEQUAL 283
#define WHILE 284
#define DO 285
#define ENDWHILE 286
#define FOR 287
#define T 288
#define F 289
#define MAIN 290
#define RETURN 291




/* Copy the first part of user declarations.  */
#line 1 "src/compiler.y"

int yylex();
#include <stdio.h>
#include <stdlib.h>
#include "include/tree.h"
#include "include/symbol_table.h"
#include <string.h>
 Symbol* symbol_table;
 Node* root;
void yyerror(const char *s);
/*
typedef struct console_output{
	int value;
	struct console_output* next;
} console_output;

this can be used incase of printing all the outputs of print together
*/
// extern int error_flag;


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
#line 22 "src/compiler.y"
{
	int num;
    double flnum;
	char* var;
	struct Node* node;
}
/* Line 193 of yacc.c.  */
#line 196 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 209 "y.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
      49,    50,    41,    39,    45,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      37,    48,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    15,    19,    20,    23,    27,
      29,    31,    33,    35,    39,    41,    46,    54,    55,    58,
      60,    63,    66,    68,    71,    74,    78,    82,    87,    88,
      90,    92,    96,    98,   104,   112,   114,   116,   128,   138,
     149,   158,   168,   178,   189,   200,   210,   219,   221,   223,
     226,   228,   230,   232,   236,   240,   244,   248,   252,   256,
     259,   263,   267,   271,   275,   279,   283,   287,   291,   296,
     304,   306,   311
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    61,    -1,    55,     3,    61,     4,
      -1,    12,    56,    11,    -1,    10,    56,    11,    -1,    -1,
      57,    56,    -1,    58,    59,    44,    -1,     5,    -1,     6,
      -1,     7,    -1,    60,    -1,    60,    45,    59,    -1,    15,
      -1,    15,    46,    16,    47,    -1,    15,    46,    16,    47,
      46,    16,    47,    -1,    -1,    61,    62,    -1,     1,    -1,
      63,    44,    -1,    64,    44,    -1,    68,    -1,    13,    44,
      -1,    14,    44,    -1,    72,    48,    71,    -1,    73,    48,
      71,    -1,     9,    49,    65,    50,    -1,    -1,    66,    -1,
      67,    -1,    67,    45,    66,    -1,    71,    -1,    18,    71,
      19,    61,    21,    -1,    18,    71,    19,    61,    20,    61,
      21,    -1,    69,    -1,    70,    -1,    32,    49,    63,    44,
      71,    44,    63,    50,    51,    61,    52,    -1,    32,    49,
      44,    71,    44,    50,    51,    61,    52,    -1,    32,    49,
      44,    71,    44,    63,    50,    51,    61,    52,    -1,    32,
      49,    44,    44,    50,    51,    61,    52,    -1,    32,    49,
      63,    44,    44,    50,    51,    61,    52,    -1,    32,    49,
      44,    44,    63,    50,    51,    61,    52,    -1,    32,    49,
      63,    44,    71,    44,    50,    51,    61,    52,    -1,    32,
      49,    63,    44,    44,    63,    50,    51,    61,    52,    -1,
      30,    51,    61,    52,    29,    49,    71,    50,    44,    -1,
      30,    51,    61,    52,    29,    49,    50,    44,    -1,    16,
      -1,    17,    -1,    40,    16,    -1,    72,    -1,    33,    -1,
      34,    -1,    49,    71,    50,    -1,    71,    39,    71,    -1,
      71,    40,    71,    -1,    71,    41,    71,    -1,    71,    42,
      71,    -1,    71,    43,    71,    -1,    23,    71,    -1,    71,
      22,    71,    -1,    71,    24,    71,    -1,    71,    37,    71,
      -1,    71,    38,    71,    -1,    71,    27,    71,    -1,    71,
      26,    71,    -1,    71,    28,    71,    -1,    71,    25,    71,
      -1,    72,    46,    71,    47,    -1,    72,    46,    71,    47,
      46,    71,    47,    -1,    15,    -1,    15,    46,    71,    47,
      -1,    15,    46,    71,    47,    46,    71,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    72,    88,    93,   100,   101,   115,   128,
     129,   130,   134,   135,   144,   156,   169,   190,   191,   201,
     205,   215,   218,   221,   222,   224,   234,   240,   244,   245,
     256,   257,   263,   267,   270,   273,   274,   277,   280,   283,
     286,   289,   292,   295,   298,   303,   306,   309,   312,   316,
     319,   323,   326,   329,   333,   336,   339,   342,   350,   358,
     359,   360,   361,   364,   367,   370,   373,   376,   379,   389,
     402,   412,   430
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "END", "T_INT", "T_BOOL",
  "T_FLOAT", "READ", "WRITE", "BEGDECL", "ENDDECL", "DECL", "BREAK",
  "CONTINUE", "VAR", "NUM", "FLNUM", "IF", "THEN", "ELSE", "ENDIF",
  "LOGICAL_AND", "LOGICAL_NOT", "LOGICAL_OR", "EQUALEQUAL",
  "LESSTHANOREQUAL", "GREATERTHANOREQUAL", "NOTEQUAL", "WHILE", "DO",
  "ENDWHILE", "FOR", "T", "F", "MAIN", "RETURN", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['", "']'", "'='", "'('",
  "')'", "'{'", "'}'", "$accept", "Prog", "Gdecl_sec", "Gdecl_list",
  "Gdecl", "type", "Gid_list", "Gid", "stmt_list", "statement",
  "assign_stmt", "write_stmt", "para_list", "para_list1", "para",
  "cond_stmt", "for_stmt", "do_while", "expr", "var_expr", "array_expr", 0
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
     285,   286,   287,   288,   289,   290,   291,    60,    62,    43,
      45,    42,    47,    37,    59,    44,    91,    93,    61,    40,
      41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    56,    57,    58,
      58,    58,    59,    59,    60,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    62,    63,    63,    64,    65,    65,
      66,    66,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     3,     0,     2,     3,     1,
       1,     1,     1,     3,     1,     4,     7,     0,     2,     1,
       2,     2,     1,     2,     2,     3,     3,     4,     0,     1,
       1,     3,     1,     5,     7,     1,     1,    11,     9,    10,
       8,     9,     9,    10,    10,     9,     8,     1,     1,     2,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     7,
       1,     4,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     6,     0,     0,     9,    10,    11,     0,     6,
       0,     0,     1,    19,     0,     2,     5,     7,    14,     0,
      12,     4,     0,     0,     0,     0,    70,     0,     0,     0,
      18,     0,     0,    22,    35,    36,     0,     0,     0,     8,
       0,     3,    28,    23,    24,     0,    70,    47,    48,     0,
      51,    52,     0,     0,     0,    50,     0,     0,    20,    21,
       0,     0,     0,    13,     0,    29,    30,    32,     0,    59,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    15,    27,     0,    71,    53,     0,    60,    61,
      67,    65,    64,    66,    62,    63,    54,    55,    56,    57,
      58,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      33,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    72,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    46,     0,    40,     0,     0,
       0,     0,     0,     0,     0,    45,    42,    38,     0,    41,
       0,     0,     0,    39,    44,    43,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     8,     9,    10,    19,    20,    15,    30,
      31,    32,    64,    65,    66,    33,    34,    35,    67,    55,
      37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int16 yypact[] =
{
      14,    30,    30,     5,   367,   -56,   -56,   -56,    17,    30,
      23,    18,   -56,   -56,   399,   341,   -56,   -56,    -7,    11,
      19,   -56,   482,    16,    22,    24,    33,   329,    25,    28,
     -56,    36,    41,   -56,   -56,   -56,    39,    40,    51,   -56,
      23,   -56,   329,   -56,   -56,   329,   -56,   -56,   -56,   329,
     -56,   -56,    70,   329,   577,    43,     2,     4,   -56,   -56,
     329,   329,    44,   -56,    46,   -56,    48,   654,   479,   -56,
     -56,   415,   374,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,    -5,   289,    50,
     654,   654,    56,   -56,   329,    57,   -56,   612,   -56,   -56,
     408,   408,   408,   408,   661,   661,     9,     9,    38,    38,
     -10,   503,    68,    -9,   623,   309,    89,   -56,   329,   406,
     -56,    61,    59,    58,    63,     3,     6,   631,    67,   527,
     622,   329,   269,     2,    66,    71,    69,    72,    75,     7,
     -56,   -56,   -56,   551,    77,   442,    31,     2,     2,    76,
       2,    78,    79,    82,   -56,   -56,    84,   -56,    60,    86,
       2,   187,     2,     2,    88,   -56,   -56,   -56,   198,   -56,
     229,   239,     2,   -56,   -56,   -56,   264,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,    21,   -56,   -56,    93,   -56,   -13,   -56,
     -55,   -56,   -56,    32,   -56,   -56,   -56,   -56,   109,   -15,
     -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -18
static const yytype_int16 yytable[] =
{
      36,    22,    89,    13,    23,    12,    26,    36,    24,    25,
      26,   -17,    73,    27,    74,   -17,   -17,   -17,    26,    26,
     -17,    26,    26,    11,     1,    28,     2,    29,    16,    21,
      17,    73,   -17,    74,   -17,     5,     6,     7,    18,    38,
      23,   123,    36,    87,    24,    25,    26,   112,    88,    27,
      83,    84,    85,   135,   -17,    39,   137,   152,   124,    97,
      73,    28,    74,    29,    40,    42,    43,    62,    44,    23,
     136,   138,    36,    24,    25,    26,    56,    57,    27,    45,
      58,    85,    36,   157,   153,    59,    70,    60,    61,    86,
      28,    92,    29,    94,   115,    23,    93,   122,    36,    24,
      25,    26,   116,   118,    27,   128,   130,   131,   132,   133,
      36,    36,   166,   134,   140,    36,    28,   147,    29,   149,
     146,   155,   148,   150,    36,   151,   117,   160,   165,   162,
     163,    36,   164,    63,   158,   159,    54,   161,   167,   172,
       0,     0,     0,    36,    36,     0,    36,   168,     0,   170,
     171,     0,     0,    36,    68,    36,    36,     0,    69,   176,
       0,    36,    71,     0,     0,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    23,   114,     0,     0,
      24,    25,    26,     0,     0,    27,     0,    23,     0,     0,
       0,    24,    25,    26,     0,     0,    27,    28,     0,    29,
       0,     0,     0,     0,   127,     0,     0,   129,    28,     0,
      29,     0,     0,     0,     0,     0,     0,     0,    23,   169,
     143,   145,    24,    25,    26,     0,     0,    27,    23,     0,
     173,     0,    24,    25,    26,     0,     0,    27,     0,    28,
       0,    29,     0,     0,     0,     0,     0,     0,     0,    28,
       0,    29,     0,    23,     0,     0,     0,    24,    25,    26,
       0,   174,    27,     0,    46,    47,    48,     0,     0,     0,
       0,   175,    49,     0,    28,     0,    29,     0,     0,     0,
       0,     0,    50,    51,    46,    47,    48,     0,     0,    52,
       0,     0,    49,     0,     0,     0,   177,     0,    53,   144,
       0,     0,    50,    51,    46,    47,    48,     0,     0,    52,
       0,     0,    49,   113,     0,     0,     0,     0,    53,     0,
       0,     0,    50,    51,    46,    47,    48,     0,     0,    52,
      23,     0,    49,   126,    24,    25,    26,     0,    53,    27,
       0,     0,    50,    51,     0,     0,     0,   -17,    13,    52,
      14,    28,     0,    29,     0,    13,   -17,     0,    53,     0,
     -17,   -17,   -17,   -17,     0,   -17,     0,   -17,   -17,   -17,
       0,     0,   -17,     0,   -17,   -17,     0,   -17,     0,   -17,
      13,     0,     0,   -17,   -17,     0,   -17,    13,   -17,     0,
       0,     0,   -17,   -17,   -17,   -17,     0,   -17,     0,   -17,
     -17,   -17,     0,     0,   -17,     0,     0,   -17,     0,   -17,
      73,   -17,    74,     0,     0,     0,   -17,    73,   -17,    74,
      75,    76,    77,    78,     0,     0,     0,    81,    82,    83,
      84,    85,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    73,    96,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    41,     0,     0,     0,
       0,    23,   156,     0,     0,    24,    25,    26,     0,     0,
      27,    73,     0,    74,    75,    76,    77,    78,     0,     0,
       0,     0,    28,     0,    29,     0,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    73,    95,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    73,
     121,    74,    75,    76,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    73,   141,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,     0,    72,     0,   154,    73,
       0,    74,    75,    76,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    23,     0,     0,     0,    24,    25,    26,     0,     0,
      27,    23,   119,   120,     0,    24,    25,    26,     0,     0,
      27,     0,    28,   142,    29,    73,     0,    74,    75,    76,
      77,    78,    28,    73,    29,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   125,    79,    80,
      81,    82,    83,    84,    85,   139,    73,     0,    74,    75,
      76,    77,    78,    73,     0,    74,    75,    76,    77,    78,
       0,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      15,    14,    57,     1,     9,     0,    15,    22,    13,    14,
      15,     9,    22,    18,    24,    13,    14,    15,    15,    15,
      18,    15,    15,     2,    10,    30,    12,    32,    11,    11,
       9,    22,    30,    24,    32,     5,     6,     7,    15,    46,
       9,    50,    57,    56,    13,    14,    15,    52,    44,    18,
      41,    42,    43,    50,    52,    44,    50,    50,   113,    72,
      22,    30,    24,    32,    45,    49,    44,    16,    44,     9,
     125,   126,    87,    13,    14,    15,    51,    49,    18,    46,
      44,    43,    97,    52,   139,    44,    16,    48,    48,    46,
      30,    47,    32,    45,    44,     9,    50,    29,   113,    13,
      14,    15,    46,    46,    18,    16,   119,    46,    49,    51,
     125,   126,    52,    50,    47,   130,    30,    51,    32,    50,
     133,    44,    51,    51,   139,    50,    94,    51,    44,    51,
      51,   146,    50,    40,   147,   148,    27,   150,    52,    51,
      -1,    -1,    -1,   158,   159,    -1,   161,   160,    -1,   162,
     163,    -1,    -1,   168,    45,   170,   171,    -1,    49,   172,
      -1,   176,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     9,    88,    -1,    -1,
      13,    14,    15,    -1,    -1,    18,    -1,     9,    -1,    -1,
      -1,    13,    14,    15,    -1,    -1,    18,    30,    -1,    32,
      -1,    -1,    -1,    -1,   115,    -1,    -1,   118,    30,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    52,
     131,   132,    13,    14,    15,    -1,    -1,    18,     9,    -1,
      52,    -1,    13,    14,    15,    -1,    -1,    18,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,     9,    -1,    -1,    -1,    13,    14,    15,
      -1,    52,    18,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    52,    23,    -1,    30,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    33,    34,    15,    16,    17,    -1,    -1,    40,
      -1,    -1,    23,    -1,    -1,    -1,    52,    -1,    49,    50,
      -1,    -1,    33,    34,    15,    16,    17,    -1,    -1,    40,
      -1,    -1,    23,    44,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    33,    34,    15,    16,    17,    -1,    -1,    40,
       9,    -1,    23,    44,    13,    14,    15,    -1,    49,    18,
      -1,    -1,    33,    34,    -1,    -1,    -1,     0,     1,    40,
       3,    30,    -1,    32,    -1,     1,     9,    -1,    49,    -1,
      13,    14,    15,     9,    -1,    18,    -1,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    30,    -1,    32,
       1,    -1,    -1,     4,    30,    -1,    32,     1,     9,    -1,
      -1,    -1,    13,    14,    15,     9,    -1,    18,    -1,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    21,    -1,    30,
      22,    32,    24,    -1,    -1,    -1,    30,    22,    32,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    22,    50,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,     4,    -1,    -1,    -1,
      -1,     9,    50,    -1,    -1,    13,    14,    15,    -1,    -1,
      18,    22,    -1,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    30,    -1,    32,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    22,    47,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    22,
      47,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    22,    47,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    -1,    19,    -1,    47,    22,
      -1,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,     9,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,
      18,     9,    20,    21,    -1,    13,    14,    15,    -1,    -1,
      18,    -1,    30,    21,    32,    22,    -1,    24,    25,    26,
      27,    28,    30,    22,    32,    24,    25,    26,    27,    28,
      37,    38,    39,    40,    41,    42,    43,    44,    37,    38,
      39,    40,    41,    42,    43,    44,    22,    -1,    24,    25,
      26,    27,    28,    22,    -1,    24,    25,    26,    27,    28,
      -1,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    12,    54,    55,     5,     6,     7,    56,    57,
      58,    56,     0,     1,     3,    61,    11,    56,    15,    59,
      60,    11,    61,     9,    13,    14,    15,    18,    30,    32,
      62,    63,    64,    68,    69,    70,    72,    73,    46,    44,
      45,     4,    49,    44,    44,    46,    15,    16,    17,    23,
      33,    34,    40,    49,    71,    72,    51,    49,    44,    44,
      48,    48,    16,    59,    65,    66,    67,    71,    71,    71,
      16,    71,    19,    22,    24,    25,    26,    27,    28,    37,
      38,    39,    40,    41,    42,    43,    46,    61,    44,    63,
      71,    71,    47,    50,    45,    47,    50,    61,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    52,    44,    71,    44,    46,    66,    46,    20,
      21,    47,    29,    50,    63,    44,    44,    71,    16,    71,
      61,    46,    49,    51,    50,    50,    63,    50,    63,    44,
      47,    47,    21,    71,    50,    71,    61,    51,    51,    50,
      51,    50,    50,    63,    47,    44,    50,    52,    61,    61,
      51,    61,    51,    51,    50,    44,    52,    52,    61,    52,
      61,    61,    51,    52,    52,    52,    61,    52
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
        case 2:
#line 57 "src/compiler.y"
    { 
    root = createnode(0, "program", 0, NULL,(yyvsp[(1) - (2)].node), NULL, NULL);
    if ((yyvsp[(1) - (2)].node)) {
        (yyvsp[(1) - (2)].node)->extra = (yyvsp[(2) - (2)].node);  
    }

    //  printf("error flag === %d\n", error_flag);
    evaluate_statement(root->left, symbol_table);
    //  printf("error flag === %d\n", error_flag);
    if (error_flag == 1){
        return 0;
    }
    printf("\n---the syntax tree---\n");
    printroot(root, 0);
}
    break;

  case 3:
#line 72 "src/compiler.y"
    {
		
        Node* temp = (yyvsp[(1) - (4)].node);
    while (temp->extra != NULL) temp = temp->extra;
    temp->extra = (yyvsp[(3) - (4)].node);  
    root = createnode(0, "program", 0, NULL, (yyvsp[(1) - (4)].node), NULL, NULL);
 
    evaluate_statement(root->left, symbol_table);
    if (error_flag == 1){
        return 0;
    }
       printroot(root, 0);
	}
    break;

  case 4:
#line 88 "src/compiler.y"
    { printf("printing symbol table values\n");
			 printsymboltable(symbol_table); 
	(yyval.node) = createnode(0, "decl_list", 0, NULL, (yyvsp[(2) - (3)].node), NULL, NULL);
// $$ = $2;
}
    break;

  case 5:
#line 93 "src/compiler.y"
    { printf("printing symbol table values\n");
			 printsymboltable(symbol_table); 
	(yyval.node) = createnode(0, "decl_list", 0, NULL, (yyvsp[(2) - (3)].node), NULL, NULL);
// $$ = $2;
}
    break;

  case 6:
#line 100 "src/compiler.y"
    {(yyval.node) = NULL;}
    break;

  case 7:
#line 101 "src/compiler.y"
    {  
			// // $$ = createnode(0, "list",0,  NULL, $1, NULL, $2);
			// $$ = $1;
            // while($1->extra == NULL)
			// $1->extra = $2;
            Node* temp = (yyvsp[(1) - (2)].node);
            while (temp->extra != NULL) temp = temp->extra;  // find last node, where we can append
            temp->extra = (yyvsp[(2) - (2)].node);  // other statements would be chained to the end
            (yyval.node) = (yyvsp[(1) - (2)].node);  
        }
    break;

  case 8:
#line 115 "src/compiler.y"
    {Type t;
if (strcmp((yyvsp[(1) - (3)].node)->name, "integer") == 0) t = TYPE_INT;
else if (strcmp((yyvsp[(1) - (3)].node)->name, "boolean") == 0) t = TYPE_BOOL; 
else if (strcmp((yyvsp[(1) - (3)].node)->name, "float") == 0) t = TYPE_FLOAT;
			Node* p = (yyvsp[(2) - (3)].node);
			while(p != NULL ){
                if (strcmp(p->name,"Array")!=0 && strcmp(p->name, "2D_Array") != 0)
				    p->var_pointer->type = t;
                
				p=p->extra;
			}
			(yyval.node)= createnode(0, "decl", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), NULL);}
    break;

  case 9:
#line 128 "src/compiler.y"
    { (yyval.node) = createnode(0, "integer", 0, NULL, NULL, NULL, NULL);}
    break;

  case 10:
#line 129 "src/compiler.y"
    { (yyval.node) = createnode(0, "boolean",0, NULL, NULL, NULL, NULL); }
    break;

  case 11:
#line 130 "src/compiler.y"
    { (yyval.node) = createnode(0, "float",0, NULL, NULL, NULL, NULL); }
    break;

  case 12:
#line 134 "src/compiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:
#line 135 "src/compiler.y"
    { 
        Node* temp = (yyvsp[(1) - (3)].node);
        while (temp->extra != NULL) temp = temp->extra;
        temp->extra = (yyvsp[(3) - (3)].node);
        (yyval.node) = (yyvsp[(1) - (3)].node);
    }
    break;

  case 14:
#line 144 "src/compiler.y"
    { 
        Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (1)].var));
        if (sym == NULL) {
            insertSymbol(&symbol_table, (yyvsp[(1) - (1)].var), TYPE_INT, 0, 0, NULL); 
            sym = lookupSymbol(symbol_table, (yyvsp[(1) - (1)].var)); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        (yyval.node) = createnode(0, (yyvsp[(1) - (1)].var), sym->value.intval, sym, NULL, NULL, NULL);
    }
    break;

  case 15:
#line 156 "src/compiler.y"
    {  
        // printf("hii"); 
        Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].var));
        if (sym == NULL) {
            insertSymbol(&symbol_table, (yyvsp[(1) - (4)].var), TYPE_ARRAY_INT, (yyvsp[(3) - (4)].num), 0, NULL); 
            sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].var)); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        (yyval.node) = createnode(0, "Array", 0, NULL, createnode(0, "size", (yyvsp[(3) - (4)].num), NULL, NULL,NULL,NULL), createnode(0, (yyvsp[(1) - (4)].var), 0, sym, NULL, NULL,NULL),NULL);
    }
    break;

  case 16:
#line 169 "src/compiler.y"
    {  
        // printf("hii"); 
        Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (7)].var));
        if (sym == NULL) {
            int dim[2];
            dim[0] = (yyvsp[(3) - (7)].num);
            dim[1] = (yyvsp[(6) - (7)].num);
            insertSymbol(&symbol_table, (yyvsp[(1) - (7)].var), TYPE_2DARRAY_INT, (yyvsp[(3) - (7)].num),  0, dim); 
            sym = lookupSymbol(symbol_table, (yyvsp[(1) - (7)].var)); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        // printf("got a 2d array %d\n", $3 * $6);
        (yyval.node) = createnode(0, "2D_Array", 0, NULL, createnode(0, "size", (yyvsp[(3) - (7)].num) * (yyvsp[(6) - (7)].num), NULL, NULL,NULL,NULL), createnode(0, (yyvsp[(1) - (7)].var), 0, sym, NULL, NULL,NULL),NULL);
    }
    break;

  case 17:
#line 190 "src/compiler.y"
    { (yyval.node) = NULL; }
    break;

  case 18:
#line 191 "src/compiler.y"
    {
        if ((yyvsp[(1) - (2)].node) == NULL) {
            (yyval.node) = (yyvsp[(2) - (2)].node);  // First statement
        } else {
            Node* temp = (yyvsp[(1) - (2)].node);
            while (temp->extra != NULL) temp = temp->extra;  // Find last node, where we can append
            temp->extra = (yyvsp[(2) - (2)].node);  // other statements would be chained to the end
            (yyval.node) = (yyvsp[(1) - (2)].node);  
        }
    }
    break;

  case 19:
#line 201 "src/compiler.y"
    { yyerror("Syntax error in statement."); }
    break;

  case 20:
#line 205 "src/compiler.y"
    { 
    // if (error_flag == 1){
    //     return 0;
    // }
    // printf("printing symbol table values\n");
			//  printsymboltable(symbol_table); 
	//   printsymboltable(symbol_table); 
	(yyval.node) = (yyvsp[(1) - (2)].node); 
    // evaluate_statement($$);
    }
    break;

  case 21:
#line 215 "src/compiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node);
        // evaluate_statement($$);
        }
    break;

  case 22:
#line 218 "src/compiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);
        // evaluate_statement($$);
        }
    break;

  case 23:
#line 221 "src/compiler.y"
    { (yyval.node) = createnode(0, "break", 0, NULL, NULL, NULL, NULL); }
    break;

  case 24:
#line 222 "src/compiler.y"
    {  (yyval.node) = createnode(0, "continue", 0, NULL, NULL, NULL, NULL); }
    break;

  case 25:
#line 224 "src/compiler.y"
    { 
    (yyval.node) = createnode('=', "assign", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);

    
    // if ($1->var_pointer) {  
    //     $1->var_pointer->value.intval = $3->value;  
    // } else {
    //     yyerror("Error: Assignment to an undefined variable!");
    // }
}
    break;

  case 26:
#line 234 "src/compiler.y"
    {
            (yyval.node) = createnode('=', "assign_array", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL); 
    //    $1->left->var_pointer->value.int_arrayval[$1->right->value] = $3->value;  
    }
    break;

  case 27:
#line 240 "src/compiler.y"
    { 
    (yyval.node) = createnode(0, "write", 0, NULL,(yyvsp[(3) - (4)].node), NULL, NULL);
}
    break;

  case 28:
#line 244 "src/compiler.y"
    { (yyval.node) = NULL; }
    break;

  case 29:
#line 245 "src/compiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); 
		//   Node* para;
		//   para = $$;
		//   printf("console output : \n");
		//   while (para){
		// 	// printf("%d\n", para->value);
		// 	para = para->extra;
		//   }
        }
    break;

  case 30:
#line 256 "src/compiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 31:
#line 257 "src/compiler.y"
    { 
                (yyval.node) = (yyvsp[(1) - (3)].node); 
                (yyvsp[(1) - (3)].node)->extra = (yyvsp[(3) - (3)].node); 
           }
    break;

  case 32:
#line 263 "src/compiler.y"
    { 
    (yyval.node) = createnode(0, "parameter", (yyvsp[(1) - (1)].node)->value, NULL, (yyvsp[(1) - (1)].node), NULL, NULL); 
}
    break;

  case 33:
#line 267 "src/compiler.y"
    { 
    (yyval.node) = createnode(0,"if-then", 0, NULL,  createnode(0,"if", 0, NULL, (yyvsp[(2) - (5)].node),createnode(0,"then", 0, NULL, (yyvsp[(4) - (5)].node),NULL,NULL),NULL), NULL, NULL); 
                                                }
    break;

  case 34:
#line 270 "src/compiler.y"
    { 
            (yyval.node) = createnode(0,"if-then-else", 0, NULL,  createnode(0,"if", 0, NULL, (yyvsp[(2) - (7)].node),createnode(0,"then", 0, NULL, (yyvsp[(4) - (7)].node),NULL,NULL),createnode(0,"else", 0, NULL, (yyvsp[(6) - (7)].node),NULL,NULL)), NULL, NULL);  
            }
    break;

  case 35:
#line 273 "src/compiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 36:
#line 274 "src/compiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 37:
#line 277 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (11)].node),createnode(0, "final-condition", 0, NULL, (yyvsp[(5) - (11)].node), NULL, NULL),createnode(0, "step", 0, NULL, (yyvsp[(7) - (11)].node), NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(10) - (11)].node), NULL, NULL), NULL);
            }
    break;

  case 38:
#line 280 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL, createnode(0, "final-condition", 0, NULL, (yyvsp[(4) - (9)].node), NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(8) - (9)].node), NULL, NULL), NULL);
            }
    break;

  case 39:
#line 283 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL, (yyvsp[(4) - (10)].node), NULL, NULL),createnode(0, "step", 0, NULL, (yyvsp[(6) - (10)].node), NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(9) - (10)].node), NULL, NULL), NULL);
            }
    break;

  case 40:
#line 286 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(7) - (8)].node), NULL, NULL), NULL);
            }
    break;

  case 41:
#line 289 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (9)].node),createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(8) - (9)].node), NULL, NULL), NULL);
            }
    break;

  case 42:
#line 292 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL,(yyvsp[(5) - (9)].node) , NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(8) - (9)].node), NULL, NULL), NULL);
            }
    break;

  case 43:
#line 295 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (10)].node),createnode(0, "final-condition", 0, NULL, (yyvsp[(5) - (10)].node), NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(9) - (10)].node), NULL, NULL), NULL);
            }
    break;

  case 44:
#line 298 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (10)].node),createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, (yyvsp[(6) - (10)].node), NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(9) - (10)].node), NULL, NULL), NULL);
            }
    break;

  case 45:
#line 303 "src/compiler.y"
    {
    (yyval.node) = createnode(0, "do-while", 0, NULL, createnode(0,"do_statements", 0, NULL,(yyvsp[(3) - (9)].node),NULL,NULL), createnode(0,"while", 0, NULL,(yyvsp[(7) - (9)].node),NULL,NULL), NULL);
}
    break;

  case 46:
#line 307 "src/compiler.y"
    {(yyval.node) = createnode(0, "do-while", 0, NULL, createnode(0,"do_statements", 0, NULL,(yyvsp[(3) - (8)].node),NULL,NULL), createnode(0,"while", 0, NULL, NULL,NULL,NULL), NULL);}
    break;

  case 47:
#line 309 "src/compiler.y"
    { 
            (yyval.node) = createnode(0, "number", (yyvsp[(1) - (1)].num), NULL, NULL, NULL, NULL); 
        }
    break;

  case 48:
#line 312 "src/compiler.y"
    { 
            // printf("floating number ==== %f",$1);
            (yyval.node) = createnode(0, "flnumber", (yyvsp[(1) - (1)].flnum), NULL, NULL, NULL, NULL); 
        }
    break;

  case 49:
#line 316 "src/compiler.y"
    {  
            (yyval.node) = createnode(0, "number", -(yyvsp[(2) - (2)].num), NULL, NULL, NULL, NULL); 
        }
    break;

  case 50:
#line 319 "src/compiler.y"
    {  
            Symbol* sym = (yyvsp[(1) - (1)].node)->var_pointer; 
            (yyval.node) = createnode(0, "var_expr", sym ? sym->value.intval : 0, NULL, (yyvsp[(1) - (1)].node), NULL, NULL); 
        }
    break;

  case 51:
#line 323 "src/compiler.y"
    { 
            (yyval.node) = createnode(0, "T", 1, NULL, NULL, NULL, NULL);					  	
        }
    break;

  case 52:
#line 326 "src/compiler.y"
    { 
            (yyval.node) = createnode(0, "F", 0, NULL, NULL, NULL, NULL);
        }
    break;

  case 53:
#line 329 "src/compiler.y"
    {  
            (yyval.node) = (yyvsp[(2) - (3)].node);			
        }
    break;

  case 54:
#line 333 "src/compiler.y"
    {  
            (yyval.node) = createnode('+', "add", (yyvsp[(1) - (3)].node)->value + (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);					
        }
    break;

  case 55:
#line 336 "src/compiler.y"
    {  
            (yyval.node) = createnode('-', "subtract", (yyvsp[(1) - (3)].node)->value - (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);						
        }
    break;

  case 56:
#line 339 "src/compiler.y"
    {  
            (yyval.node) = createnode('*', "multiply", (yyvsp[(1) - (3)].node)->value * (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);			
        }
    break;

  case 57:
#line 342 "src/compiler.y"
    {  
            if ((yyvsp[(3) - (3)].node)->value == 0) {
                yyerror("Division by zero!"); 
                (yyval.node) = createnode('/', "divide", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            } else {
                (yyval.node) = createnode('/', "divide", (yyvsp[(1) - (3)].node)->value / (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            }
        }
    break;

  case 58:
#line 350 "src/compiler.y"
    { 
            if ((yyvsp[(3) - (3)].node)->value == 0) {
                yyerror("Modulo by zero!"); 
                (yyval.node) = createnode('%', "mod", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            } else {
                (yyval.node) = createnode('%', "mod", (int)(yyvsp[(1) - (3)].node)->value % (int)(yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            }
        }
    break;

  case 59:
#line 358 "src/compiler.y"
    { (yyval.node) = createnode('!', "not", !(yyvsp[(2) - (2)].node)->value, NULL, (yyvsp[(2) - (2)].node),NULL,NULL );						}
    break;

  case 60:
#line 359 "src/compiler.y"
    { (yyval.node) = createnode('&', "and", (yyvsp[(1) - (3)].node)->value && (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node),NULL );						}
    break;

  case 61:
#line 360 "src/compiler.y"
    { 	(yyval.node) = createnode('|', "or", (yyvsp[(1) - (3)].node)->value || (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node),NULL );					}
    break;

  case 62:
#line 361 "src/compiler.y"
    { 
            (yyval.node) = createnode('<', "lt", (yyvsp[(1) - (3)].node)->value < (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 63:
#line 364 "src/compiler.y"
    { 
            (yyval.node) = createnode('>', "gt", (yyvsp[(1) - (3)].node)->value > (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 64:
#line 367 "src/compiler.y"
    {  
            (yyval.node) = createnode('G', "gte", (yyvsp[(1) - (3)].node)->value >= (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 65:
#line 370 "src/compiler.y"
    { 
            (yyval.node) = createnode('L', "lte", (yyvsp[(1) - (3)].node)->value <= (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 66:
#line 373 "src/compiler.y"
    { 
            (yyval.node) = createnode('N', "neq", (yyvsp[(1) - (3)].node)->value != (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 67:
#line 376 "src/compiler.y"
    { 
            (yyval.node) = createnode('E', "eq", (yyvsp[(1) - (3)].node)->value == (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 68:
#line 379 "src/compiler.y"
    {
            Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].node)->name);
            if (sym->type != TYPE_ARRAY_INT){
                yyerror("Not array so indexing is not possible");
                (yyval.node) = NULL;
            }
            else{
                (yyval.node) = createnode(0, "Array_exp", sym->value.int_arrayval[(int)(yyvsp[(3) - (4)].node)->value], NULL, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), NULL);
            }
        }
    break;

  case 69:
#line 389 "src/compiler.y"
    {
            Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (7)].node)->name);
            if (sym->type != TYPE_2DARRAY_INT){
                yyerror("Not array so indexing is not possible");
                (yyval.node) = NULL;
            }
            else{
                (yyval.node) = createnode(0, "2d_Array_exp", sym->value.int_arrayval[(int)(yyvsp[(3) - (7)].node)->value*sym->dim[1] + (int)(yyvsp[(6) - (7)].node)->value], NULL, (yyvsp[(1) - (7)].node), createnode(0, "2d_array_index", 0, NULL, (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node), NULL), NULL);
            }
        }
    break;

  case 70:
#line 402 "src/compiler.y"
    { 
    Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (1)].var));
    if (!sym) { 
        printf("%s\n", (yyvsp[(1) - (1)].var));
        yyerror("Error: Undefined variable used in expression");
        return 0;
    }
    (yyval.node) = createnode(0, (yyvsp[(1) - (1)].var), sym->value.intval, sym, NULL, NULL, NULL);
}
    break;

  case 71:
#line 412 "src/compiler.y"
    {
    Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].var));
    if (!sym){
        printf("%s\n", (yyvsp[(1) - (4)].var));
        yyerror("Error: Undefined variable used in expression\n ");
        return 0; 
    }
    if (sym->type != TYPE_ARRAY_INT){
        printf("%s\n", (yyvsp[(1) - (4)].var));
        yyerror("Error: Variable is not an array\n ");
        return 0; 
    }
    if (evaluate_expr((yyvsp[(3) - (4)].node), symbol_table) >= sym->size){
       yyerror("Error: index out of range"); 
       return 0; 
    }
    (yyval.node) = createnode(0, "Array_exp", sym->value.int_arrayval[(int)(yyvsp[(3) - (4)].node)->value], NULL, createnode(0, (yyvsp[(1) - (4)].var), 0, sym, NULL, NULL,NULL), (yyvsp[(3) - (4)].node), NULL);
}
    break;

  case 72:
#line 430 "src/compiler.y"
    {
                Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (7)].var));
                if (!sym){
                    printf("%s\n", (yyvsp[(1) - (7)].var));
                    yyerror("Error: Undefined variable used in expression\n ");
                    return 0; 
                }
                if (sym->type != TYPE_2DARRAY_INT){
                    printf("%s\n", (yyvsp[(1) - (7)].var));
                    yyerror("Error: Variable is not a 2D array\n ");
                    return 0; 
                }
                if (evaluate_expr((yyvsp[(3) - (7)].node), symbol_table) >= sym->dim[0] || evaluate_expr((yyvsp[(6) - (7)].node), symbol_table) >= sym->dim[1]){
                yyerror("Error: index out of range"); 
                return 0; 
                }
        (yyval.node) = createnode(0, "2d_Array_exp", sym->value.int_arrayval[(int)(yyvsp[(3) - (7)].node)->value * sym->dim[1] +(int)(yyvsp[(6) - (7)].node)->value], NULL, createnode(0, (yyvsp[(1) - (7)].var), 0, sym, NULL, NULL,NULL), createnode(0, "2d_array_index", 0, NULL, (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node), NULL), NULL);
        }
    break;


/* Line 1267 of yacc.c.  */
#line 2292 "y.tab.c"
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


#line 453 "src/compiler.y"


void yyerror ( const char  *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(){
yyparse();
free_tree(root);
free_symbol_table(symbol_table);
}





