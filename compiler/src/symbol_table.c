#include "../include/symbol_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



Symbol* createSymbol(char* name, Type type, int isfunction) {
    Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
    sym->varname = strdup(name);
    sym->type = type;
	sym->is_function = isfunction;
    
    if (type == TYPE_INT) {
        sym->value.intval = 0; 
    } else if (type == TYPE_BOOL) {
        sym->value.boolval = -1;
    }

    sym->next = NULL;
    return sym;
}

void insertSymbol(Symbol** root, char* name, Type type, int isfunction) {
    if (*root == NULL) {
        *root = createSymbol(name, type, isfunction);
        return;
    }
    Symbol* temp = *root;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createSymbol(name, type, isfunction);
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

Symbol* lookupSymbol(Symbol* root, char* name) {
    while (root) {
        if (strcmp(root->varname, name) == 0) {
            return root;
        }
        root = root->next;
    }
    return NULL;
}

void assign(Symbol* var, int value){

	if (var->type == TYPE_INT)
		var->value.intval = value;
	if (var->type == TYPE_BOOL)
		var->value.boolval = value;

}

void printsymboltable(Symbol* table){
    if (table != NULL){
        if (table->is_function == 0)
            printf("%s = %d\n", table->varname, table->value.intval);
        printsymboltable(table->next);
    }
    else{
        return;
    }
}