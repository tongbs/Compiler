%{
/*
 * grammar.y
 *
 * Pascal grammar in Yacc format, based originally on BNF given
 * in "Standard Pascal -- User Reference Manual", by Doug Cooper.
 * This in turn is the BNF given by the ANSI and ISO Pascal standards,
 * and so, is PUBLIC DOMAIN. The grammar is for ISO Level 0 Pascal.
 * The grammar has been massaged somewhat to make it LALR, and added
 * the following extensions.
 *
 * constant expressions
 * otherwise statement in a case
 * productions to correctly match else's with if's
 * beginnings of a separate compilation facility
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"

void yyerror (char const *s) 
{
   extern char *yytext;
   extern int lineCount;
   fprintf (stderr, "%s: at line %d symbol'%s'\n", s,lineCount,yytext);
 }
 
int yylex();

struct nodeType *root;
%}

%union 
{
    struct nodeType * node;
}

%token <node> ASSIGNMENT COLON COMMA DOT DOTDOT EQUAL FUNCTION GE GT LBRAC LE LPAREN LT MINUS NOTEQUAL PLUS RBRAC RPAREN SEMICOLON SLASH STAR

%token <node> NUMBER
%token <node> FLOAT
%token <node> ARRAY DO ELSE PBEGIN END IF VAR WHILE REALNUMBER STRING THEN
%token <node> PROCEDURE PROGRAM OF OR INTEGER NOT IDENTIFIER

%type <node> prog identifier_list declarations type standard_type subprogram_declarations
%type <node> subprogram_declaration subprogram_head arguments parameter_list
%type <node> optional_var compound_statement optional_statements statement statement_list
%type <node> variable tail procedure_statement expression_list expression simple_expression
%type <node> term factor addop mulop relop

%left PLUS MINUS
%left STAR SLASH
%%

prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations
	   compound_statement DOT 
{
	printf("Reduction->rule no 1\n");
	$$=newNode(NODE,"prog");
	addChild($$,newNode(NODE,"PROGRAM"));addChild($$,newNode(NODE,"IDENTIFIER"));addChild($$,newNode(NODE,"LPAREN"));
	addChild($$,$4);
	addChild($$,newNode(NODE,"RPAREN"));addChild($$,newNode(NODE,"SEMICOLON"));
	addChild($$,$7);
	addChild($$,$8);
	addChild($$,$9);
	addChild($$,newNode(NODE,"DOT"));
	root=$$;
}
;

identifier_list :  IDENTIFIER
{
	printf("Reduction->rule no 2\n");
	$$=newNode(NODE,"identifier_list");
	addChild($$,newNode(NODE,"IDENTIFIER"));
}
| identifier_list COMMA IDENTIFIER 
{
	printf("Reduction->rule no 3\n");
	$$=newNode(NODE,"identifier_list");
	addChild($$,$1);
	addChild($$,newNode(NODE,"COMMA"));
	addChild($$,newNode(NODE,"IDENTIFIER"));
}
;

declarations :  declarations VAR identifier_list COLON type SEMICOLON 
{
	printf("Reduction->rule no 4\n");
	$$=newNode(NODE,"declarations");
	addChild($$,$1);addChild($$,newNode(NODE,"VAR"));
	addChild($$,$3);addChild($$,newNode(NODE,"COLON"));
	addChild($$,$5);addChild($$,newNode(NODE,"SEMICOLON"));
}
| 	
{
	printf("Reduction->rule no 5\n");
	$$=newNode(NODE,"declarations");
	addChild($$,newNode(NODE,"empty"));
}
;

type :  standard_type 
{
	printf("Reduction->rule no 6\n");
	$$=newNode(NODE,"type");
	addChild($$,$1);
}
| ARRAY LBRAC NUMBER DOTDOT NUMBER RBRAC OF type 
{
	printf("Reduction->rule no 7\n");
	$$=newNode(NODE,"type");
	addChild($$,newNode(NODE,"ARRAY"));addChild($$,newNode(NODE,"LBRAC"));
	addChild($$,newNode(NODE,"NUMBER"));addChild($$,newNode(NODE,"DOTDOT"));
	addChild($$,newNode(NODE,"NUMBER"));addChild($$,newNode(NODE,"RBRAC"));
	addChild($$,newNode(NODE,"OF"));
	addChild($$,$8);
}
;

standard_type :  INTEGER 
{
	printf("Reduction->rule no 8\n");
	$$=newNode(NODE,"standard_type");
	addChild($$,newNode(NODE,"INTEGER"));
}
| REALNUMBER 
{
	printf("Reduction->rule no 9\n");
	$$=newNode(NODE,"standard_type");
	addChild($$,newNode(NODE,"REALNUMBER"));
}
| STRING 
{
	printf("Reduction->rule no 10\n");
	$$=newNode(NODE,"standard_type");
	addChild($$,newNode(NODE,"STRING"));
}
;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON 
{
	printf("Reduction->rule no 11\n");
	$$=newNode(NODE,"subprogram_declarations");
	addChild($$,$1);addChild($$,$2);
	addChild($$,newNode(NODE,"SEMICOLON"));
}
| 
{
	printf("Reduction->rule no 12\n");
	$$=newNode(NODE,"subprogram_declarations");
	addChild($$,newNode(NODE,"empty"));
}
;

subprogram_declaration : subprogram_head declarations compound_statement 
{
	printf("Reduction->rule no 13\n");
	$$=newNode(NODE,"subprogram_declaration");
	addChild($$,$1);addChild($$,$2);addChild($$,$3);
}
;

subprogram_head :  FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON 
{
	printf("Reduction->rule no 14\n");
	$$=newNode(NODE,"subprogram_head");
	addChild($$,newNode(NODE,"FUNCTION"));addChild($$,newNode(NODE,"IDENTIFIER"));
	addChild($$,$3);
	addChild($$,newNode(NODE,"COLON"));
	addChild($$,$5);
	addChild($$,newNode(NODE,"SEMICOLON"));
}
| PROCEDURE IDENTIFIER arguments SEMICOLON 
{
	printf("Reduction->rule no 15\n");
	$$=newNode(NODE,"subprogram_head");
	addChild($$,newNode(NODE,"PROCEDURE"));addChild($$,newNode(NODE,"IDENTIFIER"));
	addChild($$,$3);
	addChild($$,newNode(NODE,"SEMICOLON"));
}
;

arguments :  LPAREN parameter_list RPAREN 
{
	printf("Reduction->rule no 16\n");
	$$=newNode(NODE,"arguments");
	addChild($$,newNode(NODE,"LPAREN"));
	addChild($$,$2);
	addChild($$,newNode(NODE,"RPAREN"));
}
| 
{
	printf("Reduction->rule no 17\n");
	$$=newNode(NODE,"arguments");
	addChild($$,newNode(NODE,"empty"));
}
;

parameter_list :  optional_var identifier_list COLON type 
{
	printf("Reduction->rule no 18\n");
	$$=newNode(NODE,"parameter_list");
	addChild($$,$1);
	addChild($$,$2);
	addChild($$,newNode(NODE,"COLON"));
	addChild($$,$4);
}
| optional_var identifier_list COLON type SEMICOLON parameter_list 
{
	printf("Reduction->rule no 19\n");
	$$=newNode(NODE,"parameter_list");
	addChild($$,$1);
	addChild($$,$2);
	addChild($$,newNode(NODE,"COLON"));
	addChild($$,$4);
	addChild($$,newNode(NODE,"SEMICOLON"));
	addChild($$,$6);
}
;

optional_var :  VAR 
{
	printf("Reduction->rule no 20\n");
	$$=newNode(NODE,"optional_var");
	addChild($$,newNode(NODE,"VAR"));
}
| 
{
	printf("Reduction->rule no 21\n");
	$$=newNode(NODE,"optional_var");
	addChild($$,newNode(NODE,"empty"));
}
;

compound_statement :  PBEGIN 
		       optional_statements
		       END 
{
	printf("Reduction->rule no 22\n");
	$$=newNode(NODE,"compound_statement");
	addChild($$,newNode(NODE,"PBEGIN"));
	addChild($$,$2);
	addChild($$,newNode(NODE,"END"));
}
;

optional_statements : statement_list 
{
	printf("Reduction->rule no 23\n");
	$$=newNode(NODE,"optional_statements");
	addChild($$,$1);
}
;

statement_list :  statement 
{
	printf("Reduction->rule no 24\n");
	$$=newNode(NODE,"statement_list");
	addChild($$,$1);
}
| statement_list SEMICOLON statement 
{
	printf("Reduction->rule no 25\n");
	$$=newNode(NODE,"statement_list");
	addChild($$,$1);
	addChild($$,newNode(NODE,"SEMICOLON"));
	addChild($$,$3);
}
;

statement :  variable ASSIGNMENT expression 
{
	printf("Reduction->rule no 26\n");
	$$=newNode(NODE,"statement");
	addChild($$,$1);
	addChild($$,newNode(NODE,"ASSIGNMENT"));
	addChild($$,$3);
}
| procedure_statement 
{
	printf("Reduction->rule no 27\n");
	$$=newNode(NODE,"statement");
	addChild($$,$1);
}
| compound_statement 
{
	printf("Reduction->rule no 28\n");
	$$=newNode(NODE,"statement");
	addChild($$,$1);
}
| IF expression THEN statement ELSE statement 
{
	printf("Reduction->rule no 29\n");
	$$=newNode(NODE,"statement");
	addChild($$,newNode(NODE,"IF"));addChild($$,$2);
	addChild($$,newNode(NODE,"THEN"));addChild($$,$4);
	addChild($$,newNode(NODE,"ELSE"));
	addChild($$,$6);
}
| WHILE expression DO statement 
{
	printf("Reduction->rule no 30\n");
	$$=newNode(NODE,"statement");
	addChild($$,newNode(NODE,"WHILE"));
	addChild($$,$2);
	addChild($$,newNode(NODE,"DO"));
	addChild($$,$4);
}
| 
{
	printf("Reduction->rule no 31\n");
	$$=newNode(NODE,"statement");
	addChild($$,newNode(NODE,"empty"));
}
;

variable :  IDENTIFIER tail 
{
	printf("Reduction->rule no 32\n");
	$$=newNode(NODE,"variable");
	addChild($$,newNode(NODE,"IDENTIFIER"));
	addChild($$,$2);
}
;

tail     :  LBRAC expression RBRAC tail 
{
	printf("Reduction->rule no 33\n");
	$$=newNode(NODE,"tail");
	addChild($$,newNode(NODE,"LBRAC"));
	addChild($$,$2);
	addChild($$,newNode(NODE,"RBRAC"));
	addChild($$,$4);
}
| 
{
	printf("Reduction->rule no 34\n");
	$$=newNode(NODE,"tail");
	addChild($$,newNode(NODE,"empty"));
}
;

procedure_statement :  IDENTIFIER 
{
	printf("Reduction->rule no 35\n");
	$$=newNode(NODE,"procedure_statement");
	addChild($$,newNode(NODE,"IDENTIFIER"));
}
| IDENTIFIER LPAREN expression_list RPAREN 
{
	printf("Reduction->rule no 36\n");
	$$=newNode(NODE,"procedure_statement");
	addChild($$,newNode(NODE,"IDENTIFIER"));
	addChild($$,newNode(NODE,"LPAREN"));
	addChild($$,$3);
	addChild($$,newNode(NODE,"RPAREN"));
}
;

expression_list :  expression 
{
	printf("Reduction->rule no 37\n");
	$$=newNode(NODE,"expression_list");
	addChild($$,$1);
}
| expression_list COMMA expression 
{
	printf("Reduction->rule no 38\n");
	$$=newNode(NODE,"expression_list");
	addChild($$,$1);
	addChild($$,newNode(NODE,"COMMA"));
	addChild($$,$3);
}
;

expression :  simple_expression 
{
	printf("Reduction->rule no 39\n");
	$$=newNode(NODE,"expression");
	addChild($$,$1);
}
| simple_expression relop simple_expression 
{
	printf("Reduction->rule no 40\n");
	$$=newNode(NODE,"expression");
	addChild($$,$1);
	addChild($$,$2);
	addChild($$,$3);
}
;

simple_expression :  term 
{
	printf("Reduction->rule no 41\n");
	$$=newNode(NODE,"simple_expression");
	addChild($$,$1);
}
| simple_expression addop term 
{
	printf("Reduction->rule no 42\n");
	$$=newNode(NODE,"simple_expression");
	addChild($$,$1);addChild($$,$2);addChild($$,$3);
}
;

term :  factor 
{
	printf("Reduction->rule no 43\n");
	$$=newNode(NODE,"term");
	addChild($$,$1);
}
| term mulop factor 
{
	printf("Reduction->rule no 44\n");
	$$=newNode(NODE,"term");
	addChild($$,$1);addChild($$,$2);addChild($$,$3);
}
;

factor :  IDENTIFIER tail 
{	
	printf("Reduction->rule no 45\n");
	$$=newNode(NODE,"factor");
	addChild($$,newNode(NODE,"IDENTIFIER"));
	addChild($$,$2);
}
| IDENTIFIER LPAREN expression_list RPAREN 
{
	printf("Reduction->rule no 46\n");
	$$=newNode(NODE,"factor");
	addChild($$,newNode(NODE,"IDENTIFIER"));
	addChild($$,newNode(NODE,"LPAREN"));
	addChild($$,$3);
	addChild($$,newNode(NODE,"RPAREN"));
}
| NUMBER 
{
	printf("Reduction->rule no 47\n");
	$$=newNode(NODE,"factor");
	addChild($$,newNode(NODE,"NUMBER"));
}
| FLOAT 
{
	printf("Reduction->rule no 48\n");
	$$=newNode(NODE,"factor");
	addChild($$,newNode(NODE,"FLOAT"));
}
| LPAREN expression RPAREN 
{
	printf("Reduction->rule no 49\n");
	$$=newNode(NODE,"factor");
	addChild($$,newNode(NODE,"LPAREN"));
	addChild($$,$2);
	addChild($$,newNode(NODE,"RPAREN"));
}
| NOT factor 
{
	printf("Reduction->rule no 50\n");
	$$=newNode(NODE,"factor");
	addChild($$,newNode(NODE,"NOT"));
	addChild($$,$2);
}
| addop factor 
{
	printf("Reduction->rule no 51\n");
	$$=newNode(NODE,"factor");
	addChild($$,$1);
	addChild($$,$2);
}
;

addop :  PLUS 
{
	printf("Reduction->rule no 52\n");
	$$=newNode(NODE,"addop");
	addChild($$,newNode(NODE,"PLUS"));
} 
| MINUS 
{
	printf("Reduction->rule no 53\n");
	$$=newNode(NODE,"addop");
	addChild($$,newNode(NODE,"MINUS"));
}
;

mulop :  STAR 
{
	printf("Reduction->rule no 54\n");
	$$=newNode(NODE,"mulop");
	addChild($$,newNode(NODE,"STAR"));
} 
| SLASH 
{
	printf("Reduction->rule no 55\n");
	$$=newNode(NODE,"mulop");
	addChild($$,newNode(NODE,"SLASH"));
}
;

relop :  LT 
{
	printf("Reduction->rule no 56\n");
	$$=newNode(NODE,"relop");
	addChild($$,newNode(NODE,"LT"));
}
| GT 
{
	printf("Reduction->rule no 57\n");
	$$=newNode(NODE,"relop");
	addChild($$,newNode(NODE,"GT"));
}
| EQUAL 
{
	printf("Reduction->rule no 58\n");
	$$=newNode(NODE,"relop");
	addChild($$,newNode(NODE,"EQUAL"));
}
| LE 
{
	printf("Reduction->rule no 59\n");
	$$=newNode(NODE,"relop");
	addChild($$,newNode(NODE,"LE"));
}
| GE 
{
	printf("Reduction->rule no 60\n");
	$$=newNode(NODE,"relop");
	addChild($$,newNode(NODE,"GE"));
}
| NOTEQUAL 
{
	printf("Reduction->rule no 61\n");
	$$=newNode(NODE,"relop");
	addChild($$,newNode(NODE,"NOTEQUAL"));
}
;
%%
 
int main(int argc, char** argv) {
    int res;
    
    fprintf(stderr, "open file.\n");
    if(argc>1 && freopen(argv[1],"r",stdin)==NULL){
        exit(1);
    }
    
    fprintf(stderr, "call yyparse\n");
    res = yyparse();
	
    fprintf(stderr, "after call yyparse, res = %d.\n", res);
    
    if (res==0)
	{
        fprintf(stderr, "SUCCESS\n");
		printf("==TREE start==\n");
		printTree(root, 0);
		printf("==end==\n");
	}
    else
        fprintf(stderr, "ERROR\n");	
    return 0;
}