%{
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include "include/tree.h"
#include "include/symbol_table.h"
#include <string.h>
 Symbol* symbol_table;
 Node* root;
void yyerror(const char *s);
/*
typedef struct console_output{
	int value;
	struct console_output* next;
} console_output;

this can be used incase of printing all the outputs of print together
*/
// extern int error_flag;
%}

%union{
	int num;
	char* var;
	struct Node* node;
}

%token BEG END
%token T_INT T_BOOL
%token READ WRITE
%token BEGDECL ENDDECL DECL
%token BREAK CONTINUE
%token <var> VAR
%token <num> NUM
%token IF THEN ELSE ENDIF
%token LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token <op> EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token WHILE DO ENDWHILE FOR 
%token T F 
%token MAIN RETURN
%type <node> Gdecl_sec  Gdecl Gdecl_list Gid_list type Gid array_expr cond_stmt for_stmt
%type <node> stmt_list statement assign_stmt var_expr expr write_stmt para_list para_list1 para



%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left '+' '-'
%left '*' '/'
%left '%'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT

%%
Prog : Gdecl_sec stmt_list  { 
    root = createnode(0, "program", 0, NULL,$1, NULL, NULL);
    if ($1) {
        $1->extra = $2;  
    }

    //  printf("error flag === %d\n", error_flag);
    evaluate_statement(root->left, symbol_table);
    //  printf("error flag === %d\n", error_flag);
    if (error_flag == 1){
        return 0;
    }
    printf("\n---the syntax tree---\n");
    printroot(root, 0);
}
    |  Gdecl_sec BEG stmt_list END {
		
        Node* temp = $1;
    while (temp->extra != NULL) temp = temp->extra;
    temp->extra = $3;  
    root = createnode(0, "program", 0, NULL, $1, NULL, NULL);
 
    evaluate_statement(root->left, symbol_table);
    if (error_flag == 1){
        return 0;
    }
       printroot(root, 0);
	}

		;

Gdecl_sec:	DECL Gdecl_list ENDDECL	{ printf("printing symbol table values\n");
			 printsymboltable(symbol_table); 
	$$ = createnode(0, "decl_list", 0, NULL, $2, NULL, NULL);
// $$ = $2;
}
    | BEGDECL Gdecl_list ENDDECL	{ printf("printing symbol table values\n");
			 printsymboltable(symbol_table); 
	$$ = createnode(0, "decl_list", 0, NULL, $2, NULL, NULL);
// $$ = $2;
}
		;

Gdecl_list:	/* NULL  */ {$$ = NULL;}
		| Gdecl  Gdecl_list {  
			// // $$ = createnode(0, "list",0,  NULL, $1, NULL, $2);
			// $$ = $1;
            // while($1->extra == NULL)
			// $1->extra = $2;
            Node* temp = $1;
            while (temp->extra != NULL) temp = temp->extra;  // find last node, where we can append
            temp->extra = $2;  // other statements would be chained to the end
            $$ = $1;  
        }
		
		;


Gdecl	:	type Gid_list ';' {Type t = (strcmp($1->name,"integer") == 0)?TYPE_INT : TYPE_BOOL;
			Node* p = $2;
			while(p != NULL ){
                if (strcmp(p->name,"Array")!=0)
				    p->var_pointer->type = t;
				p=p->extra;
			}
			$$= createnode(0, "decl", 0, NULL, $1, $2, NULL);}

type	:	T_INT			{ $$ = createnode(0, "integer", 0, NULL, NULL, NULL, NULL);}
		| T_BOOL { $$ = createnode(0, "boolean",0, NULL, NULL, NULL, NULL); }
		;

Gid_list:
    Gid { $$ = $1; } 
    | Gid ',' Gid_list { 
        Node* temp = $1;
        while (temp->extra != NULL) temp = temp->extra;
        temp->extra = $3;
        $$ = $1;
    }
    ;

