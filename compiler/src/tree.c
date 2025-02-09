#include "../include/tree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Node* createnode(char op, char* name, int value,  Symbol* var, Node* left, Node* right,Node* extra){
	Node* new = (Node*) malloc(sizeof(Node));
	new->op = op;
	new->name = strdup(name);
	new->value = value;
	// new->index = index; //if a variable it would have 
	// but incase of array implementation only, so not needed, 
	// so instead we can have a pointer to the symbol in the symbol table
	new->var_pointer = var;
	new->left = left;
	new->right = right;
	new->extra = extra;
	return new;
}

void printroot(Node* node, int depth) {
    if (node == NULL) return;

    // Print indentation for depth
    for (int i = 0; i < depth; i++) {
        printf("  ");  
    }

    // Print the node's information
    if (node->name) {
        printf("|-- %s", node->name);
    } else {
        printf("|-- (op: %c)", node->op);
    }

    // Print variable or constant value if applicable
    if (node->var_pointer) {
        printf(" [Var: %s, value : %d]", node->var_pointer->varname, node->var_pointer->value.intval);
    }

    printf("\n");

    // Recursively print child nodes
    printroot(node->left, depth + 1);
    printroot(node->right, depth + 1);
    printroot(node->extra, depth );  // Extra node for additional linking (like function args)
}