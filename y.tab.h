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
     INTEGER = 258,
     BINARY = 259,
     HEXA = 260,
     ARRAY_START = 261,
     ARRAY_END = 262,
     PLUS = 263,
     MPY = 264,
     TILDE = 265,
     L_BR = 266,
     R_BR = 267,
     RAND = 268,
     SEPARATOR = 269,
     INT_TYPE = 270,
     BIN_TYPE = 271,
     HEX_TYPE = 272,
     LINE_END = 273
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define BINARY 259
#define HEXA 260
#define ARRAY_START 261
#define ARRAY_END 262
#define PLUS 263
#define MPY 264
#define TILDE 265
#define L_BR 266
#define R_BR 267
#define RAND 268
#define SEPARATOR 269
#define INT_TYPE 270
#define BIN_TYPE 271
#define HEX_TYPE 272
#define LINE_END 273




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 70 "my_language.y"
{
  int int_value;
  char* str_value;
}
/* Line 1529 of yacc.c.  */
#line 90 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

