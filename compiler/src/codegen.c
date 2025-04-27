#include "../include/codegen.h"
#include "../include/symbol_table.h"
#include "../include/tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <stdio.h>
// #include <file.h>


static FILE *outfile;
static int registers[32]; // to keep track of registers, if occuppied : 1 else 0
char* file_name;
static int label_count = 0;
static int temp_reg_num = 8;
static bool free2 = true;
static bool free3 = true;
static int rw_lc = 0;
#define MAX_TEMP_REGS 8 // $t0 to $t7
char* break_label;

int get_arg_reg(){
	int i = 4;
	while (registers[i] != 0 && i <= 7){
		i++;
	}
	return i;
}

void reset_arg(){
	for (int i = 4; i <= 7; i++){
		registers[i] = 0;
	   }
}

int get_sub_reg(){
	// int i = 2;
	if (registers[2] == 0){
		return 2;
	}
	else if (registers[3] == 0){
		return 3;
	}
	return -1;
}

int get_temp_reg(){
	int i = 8;
	while (i <= 15 && registers[i] != 0){
		i++;
	}
	if (i <= 15){
		return i;
	}
	else {
		if (registers[24] == 0){
			return 24;
		}
		else if (registers[25] == 0){
			return 25;
		}
		
	}
	return -1;
}



void reset_regs() {
   for (int i = 0; i < 32; i++){
	registers[i] = 0;
   }
}

void reset_temp_regs(){
	int i = 8;
	while (i <= 15){
		registers[i] = 0;
		i++;
	}
	registers[24] = 0;
	registers[25]=0;
}



char* generate_label() {
    static char label_buf[10];
    sprintf(label_buf, "L%d", label_count++);
    return strdup(label_buf); 
}

void gen_prologue(Node* root, Symbol* symbol_table){

	fprintf(outfile, "\t.file  1 \"%s\"\n", file_name);
	fprintf(outfile, "\t.section .mdebug.abi32\n");
	fprintf(outfile, "\t.previous\n");
	fprintf(outfile, "\t.nan\tlegacy\n");
	fprintf(outfile, "\t.module\tfp=32\n");
	fprintf(outfile, "\t.module\tnooddspreg\n");
	fprintf(outfile, "\t.abicalls\n");
	fprintf(outfile, "\t.text\n");

}

void gen_mprologue(Node* root, Symbol* symbol_table){
	fprintf(outfile, "\t.align 2\n");
	fprintf(outfile, "\t.globl main\n");
	fprintf(outfile, "\t.set nomips16\n");
	fprintf(outfile, "\t.set nomicromips\n");
	fprintf(outfile, "\t.ent main\n");
	fprintf(outfile, "\t.type main, @function\n");
	// fprintf(outfile, "    .align 2\n");
	fprintf(outfile, "main:\n");
}


void gen_decl(Node* root, Symbol* symbol_table){
	Symbol* var = symbol_table;
	if (var != NULL){
		// the initial variable
		if (var->type == TYPE_INT){
			fprintf(outfile, "\t.globl %s\n", var->varname);
			fprintf(outfile, "\t.section	.bss,\"aw\",@nobits\n");
			fprintf(outfile, "\t.align 2\n");
			fprintf(outfile, "\t.type	%s, @object\n", var->varname);
			fprintf(outfile, "\t.size	%s, 4\n", var->varname);
			fprintf(outfile, "%s:\n", var->varname);
			fprintf(outfile,"\t.space 4\n");
		}
		else if (var->type == TYPE_ARRAY_INT){

			fprintf(outfile, "\t.globl %s\n", var->varname);
			fprintf(outfile, "\t.section	.bss,\"aw\",@nobits\n");
			fprintf(outfile, "\t.align 2\n");
			fprintf(outfile, "\t.type %s, @object\n", var->varname);
			fprintf(outfile, "\t.size %s, %d\n", var->varname, 4 * var->size);
			fprintf(outfile, "%s:\n", var->varname);
			fprintf(outfile,"\t.space %d\n", 4 * var->size);
		}
		var = var->next;
	}
	while (var != NULL){
		if (var->type == TYPE_INT){
			
			fprintf(outfile, "\t.globl %s\n", var->varname);
			fprintf(outfile, "\t.align 2\n");
			fprintf(outfile, "\t.type %s, @object\n", var->varname);
			fprintf(outfile, "\t.size %s, 4\n", var->varname);
			fprintf(outfile, "%s:\n", var->varname);
			fprintf(outfile,"\t.space 4\n");
		}
		else if (var->type == TYPE_ARRAY_INT){
			fprintf(outfile, "\t.globl %s\n", var->varname);
			fprintf(outfile, "\t.align 2\n");
			fprintf(outfile, "\t.type %s, @object\n", var->varname);
			fprintf(outfile, "\t.size %s, %d\n", var->varname, 4 * var->size);
			fprintf(outfile, "%s:\n", var->varname);
			fprintf(outfile,"\t.space %d\n", 4 * var->size);
		}
		var = var->next;
	}
	
}

