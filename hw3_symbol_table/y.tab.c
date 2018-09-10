/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct nodeType* newOpNode(int op);
extern struct nodeType* ASTRoot;
 

#line 77 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 13 "parse.y" /* yacc.c:355  */

    struct nodeType *node;

#line 203 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    32,    32,    54,    60,    69,   105,   111,   115,   132,
     138,   144,   153,   159,   167,   178,   189,   201,   207,   213,
     226,   242,   253,   257,   263,   268,   276,   283,   287,   291,
     301,   311,   319,   349,   355,   360,   371,   376,   384,   388,
     396,   400,   408,   412,   420,   426,   434,   446,   452,   458,
     466,   471,   478,   483,   491,   496,   501,   506,   511,   516,
     524
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ID", "VAR", "ARRAY", "NUM",
  "OF", "INTEGER", "REAL", "FUNCTION", "PROCEDURE", "PBEGIN", "END", "IF",
  "THEN", "ELSE", "WHILE", "DO", "NOT", "ASSIGNMENT", "COLON", "COMMA",
  "DOT", "DOTDOT", "EQUAL", "NOTEQUAL", "GE", "GT", "LBRAC", "LE",
  "LPAREN", "LT", "MINUS", "PLUS", "RBRAC", "RPAREN", "SEMICOLON", "SLASH",
  "STAR", "UPARROW", "$accept", "program", "identifier_list",
  "declarations", "type", "standard_type", "subprogram_declarations",
  "subprogram_declaration", "subprogram_head", "arguments",
  "parameter_list", "compound_statement", "optional_statements",
  "statement_list", "statement", "variable", "tail", "procedure_statement",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "addop", "mulop", "relop", "lambda", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -61

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,    21,    18,     8,   -95,    54,   -95,   -10,    60,    15,
     -95,   -95,    42,   -95,    54,    64,   -95,    -7,    67,    70,
      13,    28,   -95,    56,    39,    55,    55,   -11,     4,     4,
     -95,    72,    58,   -95,    74,   -95,   -95,   -95,     9,   -95,
      68,   -95,   -95,   -95,    59,   -95,    54,    77,   -95,    65,
       4,     4,   -95,   -95,    49,   -95,     4,     4,     4,    84,
      34,    43,   -95,    82,   -95,    13,     4,   -95,    95,   -95,
      62,    52,    63,   -95,    69,    14,   -95,     4,   -95,   -95,
      73,   -95,    13,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,     4,     4,   -95,   -95,     4,    13,   -95,   -95,    79,
      39,   -95,    54,    75,    76,     4,   -95,    20,   -95,    90,
      43,    57,   -95,   -95,   101,   -95,    71,   -95,   -95,   -95,
     -95,    13,    78,    39,   -95,   103,   -95,    39,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       4,    60,    60,     6,     0,     0,    13,     0,     0,     0,
      60,     0,    60,     0,     0,    60,    60,    34,     0,     0,
      28,     0,    22,    24,     0,    27,    23,    12,     0,     2,
       0,    11,     9,    10,     0,     7,     0,     0,    18,     0,
       0,     0,    31,    33,    60,    46,     0,     0,     0,     0,
      38,    40,    42,     0,    21,     0,     0,    14,     0,     5,
       0,     0,     0,    16,     0,     0,    36,     0,    44,    48,
       0,    49,     0,    56,    59,    58,    55,    57,    54,    51,
      50,     0,     0,    53,    52,     0,     0,    25,    26,     0,
       0,    17,     0,     0,    60,     0,    35,     0,    47,     0,
      41,    39,    43,    30,     0,    19,     0,    15,    32,    37,
      45,     0,     0,     0,    29,     0,    20,     0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -14,    87,   -94,    40,   -95,   -95,   -95,    89,
     -95,    -3,   -95,   -95,   -62,   -95,   -50,   -95,    41,   -27,
      24,    26,   -51,   -95,   -95,   -95,    30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    44,    45,    15,    21,    22,    47,
      71,    30,    31,    32,    33,    34,    52,    35,    75,    76,
      60,    61,    62,    91,    95,    92,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    59,    63,    97,    78,    79,   115,    81,    54,     1,
     -60,    55,    23,     8,    14,    24,     8,    27,     4,    50,
     109,    51,    20,    74,    56,     3,    20,     9,    28,   126,
      80,    29,    70,   128,   113,    67,    57,   105,    58,    98,
       5,    13,    16,   105,   112,    40,    41,    14,    42,    43,
      36,   106,    13,    11,   118,    48,    48,   120,     6,   124,
      83,    84,    85,    86,    10,    87,    37,    88,    89,    90,
      41,    25,    42,    43,    26,    18,    19,    20,   119,    50,
      39,    77,    93,    94,   100,     8,    64,    46,   116,   101,
     102,    89,    90,   123,     8,    66,    65,    69,    68,    72,
      82,    96,    99,    73,   114,   104,    50,   121,   122,    38,
     108,   127,   103,   117,   125,    49,   111,   110,   107
};

