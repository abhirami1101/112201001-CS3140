#ifndef TREE_H
#define TREE_H

#include "symbol_table.h"

typedef struct Node{
	char op;
	char* name;
	int value;
	Symbol* var_pointer;
	struct Node* left;
	struct Node* right;
	 struct Node* extra; //not needed actually
} Node;

Node* createnode(char op, char* name,int value, Symbol* var, Node* left, Node* right, Node* extra);
void printroot(Node* root, int depth);

#endif