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
     READ = 262,
     WRITE = 263,
     BEGDECL = 264,
     ENDDECL = 265,
     DECL = 266,
     BREAK = 267,
     CONTINUE = 268,
     VAR = 269,
     NUM = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     ENDIF = 274,
     LOGICAL_AND = 275,
     LOGICAL_NOT = 276,
     LOGICAL_OR = 277,
     EQUALEQUAL = 278,
     LESSTHANOREQUAL = 279,
     GREATERTHANOREQUAL = 280,
     NOTEQUAL = 281,
     WHILE = 282,
     DO = 283,
     ENDWHILE = 284,
     FOR = 285,
     T = 286,
     F = 287,
     MAIN = 288,
     RETURN = 289
   };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define READ 262
#define WRITE 263
#define BEGDECL 264
#define ENDDECL 265
#define DECL 266
#define BREAK 267
#define CONTINUE 268
#define VAR 269
#define NUM 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define LOGICAL_AND 275
#define LOGICAL_NOT 276
#define LOGICAL_OR 277
#define EQUALEQUAL 278
#define LESSTHANOREQUAL 279
#define GREATERTHANOREQUAL 280
#define NOTEQUAL 281
#define WHILE 282
#define DO 283
#define ENDWHILE 284
#define FOR 285
#define T 286
#define F 287
#define MAIN 288
#define RETURN 289




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
	char* var;
	struct Node* node;
}
/* Line 193 of yacc.c.  */
#line 191 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 204 "y.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
      47,    48,    39,    37,    43,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      35,    46,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    15,    19,    20,    23,    27,
      29,    31,    33,    37,    39,    44,    45,    48,    50,    53,
      56,    58,    61,    64,    68,    72,    77,    78,    80,    82,
      86,    88,    94,   102,   104,   116,   126,   137,   146,   156,
     166,   177,   188,   190,   193,   195,   197,   199,   203,   207,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   247,
     252,   255,   259,   263,   265
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    59,    -1,    53,     3,    59,     4,
      -1,    11,    54,    10,    -1,     9,    54,    10,    -1,    -1,
      55,    54,    -1,    56,    57,    42,    -1,     5,    -1,     6,
      -1,    58,    -1,    58,    43,    57,    -1,    14,    -1,    14,
      44,    15,    45,    -1,    -1,    59,    60,    -1,     1,    -1,
      61,    42,    -1,    62,    42,    -1,    66,    -1,    12,    42,
      -1,    13,    42,    -1,    69,    46,    68,    -1,    70,    46,
      68,    -1,     8,    47,    63,    48,    -1,    -1,    64,    -1,
      65,    -1,    65,    43,    64,    -1,    68,    -1,    16,    68,
      17,    59,    19,    -1,    16,    68,    17,    59,    18,    59,
      19,    -1,    67,    -1,    30,    47,    61,    42,    68,    42,
      61,    48,    49,    59,    50,    -1,    30,    47,    42,    68,
      42,    48,    49,    59,    50,    -1,    30,    47,    42,    68,
      42,    61,    48,    49,    59,    50,    -1,    30,    47,    42,
      42,    48,    49,    59,    50,    -1,    30,    47,    61,    42,
      42,    48,    49,    59,    50,    -1,    30,    47,    42,    42,
      61,    48,    49,    59,    50,    -1,    30,    47,    61,    42,
      68,    42,    48,    49,    59,    50,    -1,    30,    47,    61,
      42,    42,    61,    48,    49,    59,    50,    -1,    15,    -1,
      38,    15,    -1,    69,    -1,    31,    -1,    32,    -1,    47,
      68,    48,    -1,    68,    37,    68,    -1,    68,    38,    68,
      -1,    68,    39,    68,    -1,    68,    40,    68,    -1,    68,
      41,    68,    -1,    68,    35,    68,    -1,    68,    36,    68,
      -1,    68,    25,    68,    -1,    68,    24,    68,    -1,    68,
      26,    68,    -1,    68,    23,    68,    -1,    69,    44,    68,
      45,    -1,    21,    68,    -1,    68,    20,    68,    -1,    68,
      22,    68,    -1,    14,    -1,    14,    44,    68,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    70,    86,    91,    98,    99,   113,   122,
     123,   127,   128,   137,   149,   166,   167,   177,   181,   191,
     194,   197,   198,   200,   210,   216,   220,   221,   232,   233,
     239,   243,   246,   249,   252,   255,   258,   261,   264,   267,
     270,   273,   278,   281,   284,   288,   291,   294,   298,   301,
     304,   307,   315,   324,   327,   330,   333,   336,   339,   342,
     352,   353,   354,   358,   368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "END", "T_INT", "T_BOOL", "READ",
  "WRITE", "BEGDECL", "ENDDECL", "DECL", "BREAK", "CONTINUE", "VAR", "NUM",
  "IF", "THEN", "ELSE", "ENDIF", "LOGICAL_AND", "LOGICAL_NOT",
  "LOGICAL_OR", "EQUALEQUAL", "LESSTHANOREQUAL", "GREATERTHANOREQUAL",
  "NOTEQUAL", "WHILE", "DO", "ENDWHILE", "FOR", "T", "F", "MAIN", "RETURN",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['",
  "']'", "'='", "'('", "')'", "'{'", "'}'", "$accept", "Prog", "Gdecl_sec",
  "Gdecl_list", "Gdecl", "type", "Gid_list", "Gid", "stmt_list",
  "statement", "assign_stmt", "write_stmt", "para_list", "para_list1",
  "para", "cond_stmt", "for_stmt", "expr", "var_expr", "array_expr", 0
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
     285,   286,   287,   288,   289,    60,    62,    43,    45,    42,
      47,    37,    59,    44,    91,    93,    61,    40,    41,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    62,    63,    63,    64,    64,
      65,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     3,     0,     2,     3,     1,
       1,     1,     3,     1,     4,     0,     2,     1,     2,     2,
       1,     2,     2,     3,     3,     4,     0,     1,     1,     3,
       1,     5,     7,     1,    11,     9,    10,     8,     9,     9,
      10,    10,     1,     2,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       2,     3,     3,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     6,     0,     0,     9,    10,     0,     6,     0,
       0,     1,    17,     0,     2,     5,     7,    13,     0,    11,
       4,     0,     0,     0,     0,    63,     0,     0,    16,     0,
       0,    20,    33,     0,     0,     0,     8,     0,     3,    26,
      21,    22,     0,    63,    42,     0,    45,    46,     0,     0,
       0,    44,     0,    18,    19,     0,     0,     0,    12,     0,
      27,    28,    30,     0,    60,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    14,    25,     0,    64,
      47,     0,    61,    62,    58,    56,    55,    57,    53,    54,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    29,
       0,    31,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,    39,    35,     0,    38,     0,     0,     0,
      36,    41,    40,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     7,     8,     9,    18,    19,    14,    28,
      29,    30,    59,    60,    61,    31,    32,    62,    51,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -40
static const yytype_int16 yypact[] =
{
      28,     7,     7,    21,   255,   -40,   -40,    15,     7,    10,
      41,   -40,   -40,   283,    14,   -40,   -40,   -39,    16,    32,
     -40,   332,    29,    36,    39,    13,    65,    35,   -40,    43,
      45,   -40,   -40,    42,    44,    74,   -40,    10,   -40,    65,
     -40,   -40,    65,   -40,   -40,    65,   -40,   -40,    76,    65,
     379,    50,    -8,   -40,   -40,    65,    65,    55,   -40,    47,
     -40,    62,   455,   329,   -40,   -40,   294,   264,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,   205,    64,   455,   455,   -40,   -40,    65,   -40,
     -40,   444,   -40,   -40,   134,   134,   134,   134,   462,   462,
       9,     9,   -18,   -18,    34,   353,    -6,   386,   207,   -40,
     292,   -40,   -40,    59,    61,    -5,    -3,   409,   453,     2,
      66,    69,    72,    75,    73,     5,   -40,   128,     2,     2,
      78,     2,    81,    83,    87,   -40,   135,   147,     2,   154,
       2,     2,    89,   -40,   -40,   175,   -40,   182,   194,     2,
     -40,   -40,   -40,   201,   -40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,    33,   -40,   -40,    77,   -40,   -12,   -40,
     -32,   -40,   -40,    22,   -40,   -40,   -40,    -9,   -14,   -40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yytype_int16 yytable[] =
{
      33,    21,    68,    12,    69,    35,    25,    33,    25,    25,
     -15,    25,     5,     6,   -15,   -15,   -15,    50,   -15,    25,
      83,    11,    22,    80,    17,    15,    23,    24,    25,    68,
      26,    69,   -15,    63,    82,    10,    64,     1,    33,     2,
      66,    16,   113,   121,    27,   123,    84,    85,    78,    79,
      80,    20,   -15,   133,    68,    91,    69,    42,    36,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   107,   114,    37,    39,    33,    40,    43,
      44,    41,    52,   122,   124,    53,    45,    54,    55,    57,
      56,    65,    33,   134,    81,    87,    46,    47,   118,   117,
      86,    33,    33,    48,    33,    88,   108,   127,   119,   120,
     109,    33,    49,    33,    58,   128,   136,   137,   129,   139,
     130,   132,    33,    33,   131,    33,   145,   138,   147,   148,
     140,    33,   141,    33,    33,   142,    22,   153,   149,    33,
      23,    24,    25,    22,    26,     0,     0,    23,    24,    25,
       0,    26,     0,     0,    68,    22,    69,     0,    27,    23,
      24,    25,    22,    26,     0,    27,    23,    24,    25,     0,
      26,    76,    77,    78,    79,    80,     0,    27,   135,     0,
       0,     0,     0,    22,    27,   143,     0,    23,    24,    25,
      22,    26,     0,     0,    23,    24,    25,   144,    26,     0,
       0,     0,    22,     0,   146,    27,    23,    24,    25,    22,
      26,     0,    27,    23,    24,    25,     0,    26,     0,    43,
      44,    43,    44,     0,    27,   150,    45,     0,    45,     0,
       0,    27,   151,     0,     0,     0,    46,    47,    46,    47,
       0,     0,     0,    48,   152,    48,     0,   106,     0,   116,
       0,   154,    49,     0,    49,   -15,    12,     0,    13,     0,
       0,     0,     0,   -15,     0,    12,     0,   -15,   -15,   -15,
       0,   -15,   -15,     0,     0,     0,   -15,   -15,   -15,     0,
     -15,     0,   -15,   -15,    12,   -15,     0,   -15,     0,     0,
       0,   -15,     0,    12,   -15,   -15,   -15,   -15,     0,   -15,
     -15,     0,     0,     0,   -15,   -15,   -15,     0,   -15,     0,
       0,   -15,     0,   -15,    68,     0,    69,    70,    71,    72,
      73,     0,   -15,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    38,     0,     0,     0,
      22,     0,    90,     0,    23,    24,    25,     0,    26,    68,
       0,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,     0,    27,     0,    74,    75,    76,    77,    78,    79,
      80,     0,     0,    68,    89,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,     0,    67,     0,   112,    68,
       0,    69,    70,    71,    72,    73,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,    77,    78,    79,
      80,    74,    75,    76,    77,    78,    79,    80,   115,    68,
       0,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,   125,    22,     0,     0,     0,    23,    24,    25,     0,
      26,    22,   110,   111,     0,    23,    24,    25,     0,    26,
       0,     0,   126,     0,    27,    68,     0,    69,    70,    71,
      72,    73,    68,    27,    69,    70,    71,    72,    73,     0,
      74,    75,    76,    77,    78,    79,    80,     0,     0,    76,
      77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      14,    13,    20,     1,    22,    44,    14,    21,    14,    14,
       8,    14,     5,     6,    12,    13,    14,    26,    16,    14,
      52,     0,     8,    41,    14,    10,    12,    13,    14,    20,
      16,    22,    30,    42,    42,     2,    45,     9,    52,    11,
      49,     8,    48,    48,    30,    48,    55,    56,    39,    40,
      41,    10,    50,    48,    20,    67,    22,    44,    42,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   106,    43,    47,    91,    42,    14,
      15,    42,    47,   115,   116,    42,    21,    42,    46,    15,
      46,    15,   106,   125,    44,    48,    31,    32,   110,   108,
      45,   115,   116,    38,   118,    43,    42,   119,    49,    48,
      88,   125,    47,   127,    37,    49,   128,   129,    49,   131,
      48,    48,   136,   137,    49,   139,   138,    49,   140,   141,
      49,   145,    49,   147,   148,    48,     8,   149,    49,   153,
      12,    13,    14,     8,    16,    -1,    -1,    12,    13,    14,
      -1,    16,    -1,    -1,    20,     8,    22,    -1,    30,    12,
      13,    14,     8,    16,    -1,    30,    12,    13,    14,    -1,
      16,    37,    38,    39,    40,    41,    -1,    30,    50,    -1,
      -1,    -1,    -1,     8,    30,    50,    -1,    12,    13,    14,
       8,    16,    -1,    -1,    12,    13,    14,    50,    16,    -1,
      -1,    -1,     8,    -1,    50,    30,    12,    13,    14,     8,
      16,    -1,    30,    12,    13,    14,    -1,    16,    -1,    14,
      15,    14,    15,    -1,    30,    50,    21,    -1,    21,    -1,
      -1,    30,    50,    -1,    -1,    -1,    31,    32,    31,    32,
      -1,    -1,    -1,    38,    50,    38,    -1,    42,    -1,    42,
      -1,    50,    47,    -1,    47,     0,     1,    -1,     3,    -1,
      -1,    -1,    -1,     8,    -1,     1,    -1,    12,    13,    14,
      -1,    16,     8,    -1,    -1,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    19,     1,    30,    -1,     4,    -1,    -1,
      -1,     8,    -1,     1,    30,    12,    13,    14,    -1,    16,
       8,    -1,    -1,    -1,    12,    13,    14,    -1,    16,    -1,
      -1,    19,    -1,    30,    20,    -1,    22,    23,    24,    25,
      26,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,     4,    -1,    -1,    -1,
       8,    -1,    48,    -1,    12,    13,    14,    -1,    16,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    20,    45,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    17,    -1,    45,    20,
      -1,    22,    23,    24,    25,    26,    20,    -1,    22,    23,
      24,    25,    26,    -1,    35,    36,    37,    38,    39,    40,
      41,    35,    36,    37,    38,    39,    40,    41,    42,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,     8,    -1,    -1,    -1,    12,    13,    14,    -1,
      16,     8,    18,    19,    -1,    12,    13,    14,    -1,    16,
      -1,    -1,    19,    -1,    30,    20,    -1,    22,    23,    24,
      25,    26,    20,    30,    22,    23,    24,    25,    26,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    37,
      38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    11,    52,    53,     5,     6,    54,    55,    56,
      54,     0,     1,     3,    59,    10,    54,    14,    57,    58,
      10,    59,     8,    12,    13,    14,    16,    30,    60,    61,
      62,    66,    67,    69,    70,    44,    42,    43,     4,    47,
      42,    42,    44,    14,    15,    21,    31,    32,    38,    47,
      68,    69,    47,    42,    42,    46,    46,    15,    57,    63,
      64,    65,    68,    68,    68,    15,    68,    17,    20,    22,
      23,    24,    25,    26,    35,    36,    37,    38,    39,    40,
      41,    44,    42,    61,    68,    68,    45,    48,    43,    45,
      48,    59,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    42,    68,    42,    64,
      18,    19,    45,    48,    61,    42,    42,    68,    59,    49,
      48,    48,    61,    48,    61,    42,    19,    59,    49,    49,
      48,    49,    48,    48,    61,    50,    59,    59,    49,    59,
      49,    49,    48,    50,    50,    59,    50,    59,    59,    49,
      50,    50,    50,    59,    50
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
#line 55 "src/compiler.y"
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
#line 70 "src/compiler.y"
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
#line 86 "src/compiler.y"
    { printf("printing symbol table values\n");
			 printsymboltable(symbol_table); 
	(yyval.node) = createnode(0, "decl_list", 0, NULL, (yyvsp[(2) - (3)].node), NULL, NULL);
// $$ = $2;
}
    break;

  case 5:
#line 91 "src/compiler.y"
    { printf("printing symbol table values\n");
			 printsymboltable(symbol_table); 
	(yyval.node) = createnode(0, "decl_list", 0, NULL, (yyvsp[(2) - (3)].node), NULL, NULL);
// $$ = $2;
}
    break;

  case 6:
#line 98 "src/compiler.y"
    {(yyval.node) = NULL;}
    break;

  case 7:
#line 99 "src/compiler.y"
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
#line 113 "src/compiler.y"
    {Type t = (strcmp((yyvsp[(1) - (3)].node)->name,"integer") == 0)?TYPE_INT : TYPE_BOOL;
			Node* p = (yyvsp[(2) - (3)].node);
			while(p != NULL ){
                if (strcmp(p->name,"Array")!=0)
				    p->var_pointer->type = t;
				p=p->extra;
			}
			(yyval.node)= createnode(0, "decl", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), NULL);}
    break;

  case 9:
#line 122 "src/compiler.y"
    { (yyval.node) = createnode(0, "integer", 0, NULL, NULL, NULL, NULL);}
    break;

  case 10:
#line 123 "src/compiler.y"
    { (yyval.node) = createnode(0, "boolean",0, NULL, NULL, NULL, NULL); }
    break;

  case 11:
#line 127 "src/compiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:
#line 128 "src/compiler.y"
    { 
        Node* temp = (yyvsp[(1) - (3)].node);
        while (temp->extra != NULL) temp = temp->extra;
        temp->extra = (yyvsp[(3) - (3)].node);
        (yyval.node) = (yyvsp[(1) - (3)].node);
    }
    break;

  case 13:
#line 137 "src/compiler.y"
    { 
        Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (1)].var));
        if (sym == NULL) {
            insertSymbol(&symbol_table, (yyvsp[(1) - (1)].var), TYPE_INT, 0, 0); 
            sym = lookupSymbol(symbol_table, (yyvsp[(1) - (1)].var)); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        (yyval.node) = createnode(0, (yyvsp[(1) - (1)].var), sym->value.intval, sym, NULL, NULL, NULL);
    }
    break;

  case 14:
