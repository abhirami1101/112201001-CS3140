#include "include/codegen.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <stdio.h>
// #include <file.h>


static FILE *outfile;
char* file_name;
static int label_count = 0;
static int temp_reg_num = 0;
#define MAX_TEMP_REGS 8

const char* get_temp_reg() {
    if (temp_reg_num >= MAX_TEMP_REGS) {
        fprintf(stderr, "Error: Out of temporary registers!\n");
        exit(1);
    }
    static char* reg_name;
    sprintf(reg_name, "$t%d", temp_reg_num++); 
    return strdup(reg_name);
}

void reset_temp_regs() {
    temp_reg_num = 0;
}

char* generate_label() {
    static char label_buf[10];
    sprintf(label_buf, "L%d", label_count++);
    return strdup(label_buf); 
}

void gen_init(Node* root, Symbol* symbol_table){

	fprintf(outfile, "	.file  1 \"%s\"\n", file_name);
	fprintf(outfile, "	.section .mdebug.abi32\n");
	fprintf(outfile, "	.previous\n");
	fprintf(outfile, "	.nanlegacy\n");
	fprintf(outfile, "	.module  fp=32\n");
	fprintf(outfile, "	.module  nooddspreg\n");
	fprintf(outfile, "	.abicalls\n");
	fprintf(outfile, "	.text\n");

}

void gen_decl(Node* root, Symbol* symbol_table){
	Symbol* var = symbol_table;
	if (var != NULL){
		if (var->type == TYPE_INT){
			fprintf(outfile, "	.globl %s\n", var->varname);
			fprintf(outfile, "	.section	.bss,\"aw\",@nobits\n");
			fprintf(outfile, "	.align 2\n");
			fprintf(outfile, "	.type %s, @object\n", var->varname);
			fprintf(outfile, "	.type %s, 4\n", var->varname);
			fprintf(outfile, "%s:", var->varname);
			fprintf(outfile,"	.space 4\n");
		}
		else if (var->type == TYPE_ARRAY_INT){
			fprintf(outfile, "	.globl %s\n", var->varname);
			fprintf(outfile, "	.section	.bss,\"aw\",@nobits\n");
			fprintf(outfile, "	.align 2\n");
			fprintf(outfile, "	.type %s, @object\n", var->varname);
			fprintf(outfile, "	.type %s, %d\n", var->varname, 4 * var->size);
			fprintf(outfile, "%s:", var->varname);
			fprintf(outfile,"	.space %d\n", 4 * var->size);
		}
		var = var->next;
	}
	while (var != NULL){
		if (var->type == TYPE_INT){
			fprintf(outfile, "	.globl %s\n", var->varname);
			fprintf(outfile, "	.align 2\n");
			fprintf(outfile, "	.type %s, @object\n", var->varname);
			fprintf(outfile, "	.type %s, 4\n", var->varname);
			fprintf(outfile, "%s:", var->varname);
			fprintf(outfile,"	.space 4\n");
		}
		else if (var->type == TYPE_ARRAY_INT){
			fprintf(outfile, "	.globl %s\n", var->varname);
			fprintf(outfile, "	.align 2\n");
			fprintf(outfile, "	.type %s, @object\n", var->varname);
			fprintf(outfile, "	.type %s, %d\n", var->varname, 4 * var->size);
			fprintf(outfile, "%s:", var->varname);
			fprintf(outfile,"	.space %d\n", 4 * var->size);
		}
		var = var->next;
	}
}


