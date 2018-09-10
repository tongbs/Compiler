#ifndef __NODE_H__
#define __NODE_H__

#define VALUE_INVALID   0
#define VALUE_I_VALID   1
#define VALUE_R_VALID   2


#define NODE_TOKEN          1
#define NODE_OP             2
#define NODE_INT            3
#define NODE_REAL           4
#define NODE_VARIABLE       5
#define NODE_INDEX_VAR      6  
#define NODE_PROCEDURE_STMT 7
#define NODE_PARA_LIST      8

#define NODE_DECLARE        9
#define NODE_ARRAY          10
#define NODE_NUM            11  
#define NODE_FUNC           12
#define NODE_PROCEDURE      13
#define NODE_PARAMETER      14
#define NODE_ASSIGN         15
#define NODE_IF             16
#define NODE_WHILE          17
#define NODE_PROGRAM        18
#define NODE_ID_LIST        19
#define NODE_INDEX_LIST     20
#define NODE_EXPR_LIST      21
#define NODE_STMT_LIST      22
#define NODE_SUBPROGRAM_LIST 23
#define NODE_TYPE            24

#define NODE_LIST           50

#define NODE_VAR_OR_PROC    99
#define NODE_ERROR          100
#define NODE_EMPTY          101

#define OP_ADD  1
#define OP_SUB  2
#define OP_MUL  3
#define OP_DIV  4
#define OP_GT   5
#define OP_LT   6
#define OP_EQ   7
#define OP_GE   8
#define OP_LE   9
#define OP_NE   10
#define OP_NOT  11

#define TYPE_INT   1
#define TYPE_REAL  2
#define TYPE_NUM   3
#define TYPE_ARRY  4

struct nodeType {
    int nodeType;
    struct nodeType *parent;
    struct nodeType *child;
    struct nodeType *lsibling;
    struct nodeType *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    int iValue;
    double rValue;
    int valueValid;

    char *string;

    char op;
	int varType;
	int arry_start,arry_end;
};

struct nodeType* newNode(int type);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int identifier);

//出現在函數語句中的形式參數列表可以是簡單的或者下標的變量，數組或者結構化變量，或者子程序。
struct argument
{
	int num;
	int argType;
	struct argument* next;
};

struct symbol
{
	char* name;
	int varType;
	int argValid;
	struct symbol* next;
	struct argument* argv;
	struct nodeType* arryhead;
	
	int iValue;
    double rValue;
    int valueValid;
	
	int isfunc;
	int init;//initialize
};

#endif