Gid:
    VAR { 
        Symbol* sym = lookupSymbol(symbol_table, $1);
        if (sym == NULL) {
            insertSymbol(&symbol_table, $1, TYPE_INT, 0, 0); 
            sym = lookupSymbol(symbol_table, $1); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        $$ = createnode(0, $1, sym->value.intval, sym, NULL, NULL, NULL);
    }
    | VAR '[' NUM ']' {  
        // printf("hii"); 
        Symbol* sym = lookupSymbol(symbol_table, $1);
        if (sym == NULL) {
            insertSymbol(&symbol_table, $1, TYPE_ARRAY_INT, $3, 0); 
            sym = lookupSymbol(symbol_table, $1); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        $$ = createnode(0, "Array", 0, NULL, createnode(0, "size", $3, NULL, NULL,NULL,NULL), createnode(0, $1, 0, sym, NULL, NULL,NULL),NULL);
    }
;


stmt_list:
    /* NULL */ { $$ = NULL; }
    | stmt_list statement {
        if ($1 == NULL) {
            $$ = $2;  // First statement
        } else {
            Node* temp = $1;
            while (temp->extra != NULL) temp = temp->extra;  // Find last node, where we can append
            temp->extra = $2;  // other statements would be chained to the end
            $$ = $1;  
        }
    } 
    | error { yyerror("Syntax error in statement."); }
    ;


statement:	assign_stmt  ';'		{ 
    // if (error_flag == 1){
    //     return 0;
    // }
    // printf("printing symbol table values\n");
			//  printsymboltable(symbol_table); 
	//   printsymboltable(symbol_table); 
	$$ = $1; 
    // evaluate_statement($$);
    }
		| write_stmt ';' { $$ = $1;
        // evaluate_statement($$);
        }
        | cond_stmt {$$ = $1;
        // evaluate_statement($$);
        }
        | BREAK ';' { $$ = createnode(0, "break", 0, NULL, NULL, NULL, NULL); }
        | CONTINUE ';' {  $$ = createnode(0, "continue", 0, NULL, NULL, NULL, NULL); }
		;
assign_stmt: var_expr '=' expr { 
    $$ = createnode('=', "assign", 0, NULL, $1, $3, NULL);

    
    // if ($1->var_pointer) {  
    //     $1->var_pointer->value.intval = $3->value;  
    // } else {
    //     yyerror("Error: Assignment to an undefined variable!");
    // }
}
        | array_expr '=' expr{
            $$ = createnode('=', "assign_array", 0, NULL, $1, $3, NULL); 
    //    $1->left->var_pointer->value.int_arrayval[$1->right->value] = $3->value;  
    } 


write_stmt : WRITE '(' para_list ')' { 
    $$ = createnode(0, "write", 0, NULL,$3, NULL, NULL);
};

para_list : /* null */ { $$ = NULL; }
          | para_list1 { $$ = $1; 
		//   Node* para;
		//   para = $$;
		//   printf("console output : \n");
		//   while (para){
		// 	// printf("%d\n", para->value);
		// 	para = para->extra;
		//   }
        }
          ;

para_list1 : para { $$ = $1; } 
           | para ',' para_list1 { 
                $$ = $1; 
                $1->extra = $3; 
           }
           ;

para : expr { 
    $$ = createnode(0, "parameter", $1->value, NULL, $1, NULL, NULL); 
};

cond_stmt:	IF expr THEN stmt_list ENDIF 	{ 
    $$ = createnode(0,"if-then", 0, NULL,  createnode(0,"if", 0, NULL, $2,createnode(0,"then", 0, NULL, $4,NULL,NULL),NULL), NULL, NULL); 
                                                }
		|	IF expr THEN stmt_list ELSE stmt_list ENDIF 	{ 
            $$ = createnode(0,"if-then-else", 0, NULL,  createnode(0,"if", 0, NULL, $2,createnode(0,"then", 0, NULL, $4,NULL,NULL),createnode(0,"else", 0, NULL, $6,NULL,NULL)), NULL, NULL);  
            }
	    | for_stmt {$$ = $1;}
		;

for_stmt :     FOR '(' assign_stmt  ';'  expr ';'  assign_stmt ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, $3,createnode(0, "final-condition", 0, NULL, $5, NULL, NULL),createnode(0, "step", 0, NULL, $7, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $10, NULL, NULL), NULL);
            }
        |    FOR '(' ';'  expr ';'  ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL, createnode(0, "final-condition", 0, NULL, $4, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $8, NULL, NULL), NULL);
            }
        |    FOR '(' ';'  expr ';'  assign_stmt ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL, $4, NULL, NULL),createnode(0, "step", 0, NULL, $6, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $9, NULL, NULL), NULL);
            }
        |    FOR '(' ';' ';'  ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $7, NULL, NULL), NULL);
            }
        |    FOR '(' assign_stmt ';' ';'  ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, $3,createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $8, NULL, NULL), NULL);
            };
        |    FOR '('  ';' ';' assign_stmt ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, NULL,createnode(0, "final-condition", 0, NULL,$5 , NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $8, NULL, NULL), NULL);
            }
        |    FOR '(' assign_stmt ';' expr ';'  ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, $3,createnode(0, "final-condition", 0, NULL, $5, NULL, NULL),createnode(0, "step", 0, NULL, NULL, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $9, NULL, NULL), NULL);
            }
        |    FOR '(' assign_stmt  ';' ';'  assign_stmt ')' '{' stmt_list '}'   { 
                $$ = createnode(0, "for-loop", 0, NULL, createnode(0, "for_conditions", 0, NULL, $3,createnode(0, "final-condition", 0, NULL, NULL, NULL, NULL),createnode(0, "step", 0, NULL, $6, NULL, NULL)), createnode(0, "in-loop", 0, NULL, $9, NULL, NULL), NULL);
            };