void gen_main(Node* root, Symbol* symbol_table){

	gen_mprologue(root, symbol_table);
	
	int frame_size = 32;
	// here since we wouldnt consider local variables (all are global no of local vars = 0 
	// and hence stack size need not be considered )
	int fp_offset = 8;
	int ra_offset = 4; // possibilites of using a jal for scanf..

	int mask_value = 0xc0000000; // would be $ra 0x80000000 | $fp (0x40000000)
    int mask_offset = ra_offset - frame_size; // this is the offset from $fp where $ra is saved
	fprintf(outfile, "\t.frame $fp,%d,$31\n", frame_size);
	fprintf(outfile, "\t.mask 0x%x,%d\n",mask_value, mask_offset);
	fprintf(outfile, "\t.fmask 0x00000000,0\n");
	fprintf(outfile, "\t.set noreorder\n");
	fprintf(outfile, "\t.cpload $25\n");
	fprintf(outfile, "\t.set reorder\n");
	fprintf(outfile, "\taddiu $sp,$sp,-%d\n",frame_size);
	fprintf(outfile, "\tsw $ra,%d($sp)\n", frame_size-ra_offset); // to store ra during function calls
	fprintf(outfile, "\tsw $fp,%d($sp)\n", frame_size-fp_offset);
	fprintf(outfile, "\tmove $fp,$sp\n");
	fprintf(outfile, "\t.cprestore	16\n");
}

void gen_statement(Node* root, Symbol* symbol_table){
	if (root == NULL ) return;
	// printf("read resched and root is %s\n", root->name);

    if (strcmp(root->name, "if-then") == 0) {
        gen_if_then(root,symbol_table);
    } 
	if (strcmp(root->name, "if-then-else") == 0){
		gen_if_then_else(root,symbol_table);
	}
    else if (strcmp(root->name, "write") == 0) {
       gen_write(root,symbol_table);
    } 
	else if (strcmp(root->name, "read") == 0){
		gen_read(root,symbol_table);
	}
    else if (strcmp(root->name, "assign") == 0 || strcmp(root->name, "assign_array") == 0 ) {
        gen_assign(root,symbol_table);
    }
    else if (strcmp(root->name, "for-loop") == 0){
        gen_for(root,symbol_table);
    }
	else if (strcmp(root->name, "break") == 0){
		break_label = generate_label();
		fprintf(outfile,"\tj\t%s\n",break_label);
	}
	// printf("read resched and root is %s\n", root->extra->name);
    // to evaluate next statements (connected through extra)
}

void gen_statement_list(Node* root, Symbol* symbol_table){
	Node* current_stmt = root;
	while (current_stmt != NULL){
		// printf("%s --\n ", current_stmt->name);
		gen_statement(current_stmt, symbol_table);
		current_stmt = current_stmt->extra;
	}

}

// $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, $3, // initializer assign
// createnode(0, "final-condition", 0, NULL, $5, NULL, NULL), // contains condition expr
// createnode(0, "step", 0, NULL, $7, NULL, NULL)), // contains step assign
// createnode(0, "in-loop", 0, NULL, $10, NULL, NULL), NULL); // contains loop body stmts
// this is how, for loop node is initialised

