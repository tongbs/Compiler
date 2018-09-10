#ifndef __NODE_H__
#define __NODE_H__

struct nodeType;
enum ntype {
    VALUE_INVALID,
	NODE
	/*
	NODE_PROG,
    NODE_IDLIST,
	NODE_DCL,
	NODE_TYPE,
	NODE_STD_TYPE,
	NODE_SUBPROG_DCLS,
	NODE_SUBPROG_DCL,
	NODE_SUBPROG_HEAD,
	NODE_ARG,
	NODE_PRM_LIST,
	NODE_OPT_VAR,
	NODE_CPD_STMT,
	NODE_OPT_STMT,
	NODE_STMT_LIST,
	NODE_STMT,
	NODE_VARIABLE,
	NODE_TAIL,
	NODE_PCD_STMT,
	NODE_EXPR_LIST,
	NODE_EXPR,
	NODE_SP_EXPR,
    NODE_TERM,              
    NODE_FACTOR,                     
    NODE_ADD,
	NODE_MUL,
	NODE_REL,
	*/
};

// #include "symtab.h"
struct nodeType {
    int nodeType;
    struct nodeType *parent;
    struct nodeType *child;
    struct nodeType *lsibling;
    struct nodeType *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    /* items for Array */
    int idxstart;
    int idxend;
    int arraydepth;
    struct nodeType *ref;

    /* Values for general use */
    int iValue;
    double rValue;
    char valueValid;
    char *string;
	char *name;
    
    /* Indicates which OP */
    char op;

};

struct nodeType* newNode(int type, char *s);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);

#endif