static const yytype_uint8 yycheck[] =
{
      14,    28,    29,    65,    54,    56,   100,    58,     4,     3,
      21,     7,    15,    23,     5,    22,    23,     4,     0,    30,
      82,    32,    13,    50,    20,     4,    13,    37,    15,   123,
      57,    18,    46,   127,    96,    38,    32,    23,    34,    66,
      32,    11,    12,    23,    95,     6,     7,     5,     9,    10,
      20,    37,    22,    38,   104,    25,    26,    37,     4,   121,
      26,    27,    28,    29,     4,    31,    38,    33,    34,    35,
       7,     4,     9,    10,     4,    11,    12,    13,   105,    30,
      24,    32,    39,    40,    22,    23,    14,    32,   102,    37,
      38,    34,    35,    22,    23,    21,    38,    38,    30,    22,
      16,    19,     7,    38,    25,    36,    30,    17,     7,    22,
      37,     8,    72,    38,    36,    26,    92,    91,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,     4,     0,    32,     4,    44,    23,    37,
       4,    38,    45,    68,     5,    48,    68,    44,    11,    12,
      13,    49,    50,    53,    22,     4,     4,     4,    15,    18,
      53,    54,    55,    56,    57,    59,    68,    38,    45,    24,
       6,     7,     9,    10,    46,    47,    32,    51,    68,    51,
      30,    32,    58,    68,     4,     7,    20,    32,    34,    61,
      62,    63,    64,    61,    14,    38,    21,    53,    30,    38,
      44,    52,    22,    38,    61,    60,    61,    32,    58,    64,
      61,    64,    16,    26,    27,    28,    29,    31,    33,    34,
      35,    65,    67,    39,    40,    66,    19,    56,    61,     7,
      22,    37,    38,    47,    36,    23,    37,    60,    37,    56,
      63,    62,    64,    56,    25,    46,    44,    38,    58,    61,
      37,    17,     7,    22,    56,    36,    46,     8,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     1,     1,     8,     1,
       1,     1,     3,     1,     3,     6,     4,     3,     1,     3,
       5,     3,     1,     1,     1,     3,     3,     1,     1,     6,
       4,     2,     4,     1,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     4,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 37 "parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = newNode(NODE_PROGRAM);
			deleteNode((yyvsp[-9].node));
			addChild((yyval.node),(yyvsp[-8].node));
			(yyvsp[-8].node)->nodeType = NODE_VARIABLE;
			deleteNode((yyvsp[-7].node));
			addChild((yyval.node),(yyvsp[-6].node));
			deleteNode((yyvsp[-5].node));
			deleteNode((yyvsp[-4].node));
			addChild((yyval.node),(yyvsp[-3].node));
			addChild((yyval.node),(yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[-1].node));
			deleteNode((yyvsp[0].node));
			ASTRoot = (yyval.node);
		}