void gen_for(Node* root, Symbol* symbol_table){
    Node* initial_assign = root->left->left;        // assignment node for initialization
    Node* condition_node = root->left->right;       // final-condition node
    Node* step_node      = root->left->extra;        // step node
    Node* in_loop_node   = root->right;            // in-loop node

    Node* condition_expr  = (condition_node) ? condition_node->left : NULL;
    Node* step_assign     = (step_node) ? step_node->left : NULL;
    Node* loop_body_stmts = (in_loop_node) ? in_loop_node->left : NULL;


    char* loop_start_label = generate_label();
    char* condition_check_label = generate_label();
    char* loop_end_label = generate_label();

    if (initial_assign != NULL) {
        gen_assign(initial_assign, symbol_table);
        // reset_temp_regs(); 
    }
	reset_temp_regs();
    fprintf(outfile, "\tb\t%s\n", condition_check_label);
    fprintf(outfile, "\t#nop\n"); 


    fprintf(outfile, "%s:\n", loop_start_label);

    if (loop_body_stmts != NULL) {
        gen_statement_list(loop_body_stmts, symbol_table);
        // reset_temp_regs();
    } 
	reset_temp_regs();
    if (step_assign != NULL) {
        gen_assign(step_assign, symbol_table);
         reset_temp_regs();
    }

    fprintf(outfile, "%s:\n", condition_check_label);
    int cond_result = -1;
    if (condition_expr != NULL) {
        cond_result = gen_expr(condition_expr, symbol_table);
		registers[cond_result] = 1;
    } 

    if (cond_result != -1) {
        fprintf(outfile, "\tbne\t$%d, $0, %s\n", cond_result, loop_start_label);
        fprintf(outfile, "\t#nop\n");
        registers[cond_result] = 0;
    } else if (condition_expr == NULL) {
        fprintf(outfile, "\tb\t%s\n", loop_start_label);
        fprintf(outfile, "\t#nop\n");
    }
	if (break_label)
		fprintf(outfile,"%s:\n",break_label);
    reset_temp_regs();
}
// createnode(0,"if-then", 0, NULL,  createnode(0,"if", 0, NULL, $2,
// 	createnode(0,"then", 0, NULL, $4,NULL,NULL),NULL), NULL, NULL); 

void gen_if_then(Node* root, Symbol* symbol_table){
	Node* condition = root->left; // if node
	Node* then = root->left->right; // then node

	int if_reg = gen_expr(condition->left,symbol_table); 
	// contains value of the condition
	registers[if_reg] = 1;
	char* then_label = generate_label();
	char* out_label = generate_label();

	fprintf(outfile, "\tbeq\t$%d,$0,%s\n",if_reg,out_label);
	fprintf(outfile, "%s:\n",then_label);
	gen_statement_list(then->left,symbol_table);
	fprintf(outfile, "%s:\n",out_label);
	registers[if_reg] = 0;

}

// createnode(0,"if-then-else", 0, NULL,  createnode(0,"if", 0, NULL, $2,
// createnode(0,"then", 0, NULL, $4,NULL,NULL),createnode(0,"else", 0, NULL, $6,NULL,NULL)), NULL, NULL);  

void gen_if_then_else(Node* root, Symbol* symbol_table){
	Node* condition = root->left; // if node
	Node* then = root->left->right; // then node
	Node* else_node = root->left->extra;

	int if_reg = gen_expr(condition->left,symbol_table); 
	// contains value of the condition
	registers[if_reg] = 1;
	char* then_label = generate_label();
	char* else_label = generate_label();
	char* out_label = generate_label();

	fprintf(outfile, "\tbeq\t$%d,$0,%s\n",if_reg,else_label);
	fprintf(outfile, "%s:\n",then_label);
	gen_statement_list(then->left,symbol_table);
	fprintf(outfile, "\tj\t%s\n",out_label);
	fprintf(outfile, "%s:\n",else_label);
	gen_statement_list(else_node->left,symbol_table);
	fprintf(outfile, "%s:\n",out_label);
	registers[if_reg] = 0;

}