#line 149 "src/compiler.y"
    {  
        // printf("hii"); 
        Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].var));
        if (sym == NULL) {
            insertSymbol(&symbol_table, (yyvsp[(1) - (4)].var), TYPE_ARRAY_INT, (yyvsp[(3) - (4)].num), 0); 
            sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].var)); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        (yyval.node) = createnode(0, "Array", 0, NULL, createnode(0, "size", (yyvsp[(3) - (4)].num), NULL, NULL,NULL,NULL), createnode(0, (yyvsp[(1) - (4)].var), 0, sym, NULL, NULL,NULL),NULL);
    }
    break;

  case 15:
#line 166 "src/compiler.y"
    { (yyval.node) = NULL; }
    break;

  case 16:
#line 167 "src/compiler.y"
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

  case 17:
#line 177 "src/compiler.y"
    { yyerror("Syntax error in statement."); }
    break;

  case 18:
#line 181 "src/compiler.y"
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

  case 19:
#line 191 "src/compiler.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node);
        // evaluate_statement($$);
        }
    break;

  case 20:
#line 194 "src/compiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);
        // evaluate_statement($$);
        }
    break;

  case 21:
#line 197 "src/compiler.y"
    { (yyval.node) = createnode(0, "break", 0, NULL, NULL, NULL, NULL); }
    break;

  case 22:
