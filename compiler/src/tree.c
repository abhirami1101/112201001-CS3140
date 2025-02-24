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



void evaluate_statement(Node* root,  Symbol* symbol_table){
    if (root == NULL) return;

    if (strcmp(root->name, "if-then") == 0 || strcmp(root->name, "if-then-else") == 0) {
        evaluate_if(root,symbol_table);
    } 
    else if (strcmp(root->name, "write") == 0) {
        evaluate_write(root,symbol_table);
    } 
    else if (strcmp(root->name, "assign") == 0) {
        evaluate_assign(root,symbol_table);
    }
    else if (strcmp(root->name, "for-loop") == 0){
        evaluate_for(root,symbol_table);
    }

    // Always evaluate extra statements in sequence
    if (root->extra != NULL) {
        evaluate_statement(root->extra,symbol_table);
    }
}


void evaluate_if(Node* root ,Symbol* symbol_table){
    if (root == NULL)
        return;
    if (strcmp(root->name,"if-then") == 0){
        Node* if_node = root->left;
        Node* then_node = root->right;
        if (if_node->left->value == 1){
            evaluate_statement(then_node->left,symbol_table);
            // printf("heyyy\n");
        }

    }
    if (strcmp(root->name,"if-then-else") == 0){
        Node* if_node = root->left;
        Node* then_node = root->right;
        Node* else_node = root->extra;
        if (if_node->left->value == 1){
            evaluate_statement(then_node->left,symbol_table);
            // printf("heyyy\n");
        }
        else{
            evaluate_statement(else_node->left,symbol_table);
        }

    }
}

void evaluate_write(Node* root,  Symbol* symbol_table){
    	  Node* para;
		  para = root->left;
          printf("\n");
		  printf("console output : \n");
        //   printf("\n");
		  while (para){
			printf("%d\n", para->value);
			para = para->extra;
		  }
          printf("\n");
}

void evaluate_assign(Node* root,  Symbol* symbol_table){
   if (strcmp(root->name, "assign") == 0){
    if (root->left->var_pointer){
        // root->left->var_pointer->value.intval = root->right->value;
        root->left->var_pointer->value.intval = evaluate_expr(root->right, symbol_table);
        
    }
    else{
       fprintf(stderr, "Error: Assignment to an undefined variable!"); 
    }
   }
   else if (strcmp(root->name, "assign_array") == 0){
    // root->left->left->var_pointer->value.int_arrayval[root->left->right->value] = root->right->value;
    root->left->left->var_pointer->value.int_arrayval[root->left->right->value] = evaluate_expr(root->right, symbol_table);
   }
   printf("printing symbol table values\n");
   printsymboltable(symbol_table);
   printf("\n-----------------------------\n");
}

void evaluate_for(Node* root, Symbol* symbol_table){
    Node* initial = root->left;
    Node* condition = root->left->extra;
    Node* step = root->right;
    Node* stmt_list = root->extra;
    evaluate_assign(initial->left,symbol_table);
    while (evaluate_expr(condition->left,symbol_table)){
        evaluate_statement(stmt_list->left, symbol_table);
        evaluate_assign(step, symbol_table);
        if (!evaluate_expr(condition->left, symbol_table)) {
            break;
        }
    }

}






