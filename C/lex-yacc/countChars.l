%{
  int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU] { vowels++; }
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] { consonants++; }
.|\n ; 
%%

int main() {
  printf("Enter a string: ");
  yylex(); 
  printf("Vowels: %d\n", vowels);
  printf("Consonants: %d\n", consonants);
  return 0;
}
