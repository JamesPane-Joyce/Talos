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
     IA_AND = 258,
     IA_EQUAL = 259,
     IA_EQUIV = 260,
     IA_EXISTS = 261,
     IA_FALSE = 262,
     IA_FORALL = 263,
     IA_IMPLIED = 264,
     IA_IMPLIES = 265,
     IA_NOT = 266,
     IA_OR = 267,
     IA_PROVE = 268,
     IA_TRUE = 269,
     IA_NUM = 270,
     IA_ID = 271
   };
#endif
/* Tokens.  */
#define IA_AND 258
#define IA_EQUAL 259
#define IA_EQUIV 260
#define IA_EXISTS 261
#define IA_FALSE 262
#define IA_FORALL 263
#define IA_IMPLIED 264
#define IA_IMPLIES 265
#define IA_NOT 266
#define IA_OR 267
#define IA_PROVE 268
#define IA_TRUE 269
#define IA_NUM 270
#define IA_ID 271




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 106 "iaparser.y"
{
  int       number;
  char*     string;
  SYMBOL    symbol;
  TERM      term;
  LIST      list;
}
/* Line 1489 of yacc.c.  */
#line 89 "iaparser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE ia_lval;