#line 1397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_ID_LIST); 
        addChild((yyval.node), (yyvsp[0].node));
		(yyvsp[0].node)->nodeType = NODE_VARIABLE;
	}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-2].node);
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
		(yyvsp[0].node)->nodeType = NODE_VARIABLE;
	}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "parse.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].node)->nodeType != NODE_ARRAY ){
			(yyval.node) = (yyvsp[-5].node);
			deleteNode((yyvsp[-4].node));
			deleteNode((yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[-1].node));
			struct nodeType* temp_res=(yyvsp[-1].node)->child;
			if(temp_res!=NULL){
				while(temp_res->child!=NULL) temp_res=temp_res->child;
				addChild(temp_res,(yyvsp[-3].node));
			}else
			{
				addChild((yyvsp[-1].node),(yyvsp[-3].node));
			}
			deleteNode((yyvsp[0].node));
		}
		else
		{
			(yyval.node) = (yyvsp[-5].node);
			deleteNode((yyvsp[-4].node));
			deleteNode((yyvsp[-2].node));
			addChild((yyval.node),(yyvsp[-1].node));
			struct nodeType* temp_res=(yyvsp[-1].node)->child;
			if(temp_res!=NULL)
			{
				while(temp_res->child!=NULL) temp_res=temp_res->child;
				addChild(temp_res,(yyvsp[-3].node));
			}
			else
			{
				addChild((yyvsp[-1].node),(yyvsp[-3].node));
			}
			deleteNode((yyvsp[0].node));
		}
	}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_DECLARE);
	}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_ARRAY);
		(yyval.node)->varType = TYPE_ARRY;
		deleteNode((yyvsp[-7].node));
		deleteNode((yyvsp[-6].node));
		(yyval.node)->arry_start = (yyvsp[-5].node)->iValue;
		deleteNode((yyvsp[-5].node));
		deleteNode((yyvsp[-4].node));
		(yyval.node)->arry_end = (yyvsp[-3].node)->iValue;
		deleteNode((yyvsp[-3].node));
		deleteNode((yyvsp[-2].node));
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 133 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
		(yyval.node)->nodeType=NODE_TYPE;
		(yyval.node)->varType = TYPE_INT;
	}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 139 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
		(yyval.node)->nodeType=NODE_TYPE;
		(yyval.node)->varType = TYPE_REAL;
	}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
		(yyval.node)->nodeType=NODE_TYPE;
		(yyval.node)->varType = TYPE_NUM;
	}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 154 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-2].node);
		addChild((yyval.node),(yyvsp[-1].node));
		deleteNode((yyvsp[0].node));
	}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_SUBPROGRAM_LIST);
	}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_PROGRAM);
		addChild((yyval.node),(yyvsp[-2].node));
		addChild((yyval.node),(yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 179 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_FUNC);
		deleteNode((yyvsp[-5].node));
		addChild((yyval.node),(yyvsp[-1].node));
		addChild((yyvsp[-1].node),(yyvsp[-4].node));
		(yyvsp[-4].node)->nodeType = NODE_VARIABLE;
		addChild((yyval.node),(yyvsp[-3].node));
		deleteNode((yyvsp[-2].node));
		deleteNode((yyvsp[0].node));
	}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 190 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_PROCEDURE);
		deleteNode((yyvsp[-3].node));
		addChild((yyval.node),(yyvsp[-2].node));
		(yyvsp[-2].node)->nodeType = NODE_VARIABLE;
		addChild((yyval.node),(yyvsp[-1].node));
		deleteNode((yyvsp[0].node));
	}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "parse.y" /* yacc.c:1646  */
    {
		deleteNode((yyvsp[-2].node));
		(yyval.node) = (yyvsp[-1].node);
		deleteNode((yyvsp[0].node));
	}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 208 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = NULL;
	}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_PARA_LIST);
		addChild((yyval.node),(yyvsp[0].node));
		deleteNode((yyvsp[-1].node));
		if((yyvsp[0].node)->nodeType==NODE_ARRAY)
		{
			struct nodeType* temp_res=(yyvsp[0].node);
			while(temp_res->child!=NULL) temp_res = temp_res->child;
			addChild(temp_res,(yyvsp[-2].node));
		}
		else addChild((yyvsp[0].node),(yyvsp[-2].node));
	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 227 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-4].node);
		deleteNode((yyvsp[-3].node));
		addChild((yyval.node),(yyvsp[0].node));
		deleteNode((yyvsp[-1].node));
		if((yyvsp[0].node)->nodeType==NODE_ARRAY)
		{
			struct nodeType* temp_res=(yyvsp[0].node);
			while(temp_res->child!=NULL) temp_res = temp_res->child;
			addChild(temp_res,(yyvsp[-2].node));
		}
		else addChild((yyvsp[0].node),(yyvsp[-2].node));
	}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "parse.y" /* yacc.c:1646  */
    {
					deleteNode((yyvsp[-2].node));
					if((yyvsp[-1].node) != NULL) (yyval.node) = (yyvsp[-1].node);
					else (yyval.node) = NULL;
					deleteNode((yyvsp[0].node));
			   }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 254 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 258 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = NULL;
	}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 264 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_STMT_LIST);
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 269 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-2].node);
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 277 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_ASSIGN);
		addChild((yyval.node),(yyvsp[-2].node));
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 284 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 288 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 292 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_IF);
		deleteNode((yyvsp[-5].node));
		addChild((yyval.node),(yyvsp[-4].node));
		deleteNode((yyvsp[-3].node));
		addChild((yyval.node),(yyvsp[-2].node));
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 302 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_WHILE);
		deleteNode((yyvsp[-3].node));
		addChild((yyval.node),(yyvsp[-2].node));
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 312 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
		(yyvsp[-1].node)->nodeType=NODE_VARIABLE;
		if((yyvsp[0].node)->child != NULL) addChild((yyval.node),(yyvsp[0].node));
	}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 320 "parse.y" /* yacc.c:1646  */
    {
		deleteNode((yyvsp[-3].node));
		(yyval.node) = (yyvsp[0].node);
		struct nodeType *child = (yyvsp[0].node)->child;
		if(child == NULL) 
		{
			addChild((yyval.node),(yyvsp[-2].node));
		}
		else
		{ 
			struct nodeType *tchild = (yyvsp[0].node)->child->lsibling;
			if(child == tchild){
				(yyvsp[-2].node)->rsibling = child;
				child->rsibling = (yyvsp[-2].node);
				(yyvsp[-2].node)->lsibling=child;
				child->lsibling=(yyvsp[-2].node);
				(yyval.node)->child=(yyvsp[-2].node);
			}
			else
			{
				(yyvsp[-2].node)->rsibling = child;
				tchild->rsibling = (yyvsp[-2].node);
				(yyvsp[-2].node)->lsibling=tchild;
				child->lsibling=(yyvsp[-2].node);
				(yyval.node)->child=(yyvsp[-2].node);
			}
		}
		deleteNode((yyvsp[-1].node));
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 350 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_INDEX_LIST);
	}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 356 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
		(yyvsp[0].node)->nodeType=NODE_VARIABLE;
	}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 361 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_PROCEDURE);
		addChild((yyval.node),(yyvsp[-3].node));
		(yyvsp[-3].node)->nodeType=NODE_VARIABLE;
		deleteNode((yyvsp[-2].node));
		addChild((yyval.node),(yyvsp[-1].node));
		deleteNode((yyvsp[0].node));
	}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 372 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newNode(NODE_EXPR_LIST);
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 377 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-2].node);
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 385 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 389 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[-1].node)->op);
		addChild((yyval.node),(yyvsp[-2].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 397 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 401 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
		addChild((yyval.node),(yyvsp[-2].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 409 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 413 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
		addChild((yyval.node),(yyvsp[-2].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 421 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
		(yyvsp[-1].node)->nodeType = NODE_VARIABLE;
		if((yyvsp[0].node)->child != NULL) addChild((yyval.node),(yyvsp[0].node));
	}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 427 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-3].node);
		(yyvsp[-3].node)->nodeType = NODE_VARIABLE;
		deleteNode((yyvsp[-2].node));
		addChild((yyval.node),(yyvsp[-1].node));
		deleteNode((yyvsp[0].node));
	}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 435 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
		if((yyvsp[0].node)->valueValid == 1)
		{
			(yyvsp[0].node)->nodeType=NODE_INT;
		}
		else if((yyvsp[0].node)->valueValid == 2)
		{
			(yyvsp[0].node)->nodeType=NODE_REAL;
		}
	}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 447 "parse.y" /* yacc.c:1646  */
    {
		deleteNode((yyvsp[-2].node));
		(yyval.node) = (yyvsp[-1].node);
		deleteNode((yyvsp[0].node));
	}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 453 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode(OP_NOT);
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 459 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[-1].node)->op);
		deleteNode((yyvsp[-1].node));
		addChild((yyval.node),(yyvsp[0].node));
	}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 467 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 472 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 479 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 484 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 492 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 497 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 502 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 507 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 512 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 517 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpNode((yyvsp[0].node)->op);
		deleteNode((yyvsp[0].node));
	}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 524 "parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = NULL;
	}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2049 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 529 "parse.y" /* yacc.c:1906  */



