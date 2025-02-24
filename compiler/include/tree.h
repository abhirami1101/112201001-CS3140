#ifndef TREE_H
#define TREE_H

#include "symbol_table.h"

typedef struct Node{
	char op;
	char* name;
	int value;
	// union{
	// 	int val_int;
	// 	bool val_bool;
	// } value;
	Symbol* var_pointer;
	struct Node* left;
	struct Node* right;
	 struct Node* extra; //not needed actually
} Node;

Node* createnode(char op, char* name,int value, Symbol* var, Node* left, Node* right, Node* extra);
void printroot(Node* root, int depth);
void evaluate_if(Node* root);
void evaluate_write(Node* root);
void evaluate_statement(Node* root);
void evaluate_if(Node* root);
void evaluate_assign(Node* root);


#endif