void gen_assign(Node* root, Symbol* symbol_table){
	// int lhs = gen_expr(root->left,symbol_table);
	if (strcmp(root->name, "assign") == 0){
		int lhs = get_sub_reg();
		if (lhs == -1){
			lhs = get_temp_reg();
		}
		fprintf(outfile, "\tla\t$%d, %s\t\n", lhs, root->left->name);
		registers[lhs] = 1;
		int rhs = gen_expr(root->right,symbol_table);
		registers[rhs] = 1;
		fprintf(outfile, "\tsw\t$%d, 0($%d)\t\n", rhs, lhs);
		fprintf(outfile,"\t#nop\n");
	}
	if (strcmp(root->name, "assign_array") == 0){
		int lhs = get_sub_reg();
		if (lhs == -1){
			lhs = get_temp_reg();
		}
		fprintf(outfile, "\tla\t$%d, %s\t\n", lhs, root->left->left->name);
		registers[lhs] = 1;
		int rhs = gen_expr(root->right,symbol_table);
		registers[rhs] = 1;
		int index_reg;
		int final_pos;
		// if (strcmp(root->left->right->name,"number") != 0){
			index_reg = gen_expr(root->left->right, symbol_table);
			final_pos = get_sub_reg();
			if (final_pos == -1){
				final_pos = get_temp_reg();
			}
			fprintf(outfile, "\tsll\t$%d,$%d,2\t\n", final_pos,index_reg);
			fprintf(outfile, "\taddu\t$%d,$%d,$%d\t\n", lhs,final_pos,lhs);
			fprintf(outfile, "\tsw\t$%d, 0($%d)\t\n", rhs, lhs);
			// registers[index_reg]= 0;
			
		// }
		// else{
		// fprintf(outfile, "\tsw\t$%d, %d($%d)\t\n", rhs,4*(root->left->right->value), lhs);}
		fprintf(outfile,"\t#nop\n");
	}
	reset_regs();
}