struct nodeType *ASTRoot;

int yyerror(const char* s) 
{
    printf("Syntax error\n");
	exit(0);
}

struct nodeType* newOpNode(int op) 
{
    struct nodeType *node = newNode(NODE_OP);
    node->op = op;
    return node;
}


//-------------------------------------------------------------------------------
int current;
int flag=-1;
struct symbol* symTable[1024];
int temp_array[1024];

void openScope()
{
	flag++;
	current=flag;
	temp_array[flag]=1;
	symTable[flag]=NULL;
	return;
}

void closeScope()
{
	temp_array[current]=0;
	for(;current>=0;current--)
	{
		if(temp_array[current]==1) break;
	}
	return;
}

struct symbol* getSymbol(char* name,int type,struct argument* argv){    // in local
	struct symbol* create_sym=symTable[current];
	while(create_sym!=NULL)
	{
		if(strcmp(create_sym->name,name)==0)
		{
			if(create_sym->argValid==1 && argv==NULL) ;
			else if(create_sym->argValid==0 && argv!=NULL);
			else if(create_sym->argValid==1 && argv!=NULL && type!=create_sym->varType);
			else return create_sym;
		}
		create_sym = create_sym->next;
	}
	return create_sym;
}

void enterSymbol(char* name,int type,struct argument* argv,struct nodeType* arryhead,int func)
{
	if(getSymbol(name,type,argv)!=NULL)
	{
		printf("[ERROR]duplicate declaration temp_array %s!!!\n",name);
	}
	struct symbol* temp_res = malloc(sizeof(struct symbol));
	temp_res->next = NULL;
	temp_res->name = malloc(strlen(name)+1);
	strcpy(temp_res->name,name);
	temp_res->varType = type;
	
	if(argv==NULL) temp_res->argValid=0;
	else temp_res->argValid = 1;
	temp_res->isfunc = func;
	temp_res->argv = argv;
	temp_res->arryhead = arryhead;
	temp_res->init=0;
	
	struct symbol* st_symbol = symTable[current];
	if(st_symbol==NULL) symTable[current]=temp_res;
	else
	{
		while(st_symbol->next!=NULL) st_symbol = st_symbol->next;
		st_symbol->next = temp_res;
	}
	return;
}

