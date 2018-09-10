%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct nodeType* newOpNode(int op);
extern struct nodeType* ASTRoot;
 
%}

%union 
{
    struct nodeType *node;
}


%token <node> PROGRAM ID VAR ARRAY NUM OF INTEGER REAL FUNCTION PROCEDURE 
%token <node> PBEGIN END IF THEN ELSE WHILE DO NOT   
%token <node> ASSIGNMENT COLON COMMA DOT DOTDOT EQUAL NOTEQUAL GE GT LBRAC LE LPAREN LT MINUS 
%token <node> PLUS RBRAC RPAREN SEMICOLON SLASH STAR UPARROW 

%type <node> program identifier_list declarations type
%type <node> standard_type subprogram_declaration subprogram_declarations subprogram_head 
%type <node> arguments parameter_list compound_statement optional_statements statement_list
%type <node> statement variable tail procedure_statement expression_list expression
%type <node> simple_expression term factor addop mulop relop lambda

%%

 
 program : PROGRAM ID LPAREN identifier_list RPAREN SEMICOLON
  	    declarations
	    subprogram_declarations
	    compound_statement
	    DOT
		{
			$$ = newNode(NODE_PROGRAM);
			deleteNode($1);
			addChild($$,$2);
			$2->nodeType = NODE_VARIABLE;
			deleteNode($3);
			addChild($$,$4);
			deleteNode($5);
			deleteNode($6);
			addChild($$,$7);
			addChild($$,$8);
			addChild($$,$9);
			deleteNode($10);
			ASTRoot = $$;
		}
 ;

identifier_list : ID 
	{
		$$ = newNode(NODE_ID_LIST); 
        addChild($$, $1);
		$1->nodeType = NODE_VARIABLE;
	}
	| identifier_list COMMA ID
	{
		$$ = $1;
		deleteNode($2);
		addChild($$,$3);
		$3->nodeType = NODE_VARIABLE;
	}
;

declarations : declarations VAR identifier_list COLON type SEMICOLON
	{
		if($5->nodeType != NODE_ARRAY ){
			$$ = $1;
			deleteNode($2);
			deleteNode($4);
			addChild($$,$5);
			struct nodeType* temp_res=$5->child;
			if(temp_res!=NULL){
				while(temp_res->child!=NULL) temp_res=temp_res->child;
				addChild(temp_res,$3);
			}else
			{
				addChild($5,$3);
			}
			deleteNode($6);
		}
		else
		{
			$$ = $1;
			deleteNode($2);
			deleteNode($4);
			addChild($$,$5);
			struct nodeType* temp_res=$5->child;
			if(temp_res!=NULL)
			{
				while(temp_res->child!=NULL) temp_res=temp_res->child;
				addChild(temp_res,$3);
			}
			else
			{
				addChild($5,$3);
			}
			deleteNode($6);
		}
	}
	| lambda
	{
		$$ = newNode(NODE_DECLARE);
	}
;

type : standard_type
	{
		$$ = $1;
	}
	| ARRAY LBRAC NUM DOTDOT NUM RBRAC OF type
	{
		$$ = newNode(NODE_ARRAY);
		$$->varType = TYPE_ARRY;
		deleteNode($1);
		deleteNode($2);
		$$->arry_start = $3->iValue;
		deleteNode($3);
		deleteNode($4);
		$$->arry_end = $5->iValue;
		deleteNode($5);
		deleteNode($6);
		deleteNode($7);
		addChild($$,$8);
	}
;

standard_type : INTEGER
	{
		$$ = $1;
		$$->nodeType=NODE_TYPE;
		$$->varType = TYPE_INT;
	}
	| REAL
	{
		$$ = $1;
		$$->nodeType=NODE_TYPE;
		$$->varType = TYPE_REAL;
	}
    | NUM
	{
		$$ = $1;
		$$->nodeType=NODE_TYPE;
		$$->varType = TYPE_NUM;
	}
;

subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
	{
		$$ = $1;
		addChild($$,$2);
		deleteNode($3);
	}
	| lambda
	{
		$$ = newNode(NODE_SUBPROGRAM_LIST);
	}
;


subprogram_declaration :
	subprogram_head 
	declarations 			
    compound_statement
	{
		$$ = newNode(NODE_PROGRAM);
		addChild($$,$1);
		addChild($$,$2);
		addChild($$,$3);
	}
;

