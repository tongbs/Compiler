#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"
#include <signal.h>

struct nodeType* newNode(int type, char *s) {
    struct nodeType *node = (struct nodeType*)malloc(sizeof(struct nodeType));
    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;
    node->child = NULL;
    node->lsibling = node;
    node->rsibling = node;
	node->name=s;

    return node;
}

void addChild(struct nodeType *node, struct nodeType *child) {
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

void printTree(struct nodeType *node, int ident) {
    //static char blank[1024];
    //for(int i=0; i<ident; i++)
        //blank[i] = ' ';
    //blank[ident] = 0;
	for(int i=0;i<ident;i++) printf("    ");
	printf("%s\n", node->name);
	ident++;
/*
    switch(node->nodeType) {
        case OP_ADD:
            printf("%s/ADD\n", blank);
            break;
        case OP_SUB:
            printf("%s/SUB\n", blank);
            break;
        case OP_MUL:
            printf("%s/MUL\n", blank);
            break;
        case OP_DIV:
            printf("%s/DIV\n", blank);
            break;
        case NODE_INT:
            printf("%s%d\n", blank, node->iValue);
            ident += 8;
            break;
        case NODE_STMT:
            printf("%s/STMT\n", blank);
            ident += 8;
            break;
        case NODE_TERM:
            printf("%s/TERM\n", blank);
            ident += 8;
            break;
        case NODE_PROGRAM:
            printf("%s/PROGRAM\n", blank);
            ident += 8;
            break;
        case NODE_EXPR:
            printf("%s/EXPR\n", blank);
            ident += 8;
            break;
        default:
            printf("%sdefault:%d\n", blank, node->nodeType);
          break;

    }
	*/

    struct nodeType *child = node->child;

    if(child != NULL) {

        do {
            printTree(child, ident);
            child = child->rsibling;
        } while(child != node->child);

		/*
		printTree(child,ident);
		child=child->lsibling;
		while(child!=node->child){
			printTree(child, ident);
			child=child->lsibling;
		}
		*/
    }


}