void addList(struct nodeType* list,int type,struct nodeType* arryhead)
{
	struct nodeType* child = list->child;
	if(child!=NULL)
	{
		do
		{
			enterSymbol(child->string,type,NULL,arryhead,0);
			child = child->rsibling;
		}while(child!=list->child);
	}
}

void processDeclare(struct nodeType* node)
{
	struct nodeType* temp;
	switch(node->nodeType)
	{
		case NODE_DECLARE:
			break;
		case NODE_ID_LIST:
			break;
		case NODE_ARRAY:
			temp=node;
			node=node->child;
			int temp_res = 1;
			while(node->nodeType!=NODE_ID_LIST)
			{
				if(node->varType==4) temp_res++;
				else temp_res=temp_res*10 + node->varType;
				node = node->child;
			}
			addList(node,temp_res,temp);
			break;
		case NODE_TYPE:
			addList(node->child,node->varType,NULL);
			return;
	}
	
	struct nodeType *child = node->child;
    if(child != NULL) 
	{
        do {
            processDeclare(child);
            child = child->rsibling;
        } while(child != node->child);
    }
}

struct argument* makeArg(struct nodeType* node)
{  
	struct nodeType *child = node->child;  
	struct nodeType *first = child;
	struct argument* head = NULL;
	do{
		int count1=0;
		struct nodeType *temp_res;
		int note ;

		switch(child->nodeType)
		{
			case NODE_ARRAY:
				note=1;
				temp_res = child;
				
				temp_res=temp_res->child;
				
				while(temp_res->nodeType!=NODE_ID_LIST){
					
					if(temp_res->varType==4) note++;
					else note=note*10 + temp_res->varType;
					temp_res = temp_res->child;
				}
				break;
				
			case NODE_TYPE:
				note = child->varType;
			
				break;
		};
		temp_res = child;
		temp_res = temp_res->child;
		struct nodeType *st_symbol2 = temp_res->child;
		do
		{
			count1++;
			st_symbol2 = st_symbol2 -> rsibling;
		}while(st_symbol2!=temp_res->child);
		struct argument* n = malloc(sizeof(struct argument));
		n->argType = note;
		n->num = count1;
		n->next=NULL;
		if(head==NULL) head = n;
		else
		{
			struct argument* st_symbol = head;
			while(st_symbol->next!=NULL) st_symbol = st_symbol->next;
			st_symbol->next = n;
		}
		child = child->rsibling;
	}while(child!=first);
	
	return head;
}

struct symbol* findVARall(char* name)
{
	int temp=current;
	while(temp>=0)
	{
		if(temp_array[temp]==0)
		{
			temp--;
			continue;
		}
		struct symbol* create_sym=symTable[temp];
		while(create_sym!=NULL)
		{
			if(strcmp(create_sym->name,name)==0 && create_sym->argValid==0)
			{
				return create_sym;
			}
			create_sym = create_sym->next;
		}
		temp--;
	}
	return NULL;
}

int argCheck(struct nodeType* node,struct argument* argv){ 
	struct nodeType* child = node->child;
	int compiler=argv->num;
	
	do
	{
		int temp2;
		if(child->nodeType==NODE_INT) temp2 = 1;
		else if(child->nodeType==NODE_REAL) temp2=2;
		else if(child->nodeType==NODE_VARIABLE) temp2=varValid(child,NULL);
		else if(child->nodeType==NODE_OP)
		{
			temp2=expValid(child,1);
			if(temp2==0) temp2=expValid(child,2);
		}
		if(temp2==argv->argType);
		else
		{
			printf("[ERROR]argument type error!!!");
			return 0;
		}

		(compiler)--;
		if(compiler==0)
		{
			argv=argv->next;
			if(argv!=NULL) compiler=argv->num;
		}
		child = child->rsibling;
		if(argv==NULL && child!=node->child)
		{
			printf("[ERROR]more arguments in this declaration");
			return 0;
		}
	}
	while(child!=node->child);
	if(argv==NULL) return 1;
	else
	{
		printf("[ERROR]fewer arguments in this declaration");
		return 0;
	}
}

struct symbol* findFUNCall(char* name)
{
	int temp=current;
	while(temp>=0)
	{
		if(temp_array[temp]==0)
		{
			temp--;
			continue;
		}
		struct symbol* create_sym=symTable[temp];
		while(create_sym!=NULL)
		{
			if(strcmp(create_sym->name,name)==0 && create_sym->argValid==1 )
			{
				return create_sym;
			}
			create_sym = create_sym->next;
		}
		temp--;
	}
	return NULL;
}

