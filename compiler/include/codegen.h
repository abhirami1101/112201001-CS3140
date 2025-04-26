#ifndef CODEGEN_H
#define CODEGEN_H

#include "symbol_table.h"
#include "tree.h"


// Node* createnode(char op, char* name,int value, Symbol* var, Node* left, Node* right, Node* extra);
void genMIPS (const char* filename,Node* root, Symbol* symbol_table);
void gen_if_then(Node* root, Symbol* symbol_table);
void gen_if_then_else(Node* root, Symbol* symbol_table);
void gen_write(Node* root, Symbol* symbol_table);
void gen_statement(Node* root, Symbol* symbol_table);
void gen_assign(Node* root, Symbol* symbol_table);
void gen_for(Node* root, Symbol* symbol_table);
int gen_expr(Node* root, Symbol* symbol_table);
void gen_read(Node* root, Symbol* symbol_table);
void gen_decl(Node* root, Symbol* symbol_table);
void gen_prologue(Node* root, Symbol* symbol_table);
void gen_mprologue(Node* root, Symbol* symbol_table);
void gen_main(Node* root, Symbol* symbol_table);
void gen_read(Node* root, Symbol* symbol_table);
// void check_state(Node* root, Symbol* symbol_table);
void generate_data_section_entries(Node* node, Symbol* symbol_table);
void gen_statement_list(Node* root, Symbol* symbol_table);
void gen_epilogue();
void reset_regs();
int get_temp_reg();
int get_sub_reg();
void reset_arg();
int get_arg_reg();
void reset_temp_regs();



#endif