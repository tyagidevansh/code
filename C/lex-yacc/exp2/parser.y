%{
#include <stdio.h>
#include <stdlib.h>
%}

%token A B

%%
input: S { printf("Valid string\n"); }
     ;

S: A_list B_list
 ;

A_list: A A_list
      | A
      ;

B_list: B B_list
      | B
      ;

%%

int yyerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    return 0;
}

int main() {
    printf("Enter a string: ");
    yyparse();
    return 0;
}