subprogram_head : FUNCTION ID arguments COLON standard_type SEMICOLON
	{
		$$ = newNode(NODE_FUNC);
		deleteNode($1);
		addChild($$,$5);
		addChild($5,$2);
		$2->nodeType = NODE_VARIABLE;
		addChild($$,$3);
		deleteNode($4);
		deleteNode($6);
	}
	| PROCEDURE ID arguments SEMICOLON
	{
		$$ = newNode(NODE_PROCEDURE);
		deleteNode($1);
		addChild($$,$2);
		$2->nodeType = NODE_VARIABLE;
		addChild($$,$3);
		deleteNode($4);
	}
;


arguments : LPAREN parameter_list RPAREN
	{
		deleteNode($1);
		$$ = $2;
		deleteNode($3);
	}
	| lambda
	{
		$$ = NULL;
	}
;

parameter_list : identifier_list COLON type
	{
		$$ = newNode(NODE_PARA_LIST);
		addChild($$,$3);
		deleteNode($2);
		if($3->nodeType==NODE_ARRAY)
		{
			struct nodeType* temp_res=$3;
			while(temp_res->child!=NULL) temp_res = temp_res->child;
			addChild(temp_res,$1);
		}
		else addChild($3,$1);
	}
	| parameter_list SEMICOLON identifier_list COLON type
	{
		$$ = $1;
		deleteNode($2);
		addChild($$,$5);
		deleteNode($4);
		if($5->nodeType==NODE_ARRAY)
		{
			struct nodeType* temp_res=$5;
			while(temp_res->child!=NULL) temp_res = temp_res->child;
			addChild(temp_res,$3);
		}
		else addChild($5,$3);
	}
;

compound_statement : PBEGIN
		       optional_statements
		       END
			   {
					deleteNode($1);
					if($2 != NULL) $$ = $2;
					else $$ = NULL;
					deleteNode($3);
			   }
;

optional_statements : statement_list
	{
		$$ = $1;
	}
	| lambda
	{
		$$ = NULL;
	}
;

statement_list : statement
	{
		$$ = newNode(NODE_STMT_LIST);
		addChild($$,$1);
	}
	| statement_list SEMICOLON statement
	{
		$$ = $1;
		deleteNode($2);
		addChild($$,$3);
	}
;

statement : variable ASSIGNMENT expression
	{
		$$ = newNode(NODE_ASSIGN);
		addChild($$,$1);
		deleteNode($2);
		addChild($$,$3);
	} 
	| procedure_statement
	{
		$$ = $1;
	}
	| compound_statement
	{
		$$ = $1;
	}
	| IF expression THEN statement ELSE statement
	{
		$$ = newNode(NODE_IF);
		deleteNode($1);
		addChild($$,$2);
		deleteNode($3);
		addChild($$,$4);
		deleteNode($5);
		addChild($$,$6);
	}
	| WHILE expression DO statement
	{
		$$ = newNode(NODE_WHILE);
		deleteNode($1);
		addChild($$,$2);
		deleteNode($3);
		addChild($$,$4);
	}
;

variable : ID tail
	{
		$$ = $1;
		$1->nodeType=NODE_VARIABLE;
		if($2->child != NULL) addChild($$,$2);
	}
;

tail     : LBRAC expression RBRAC tail
	{
		deleteNode($1);
		$$ = $4;
		struct nodeType *child = $4->child;
		if(child == NULL) 
		{
			addChild($$,$2);
		}
		else
		{ 
			struct nodeType *tchild = $4->child->lsibling;
			if(child == tchild){
				$2->rsibling = child;
				child->rsibling = $2;
				$2->lsibling=child;
				child->lsibling=$2;
				$$->child=$2;
			}
			else
			{
				$2->rsibling = child;
				tchild->rsibling = $2;
				$2->lsibling=tchild;
				child->lsibling=$2;
				$$->child=$2;
			}
		}
		deleteNode($3);
	}
	| lambda 
	{
		$$ = newNode(NODE_INDEX_LIST);
	}
;

procedure_statement : ID
	{
		$$ = $1;
		$1->nodeType=NODE_VARIABLE;
	}
	| ID LPAREN expression_list RPAREN
	{
		$$ = newNode(NODE_PROCEDURE);
		addChild($$,$1);
		$1->nodeType=NODE_VARIABLE;
		deleteNode($2);
		addChild($$,$3);
		deleteNode($4);
	}
;

