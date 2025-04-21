#ifndef CODEGEN_H
#define CODEGEN_H

#include "symbol_table.h"
#include "tree.h"


// Node* createnode(char op, char* name,int value, Symbol* var, Node* left, Node* right, Node* extra);
void genMIPS(Node* root, Symbol* symbol_table);
void gen_if(Node* root, Symbol* symbol_table);
void gen_write(Node* root, Symbol* symbol_table);
void gen_statement(Node* root, Symbol* symbol_table);
void gen_assign(Node* root, Symbol* symbol_table);
void gen_for(Node* root, Symbol* symbol_table);
void gen_expr(Node* root, Symbol* symbol_table);
void gen_read(Node* root, Symbol* symbol_table);
void gen_decl(Node* root, Symbol* symbol_table);
void gen_init(Node* root, Symbol* symbol_table);


#endif