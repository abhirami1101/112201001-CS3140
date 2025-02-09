#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAXVARS 150
typedef enum{TYPE_INT, TYPE_BOOL} Type;


typedef struct Symbol{
	char* varname;
	Type type;
	int is_function;
	union{
		int intval;
		int boolval;
	}value; //as of now I have only considered two types integer and boolean
	 
	int size;
	struct Symbol* next;
	struct Symbol* children; //if we have an array (but is this really needed)
	

} Symbol;



Symbol* createSymbol(char* name, Type type, int isfunction);
void insertSymbol(Symbol** root, char* name, Type type, int isfunction);
Symbol* lookupSymbol(Symbol* root, char* name);
void assign(Symbol* var, int value);
void printsymboltable(Symbol* table);

#endif