expression_list : expression
	{
		$$ = newNode(NODE_EXPR_LIST);
		addChild($$,$1);
	}
	| expression_list COMMA expression
	{
		$$ = $1;
		deleteNode($2);
		addChild($$,$3);
	}
;

expression : simple_expression
	{
		$$ = $1;
	}
	| simple_expression relop simple_expression
	{
		$$ = newOpNode($2->op);
		addChild($$,$1);
		addChild($$,$3);
	}
;

simple_expression : term
	{
		$$ = $1;
	}
	| simple_expression addop term
	{
		$$ = $2;
		addChild($$,$1);
		addChild($$,$3);
	}	
;

term : factor
	{
		$$ = $1;
	}
	| term mulop factor
	{
		$$ = $2;
		addChild($$,$1);
		addChild($$,$3);
	}	
;

factor : ID tail
	{
		$$ = $1;
		$1->nodeType = NODE_VARIABLE;
		if($2->child != NULL) addChild($$,$2);
	}
	| ID LPAREN expression_list RPAREN
	{
		$$ = $1;
		$1->nodeType = NODE_VARIABLE;
		deleteNode($2);
		addChild($$,$3);
		deleteNode($4);
	}
	| NUM
	{
		$$ = $1;
		if($1->valueValid == 1)
		{
			$1->nodeType=NODE_INT;
		}
		else if($1->valueValid == 2)
		{
			$1->nodeType=NODE_REAL;
		}
	}
	| LPAREN expression RPAREN
	{
		deleteNode($1);
		$$ = $2;
		deleteNode($3);
	}
	| NOT factor
	{
		$$ = newOpNode(OP_NOT);
		deleteNode($1);
		addChild($$,$2);
	}
	| MINUS factor
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
		addChild($$,$2);
	}
;

addop : PLUS 
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
	| MINUS
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
;

mulop : STAR 
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
	| SLASH
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
;


relop : LT
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
	| GT
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
	| EQUAL
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
	| LE
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
	| GE
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
	| NOTEQUAL
	{
		$$ = newOpNode($1->op);
		deleteNode($1);
	}
;

lambda : 
	{
		$$ = NULL;
	}
;

 %%


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

void create_new_scope()
{
	flag++;
	current=flag;
	temp_array[flag]=1;
	symTable[flag]=NULL;
	return;
}

void destroy_new_scope()
{
	temp_array[current]=0;
	for(;current>=0;current--)
	{
		if(temp_array[current]==1) break;
	}
	return;
}

struct symbol* getSymbol(char* name,int type,struct argument* argv)
{   
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

void create_symbolTable(char* name,int type,struct argument* argv,struct nodeType* arryhead,int func)
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

void addtoList(struct nodeType* list,int type,struct nodeType* arryhead)
{
	struct nodeType* child = list->child;
	if(child!=NULL)
	{
		do
		{
			create_symbolTable(child->string,type,NULL,arryhead,0);
			child = child->rsibling;
		}while(child!=list->child);
	}
}

void del_process(struct nodeType* node)
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
			addtoList(node,temp_res,temp);
			break;
		case NODE_TYPE:
			addtoList(node->child,node->varType,NULL);
			return;
	}
	
	struct nodeType *child = node->child;
    if(child != NULL) 
	{
        do 
		{
            del_process(child);
            child = child->rsibling;
        } while(child != node->child);
    }
}

struct argument* create_argument(struct nodeType* node)
{  
	struct nodeType *child = node->child;  
	struct nodeType *first = child;
	struct argument* top = NULL;
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
		if(top==NULL) top = n;
		else
		{
			struct argument* st_symbol = top;
			while(st_symbol->next!=NULL) st_symbol = st_symbol->next;
			st_symbol->next = n;
		}
		child = child->rsibling;
	}while(child!=first);
	
	return top;
}

struct symbol* variable_whole(char* name)
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

