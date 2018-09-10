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
%{
#include <stdio.h>
#include "y.tab.h"
int lineCount = 1;
%}

%%
{A}{R}{R}{A}{Y}              printf("Shift the ARRAY\n");  return(ARRAY);
{D}{O}                       printf("Shift the DO\n");   return(DO);
{E}{L}{S}{E}                 printf("Shift the ELSE\n");  return(ELSE);
{E}{N}{D}                    printf("Shift the END\n");  return(END);
{F}{U}{N}{C}{T}{I}{O}{N}     printf("Shift the FUNCTION\n");  return(FUNCTION);
{I}{F}                       printf("Shift the IF\n");  return(IF);
{O}{F}						 printf("Shift the OF\n"); return(OF);
{N}{O}{T}                    printf("Shift the NOT\n");  return(NOT);
{B}{E}{G}{I}{N}              printf("Shift the PBEGIN\n");  return(PBEGIN);
{P}{R}{O}{G}{R}{A}{M}        printf("Shift the PROGRAM\n");  return(PROGRAM);
{P}{R}{O}{C}{E}{D}{U}{R}{E}  printf("Shift the PROCEDURE\n");  return(PROCEDURE);
{T}{H}{E}{N}                 printf("Shift the THEN\n");  return(THEN);
{V}{A}{R}                    printf("Shift the VAR\n");  return(VAR);
{W}{H}{I}{L}{E}              printf("Shift the WHILE\n");  return(WHILE);
{S}{T}{R}{I}{N}{G}           printf("Shift the STRING\n");  return(STRING);
{I}{N}{T}{E}{G}{E}{R}        printf("Shift the INTEGER\n");  return(INTEGER);
{R}{E}{A}{L}  printf("Shift the REALNUMBER\n");  return(REALNUMBER);
":="                         printf("Shift the ASSIGNMENT\n");  return(ASSIGNMENT);
":"                          printf("Shift the COLON\n");  return(COLON);
","                          printf("Shift the COMMA\n");  return(COMMA);
"."                          printf("Shift the DOT\n");  return(DOT);
".."                         printf("Shift the DOTDOT\n");  return(DOTDOT);
"="                          printf("Shift the EQUAL\n");  return(EQUAL);
"!="                         printf("Shift the NOTEQUAL\n");  return(NOTEQUAL);
">="                         printf("Shift the GE\n");  return(GE);
">"                          printf("Shift the GT\n");  return(GT);
"["                          printf("Shift the LBRAC\n");  return(LBRAC);
"<="                         printf("Shift the LE\n");  return(LE);
"("                          printf("Shift the LPAREN\n");  return(LPAREN);
"<"                          printf("Shift the LT\n");  return(LT);
"-"                          printf("Shift the MINUS\n");  return(MINUS);
"<>"                         printf("Shift the NOTEQUAL\n");  return(NOTEQUAL);
"+"                          printf("Shift the PLUS\n");  return(PLUS);
"]"                          printf("Shift the RBRAC\n");  return(RBRAC);
[0-9]+"."[0-9]+([Ee][+-]?[0-9]+)?      printf("Shift the FLOAT\n");  return(FLOAT);
")"                          printf("Shift the RPAREN\n");  return(RPAREN);
";"                          printf("Shift the SEMICOLON\n");  return(SEMICOLON);
"/"                          printf("Shift the SLASH\n");  return(SLASH);
"*"                          printf("Shift the STAR\n");  return(STAR);

"//"(.)* |
"/*"(.)*"*/"				//printf("Shift the COMMENT\n");  return(COMMENT);	
[0-9]+ 						printf("Shift the NUMBER\n");  return(NUMBER);

[a-zA-Z_]([a-zA-Z0-9_])*       printf("Shift the IDENTIFIER\n");  return(IDENTIFIER);

[ \t\f]  ;

\n  {lineCount++;}

"(*"   |
"{"    { 
			register int temp;
			while ((temp = input()))
			 {
				  if (temp == '}')
				   break;
				  else if (temp == '*')
				  {
					   if ((temp = input()) == ')')
						break;
					   else
						unput (temp);
				  }
				  else if (temp == '\n')
				   lineCount++;
				  else if (temp == 0)
					fprintf (stderr, "Unexpected EOF inside comment at line %d\n",lineCount);
			 }
		}

%%


int yywrap() {
  return(1);
}