int varValid(struct nodeType* node,int* isfunc)
{  
	if(node->child==NULL)
	{ 
		struct symbol* temp_res=findVARall(node->string);
		if(temp_res==NULL)
		{
			printf("[ERROR]variable %s does not exist",node->string);
			return -1;
		}
		else
		{
			if(isfunc!=NULL) *isfunc = temp_res->isfunc;
			return temp_res->varType;
		}
	}
	else if(node->child->nodeType == NODE_INDEX_LIST)
	{
		struct symbol* temp_res=findVARall(node->string);
		if(temp_res==NULL)
		{
			printf("[ERROR]variable %s does not exist",node->string);
			return -1;
		}
		else
		{
			int project = indexCheck(node->child,temp_res);
			if(project==0)
			{
				printf(" ---> variable %s the index does not in the range!!!\n",node->string);
				return (temp_res->varType)%10;
			}
			else
			{
				return (temp_res->varType)%10;
			}
		}
	}
	else if(node->child->nodeType==NODE_EXPR_LIST)
	{  
		struct symbol* temp_res=findFUNCall(node->string);
		if(temp_res==NULL)
		{
			printf("function/procedure %s does not exist!!!",node->string);
			return -1;
		}
		else
		{
			int project2=argCheck(node->child,temp_res->argv);
			if(project2==0)
			{
				printf(" ---> function/procedure %s arguments error!!!\n",node->string);
				return (temp_res->varType);
			}
			else
			{
				return (temp_res->varType);
			}
		}
	}
}

int expValid(struct nodeType* node,int type){

	if(node->nodeType == NODE_INT)
	{
		if(type==1) return 1;
		else
		{
			printf("[ERROR]type error %d",node->iValue);
			return 0;
		}
	}
	else if(node->nodeType==NODE_REAL)
	{
		if(type==2) return 1;
		else
		{
			printf("[ERROR]type error %f",node->rValue);
			return 0;
		}
	}
	else if(node->nodeType == NODE_VARIABLE)
	{
		if(current==0 && checkInit(node,0)==0)
		{
			printf("[ERROR]Using uninitialized VAR %s",node->string);
			return 0;
		}
		int note=varValid(node,NULL);
		if(note==-1)
		{
			printf(" ---> variable error, \n");
			return 0;
		}
		else if(note==type) return 1;
		else
		{
			if(note==5)
				printf("[ERROR]procedure cannot be used in expression");
			else
				printf("[ERROR]type error %s",node->string);
			return 0;
		}
	}
	
	struct nodeType* left = node->child;
	struct nodeType* right = left->rsibling;
	int flag3,flag4;
	if(left==right)
	{
		switch(node->op)
		{
			case OP_NOT:
				break;
			case OP_SUB:
				flag3=expValid(left,type);
				if(flag3==1)
				{
					if(type==1)
					{
						node->iValue = left->iValue;
						node->valueValid = 1;
					}
					else if(type==2)
					{
						node->rValue = left->rValue;
						node->valueValid = 2;
					}
					return 1;
				}
				else return 0;
		};
	}
	else
	{
		flag3 = expValid(left,type);
		flag4 = expValid(right,type);
		switch(node->op)
		{
			case OP_ADD:
				if(flag3==1 && flag4==1)
				{
					if(left->valueValid!=0 && right->valueValid!=0)
					{
						if(type==1)
						{
							node->iValue = left->iValue + right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = left->rValue + right->rValue;
							node->valueValid = 2;
						}
					}
					else node->valueValid=0;
					return 1;
				}
				else return 0;
			case OP_SUB:
				if(flag3==1 && flag4==1)
				{
					if(left->valueValid!=0 && right->valueValid!=0)
					{
						if(type==1)
						{
							node->iValue = left->iValue - right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = left->rValue - right->rValue;
							node->valueValid = 2;
						}
					}
					else node->valueValid=0;
					return 1;
				}
				else return 0;
			case OP_MUL:
				if(flag3==1 && flag4==1)
				{
					if(left->valueValid!=0 && right->valueValid!=0){
						if(type==1)
						{
							node->iValue = left->iValue * right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = left->rValue * right->rValue;
							node->valueValid = 2;
						}
					}
					else node->valueValid=0;
					return 1;
				}
				else return 0;
			case OP_DIV:
				if(flag3==1 && flag4==1)
				{
					if(left->valueValid!=0 && right->valueValid!=0){
						if(type==1)
						{
							node->iValue = left->iValue / right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = left->rValue / right->rValue;
							node->valueValid = 2;
						}
					}
					else node->valueValid=0;
					return 1;
				}
				else return 0;
			default:
				if(flag3==1 && flag4==1)
				{
					return 1;
				}
				else return 0;
		};
	}
}