int argumentCheck(struct nodeType* node,struct argument* argv){ 
	struct nodeType* child = node->child;
	int compiler=argv->num;
	
	do
	{
		int temp2;
		if(child->nodeType==NODE_INT) temp2 = 1;
		else if(child->nodeType==NODE_REAL) temp2=2;
		else if(child->nodeType==NODE_VARIABLE) temp2=variable_create(child,NULL);
		else if(child->nodeType==NODE_OP)
		{
			temp2=expression_valid(child,1);
			if(temp2==0) temp2=expression_valid(child,2);
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

struct symbol* function_recall(char* name)
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

int variable_create(struct nodeType* node,int* isfunc)
{  
	if(node->child==NULL)
	{ 
		struct symbol* temp_res=variable_whole(node->string);
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
		struct symbol* temp_res=variable_whole(node->string);
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
		struct symbol* temp_res=function_recall(node->string);
		if(temp_res==NULL)
		{
			printf("function/procedure %s does not exist!!!",node->string);
			return -1;
		}
		else
		{
			int project2=argumentCheck(node->child,temp_res->argv);
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

int expression_valid(struct nodeType* node,int type){

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
		int note=variable_create(node,NULL);
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
	
	struct nodeType* lt = node->child;
	struct nodeType* right = lt->rsibling;
	int flag3,flag4;
	if(lt==right)
	{
		switch(node->op)
		{
			case OP_NOT:
				break;
			case OP_SUB:
				flag3=expression_valid(lt,type);
				if(flag3==1)
				{
					if(type==1)
					{
						node->iValue = lt->iValue;
						node->valueValid = 1;
					}
					else if(type==2)
					{
						node->rValue = lt->rValue;
						node->valueValid = 2;
					}
					return 1;
				}
				else return 0;
		};
	}
	else
	{
		flag3 = expression_valid(lt,type);
		flag4 = expression_valid(right,type);
		switch(node->op)
		{
			case OP_ADD:
				if(flag3==1 && flag4==1)
				{
					if(lt->valueValid!=0 && right->valueValid!=0)
					{
						if(type==1)
						{
							node->iValue = lt->iValue + right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = lt->rValue + right->rValue;
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
					if(lt->valueValid!=0 && right->valueValid!=0)
					{
						if(type==1)
						{
							node->iValue = lt->iValue - right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = lt->rValue - right->rValue;
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
					if(lt->valueValid!=0 && right->valueValid!=0){
						if(type==1)
						{
							node->iValue = lt->iValue * right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = lt->rValue * right->rValue;
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
					if(lt->valueValid!=0 && right->valueValid!=0){
						if(type==1)
						{
							node->iValue = lt->iValue / right->iValue;
							node->valueValid = 1;
						}
						else if(type==2)
						{
							node->rValue = lt->rValue / right->rValue;
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
			
			if(variable_create(temp3,&isfunc)!=1)return 0;
		
			if(isfunc!=1 && current==0 && checkInit(temp3,1)==0)
			{
				return 0;
			}
			midnight = midnight->child;
		}
		else if(temp3->nodeType==NODE_OP)
		{
			if(expression_valid(temp3,1)==1)
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
			st_symbol=variable_whole(node->string);
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
			st_symbol=variable_whole(node->string);
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

void pro_ST(struct nodeType* node)
{
	struct nodeType* lt;
	struct nodeType* right;
	int isfunc;
	int Type;

	switch(node->nodeType){
		case NODE_STMT_LIST:
			break;
		case NODE_VARIABLE:
			isfunc=-1;
			Type = variable_create(node,&isfunc);
			if(Type==-1 && isfunc) printf(" ---> VAR error: function not exist!!!\n");
			else if(Type==-1) printf(" ---> VAR error!!!\n");
			break;
		case NODE_ASSIGN:
			lt=node->child;
			right = lt->rsibling;
			isfunc=-1;
			Type = variable_create(lt,&isfunc);
			struct symbol* st_symbol;
			
			if(Type==-1) printf(" ---> VAR error!!!\n");
			else if(isfunc==1) printf("LHS is a function or procedure!!!\n");
			else
			{
				int flag4=expression_valid(right,Type);
				if(flag4==0)
				{
					printf(" ---> expression error!!!\n");
				}
				else if(current==0)
				{
					if(checkInit(right,Type)==1)
					{
						modSymbol(lt,1,1);
					}
					else
					{
						printf("[ERROR]expression using uninitialized var\n");
					}
				}
			}
			return;
		case NODE_PROCEDURE:
			lt=node->child;
			right=lt->rsibling;
			struct symbol* flag3=function_recall(lt->string);
			if(flag3==NULL)
			{
				printf("[ERROR]function or procedure %s not exist\n",lt->string);
			}
			else
			{
				int flag4=argumentCheck(right,flag3->argv);
				if(flag4==1);
				else
				{
					printf(" ---> function or procedure %s arguments error\n",lt->string);
				}
			}
			return;
		case NODE_WHILE:
			lt=node->child;
			right=lt->rsibling;
			
			int CorrectType=expression_valid(lt,1);
			if(CorrectType==0) CorrectType=expression_valid(lt,2);
			if(CorrectType==1);
			else
			{
				printf(" ---> expression error\n");
			}
			pro_ST(right);
			return;
		case NODE_IF:
			
			lt=node->child;
			right=lt->rsibling;
			
			CorrectType=expression_valid(lt,1);
			if(CorrectType==0) CorrectType=expression_valid(lt,2);
			if(CorrectType==1);
			else
			{
				printf(" ----> expression error\n");
			}
			pro_ST(right);
			right=right->rsibling;
			pro_ST(right);
			return;
	};
	struct nodeType *st_symbol2 = node->child;
    if(st_symbol2 != NULL) 
	{
        do 
		{
            pro_ST(st_symbol2);
            st_symbol2 = st_symbol2->rsibling;
        } while(st_symbol2 != node->child);
    }
}

void pro_PG(struct nodeType* node)
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
			temp=function_recall(node->child->child->string);
			if(temp==NULL);
			else
			{
				printf("[ERROR]duplicate declaration temp_array function %s\n",node->child->child->string);
			}
			temp=variable_whole(node->child->child->string);
			if(temp==NULL);
			else if(temp->varType!=node->child->varType);
			else
			{
				printf("[ERROR]duplicate declaration temp_array VAR %s\n",node->child->child->string);
			}
			
			
			if(node->child->rsibling->nodeType==NODE_PARA_LIST)
				argv = create_argument(node->child->rsibling);
			else argv=NULL;
			child = node->child; 
			create_symbolTable(child->child->string,child->varType,argv,NULL,1);
		
			create_new_scope();
			create_symbolTable(child->child->string,child->varType,NULL,NULL,0);
			if(argv==NULL)
			{
				break;
			}
			
			child = child->rsibling; 
			
			while(child!=node->child)
			{
				
				del_process(child);
				modSymbol(child,1,1);
				
				child = child->rsibling;
			}
			break;
		case NODE_DECLARE:
			del_process(node);
			break;
		case NODE_STMT_LIST:
			pro_ST(node);
			
			destroy_new_scope();
			
			break;
		case NODE_PROCEDURE:
			if(node->child->rsibling->nodeType==NODE_PARA_LIST)
				argv = create_argument(node->child->rsibling);
			else argv=NULL;
			child = node->child;
			create_symbolTable(child->string,5,argv,NULL,2);
			create_new_scope();

			if(argv==NULL)
			{
				break;
			}
			child = child->rsibling;
			while(child!=node->child)
			{
				del_process(child);
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
            pro_PG(st_symbol2);
            st_symbol2 = st_symbol2->rsibling;
        } while(st_symbol2 != node->child);
    }
}

void create_TABLE(struct nodeType *root)
{
	struct nodeType* first = root->child;
	struct nodeType* go = root->child;
	create_new_scope();
	go = go->rsibling;
	while(go!=first){
		switch(go->nodeType)
		{
			case NODE_DECLARE:
				del_process(go);
				break;
			case NODE_SUBPROGRAM_LIST:
				pro_PG(go);
				break;
			case NODE_STMT_LIST:
				pro_ST(go);
				break;
		}
		go = go->rsibling;
	}
	destroy_new_scope();
}

void printTable()
{
	int i;
	printf("\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("name\t\ttype\t\t\tscope\n");
	printf("\n");
	for(i=0;i<=flag;i++)
	{
		struct symbol* temp_res = symTable[i];
		if(temp_res==NULL) continue;
		do
		{
			if (temp_res->varType == 1 && temp_res->isfunc!=1) printf("%s\t\tInteger\t\t\t%d",temp_res->name, i+1);
			else if (temp_res->varType == 1 && temp_res->isfunc ==1) printf("%s\t\tFunction\t\t%d",temp_res->name, i+1);
			else if (temp_res->varType == 2) printf("%s\t\tRealNum\t\t\t%d",temp_res->name, i+1);
			else if (temp_res->varType == 11) printf("%s\t\tIntArray\t\t%d",temp_res->name, i+1);
			else if (temp_res->varType == 22) printf("%s\t\tRealArray\t\t%d",temp_res->name, i+1);
		    printf("\n");	
			if(temp_res->argValid)
			{
				
				struct argument* st_symbol = temp_res -> argv;
				while(st_symbol!=NULL)
				{
					st_symbol = st_symbol->next;
				}
		
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
	create_TABLE(ASTRoot);
	printTable();
	
    return 0;
}