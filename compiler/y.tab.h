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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "src/compiler.y"
{
	int num;
	char* var;
	struct Node* node;
}
/* Line 1529 of yacc.c.  */
#line 123 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

