%{
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"

struct nodeType* newTokenNode(int tokenType);

/*
#define   PROGRAM      1
#define   ID           2
#define   VAR          3
#define   ARRAY        4
#define   NUM          5
#define   OF           6
#define   INTEGER      7
#define   REAL         8
#define   FUNCTION     9
#define   PROCEDURE    10
#define   PBEGIN       11
#define   END          12
#define   IF           13
#define   THEN         14
#define   ELSE         15
#define   WHILE        16
#define   DO           17
#define   NOT          18



#define   ASSIGNMENT      21
#define   COLON           22
#define   COMMA           23
#define   DOT             24
#define   DOTDOT          25
#define   EQUAL           26
#define   NOTEQUAL        27
#define   GE              28
#define   GT              29
#define   LBRAC           30
#define   LE              31
#define   LPAREN          32
#define   LT              33
#define   MINUS           34
#define   NOTEQUAL        35
#define   PLUS            36
#define   RBRAC           37
#define   RPAREN          38
#define   SEMICOLON       39
#define   SLASH           40
#define   STAR            41
#define   UPARROW         42
*/

int line_no = 1;


%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

%%

{P}{R}{O}{G}{R}{A}{M}        {
    yylval.node = newTokenNode(PROGRAM);
    return PROGRAM;
}

{I}{D}                       {
	yylval.node = newTokenNode(ID);
	return(ID);
}

{V}{A}{R}                    {
	yylval.node = newTokenNode(VAR);
	return(VAR);
}

{A}{R}{R}{A}{Y}              {
	yylval.node = newTokenNode(ARRAY);
	return(ARRAY);
}

{N}{U}{M}                    {
	yylval.node = newTokenNode(NUM);
	return(NUM);
}

{O}{F}                       {
	yylval.node = newTokenNode(OF);
	return(OF);
}

{I}{N}{T}{E}{G}{E}{R}        {
	yylval.node = newTokenNode(INTEGER);
	return(INTEGER);
}

{R}{E}{A}{L}                 {
	yylval.node = newTokenNode(REAL);
	return(REAL);
}

{F}{U}{N}{C}{T}{I}{O}{N}     {
	yylval.node = newTokenNode(FUNCTION);
	return(FUNCTION);
}

{P}{R}{O}{C}{E}{D}{U}{R}{E}  {
	yylval.node = newTokenNode(PROCEDURE);
	return(PROCEDURE);
}

{B}{E}{G}{I}{N}              {
	yylval.node = newTokenNode(PBEGIN);
	return(PBEGIN);
}

{E}{N}{D}                    {
	yylval.node = newTokenNode(END);
	return(END);
}

{I}{F}                       {
	yylval.node = newTokenNode(IF);
	return(IF);
}

{T}{H}{E}{N}                 {
	yylval.node = newTokenNode(THEN);
	return(THEN);
}

{E}{L}{S}{E}                 {
	yylval.node = newTokenNode(ELSE);
	return(ELSE);
}

{W}{H}{I}{L}{E}              {
	yylval.node = newTokenNode(WHILE);
	return(WHILE);
}

{D}{O}                       {
	yylval.node = newTokenNode(DO);
	return(DO);
}

{N}{O}{T}                    {
	yylval.node = newTokenNode(NOT);
	return(NOT);
}

[a-zA-Z]([a-zA-Z0-9])*       {
	yylval.node = newTokenNode(ID);
	yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
	return(ID);
}

"/""/"[^\n]*                 ;

[ \n]*                       ;

":="                         {
	yylval.node = newTokenNode(ASSIGNMENT);
	return(ASSIGNMENT);
}

":"                          {
	yylval.node = newTokenNode(COLON);
	return(COLON);
}

","                          {
	yylval.node = newTokenNode(COMMA);
	return(COMMA);
}

"."                          {
	yylval.node = newTokenNode(DOT);
	return(DOT);
}

".."                         {
	yylval.node = newTokenNode(DOTDOT);
	return(DOTDOT);
}

"="                          {
	yylval.node = newTokenNode(EQUAL);
	yylval.node->op=OP_EQ;
	return(EQUAL);
}

"!="                         {
	yylval.node = newTokenNode(NOTEQUAL);
	yylval.node->op = OP_NE;
	return(NOTEQUAL);
}

">="                         {
	yylval.node = newTokenNode(GE);
	yylval.node->op = OP_GE;
	return(GE);
}

">"                          {
	yylval.node = newTokenNode(GT);
	yylval.node->op = OP_GT;
	return(GT);
}

"["                          {
	yylval.node = newTokenNode(LBRAC);
	return(LBRAC);
}

"<="                         {
	yylval.node = newTokenNode(LE);
	yylval.node->op = OP_LE;
	return(LE);
}

"("                          {
	yylval.node = newTokenNode(LPAREN);
	return(LPAREN);
}

"<"                          {
	yylval.node = newTokenNode(LT);
	yylval.node->op = OP_LT;
	return(LT);
}

"-"                          {
	yylval.node = newTokenNode(MINUS);
	yylval.node->op = OP_SUB;
	return(MINUS);
}

"+"                          {
	yylval.node = newTokenNode(PLUS);
	yylval.node->op = OP_ADD;
	return(PLUS);
}

"]"                          {
	yylval.node = newTokenNode(RBRAC);
	return(RBRAC);
}

")"                          {
	yylval.node = newTokenNode(RPAREN);
	return(RPAREN);
}

";"                          {
	yylval.node = newTokenNode(SEMICOLON);
	return(SEMICOLON);
}

"/"                          {
	yylval.node = newTokenNode(SLASH);
	yylval.node->op = OP_DIV;
	return(SLASH);
}

"*"                          {
	yylval.node = newTokenNode(STAR);
	yylval.node->op = OP_MUL;
	return(STAR);
}

[1-9][0-9]*                       {
	yylval.node = newTokenNode(NUM);
    yylval.node->valueValid = VALUE_I_VALID;
    yylval.node->iValue = atoi(yytext);
	return(NUM);
}

[0-9]+"."[0-9]+                   {
	yylval.node = newTokenNode(NUM);
    yylval.node->valueValid = VALUE_R_VALID;
    yylval.node->rValue = atof(yytext);
	return(NUM);
}

[0-9]+"."[0-9]+{E}[+|-][0-9]+          {
	yylval.node = newTokenNode(NUM);
	yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
	return(NUM);
}

0                                 {
	yylval.node = newTokenNode(NUM);
    yylval.node->valueValid = VALUE_I_VALID;
    yylval.node->iValue = atoi(yytext);
	return(NUM);
}

''                           {
	yylval.node = newTokenNode(NUM);
	yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
	return(NUM);
}

\"\"                         {
	yylval.node = newTokenNode(NUM);
	yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
	return(NUM);
}

'({NQUOTE}|'')+'             {
	yylval.node = newTokenNode(NUM);
	yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
	return(NUM);
}

\"([^"]|\"\")+\"             {
	yylval.node = newTokenNode(NUM);
	yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
	return(NUM);
}



"(*"   |
"{"    { register int c;
     while ((c = input()))
     {
      if (c == '}')
       break;
      else if (c == '*')
      {
       if ((c = input()) == ')')
        break;
       else
        unput (c);
      }
      else if (c == '\n')
       line_no++;
      else if (c == 0)
        fprintf (stderr, "Unexpected EOF inside comment at line %d\n",line_no);
     }
    }

[ \t\f]    ;

\r         ;


[0-9]+[a-zA-Z]([a-zA-Z0-9])*  | 
.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%

struct nodeType* newTokenNode(int tokenType) {
    struct nodeType *node = newNode(NODE_TOKEN);
    node->tokenType = tokenType;
	node->string = NULL;
	node->op = 0;
	node->valueValid = 0;
	node->varType = 0;

    return node;
}

