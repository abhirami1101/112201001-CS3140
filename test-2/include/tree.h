#ifndef TREE_H
#define TREE_H

#include "symbol_table.h"

extern int error_flag;

typedef struct Node{
	char op;
	char* name;
	float value;
	// union{
	// 	int val_int;
	// 	bool val_bool;
	// } value;
	Symbol* var_pointer;
	struct Node* left;
	struct Node* right;
	 struct Node* extra; //not needed actually
} Node;

Node* createnode(char op, char* name,double value, Symbol* var, Node* left, Node* right, Node* extra);
void printroot(Node* root, int depth);
void evaluate_if(Node* root, Symbol* symbol_table);
void evaluate_write(Node* root, Symbol* symbol_table);
void evaluate_statement(Node* root, Symbol* symbol_table);
void evaluate_assign(Node* root, Symbol* symbol_table);
void evaluate_for(Node* root, Symbol* symbol_table);
double evaluate_expr(Node* root, Symbol* symbol_table);
void free_tree(Node* node);

#endif