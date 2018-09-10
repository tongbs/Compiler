/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    ID = 259,
    VAR = 260,
    ARRAY = 261,
    NUM = 262,
    OF = 263,
    INTEGER = 264,
    REAL = 265,
    FUNCTION = 266,
    PROCEDURE = 267,
    PBEGIN = 268,
    END = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    WHILE = 273,
    DO = 274,
    NOT = 275,
    ASSIGNMENT = 276,
    COLON = 277,
    COMMA = 278,
    DOT = 279,
    DOTDOT = 280,
    EQUAL = 281,
    NOTEQUAL = 282,
    GE = 283,
    GT = 284,
    LBRAC = 285,
    LE = 286,
    LPAREN = 287,
    LT = 288,
    MINUS = 289,
    PLUS = 290,
    RBRAC = 291,
    RPAREN = 292,
    SEMICOLON = 293,
    SLASH = 294,
    STAR = 295,
    UPARROW = 296
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ID 259
#define VAR 260
#define ARRAY 261
#define NUM 262
#define OF 263
#define INTEGER 264
#define REAL 265
#define FUNCTION 266
#define PROCEDURE 267
#define PBEGIN 268
#define END 269
#define IF 270
#define THEN 271
#define ELSE 272
#define WHILE 273
#define DO 274
#define NOT 275
#define ASSIGNMENT 276
#define COLON 277
#define COMMA 278
#define DOT 279
#define DOTDOT 280
#define EQUAL 281
#define NOTEQUAL 282
#define GE 283
#define GT 284
#define LBRAC 285
#define LE 286
#define LPAREN 287
#define LT 288
#define MINUS 289
#define PLUS 290
#define RBRAC 291
#define RPAREN 292
#define SEMICOLON 293
#define SLASH 294
#define STAR 295
#define UPARROW 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "parse.y" /* yacc.c:1909  */

    struct nodeType *node;

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