int gen_expr(Node* root, Symbol* symbol_table){
	// printf("to generate expression : %s\n",root->name);
	int result_reg;
	if (strcmp(root->name,"number")== 0){
		result_reg = get_sub_reg();
		if (result_reg == -1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		fprintf(outfile, "\tli\t$%d, %d\t\n", result_reg, root->value);
		return result_reg;
	}
	if (strcmp(root->name,"var_expr")== 0){
		int addr_reg = get_sub_reg();
		if (addr_reg == -1){
			addr_reg = get_temp_reg();
		}
		registers[addr_reg] = 1;
		result_reg = get_sub_reg();
		if (result_reg == -1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		fprintf(outfile, "\tla\t$%d, %s\t\n", addr_reg, root->left->var_pointer->varname);
        fprintf(outfile, "\tlw\t$%d, 0($%d)\n", result_reg, addr_reg);
		registers[addr_reg] = 0;
		fprintf(outfile,"\t#nop\n");
		return result_reg;
	}
	if(strcmp(root->name,"Array_exp")== 0){
		int addr_reg = get_sub_reg();
		if (addr_reg == -1){
			addr_reg = get_temp_reg();
		}
		registers[addr_reg] = 1;
		result_reg = get_sub_reg();
		if (result_reg == -1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		fprintf(outfile, "\tla\t$%d, %s\t\n", addr_reg, root->left->var_pointer->varname);
		int index_reg;
		int final_pos;

		index_reg = gen_expr(root->right, symbol_table);
		final_pos = get_sub_reg();
		if (final_pos == -1){
			final_pos = get_temp_reg();
		}
		fprintf(outfile, "\tsll\t$%d,$%d,2\t\n", final_pos,index_reg);
		fprintf(outfile, "\taddu\t$%d,$%d,$%d\t\n", addr_reg,final_pos,addr_reg);
		fprintf(outfile, "\tlw\t$%d, %d($%d)\n", result_reg,0, addr_reg);
		registers[addr_reg] = 0;
		fprintf(outfile,"\t#nop\n");
		registers[final_pos] = 0;
		registers[index_reg] = 0;
		return result_reg;
	}
	if (strcmp(root->name,"add")== 0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		result_reg = get_sub_reg();
		if (result_reg == -1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		fprintf(outfile, "\taddu\t$%d,$%d,$%d\n",result_reg,result1,result2);
		registers[result1] = 0;
		registers[result2] = 0;
		return result_reg;

	}
	if (strcmp(root->name,"subtract")== 0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		result_reg = get_sub_reg();
		if (result_reg == -1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		fprintf(outfile, "\tsubu\t$%d,$%d,$%d\n",result_reg,result1,result2);
		registers[result1] = 0;
		registers[result2] = 0;
		return result_reg;

	}
	if (strcmp(root->name,"multiply")== 0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		result_reg = get_sub_reg();
		if (result_reg == -1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		fprintf(outfile,"\tmult\t$%d,$%d\n",result1,result2);
		fprintf(outfile, "\tmflo\t$%d\n",result_reg);
		registers[result1] = 0;
		registers[result2] = 0;
		return result_reg;

	}
	if (strcmp(root->name,"divide")== 0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		result_reg = get_sub_reg();
		if (result_reg == -1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		// fprintf(outfile,"\tdiv\t$0,$%d,$%d\n",result1,result2);
		fprintf(outfile, "\tbne\t$%d,$0,1f\n",result2);
		fprintf(outfile,"\t#nop\n");
		fprintf(outfile,"\tbreak\t7\n");
		fprintf(outfile,"1:\n");
		fprintf(outfile,"\tdiv\t$%d,$%d\n",result1,result2);
		fprintf(outfile,"\tmflo\t$%d\n",result_reg);
		registers[result1] = 0;
		registers[result2] = 0;
		return result_reg;

	}
	if (strcmp(root->name,"and")== 0){
		int result1 = gen_expr(root->left, symbol_table);
		char* lc = generate_label();
		fprintf(outfile, "\tbeq\t$%d,$0,$%s\n",result1,lc);
		registers[result1] = 0;
		// fprintf(outfile, "\tli\t$%d,1\n",result1);
		// fprintf(outfile, "\tbeq\t$%d,$0,%s\n",result1,lc);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile, "\tbeq\t$%d,$0,$%s\n",result2,lc);
		registers[result2] = 0;
		result_reg = get_sub_reg();
		if (result_reg==-1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		fprintf(outfile, "\tli\t$%d,1\n",result_reg);
		char* nextlc = generate_label();
		fprintf(outfile, "\tb\t$%s\n",nextlc);
		fprintf(outfile,"$%s:\n",lc);
		fprintf(outfile,"\tmove\t$%d,$0\n",result_reg);
		fprintf(outfile,"$%s:\n",nextlc);
		// registers[result1] = 0;
		return result_reg;
		// if (result_reg == -1){
		// 	result_reg = get_temp_reg();
		// }
		// registers[result_reg] = 1;
		// fprintf(outfile, "\tbne\t$%d,$0,1f\n",result2);

	}
	if (strcmp(root->name,"or")== 0){
		int result1 = gen_expr(root->left, symbol_table);
		char* true_lc = generate_label();
		char* false_lc = generate_label();
		fprintf(outfile, "\tbne\t$%d,$0,$%s\n",result1,true_lc);
		registers[result1] = 0;
		// fprintf(outfile, "\tli\t$%d,1\n",result1);
		// fprintf(outfile, "\tbeq\t$%d,$0,%s\n",result1,lc);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile, "\tbeq\t$%d,$0,$%s\n",result2,false_lc);
		registers[result2] = 0;
		result_reg = get_sub_reg();
		if (result_reg==-1){
			result_reg = get_temp_reg();
		}
		registers[result_reg] = 1;
		
		// char* false_lc = 
		char* nextlc = generate_label();
		fprintf(outfile,"$%s:\n",true_lc);
		fprintf(outfile, "\tli\t$%d,1\n",result_reg);
		fprintf(outfile,"\tb\t$%s\n",nextlc);
		// char* nextlc = generate_label();
		// fprintf(outfile, "\tb\t$%s\n",nextlc);
		fprintf(outfile,"$%s:\n",false_lc);
		fprintf(outfile,"\tmove\t$%d,$0\n",result_reg);
		fprintf(outfile,"$%s:\n",nextlc);
		return result_reg;
		// if (result_reg == -1){
		// 	result_reg = get_temp_reg();
		// }
		// registers[result_reg] = 1;
		// fprintf(outfile, "\tbne\t$%d,$0,1f\n",result2);

	}
	if (strcmp(root->name,"not")== 0){
		int result1 = gen_expr(root->left, symbol_table);
		// result_reg = get_sub_reg();
		// if (result_reg==-1){
		// 	result_reg = get_temp_reg();
		// }
		// registers[result_reg] = 1;
		fprintf(outfile,"\tsltu\t$%d,$%d,1\n",result1,result1);
		fprintf(outfile,"\tandi\t$%d,$%d,0x00f\n",result1,result1);
		// registers[result1] = 0;
		return result1;
	}
	if (strcmp(root->name,"lt")==0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile,"\tslt\t$%d,$%d,$%d\n",result2,result1,result2);
		fprintf(outfile,"\tandi\t$%d,$%d,0x00f\n",result2,result2);
		registers[result1] = 0;
		return result2;
	}
	if (strcmp(root->name,"gt")==0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile,"\tslt\t$%d,$%d,$%d\n",result1,result2,result1);
		fprintf(outfile,"\tandi\t$%d,$%d,0x00f\n",result1,result1);
		registers[result2] = 0;
		return result1;
	}
	if (strcmp(root->name,"lte")==0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile,"\tslt\t$%d,$%d,$%d\n",result2,result2,result1);
		fprintf(outfile,"\txori\t$%d,$%d,0x1\n",result2,result2);
		fprintf(outfile,"\tandi\t$%d,$%d,0x00f\n",result2,result2);
		registers[result1] = 0;
		return result2;
	}
	if (strcmp(root->name,"gte")==0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile,"\tslt\t$%d,$%d,$%d\n",result2,result1,result2);
		fprintf(outfile,"\txori\t$%d,$%d,0x1\n",result2,result2);
		fprintf(outfile,"\tandi\t$%d,$%d,0x00f\n",result2,result2);
		registers[result1] = 0;
		return result2;
	}
	if (strcmp(root->name,"eq")==0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile,"\txor\t$%d,$%d,$%d\n",result2,result1,result2);
		fprintf(outfile,"\tsltu\t$%d,$%d,1\n",result2,result2);
		fprintf(outfile,"\tandi\t$%d,$%d,0x00f\n",result2,result2);
		registers[result1] = 0;
		return result2;
	}
	if (strcmp(root->name,"neq")==0){
		int result1 = gen_expr(root->left, symbol_table);
		int result2 = gen_expr(root->right, symbol_table);
		fprintf(outfile,"\txor\t$%d,$%d,$%d\n",result2,result1,result2);
		fprintf(outfile,"\tsltu\t$%d,$0,$%d\n",result2,result2);
		fprintf(outfile,"\tandi\t$%d,$%d,0x00f\n",result2,result2);
		registers[result1] = 0;
		return result2;
	}
}
// void gen_read(Node* root, Symbol* symbol_table){
// 	int label_no = root->value;
// 	// char format_string[512] = "";
// 	// printf("read resched and root is %s\n", root->name);
// 	int var_no = 5;
// 	Node* var;
// 	if (root->left)
// 		var = root->left;
	
// 	char temp[100];
// 	sprintf(temp, "\n\tla\t$4,$LR%d\n", label_no);
// 	char tempo[512];

// 	while (var != NULL){
// 		printf("var %s\n", var->name);
// 		sprintf(tempo,"	la	$%d,%s\n%s", var_no++,var->name,tempo);
// 		var = var->extra;
// 	}

// 	strcat(tempo, temp);
// 	fprintf(outfile,"%s", tempo);
// 	fprintf(outfile, "	jal	_isoc99_scanf\n");

// }


void gen_read(Node* root, Symbol* symbol_table){
    int label_no = root->value;
    int var_no   = 5;
    Node* var    = root->left;
    char label_load[64];
    snprintf(label_load, sizeof(label_load),
             "\n\tla\t$4,$LR%d\n", label_no);
	registers[4] = 1;
    char tempo[1024];
    tempo[0] = '\0';

    while (var) {
		// printf(" to read %s\n", var->name);
        char line[128];
		int arg_reg = get_arg_reg();
		registers[arg_reg] = 1;
		if (strcmp(var->name,"Array_exp")==0){
			int reg = get_sub_reg();
			if (reg == -1){
				reg = get_temp_reg();
			}
			registers[reg] = 1;
			if (strcmp(var->right->name,"number") == 0){
				snprintf(line, sizeof(line),
				"\tla\t$%d,%s\n\taddiu\t$%d,$%d,%d\n", reg, var->left->name,
				arg_reg,reg,4*var->right->value);}
			else{
				printf("variable inex type is : %s\n",var->right->name);
				int index_reg = gen_expr(var->right,symbol_table);
				int addr_reg = get_sub_reg();
				if (addr_reg == -1){
					addr_reg = get_temp_reg();
				}

				snprintf(line, sizeof(line),
				"\tsll\t$%d,$%d,2\n\tla\t$%d,%s\n\taddu\t$%d,$%d,$%d\n\tmove\t$%d,$%d\n",addr_reg,index_reg,reg,var->left->name,reg,addr_reg,reg,arg_reg,reg);
			}
			// printf("reading the pos : %d\n",4*var->right->value);
		}
		else{
			snprintf(line, sizeof(line),
					"\tla\t$%d,%s\n", arg_reg, var->name);
		}
        strncat(tempo, line, sizeof(tempo) - strlen(tempo) - 1);
		
        var = var->extra;
    }
    strncat(tempo, label_load, sizeof(tempo) - strlen(tempo) - 1);

    fprintf(outfile, "%s", tempo);
    fprintf(outfile, "\tjal	__isoc99_scanf\n");
	reset_arg();
	fprintf(outfile, "\t#nop\n");
}

void gen_write(Node* root, Symbol* symbol_table){
    int label_no = root->value;
    int var_no   = 5;
    Node* var    = root->left;
	char* used_reg[8];
    char label_load[64];
    snprintf(label_load, sizeof(label_load),
             "\n\tla\t$4,$LC%d\n", label_no);
	registers[4] = 1;
    char tempo[1024];
    tempo[0] = '\0';

    while (var) {
		// printf("to write var name %s\n", var->left->name);
        char line[128];
		int result_reg = gen_expr(var->left,symbol_table);
		int arg_reg = get_arg_reg();
		registers[arg_reg] = 1;
        snprintf(line, sizeof(line),
                 "\tmove\t$%d,$%d\n", arg_reg, result_reg);
		// registers[result_reg] = 0;
        strncat(tempo, line, sizeof(tempo) - strlen(tempo) - 1);
        var = var->extra;
    }
    strncat(tempo, label_load, sizeof(tempo) - strlen(tempo) - 1);
	reset_arg();
	reset_temp_regs();
    fprintf(outfile, "%s", tempo);
    fprintf(outfile, "\tjal\tprintf\n");
	fprintf(outfile, "\t#nop\n");
}





void generate_data_section_entries(Node* node, Symbol* symbol_table) {
    if (node == NULL) {
        return;
    }
     if (!outfile) {
         fprintf(stderr, "Error: Output file not open in generate_data_section_entries.\n");
         return;
     }

    if (strcmp(node->name, "write") == 0) {
		 Node* param = node->left; 
        int param_count = 0;
        char format_string[512] = ""; 
        while (param != NULL) {
            strcat(format_string, "%d");
            param_count++;
            param = param->extra;
            if (param != NULL) {
                strcat(format_string, " ");
            }
        }

        strcat(format_string, "\\n");

        int current_label_num = rw_lc++;
		fprintf(outfile, "\t.align 2\n");
        fprintf(outfile, "$LC%d:\n", current_label_num);
        fprintf(outfile, "\t.asciiz \"%s\"\n", format_string);
        // fprintf(outfile, "    .align 2\n");

        node->value = current_label_num;

    } else if (strcmp(node->name, "read") == 0) {
        Node* param = node->left; 
        int param_count = 0;
        char format_string[512] = ""; 
        while (param != NULL) {
            strcat(format_string, "%d");
            param_count++;
            param = param->extra;
            if (param != NULL) {
                strcat(format_string, " ");
            }
        }

        strcat(format_string, "\\000");

        int current_label_num = rw_lc++;
		fprintf(outfile, "\t.align 2\n");
        fprintf(outfile, "$LR%d:\n", current_label_num);
        fprintf(outfile, "\t.ascii \"%s\"\n", format_string);
        // fprintf(outfile, "    .align 2\n");

        node->value = current_label_num;

    }
    generate_data_section_entries(node->left, symbol_table);
    generate_data_section_entries(node->right, symbol_table);
    generate_data_section_entries(node->extra, symbol_table); // For lists (statements, params)
}

void gen_epilogue(){
	fprintf(outfile,"\tmove\t$2,$0\n");
	fprintf(outfile,"\tmove\t$sp,$fp\n");
	fprintf(outfile,"\tlw\t$ra,28($sp)\n");
	fprintf(outfile,"\tlw\t$fp,24($sp)\n");
	fprintf(outfile,"\taddiu\t$sp,$sp,32\n");
	fprintf(outfile,"\tj\t$31\n");
	fprintf(outfile,"\t.end\tmain\n");
	fprintf(outfile,"\t.size\tmain,.-main\n");
	fprintf(outfile,"\t.ident\t\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n");
	fprintf(outfile,"\t.section\t.note.GNU-stack,\"\",@progbits\n");
}

void genMIPS (const char* filename,Node* root, Symbol* symbol_table){
	printf("reached MIPS generation %s\n",filename);
	file_name = strdup(filename);
	const char *last_slash = strrchr(filename, '/');
	const char *base_start = (last_slash == NULL) ? filename : last_slash + 1;
	// const char *dot_position = strrchr(filename, '.');
	const char *last_dot = strrchr(base_start, '.');
	// size_t base_len = dot_position - filename;
	// size_t new_len = base_len + 2 + 1;
		size_t base_name_len;
	if (last_dot == NULL || last_dot == base_start) {
		base_name_len = strlen(base_start);
	} else {
		base_name_len = last_dot - base_start;
	}
	const char* output_dir = "bin/";
    const char* output_ext = ".s";
	// char *s_filename = (char *)malloc(new_len);
	// strncpy(s_filename, filename, base_len);
	// strcpy(s_filename + base_len, ".s");
	size_t full_path_len = strlen(output_dir) + base_name_len + strlen(output_ext) + 1;
	char *full_output_path = (char *)malloc(full_path_len);
    if (full_output_path == NULL) {
         perror("unable to allocate memory for output path");
         return;
    }
	strcpy(full_output_path, output_dir);
	strncat(full_output_path, base_start, base_name_len);
	strcat(full_output_path, output_ext);   
	outfile = fopen(full_output_path, "w");
	if (outfile == NULL) {
		 fprintf(stderr, "Error: unable to open output file '%s' for writing: ", full_output_path);
         perror(NULL);
		 free(full_output_path);
		 return;
	}
	printf("Assembly file created at %s\n", full_output_path);
	free(full_output_path);
	// outfile = fopen(s_filename, "w");
	gen_prologue(root, symbol_table); // to write the prologue..(and starts with the .text section)
	gen_decl(root, symbol_table); // to genrate the text section
	// printf("declaration done\n");
	// check_state(root, symbol_table);
	fprintf(outfile, "	.rdata\n"); // data section starts
	// fprintf(outfile,"	.align 2\n");
	generate_data_section_entries(root, symbol_table);
	// printf("data section done\n");
	fprintf(outfile,"\t.text\n"); // marks the end of data section
	gen_main(root, symbol_table); //  main..(prologue -- stack and fp setting up)
	// printf("Main done\n");
	if (root->left != NULL)
		gen_statement_list(root->left, symbol_table);
	gen_epilogue(); // epilogue of main, and the program

	fclose(outfile);
}