expr	:	NUM  { 
            $$ = createnode(0, "number", $1, NULL, NULL, NULL, NULL); 
        }
		|	'-' NUM {  
            $$ = createnode(0, "number", -$2, NULL, NULL, NULL, NULL); 
        }
		|	var_expr {  
            Symbol* sym = $1->var_pointer; 
            $$ = createnode(0, "var_expr", sym ? sym->value.intval : 0, NULL, $1, NULL, NULL); 
        }
		|	T { 
            $$ = createnode(0, "T", 1, NULL, NULL, NULL, NULL);					  	
        }
		|	F { 
            $$ = createnode(0, "F", 0, NULL, NULL, NULL, NULL);
        }
		|	'(' expr ')' {  
            $$ = $2;			
        }

		|	expr '+' expr {  
            $$ = createnode('+', "add", $1->value + $3->value, NULL, $1, $3, NULL);					
        }
		|	expr '-' expr {  
            $$ = createnode('-', "subtract", $1->value - $3->value, NULL, $1, $3, NULL);						
        }
		|	expr '*' expr {  
            $$ = createnode('*', "multiply", $1->value * $3->value, NULL, $1, $3, NULL);			
        }
		|	expr '/' expr {  
            if ($3->value == 0) {
                yyerror("Division by zero!"); 
                $$ = createnode('/', "divide", 0, NULL, $1, $3, NULL);
            } else {
                $$ = createnode('/', "divide", $1->value / $3->value, NULL, $1, $3, NULL);
            }
        }
		|	expr '%' expr { 
            if ($3->value == 0) {
                yyerror("Modulo by zero!"); 
                $$ = createnode('%', "mod", 0, NULL, $1, $3, NULL);
            } else {
                $$ = createnode('%', "mod", $1->value % $3->value, NULL, $1, $3, NULL);
            }
        }

		|	expr '<' expr { 
            $$ = createnode('<', "lt", $1->value < $3->value, NULL, $1, $3, NULL);
        }
		|	expr '>' expr { 
            $$ = createnode('>', "gt", $1->value > $3->value, NULL, $1, $3, NULL);
        }
		|	expr GREATERTHANOREQUAL expr {  
            $$ = createnode('G', "gte", $1->value >= $3->value, NULL, $1, $3, NULL);
        }
		|	expr LESSTHANOREQUAL expr { 
            $$ = createnode('L', "lte", $1->value <= $3->value, NULL, $1, $3, NULL);
        }
		|	expr NOTEQUAL expr { 
            $$ = createnode('N', "neq", $1->value != $3->value, NULL, $1, $3, NULL);
        }
		|	expr EQUALEQUAL expr { 
            $$ = createnode('E', "eq", $1->value == $3->value, NULL, $1, $3, NULL);
        }
        | var_expr '[' expr ']' {
            Symbol* sym = lookupSymbol(symbol_table, $1->name);
            if (sym->type != TYPE_ARRAY_INT){
                yyerror("Not array so indexing is not possible");
                $$ = NULL;
            }
            else{
                $$ = createnode(0, "Array_exp", sym->value.int_arrayval[$3->value], NULL, $1, $3, NULL);
            }
        }
        |	LOGICAL_NOT expr	{ $$ = createnode('!', "not", !$2->value, NULL, $2,NULL,NULL );						}
		|	expr LOGICAL_AND expr	{ $$ = createnode('&', "and", $1->value && $3->value, NULL, $1, $3,NULL );						}
		|	expr LOGICAL_OR expr	{ 	$$ = createnode('|', "or", $1->value || $3->value, NULL, $1, $3,NULL );					}
;

	
var_expr: VAR { 
    Symbol* sym = lookupSymbol(symbol_table, $1);
    if (!sym) { 
        printf("%s\n", $1);
        yyerror("Error: Undefined variable used in expression");
        return 0;
    }
    $$ = createnode(0, $1, sym->value.intval, sym, NULL, NULL, NULL);
};

array_expr : VAR '[' expr ']'{
    Symbol* sym = lookupSymbol(symbol_table, $1);
    if (!sym){
        printf("%s\n", $1);
        yyerror("Error: Undefined variable used in expression ");
        return 0; 
    }
    if (evaluate_expr($3, symbol_table) >= sym->size){
       yyerror("Error: index out of range"); 
       return 0; 
    }
    $$ = createnode(0, "Array_exp", sym->value.int_arrayval[$3->value], NULL, createnode(0, $1, 0, sym, NULL, NULL,NULL), $3, NULL);
}




%%

void yyerror ( const char  *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(){
yyparse();
free_tree(root);
free_symbol_table(symbol_table);
}




