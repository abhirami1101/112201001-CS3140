#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <stdbool.h>
#define MAXVARS 150
typedef enum{TYPE_INT, TYPE_BOOL, TYPE_ARRAY_INT} Type;


typedef struct Symbol{
	char* varname;
	Type type;
	int is_function;
	union{
		int intval;
		bool boolval;
		int* int_arrayval;
	}value; //as of now I have only considered two types integer and boolean
	 
	int size;
	struct Symbol* next;
	struct Symbol* children; //if we have an array (but is this really needed), no this is not needed 
	 // we can us an additional data type, like int_array and then store a pointer to it.
	 
	

} Symbol;



Symbol* createSymbol(char* name, Type type, int size, int isfunction);
void insertSymbol(Symbol** root, char* name, Type type, int size,  int isfunction);
Symbol* lookupSymbol(Symbol* root,  char* name);
void assign(Symbol* var, int index, int value);
void printsymboltable(Symbol* table);
void free_symbol_table(Symbol* sym);

#endif


