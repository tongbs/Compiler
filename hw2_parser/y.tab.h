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
    ASSIGNMENT = 258,
    COLON = 259,
    COMMA = 260,
    DOT = 261,
    DOTDOT = 262,
    EQUAL = 263,
    FUNCTION = 264,
    GE = 265,
    GT = 266,
    LBRAC = 267,
    LE = 268,
    LPAREN = 269,
    LT = 270,
    MINUS = 271,
    NOTEQUAL = 272,
    PLUS = 273,
    RBRAC = 274,
    RPAREN = 275,
    SEMICOLON = 276,
    SLASH = 277,
    STAR = 278,
    NUMBER = 279,
    FLOAT = 280,
    ARRAY = 281,
    DO = 282,
    ELSE = 283,
    PBEGIN = 284,
    END = 285,
    IF = 286,
    VAR = 287,
    WHILE = 288,
    REALNUMBER = 289,
    STRING = 290,
    THEN = 291,
    PROCEDURE = 292,
    PROGRAM = 293,
    OF = 294,
    OR = 295,
    INTEGER = 296,
    NOT = 297,
    IDENTIFIER = 298
  };
#endif
/* Tokens.  */
#define ASSIGNMENT 258
#define COLON 259
#define COMMA 260
#define DOT 261
#define DOTDOT 262
#define EQUAL 263
#define FUNCTION 264
#define GE 265
#define GT 266
#define LBRAC 267
#define LE 268
#define LPAREN 269
#define LT 270
#define MINUS 271
#define NOTEQUAL 272
#define PLUS 273
#define RBRAC 274
#define RPAREN 275
#define SEMICOLON 276
#define SLASH 277
#define STAR 278
#define NUMBER 279
#define FLOAT 280
#define ARRAY 281
#define DO 282
#define ELSE 283
#define PBEGIN 284
#define END 285
#define IF 286
#define VAR 287
#define WHILE 288
#define REALNUMBER 289
#define STRING 290
#define THEN 291
#define PROCEDURE 292
#define PROGRAM 293
#define OF 294
#define OR 295
#define INTEGER 296
#define NOT 297
#define IDENTIFIER 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "standard-pascal-no.y" /* yacc.c:1909  */

    struct nodeType * node;

#line 144 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