#line 198 "src/compiler.y"
    {  (yyval.node) = createnode(0, "continue", 0, NULL, NULL, NULL, NULL); }
    break;

  case 23:
#line 200 "src/compiler.y"
    { 
    (yyval.node) = createnode('=', "assign", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);

    
    // if ($1->var_pointer) {  
    //     $1->var_pointer->value.intval = $3->value;  
    // } else {
    //     yyerror("Error: Assignment to an undefined variable!");
    // }
}
    break;

  case 24:
#line 210 "src/compiler.y"
    {
            (yyval.node) = createnode('=', "assign_array", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL); 
    //    $1->left->var_pointer->value.int_arrayval[$1->right->value] = $3->value;  
    }
    break;

  case 25:
#line 216 "src/compiler.y"
    { 
    (yyval.node) = createnode(0, "write", 0, NULL,(yyvsp[(3) - (4)].node), NULL, NULL);
}
    break;

  case 26:
#line 220 "src/compiler.y"
    { (yyval.node) = NULL; }
    break;

  case 27:
#line 221 "src/compiler.y"
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

  case 28:
#line 232 "src/compiler.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 29:
#line 233 "src/compiler.y"
    { 
                (yyval.node) = (yyvsp[(1) - (3)].node); 
                (yyvsp[(1) - (3)].node)->extra = (yyvsp[(3) - (3)].node); 
           }
    break;

  case 30:
#line 239 "src/compiler.y"
    { 
    (yyval.node) = createnode(0, "parameter", (yyvsp[(1) - (1)].node)->value, NULL, (yyvsp[(1) - (1)].node), NULL, NULL); 
}
    break;

  case 31:
#line 243 "src/compiler.y"
    { 
    (yyval.node) = createnode(0,"if-then", 0, NULL,  createnode(0,"if", 0, NULL, (yyvsp[(2) - (5)].node),createnode(0,"then", 0, NULL, (yyvsp[(4) - (5)].node),NULL,NULL),NULL), NULL, NULL); 
                                                }
    break;

  case 32:
#line 246 "src/compiler.y"
    { 
            (yyval.node) = createnode(0,"if-then-else", 0, NULL,  createnode(0,"if", 0, NULL, (yyvsp[(2) - (7)].node),createnode(0,"then", 0, NULL, (yyvsp[(4) - (7)].node),NULL,NULL),createnode(0,"else", 0, NULL, (yyvsp[(6) - (7)].node),NULL,NULL)), NULL, NULL);  
            }
    break;

  case 33:
#line 249 "src/compiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 34:
#line 252 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (11)].node),createnode(0, "final-condition", 0, NULL, (yyvsp[(5) - (11)].node), NULL, NULL),createnode(0, "step", 0, NULL, (yyvsp[(7) - (11)].node), NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(10) - (11)].node), NULL, NULL), NULL);
            }
    break;

  case 35:
#line 255 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL, createnode(0, "final-condition", 0, NULL, (yyvsp[(4) - (9)].node), NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(8) - (9)].node), NULL, NULL), NULL);
            }
    break;

  case 36:
#line 258 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL, (yyvsp[(4) - (10)].node), NULL, NULL),createnode(0, "step", 0, NULL, (yyvsp[(6) - (10)].node), NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(9) - (10)].node), NULL, NULL), NULL);
            }
    break;

  case 37:
#line 261 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(7) - (8)].node), NULL, NULL), NULL);
            }
    break;

  case 38:
#line 264 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (9)].node),createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(8) - (9)].node), NULL, NULL), NULL);
            }
    break;

  case 39:
#line 267 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL,(yyvsp[(5) - (9)].node) , NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(8) - (9)].node), NULL, NULL), NULL);
            }
    break;

  case 40:
#line 270 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (10)].node),createnode(0, "final-condition", 0, NULL, (yyvsp[(5) - (10)].node), NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(9) - (10)].node), NULL, NULL), NULL);
            }
    break;

  case 41:
#line 273 "src/compiler.y"
    { 
                (yyval.node) = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, (yyvsp[(3) - (10)].node),createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, (yyvsp[(6) - (10)].node), NULL, NULL)), createnode(0, "in-loop", 0, NULL, (yyvsp[(9) - (10)].node), NULL, NULL), NULL);
            }
    break;

  case 42:
#line 278 "src/compiler.y"
    { 
            (yyval.node) = createnode(0, "number", (yyvsp[(1) - (1)].num), NULL, NULL, NULL, NULL); 
        }
    break;

  case 43:
#line 281 "src/compiler.y"
    {  
            (yyval.node) = createnode(0, "number", -(yyvsp[(2) - (2)].num), NULL, NULL, NULL, NULL); 
        }
    break;

  case 44:
#line 284 "src/compiler.y"
    {  
            Symbol* sym = (yyvsp[(1) - (1)].node)->var_pointer; 
            (yyval.node) = createnode(0, "var_expr", sym ? sym->value.intval : 0, NULL, (yyvsp[(1) - (1)].node), NULL, NULL); 
        }
    break;

  case 45:
#line 288 "src/compiler.y"
    { 
            (yyval.node) = createnode(0, "T", 1, NULL, NULL, NULL, NULL);					  	
        }
    break;

  case 46:
#line 291 "src/compiler.y"
    { 
            (yyval.node) = createnode(0, "F", 0, NULL, NULL, NULL, NULL);
        }
    break;

  case 47:
#line 294 "src/compiler.y"
    {  
            (yyval.node) = (yyvsp[(2) - (3)].node);			
        }
    break;

  case 48:
#line 298 "src/compiler.y"
    {  
            (yyval.node) = createnode('+', "add", (yyvsp[(1) - (3)].node)->value + (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);					
        }
    break;

  case 49:
#line 301 "src/compiler.y"
    {  
            (yyval.node) = createnode('-', "subtract", (yyvsp[(1) - (3)].node)->value - (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);						
        }
    break;

  case 50:
#line 304 "src/compiler.y"
    {  
            (yyval.node) = createnode('*', "multiply", (yyvsp[(1) - (3)].node)->value * (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);			
        }
    break;

  case 51:
#line 307 "src/compiler.y"
    {  
            if ((yyvsp[(3) - (3)].node)->value == 0) {
                yyerror("Division by zero!"); 
                (yyval.node) = createnode('/', "divide", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            } else {
                (yyval.node) = createnode('/', "divide", (yyvsp[(1) - (3)].node)->value / (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            }
        }
    break;

  case 52:
#line 315 "src/compiler.y"
    { 
            if ((yyvsp[(3) - (3)].node)->value == 0) {
                yyerror("Modulo by zero!"); 
                (yyval.node) = createnode('%', "mod", 0, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            } else {
                (yyval.node) = createnode('%', "mod", (yyvsp[(1) - (3)].node)->value % (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
            }
        }
    break;

  case 53:
#line 324 "src/compiler.y"
    { 
            (yyval.node) = createnode('<', "lt", (yyvsp[(1) - (3)].node)->value < (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 54:
#line 327 "src/compiler.y"
    { 
            (yyval.node) = createnode('>', "gt", (yyvsp[(1) - (3)].node)->value > (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 55:
#line 330 "src/compiler.y"
    {  
            (yyval.node) = createnode('G', "gte", (yyvsp[(1) - (3)].node)->value >= (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 56:
#line 333 "src/compiler.y"
    { 
            (yyval.node) = createnode('L', "lte", (yyvsp[(1) - (3)].node)->value <= (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 57:
#line 336 "src/compiler.y"
    { 
            (yyval.node) = createnode('N', "neq", (yyvsp[(1) - (3)].node)->value != (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 58:
#line 339 "src/compiler.y"
    { 
            (yyval.node) = createnode('E', "eq", (yyvsp[(1) - (3)].node)->value == (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL);
        }
    break;

  case 59:
#line 342 "src/compiler.y"
    {
            Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].node)->name);
            if (sym->type != TYPE_ARRAY_INT){
                yyerror("Not array so indexing is not possible");
                (yyval.node) = NULL;
            }
            else{
                (yyval.node) = createnode(0, "Array_exp", sym->value.int_arrayval[(yyvsp[(3) - (4)].node)->value], NULL, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), NULL);
            }
        }
    break;

  case 60:
#line 352 "src/compiler.y"
    { (yyval.node) = createnode('!', "not", !(yyvsp[(2) - (2)].node)->value, NULL, (yyvsp[(2) - (2)].node),NULL,NULL );						}
    break;

  case 61:
#line 353 "src/compiler.y"
    { (yyval.node) = createnode('&', "and", (yyvsp[(1) - (3)].node)->value && (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node),NULL );						}
    break;

  case 62:
#line 354 "src/compiler.y"
    { 	(yyval.node) = createnode('|', "or", (yyvsp[(1) - (3)].node)->value || (yyvsp[(3) - (3)].node)->value, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node),NULL );					}
    break;

  case 63:
#line 358 "src/compiler.y"
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

  case 64:
#line 368 "src/compiler.y"
    {
    Symbol* sym = lookupSymbol(symbol_table, (yyvsp[(1) - (4)].var));
    if (!sym){
        printf("%s\n", (yyvsp[(1) - (4)].var));
        yyerror("Error: Undefined variable used in expression ");
        return 0; 
    }
    if (evaluate_expr((yyvsp[(3) - (4)].node), symbol_table) >= sym->size){
       yyerror("Error: index out of range"); 
       return 0; 
    }
    (yyval.node) = createnode(0, "Array_exp", sym->value.int_arrayval[(yyvsp[(3) - (4)].node)->value], NULL, createnode(0, (yyvsp[(1) - (4)].var), 0, sym, NULL, NULL,NULL), (yyvsp[(3) - (4)].node), NULL);
}
    break;


/* Line 1267 of yacc.c.  */
#line 2132 "y.tab.c"
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


#line 385 "src/compiler.y"


void yyerror ( const char  *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(){
yyparse();
free_tree(root);
free_symbol_table(symbol_table);
}





