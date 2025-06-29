#include "../include/symbol_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



Symbol* createSymbol(char* name, Type type, int size, int isfunction, int* dim) {
    Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
    sym->varname = strdup(name);
    sym->type = type;
	sym->is_function = isfunction;
    
    if (type == TYPE_INT) {
        sym->value.intval = 0; 
    } else if (type == TYPE_BOOL) {
        sym->value.boolval = -1;
    }
    else if (type == TYPE_ARRAY_INT){
        sym->value.int_arrayval = (int*) malloc(sizeof(int) * size);
        sym->size = size;
    }
    else if (type == TYPE_ARRAY_FLOAT){
        sym->value.float_arrayval = (double*) malloc(sizeof(double) * size);
        sym->size = size;
    }
    else if (type == TYPE_2DARRAY_INT){
        sym->value.int_arrayval = (int*) malloc(sizeof(int) * size);
        sym->size = dim[0] * dim[1];
        if (dim != NULL){
        sym->dim[0] = dim[0];
        sym->dim[1] = dim[1];
        }
    }
    else if (type == TYPE_2DARRAY_FLOAT){
        sym->value.float_arrayval = (double*) malloc(sizeof(double) * size);
        sym->size = dim[0] * dim[1];
        if (dim != NULL){
        sym->dim[0] = dim[0];
        sym->dim[1] = dim[1];
        }
    }
    sym->next = NULL;
    return sym;
}

void insertSymbol(Symbol** root, char* name, Type type, int size,  int isfunction, int* dim) {
    if (*root == NULL) {
        *root = createSymbol(name, type, size, isfunction, dim);
        return;
    }
    Symbol* temp = *root;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createSymbol(name, type, size, isfunction, dim);
}

/*
Symbol* lookup(char* varname, int count_vars){
	 value = 0;
	for (int i = 0; i < count_vars; i++){
		if (strcmp(varname, symbol_table[i].varname) == 0){
			if (symbol_table[i].type == TYPE_INT)
			 	value = symbol_table[i].value.intval;
			else{
				value = symbol_table[i].value.boolval;
			}
			// return value;
		}
	}
	return value;
}


the above implementation can be used incase of arrays(for symbol table)
here maintaining a linked list for the symbol table 
should think of an optimised way to implement like a hash map
arrays wouldnt have dynamic allocation */

Symbol* lookupSymbol(Symbol* root,  char* name) {
    while (root) {
        if (strcmp(root->varname, name) == 0) {
            return root;
        }
        root = root->next;
    }
    return NULL;
}

void assign(Symbol* var, int index,  double value){

	if (var->type == TYPE_INT)
		var->value.intval = (int)value;
    if (var->type == TYPE_FLOAT)
        var->value.floatval = value;
	if (var->type == TYPE_BOOL)
		var->value.boolval = (int)value;
    if (var->type == TYPE_ARRAY_INT)
        var->value.int_arrayval[index] = (int)value;

}

void printsymboltable(Symbol* table){
    if (table != NULL){

        if (table->is_function == 0 && table->size == 0){
            if (table->type == TYPE_INT)
                printf("%s = %d\n", table->varname, table->value.intval);
            else if (table->type == TYPE_FLOAT)
                printf("%s = %f\n", table->varname, table->value.floatval);
            
        }
        else if (table->type == TYPE_ARRAY_INT){
            printf("%s = [", table->varname);
            for (int i = 0; i < table->size; i++){
                printf("%d, ",table->value.int_arrayval[i]);
            }
            printf("]\n");
        }
        else if (table->type == TYPE_ARRAY_FLOAT){
            printf("%s = [", table->varname);
            for (int i = 0; i < table->size; i++){
                printf("%f, ",table->value.float_arrayval[i]);
            }
            printf("]\n");
        }
        else if (table->type == TYPE_2DARRAY_INT){
            printf("%s = [", table->varname);
            for (int i = 0; i < table->dim[0]; i++){
                printf("[");
                for (int j = 0; j < table->dim[1]; j++)
                    printf("%d, ",table->value.int_arrayval[i * table->dim[1] + j]);
                printf("],");
            }
            printf("]\n");
        }
        else if (table->type == TYPE_2DARRAY_FLOAT){
            printf("%s = [", table->varname);
            for (int i = 0; i < table->dim[0]; i++){
                printf("[");
                for (int j = 0; j < table->dim[1]; j++)
                    printf("%f, ",table->value.float_arrayval[i * table->dim[1] + j]);
                printf("],");
            }
            printf("]\n");
        }
        printsymboltable(table->next);
    }
    else{
        return;
    }
}

void free_symbol_table(Symbol* sym){
    free(sym);
    printf("----Free symbol table-----\n");
}