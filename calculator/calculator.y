%{
int yylex();
#include <stdio.h>
#include <stdlib.h>
double symbol_table[26] = {0}; /* For the symbol table */
void yyerror(const char *s);
%}

%union {
    double num;
    int variable;
}

%token <num> number
%token <variable> var
%left	'+' '-'	  /* left associative, same precedence */
%left	'*' '/'	  /* left assoc., higher precedence */
%type <num> assignment expr term factor
%right UMINUS


%%
list: assignment {}
	| list assignment {};

assignment:	var '=' expr '\n' {
	symbol_table[$1] = $3;
	printf("%f\n", $3);
	// printf("%d at --- %d\n", symbol_table[$1], $1); // to ensure whether the symbol table is updated corectly
	}

	| expr '\n' {printf("%f\n", $1);}
	;

/*grammar discussed in class 
 E → E + T | T
 T → T * F | F
 F → NUMBER
*/

expr:	term { $$ = $1; } 
	| expr '+' term	{ $$ = $1 + $3; }
	| expr '-' term	{ $$ = $1 - $3; }
	;

term:	factor {$$ = $1; }
	| term '*' factor { $$ = $1 * $3; }
	| term '/' factor { $$ = $1 / $3; }
	;

factor:	number { $$ = $1; }
	| '-'factor %prec UMINUS {$$ = -1 * $2; }
	| var { $$ = symbol_table[$1]; } // accesses from the symbol table
	| '(' expr ')'	{ $$ = $2; }
%%

void yyerror(const char *s) {
    // fprintf(stderr, "Error: %s\n", s);
	fprintf(stderr,"Error: %s\n Follow the syntax A=20 or B=30+A*20\n", s);
}



int main() {
    printf("Enter expressions (e.g., A=20 \n B=30+A*20) \n type q and press enter to quit:\n");
    yyparse();
	return 0;
}