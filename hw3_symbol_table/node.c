#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
//0413359
struct nodeType* newNode(int type) {
    struct nodeType *node = (struct nodeType*)malloc(sizeof(struct nodeType));
    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;
    node->child = NULL;
    node->lsibling = node;
    node->rsibling = node;

    return node;
}

void addChild(struct nodeType *node, struct nodeType *child) {
    if(child == NULL) return;
	child->parent = node;

    if(node->child == NULL) {
        node->child = child;
    }
    else {
        child->lsibling = node->child->lsibling;
        child->rsibling = node->child;
        node->child->lsibling->rsibling = child;
        node->child->lsibling = child;
    }
}

void deleteNode(struct nodeType *node) {
    if(node->string != NULL)
        free(node->string);
    free(node);
}

void printTree(struct nodeType *node, int identifier) {
    static char blank[1024];
    for(int i=0; i<identifier; i++)
        blank[i] = ' ';
    blank[identifier] = 0;

    switch(node->nodeType) {
        case NODE_TOKEN:
			printf("////%sToken %s\n", blank, node->string);
            break;
		case NODE_VARIABLE:
			printf("///%sVAR %s\n", blank, node->string);
			identifier++;
            break;
        case NODE_OP:
            switch(node->op) {
                case OP_ADD:
                    printf("///%s+\n", blank);
                    break;
                case OP_SUB:
                    printf("///%s-\n", blank);
                    break;
                case OP_MUL:
                    printf("///%s*\n", blank);
                    break;
                case OP_DIV:
                    printf("///%s/\n", blank);
                    break;
                case OP_GT:
                    printf("///%s>\n", blank);
                    break;
                case OP_LT:
                    printf("///%s<\n", blank);
                    break;
                case OP_EQ:
                    printf("///%s=\n", blank);
                    break;
                case OP_GE:
                    printf("///%s>=\n", blank);
                    break;
                case OP_LE:
                    printf("///%s<=\n", blank);
                    break;
                case OP_NE:
                    printf("///%s!=\n", blank);
                    break;
				case OP_NOT:
                    printf("///%s!\n", blank);
                    break;
            }
            identifier++;
            break;
		case NODE_TYPE:
			printf("++++++++++++++++%sTYPE %d\n", blank, node->varType);
			identifier++;
            break;
        case NODE_INT:
            printf("++++++++++++++++%s%d\n", blank, node->iValue);
            break;
        case NODE_REAL:
            printf("++++++++++++++++%s%f\n", blank, node->rValue);
            break;
        case NODE_INDEX_VAR:  //X
            printf("++++++++++++++++%sIndex variable %s\n", blank, node->string);
            identifier++;
            break;
        case NODE_VAR_OR_PROC: //XX
            printf("++++++++++++++++%s%s\n", blank, node->string);
            break;
        case NODE_PROCEDURE_STMT:
            printf("++++++++++++++++%sProcedure stmt %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_DECLARE:
			printf("++++++++++++++++%sNODE_DECLARE %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_ARRAY:
			printf("++++++++++++++++%sNODE_ARRAY %d %d\n", blank, node->arry_start,node->arry_end);
            identifier++;
            break;
		case NODE_NUM: 
			printf("++++++++++++++++%sNODE_NUM %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_FUNC:
			printf("++++++++++++++++%sNODE_FUNC %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_PROCEDURE:
			printf("++++++++++++++++%sNODE_PROCEDURE %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_PARAMETER:
			printf("++++++++++++++++%sNODE_PARAMETER %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_ASSIGN:
			printf("++++++++++++++++%sNODE_ASSIGN %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_IF:
			printf("++++++++++++++++%sNODE_IF %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_WHILE:
			printf("++++++++++++++++%sNODE_WHILE %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_PROGRAM:
			printf("++++++++++++++++%sNODE_PROGRAM %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_ID_LIST:
			printf("++++++++++++++++%sNODE_ID_LIST %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_INDEX_LIST:
			printf("++++++++++++++++%sNODE_INDEX_LIST %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_EXPR_LIST:
			printf("++++++++++++++++%sNODE_EXPR_LIST %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_STMT_LIST:
			printf("++++++++++++++++%sNODE_STMT_LIST %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_SUBPROGRAM_LIST:
			printf("++++++++++++++++%sNODE_SUBPROGRAM_LIST %s\n", blank, node->string);
            identifier++;
            break;
		case NODE_PARA_LIST:
			printf("++++++++++++++++%sNODE_PARA_LIST %s\n", blank, node->string);
            identifier++;
            break;
        case NODE_LIST:
            break;
    }

    struct nodeType *child = node->child;
    if(child != NULL) {
        do {
            printTree(child, identifier);
            child = child->rsibling;
        } while(child != node->child);
    }
}

