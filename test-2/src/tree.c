#include "../include/tree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int error_flag = 0;

int break_flag = 0; /* to check for any break statements evaluated 
after the evaluation of every for-loop statements it should be reset to 1 .. 
so that even nested loops would be handled efficiently */

int continue_flag = 0;


Node* createnode(char op, char* name, double value,  Symbol* var, Node* left, Node* right,Node* extra){
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

void free_tree(Node* node){
    // printf("----------\n");
    printf("----freeing the tree-----\n");
    free(node);
}

void printroot(Node* node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) {
        printf("|  ");  
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
    if (root == NULL ) return;

    if (strcmp(root->name, "if-then") == 0 || strcmp(root->name, "if-then-else") == 0) {
        evaluate_if(root,symbol_table);
    } 
    else if (strcmp(root->name, "write") == 0) {
        evaluate_write(root,symbol_table);
    } 
    else if (strcmp(root->name, "assign") == 0 || strcmp(root->name, "assign_array") == 0 ) {
        evaluate_assign(root,symbol_table);
    }
    else if (strcmp(root->name, "for-loop") == 0){
        evaluate_for(root,symbol_table);
    }
    else if (strcmp(root->name, "do-while") == 0){
        evaluate_dowhile(root,symbol_table);
    }
    else if (strcmp(root->name, "break") == 0){
        break_flag = 1;
        return;
    }
    else if (strcmp(root->name, "continue") == 0){
        continue_flag = 1;
        return;
    }
    // printf("\n ------------------------------ \n");
    // if (error_flag != 1 ){
    // printf("--printing  symbol table values--\n");
    // printsymboltable(symbol_table);
    // printf("---------------------------------\n");
    
    // }
    // to evaluate next statements (connected through extra)
    if (root->extra != NULL && continue_flag == 0 && break_flag == 0) {
        evaluate_statement(root->extra,symbol_table);
        
    }
}


void evaluate_if(Node* root ,Symbol* symbol_table){
    // printf("[[[]]]]] %s", root->name);
    if (root == NULL)
        return;
    if (strcmp(root->name,"if-then") == 0){
        Node* if_node = root->left;
        Node* then_node = root->left->right;
        // printf("if-then ------ %s\n", then_node->left->name);
        if ((int)evaluate_expr(if_node->left, symbol_table) == 1){
            evaluate_statement(then_node->left,symbol_table);
            //  printf("if-then ------ %s\n", then_node->left->name);
        }

    }
    if (strcmp(root->name,"if-then-else") == 0){
        // printf("if-then-else\n");
        Node* if_node = root->left;

        Node* then_node = root->left->right;
        Node* else_node = root->left->extra;
        if ((int)evaluate_expr(if_node->left, symbol_table) == 1){
            evaluate_statement(then_node->left,symbol_table);
            //  printf("condition %d\n", if_node->left->value);
            // printf("if-then-else ------ %s\n", then_node->left->name);
        }
        else{
            evaluate_statement(else_node->left,symbol_table);
        }

    }
    if (error_flag != 1 ){
        printf("--printing  symbol table values--\n");
        printsymboltable(symbol_table);
        printf("---------------------------------\n");
    }
}

void evaluate_write(Node* root,  Symbol* symbol_table){
    	  Node* para;
		  para = root->left;
          printf("\n");
		  printf("console output : \n");
        //   printf("\n");
		  while (para){
            // printf("%s", para->left->left->name);
			// printf("%d\n", evaluate_expr(para->left, symbol_table));
            if (para->left->var_pointer){
                if (para->left->var_pointer->type == TYPE_INT) // if its a variable with
                    printf("%d\n", (int)evaluate_expr(para->left, symbol_table));
                if (para->left->var_pointer->type == TYPE_FLOAT)
                    printf("%f\n", evaluate_expr(para->left, symbol_table));
            }
            else
                printf("%f\n", evaluate_expr(para->left, symbol_table)); //else it just prints a float value irrespective of the expression
			para = para->extra;
		  }
          printf("\n");
          if (error_flag != 1 ){
            printf("--printing  symbol table values--\n");
            printsymboltable(symbol_table);
            printf("---------------------------------\n");
        }
}

void evaluate_assign(Node* root,  Symbol* symbol_table){


   if (strcmp(root->name, "assign") == 0){
    if (root->left->var_pointer){
        // root->left->var_pointer->value.intval = root->right->value;
        if (root->left->var_pointer->type == TYPE_INT)
            root->left->var_pointer->value.intval = evaluate_expr(root->right, symbol_table);
        if (root->left->var_pointer->type == TYPE_FLOAT)
            root->left->var_pointer->value.floatval = evaluate_expr(root->right, symbol_table);
    }
    else{
        error_flag = 1;
       fprintf(stderr, "Error: Assignment to an undefined variable!\n"); 

    }
   }
   else if (strcmp(root->name, "assign_array") == 0){
    // root->left->left->var_pointer->value.int_arrayval[root->left->right->value] = root->right->value;
    // printf("array  %d\n", evaluate_expr(root->left->right, symbol_table));
    if (strcmp(root->left->right->name,"2d_array_index") != 0 ){
    if (evaluate_expr(root->left->right, symbol_table) >= root->left->left->var_pointer->size){
        error_flag = 1;
        fprintf(stderr, "Error : Index out of range!\n"); 
        
    }
    else{
        if ( root->left->left->var_pointer->type == TYPE_ARRAY_INT)
            root->left->left->var_pointer->value.int_arrayval[(int)evaluate_expr(root->left->right, symbol_table)] = evaluate_expr(root->right, symbol_table);
        else 
        root->left->left->var_pointer->value.float_arrayval[(int)evaluate_expr(root->left->right, symbol_table)] = evaluate_expr(root->right, symbol_table);
    }
}
    else {
        if (evaluate_expr(root->left->right->left, symbol_table) * root->left->left->var_pointer->dim[1] + evaluate_expr(root->left->right->right, symbol_table) >= root->left->left->var_pointer->size){
            error_flag = 1;
            fprintf(stderr, "Error : Index out of range! ---\n"); 
            
        }
        else{
            if (root->left->left->var_pointer->type == TYPE_2DARRAY_INT)
                root->left->left->var_pointer->value.int_arrayval[(int)(evaluate_expr(root->left->right->left, symbol_table) * root->left->left->var_pointer->dim[1] + evaluate_expr(root->left->right->right, symbol_table))] = evaluate_expr(root->right, symbol_table);
            else if (root->left->left->var_pointer->type == TYPE_2DARRAY_FLOAT)
            root->left->left->var_pointer->value.float_arrayval[(int)(evaluate_expr(root->left->right->left, symbol_table) * root->left->left->var_pointer->dim[1] + evaluate_expr(root->left->right->right, symbol_table))] = evaluate_expr(root->right, symbol_table);
        }   
   }
   if (error_flag != 1 ){
    printf("--printing  symbol table values--\n");
    printsymboltable(symbol_table);
    printf("---------------------------------\n");
}
}
}

void evaluate_for(Node* root, Symbol* symbol_table){
    Node* conditions = root->left;
    Node* initial = conditions;
    Node* condition = conditions->right;
    Node* step = conditions->extra;
    Node* stmt_list = root->right->left;
    if (initial->left != NULL)
        evaluate_assign(initial->left,symbol_table);
    if (condition->left == NULL){
        while(true){
            if (stmt_list != NULL)
            evaluate_statement(stmt_list, symbol_table);
        if (break_flag == 1)
            break;
        if (continue_flag == 1){
            if (step->left != NULL)
                evaluate_assign(step->left, symbol_table);
                continue_flag = 0;
                continue;
        }
        if (step->left != NULL)
            evaluate_assign(step->left, symbol_table);  
        }
    }
    while (evaluate_expr(condition->left,symbol_table)){
        if (stmt_list != NULL)
            evaluate_statement(stmt_list, symbol_table);
        if (break_flag == 1)
            break;
        if (continue_flag == 1){
            if (step->left != NULL)
                evaluate_assign(step->left, symbol_table);
                continue_flag = 0;
                continue;
        }
        if (step->left != NULL)
            evaluate_assign(step->left, symbol_table);
        if (!evaluate_expr(condition->left, symbol_table) ) {
            break;
        }
    }
    break_flag = 0;
    if (error_flag != 1 ){
        printf("--printing  symbol table values--\n");
        printsymboltable(symbol_table);
        printf("---------------------------------\n");
    }

}

void evaluate_dowhile(Node* root,Symbol* symbol_table){
    Node* do_stmt = root->left;
    Node* while_exp = root->right;
    if (do_stmt != NULL){
        do {
            evaluate_statement(do_stmt->left, symbol_table);
            if (break_flag != 0){
                break;
            }
            if (continue_flag != 0){
                continue_flag = 0;
                continue;
            }
        } while (evaluate_expr(while_exp->left, symbol_table));
    }
    if (error_flag != 1 ){
        printf("--printing  symbol table values--\n");
        printsymboltable(symbol_table);
        printf("---------------------------------\n");
    }

}

double evaluate_expr(Node* root, Symbol* symbol_table) {
    if (root == NULL) return 0;

    if (strcmp(root->name, "number") == 0)
        return root->value;
    if (strcmp(root->name, "flnumber") == 0) // we can consider float also as a number (should we have a special consideration for float?)
        return root->value;

    else if (strcmp(root->name, "var_expr") == 0) {
        if (root->left->var_pointer) { 
            // printf("%s == %d\n", root->left->var_pointer->varname, root->left->var_pointer->value.intval);
            if (root->left->var_pointer->type == TYPE_INT)
                return root->left->var_pointer->value.intval;
            else if (root->left->var_pointer->type == TYPE_FLOAT)
                return root->left->var_pointer->value.floatval;
        } else {
            error_flag = 1;
            fprintf(stderr, "Error: Undefined variable!\n");
            return 0;
        }
    } 
    else if (strcmp(root->name, "T") == 0 || strcmp(root->name, "F") == 0)
        return root->value;
    else if (root->op == '+'){
        // printf("add\n");
        root->value = evaluate_expr(root->left, symbol_table) + evaluate_expr(root->right, symbol_table);
        return evaluate_expr(root->left, symbol_table) + evaluate_expr(root->right, symbol_table);}
    else if (root->op == '-'){
        root->value = evaluate_expr(root->left, symbol_table) - evaluate_expr(root->right, symbol_table);
        return evaluate_expr(root->left, symbol_table) - evaluate_expr(root->right, symbol_table);}
    else if (root->op == '*')
        return evaluate_expr(root->left, symbol_table) * evaluate_expr(root->right, symbol_table);
    else if (root->op == '/') {
        int denominator = evaluate_expr(root->right, symbol_table);
        if (denominator == 0) {
            error_flag = 1;
            fprintf(stderr,"Division by zero!\n");
            return 0;
        }
        return evaluate_expr(root->left, symbol_table) / denominator;
    }
    else if (root->op == '%') {
        int denominator = evaluate_expr(root->right, symbol_table);
        if (denominator == 0) {
            error_flag = 1;
            fprintf(stderr,"Modulo by zero!\n");
            return 0;
        }
        return (int)evaluate_expr(root->left, symbol_table) % denominator;
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
        return !(int)evaluate_expr(root->left, symbol_table);
    else if (root->op == '&')
        return (int)evaluate_expr(root->left, symbol_table) && (int)evaluate_expr(root->right, symbol_table);
    else if (root->op == '|')
        return (int)evaluate_expr(root->left, symbol_table) || (int)evaluate_expr(root->right, symbol_table);
    else if (strcmp(root->name, "Array_exp") == 0){
        if (root->left->var_pointer->type != TYPE_ARRAY_INT || root->left->var_pointer->type != TYPE_ARRAY_FLOAT ){
            error_flag = 1;
            fprintf(stderr,"Not an array so indexing is not possible");
            return 0;
        }
        if (root->left->var_pointer->type != TYPE_ARRAY_FLOAT)
            return root->left->var_pointer->value.int_arrayval[(int)evaluate_expr(root->right,symbol_table)];
        else
        return root->left->var_pointer->value.float_arrayval[(int)evaluate_expr(root->right,symbol_table)]; 

    }
    else if (strcmp(root->name, "2d_Array_exp") == 0){
        if (root->left->var_pointer->type != TYPE_2DARRAY_INT){
            error_flag = 1;
            fprintf(stderr,"Not a 2d array so indexing is not possible");
            return 0;
        }
        if (root->left->var_pointer->type != TYPE_2DARRAY_FLOAT)
            return root->left->var_pointer->value.int_arrayval[(int)(evaluate_expr(root->right->left,symbol_table) * root->left->var_pointer->dim[1] + evaluate_expr(root->right->right,symbol_table)) ];
        else
        return root->left->var_pointer->value.float_arrayval[(int)(evaluate_expr(root->right->left,symbol_table) * root->left->var_pointer->dim[1] + evaluate_expr(root->right->right,symbol_table)) ]; 

    }
    
    return 0;   
}
