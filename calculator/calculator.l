%{
#include "calculator.tab.h"
#include <stdlib.h>	

%}




%% 

[0-9]+(\.[0-9]+)?  {yylval.num = atof(yytext);
	   return number;}
[A-Z] { yylval.variable = yytext[0]-'A';
	     return var; }
[+/\-*&=\n] {
	return yytext[0];
}
[\t]+ {}
[()] {return yytext[0];}
"q" {return 0;}

%%

int yywrap()
 {
  return 1;
 }
