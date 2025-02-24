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
    for (int i = 0; i < depth; i++) {
        printf("  ");  
    }
    if (node->name) {
        printf("|-- %s", node->name);
    } else {
        printf("|-- (op: %c)", node->op);
    }
    if (node->var_pointer) {
        printf(" [Var: %s]", node->var_pointer->varname);
    }
    printf("\n");
    printroot(node->left, depth + 1);
    printroot(node->right, depth + 1);
    printroot(node->extra, depth );  
}



void evaluate_statement(Node* root){
    if (strcmp(root->name, "if-then") == 0|| strcmp(root->name, "if-then-else") == 0 )
        evaluate_if(root);
    else if (strcmp(root->name, "write") == 0 )
        evaluate_write(root);
    else if (strcmp(root->name, "assign") == 0 )
        evaluate_assign(root);
}

void evaluate_if(Node* root){
    if (root == NULL)
        return;
    if (strcmp(root->name,"if-then") == 0){
        Node* if_node = root->left;
        Node* then_node = root->right;
        if (if_node->left->value == 1)
            evaluate_statement(then_node->left);

    }
}

void evaluate_write(Node* root){
    	  Node* para;
		  para = root->left;
		  printf("console output : \n");
		  while (para){
			printf("%d\n", para->value);
			para = para->extra;
		  }
}

void evaluate_assign(Node* root){
   if (strcmp(root->name, "assign") == 0){
    if (root->left->var_pointer){
        root->left->var_pointer->value.intval = root->right->value;
    }
    else{
       fprintf(stderr, "Error: Assignment to an undefined variable!"); 
    }
   }
   else if (strcmp(root->name, "assign_array") == 0){
    root->left->left->var_pointer->value.int_arrayval[root->left->right->value] = root->right->value;
   } 
}