/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "src/compiler.y"
{
	int num;
    double flnum;
	char* var;
	struct Node* node;
}
/* Line 1529 of yacc.c.  */
#line 128 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