int indexCheck(struct nodeType* idxList,struct symbol* st_symbol)
{
	struct nodeType* midnight=st_symbol->arryhead;
	struct nodeType* temp3=idxList->child;
	int isfunc;//@@
	do{
		if(temp3->nodeType==NODE_VARIABLE)
		{
			isfunc=-1;
			
			if(varValid(temp3,&isfunc)!=1)return 0;
		
			if(isfunc!=1 && current==0 && checkInit(temp3,1)==0)
			{
				return 0;
			}
			midnight = midnight->child;
		}
		else if(temp3->nodeType==NODE_OP)
		{
			if(expValid(temp3,1)==1)
			{
				if(temp3->valueValid==2) return 0;
				else if(temp3->valueValid==1 && (temp3->iValue<midnight->arry_start || temp3->iValue>midnight->arry_end))
				{
					printf("[ERROR]%d not in range %d ... %d ",temp3->iValue,midnight->arry_start,midnight->arry_end);
					return 0;
				}
				midnight = midnight->child;
			}
			else
			{
				return 0;
			}
		}
		else if(temp3->iValue>=midnight->arry_start && temp3->iValue<=midnight->arry_end)
		{
			midnight = midnight->child;
		}
		else
		{
			printf("[ERROR]%d not in range %d ... %d ",temp3->iValue,midnight->arry_start,midnight->arry_end);
			return 0;
		}
		temp3 = temp3->rsibling;
		if(temp3!=idxList->child && midnight->nodeType!=NODE_ARRAY)
		{
			return 0;
		}
	}while(temp3!=idxList->child);
	if(midnight->nodeType==NODE_ARRAY)
	{
		return 0;
	}
	return 1;
}

void modSymbol(struct nodeType* node,int opt,int value)
{
	struct symbol* st_symbol;
	switch(node->nodeType)
	{
		case NODE_VARIABLE:
			st_symbol=findVARall(node->string);
			if(st_symbol==NULL) return;
			switch(opt)
			{
				case 1:                     
					if(st_symbol->isfunc==1) return;
					st_symbol->init=value;
					break;
			};
			return;
		default:
			break;
	};
	
	struct nodeType *st_symbol2 = node->child;
	if(st_symbol2 != NULL) 
	{
        do 
		{
            modSymbol(st_symbol2,opt,value);
            st_symbol2 = st_symbol2->rsibling;
        } while(st_symbol2 != node->child);
    }
	return;
}

int checkInit(struct nodeType* node,int type)
{
	struct symbol* st_symbol;
	switch(node->nodeType)
	{
		case NODE_VARIABLE:
			st_symbol=findVARall(node->string);
			if(st_symbol==NULL) return 1;   
			if(st_symbol->isfunc==1) return 1; 
			if(st_symbol->init==1) return 1;
			else return 0;
		case NODE_INT:
			return 1;
		case NODE_REAL:
			return 1;
		default:
			break;
	}
	
	struct nodeType *st_symbol2 = node->child;
    int temp4;
	if(st_symbol2 != NULL) 
	{
        do 
		{
            temp4=checkInit(st_symbol2,type);
			if(temp4==1) return 1;
            st_symbol2 = st_symbol2->rsibling;
        } while(st_symbol2 != node->child);
    }
	return 0;
}

void processStatement(struct nodeType* node)
{
	struct nodeType* left;
	struct nodeType* right;
	int isfunc;
	int Type;

	switch(node->nodeType){
		case NODE_STMT_LIST:
			break;
		case NODE_VARIABLE:
			isfunc=-1;
			Type = varValid(node,&isfunc);
			if(Type==-1 && isfunc) printf(" ---> VAR error: function not exist!!!\n");
			else if(Type==-1) printf(" ---> VAR error!!!\n");
			break;
		case NODE_ASSIGN:
			left=node->child;
			right = left->rsibling;
			isfunc=-1;
			Type = varValid(left,&isfunc);
			struct symbol* st_symbol;
			
			if(Type==-1) printf(" ---> VAR error!!!\n");
			else if(isfunc==1) printf("LHS is a function or procedure!!!\n");
			else
			{
				int flag4=expValid(right,Type);
				if(flag4==0)
				{
					printf(" ---> expression error!!!\n");
				}
				else if(current==0)
				{
					if(checkInit(right,Type)==1)
					{
						modSymbol(left,1,1);
					}
					else
					{
						printf("[ERROR]expression using uninitialized var\n");
					}
				}
			}
			return;
		case NODE_PROCEDURE:
			left=node->child;
			right=left->rsibling;
			struct symbol* flag3=findFUNCall(left->string);
			if(flag3==NULL)
			{
				printf("[ERROR]function or procedure %s not exist\n",left->string);
			}
			else
			{
				int flag4=argCheck(right,flag3->argv);
				if(flag4==1);
				else
				{
					printf(" ---> function or procedure %s arguments error\n",left->string);
				}
			}
			return;
		case NODE_WHILE:
			left=node->child;
			right=left->rsibling;
			
			int typeok=expValid(left,1);
			if(typeok==0) typeok=expValid(left,2);
			if(typeok==1);
			else
			{
				printf(" ---> expression error\n");
			}
			processStatement(right);
			return;
		case NODE_IF:
			
			left=node->child;
			right=left->rsibling;
			
			typeok=expValid(left,1);
			if(typeok==0) typeok=expValid(left,2);
			if(typeok==1);
			else
			{
				printf(" ----> expression error\n");
			}
			processStatement(right);
			right=right->rsibling;
			processStatement(right);
			return;
	};
	struct nodeType *st_symbol2 = node->child;
    if(st_symbol2 != NULL) 
	{
        do 
		{
            processStatement(st_symbol2);
            st_symbol2 = st_symbol2->rsibling;
        } while(st_symbol2 != node->child);
    }
}

