%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER

%%
expression:
    expression '+' expression { printf("%d\n", $1 + $3); }
  | expression '-' expression { printf("%d\n", $1 - $3); }
  | NUMBER { $$ = $1; }
  ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