// int evaluate_expr(Node* root, Symbol* symbol_table){
//     if (root == NULL)
//         return 0;
//     if (strcmp(root->name, "number") == 0)
//         return root->value;
//     else if (strcmp(root->name,"var_expr") == 0)
//         return root->value;
//     else if (strcmp(root->name,"T") == 0 || strcmp(root->name, "F"))
//         return root->value;
//     else if (root->op == '+')
//         return root->left->value + root->right->value;
//     else if (root->op == '-')
//         return root->left->value - root->right->value;
//     else if (root->op == '*')
//         return root->left->value * root->right->value;
//     else if (root->op == '/'){
//         // return root->left->value / root->right->value;
//         if (root->right->value == 0) {
//             fprintf(stderr,"Division by zero!"); 
//             return 0;
//         } else {
//             return root->left->value / root->right->value;
//         }
//     }
//     else if (root->op == '%'){
//         // return root->left->value / root->right->value;
//         if (root->right->value == 0) {
//             fprintf(stderr,"Modulo by zero!"); 
//             return 0;
//         } else {
//             return root->left->value % root->right->value;
//         }
//     }
//     else if (root->op == '<')
//         return root->left->value < root->right->value;
//     else if (root->op == '>')
//         return root->left->value > root->right->value;
//     else if (root->op == 'G')
//         return root->left->value >= root->right->value;
//     else if (root->op == 'L')
//         return root->left->value <= root->right->value;
//     else if (root->op == 'N')
//         return root->left->value != root->right->value;
//     else if (root->op == 'E')
//         return root->left->value == root->right->value;
//     else if (strcmp(root->name, "Array_exp") == 0)
//         return root->value;
//     else if (root->op == '!')
//         return !root->left->value;
//     else if (root->op == '&')
//         return root->left->value && root->right->value;
//     else if (root->op == '|')
//         return root->left->value || root->right->value;
//     return 0;   
// }

int evaluate_expr(Node* root, Symbol* symbol_table) {
    if (root == NULL) return 0;

    if (strcmp(root->name, "number") == 0)
        return root->value;
    else if (strcmp(root->name, "var_expr") == 0) {
        if (root->var_pointer) { 
            return root->var_pointer->value.intval;
        } else {
            fprintf(stderr, "Error: Undefined variable!\n");
            return 0;
        }
    } 
    else if (strcmp(root->name, "T") == 0 || strcmp(root->name, "F"))
        return root->value;
    else if (root->op == '+')
        return evaluate_expr(root->left, symbol_table) + evaluate_expr(root->right, symbol_table);
    else if (root->op == '-')
        return evaluate_expr(root->left, symbol_table) - evaluate_expr(root->right, symbol_table);
    else if (root->op == '*')
        return evaluate_expr(root->left, symbol_table) * evaluate_expr(root->right, symbol_table);
    else if (root->op == '/') {
        int denominator = evaluate_expr(root->right, symbol_table);
        if (denominator == 0) {
            fprintf(stderr,"Division by zero!\n");
            return 0;
        }
        return evaluate_expr(root->left, symbol_table) / denominator;
    }
    else if (root->op == '%') {
        int denominator = evaluate_expr(root->right, symbol_table);
        if (denominator == 0) {
            fprintf(stderr,"Modulo by zero!\n");
            return 0;
        }
        return evaluate_expr(root->left, symbol_table) % denominator;
    }
    else if (root->op == '<')
        return evaluate_expr(root->left, symbol_table) < evaluate_expr(root->right, symbol_table);
    else if (root->op == '>')
        return evaluate_expr(root->left, symbol_table) > evaluate_expr(root->right, symbol_table);
    else if (root->op == 'G')
        return evaluate_expr(root->left, symbol_table) >= evaluate_expr(root->right, symbol_table);
    else if (root->op == 'L')
        return evaluate_expr(root->left, symbol_table) <= evaluate_expr(root->right, symbol_table);
    else if (root->op == 'N')
        return evaluate_expr(root->left, symbol_table) != evaluate_expr(root->right, symbol_table);
    else if (root->op == 'E')
        return evaluate_expr(root->left, symbol_table) == evaluate_expr(root->right, symbol_table);
    else if (root->op == '!')
        return !evaluate_expr(root->left, symbol_table);
    else if (root->op == '&')
        return evaluate_expr(root->left, symbol_table) && evaluate_expr(root->right, symbol_table);
    else if (root->op == '|')
        return evaluate_expr(root->left, symbol_table) || evaluate_expr(root->right, symbol_table);
    
    return 0;   
}
