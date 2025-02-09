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
%}

%union{
	int num;
	char* var;
	struct Node* node;
}

%token BEG END
%token T_INT T_BOOL
%token READ WRITE
%token DECL ENDDECL
%token <var> VAR
%token <num> NUM
%token IF THEN ELSE ENDIF
// %token LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token <op> EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token WHILE DO ENDWHILE FOR 
%token T F 
%token MAIN RETURN
%type <node> Gdecl_sec  Gdecl Gdecl_list Gid_list type Gid
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
    printroot(root, 0);
}
    | BEG Gdecl_sec stmt_list END {
		root = createnode(0, "program", 0, NULL, NULL, NULL, $2);
    if ($2) {
        $2->extra = $3;  
    }
    printroot(root, 0);
	}

		;

Gdecl_sec:	DECL Gdecl_list ENDDECL	{ printf("printing symbol table values\n");
			 printsymboltable(symbol_table); 
	/*$$ = createnode(0, "decl", 0, NULL, $2, NULL, NULL);*/
$$ = $2;}
		;

Gdecl_list:	/* NULL  */ {$$ = NULL;}
		| Gdecl  Gdecl_list {  
			// $$ = createnode(0, "list",0,  NULL, $1, NULL, $2);
			$$ = $1;
			$1->extra = $2;
		}
		;


Gdecl	:	type Gid_list ';' {Type t = (strcmp($1->name,"integer") == 0)?TYPE_INT : TYPE_BOOL;
			Node* p = $2;
			while(p != NULL){
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
        $$ = $1; 
        $1->extra = $3; 
    }
    ;

Gid:
    VAR { 
        Symbol* sym = lookupSymbol(symbol_table, $1);
        if (sym == NULL) {
            insertSymbol(&symbol_table, $1, TYPE_INT, 0); 
            sym = lookupSymbol(symbol_table, $1); 
            if (!sym) { 
                yyerror("Error: Failed to insert symbol!"); 
                exit(1);
            }
        }
        $$ = createnode(0, $1, sym->value.intval, sym, NULL, NULL, NULL);
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


statement:	assign_stmt  ';'		{ printf("printing symbol table values\n");
			//  printsymboltable(symbol_table); 
	  printsymboltable(symbol_table); 
	$$ = $1; }
		| write_stmt ';' { $$ = $1;}
		;
assign_stmt: var_expr '=' expr { 
    $$ = createnode('=', "assign", 0, NULL, $1, $3, NULL);
    
    if ($1->var_pointer) {  
        $1->var_pointer->value.intval = $3->value;  
    } else {
        yyerror("Error: Assignment to an undefined variable!");
    }
};

write_stmt : WRITE '(' para_list ')' { 
    $$ = createnode(0, "write", 0, NULL,$3, NULL, NULL);
};

para_list : /* null */ { $$ = NULL; }
          | para_list1 { $$ = $1; 
		  Node* para;
		  para = $$;
		  printf("console output : \n");
		  while (para){
			printf("%d\n", para->value);
			para = para->extra;
		  }}
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
;

	
var_expr: VAR { 
    Symbol* sym = lookupSymbol(symbol_table, $1);
    if (!sym) { 
        yyerror("Error: Undefined variable used in expression! Initializing to 0.");
        insertSymbol(&symbol_table, $1, TYPE_INT, 0); 
        sym = lookupSymbol(symbol_table, $1);  
        if (!sym) { 
            yyerror("Critical Error: Symbol insertion failed!"); 
            exit(1); 
        }
    }
    $$ = createnode(0, $1, sym->value.intval, sym, NULL, NULL, NULL);
};




%%

void yyerror ( const char  *s) {
   fprintf (stderr, "%s\n", s);
 }

int main(){
yyparse();
}

/* here I have not considered  arrays, strings or other function calls 
only considered the write function call */