void processProgram(struct nodeType* node)
{
	struct argument* argv;
	struct nodeType *child;
	struct symbol* temp;
	switch(node->nodeType)
	{
		case NODE_SUBPROGRAM_LIST:
			break;
		case NODE_PROGRAM:
			break;
		case NODE_FUNC:
			printf("\n");
			temp=findFUNCall(node->child->child->string);
			if(temp==NULL);
			else
			{
				printf("[ERROR]duplicate declaration temp_array function %s\n",node->child->child->string);
			}
			temp=findVARall(node->child->child->string);
			if(temp==NULL);
			else if(temp->varType!=node->child->varType);
			else
			{
				printf("[ERROR]duplicate declaration temp_array VAR %s\n",node->child->child->string);
			}
			
			
			if(node->child->rsibling->nodeType==NODE_PARA_LIST)
				argv = makeArg(node->child->rsibling);
			else argv=NULL;
			child = node->child; 
			enterSymbol(child->child->string,child->varType,argv,NULL,1);
		
			openScope();
			enterSymbol(child->child->string,child->varType,NULL,NULL,0);
			if(argv==NULL)
			{
				break;
			}
			
			child = child->rsibling; 
			
			while(child!=node->child)
			{
				
				processDeclare(child);
				modSymbol(child,1,1);
				
				child = child->rsibling;
			}
			break;
		case NODE_DECLARE:
			processDeclare(node);
			break;
		case NODE_STMT_LIST:
			processStatement(node);
			
			closeScope();
			
			break;
		case NODE_PROCEDURE:
			if(node->child->rsibling->nodeType==NODE_PARA_LIST)
				argv = makeArg(node->child->rsibling);
			else argv=NULL;
			child = node->child;
			enterSymbol(child->string,5,argv,NULL,2);
			openScope();

			if(argv==NULL)
			{
				break;
			}
			child = child->rsibling;
			while(child!=node->child)
			{
				processDeclare(child);
				modSymbol(child,1,1);
				child = child->rsibling;
			}
			break;
	};
	
	struct nodeType *st_symbol2 = node->child;
    if(st_symbol2 != NULL) 
	{
        do 
		{
            processProgram(st_symbol2);
            st_symbol2 = st_symbol2->rsibling;
        } while(st_symbol2 != node->child);
    }
}

void makeTable(struct nodeType *root)
{
	struct nodeType* first = root->child;
	struct nodeType* go = root->child;
	openScope();
	go = go->rsibling;
	while(go!=first){
		switch(go->nodeType)
		{
			case NODE_DECLARE:
				processDeclare(go);
				break;
			case NODE_SUBPROGRAM_LIST:
				processProgram(go);
				break;
			case NODE_STMT_LIST:
				processStatement(go);
				break;
		}
		go = go->rsibling;
	}
	closeScope();
}

void printTable()
{
	int i;
	printf("\n");
	printf("---------------------------------------------------\n");
	printf("name\t\ttype\t\t\tscope\n");
	printf("---------------------------------------------------\n");
	for(i=0;i<=flag;i++)
	{
		struct symbol* temp_res = symTable[i];
		if(temp_res==NULL) continue;
		do
		{
			if (temp_res->varType == 1) printf("%s\t\tInteger\t\t\t%d",temp_res->name, i+1);
			else if (temp_res->varType == 2) printf("%s\t\tRealNum\t\t\t%d",temp_res->name, i+1);
			else if (temp_res->varType == 11) printf("%s\t\tIntArray\t\t%d",temp_res->name, i+1);
			else if (temp_res->varType == 22) printf("%s\t\tRealArray\t\t%d",temp_res->name, i+1);
		    printf("\n");	
			if(temp_res->argValid)
			{
				//printf("( ");
				struct argument* st_symbol = temp_res -> argv;
				while(st_symbol!=NULL)
				{
					//printf("%d: %d, ",st_symbol->argType,st_symbol->num);
					st_symbol = st_symbol->next;
				}
				//printf(" )\n");
			}
			else printf("\n");
			temp_res = temp_res->next;
		}while(temp_res!=NULL);
	}
}
//--------------------------------------------------------------------------------
int main() 
{
    yyparse();
    printTree(ASTRoot, 0);
	printf("\n");
	makeTable(ASTRoot);
	printTable();
    return 0;
}
