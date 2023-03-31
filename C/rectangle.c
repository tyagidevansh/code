//program to ask the user for input of number of rows, columns and a symbol, then making a reactangle with the info

#include <stdio.h>
#include <string.h>

int a, b;
char c;

void rectangle(int i, int j, char k){
    int column = 0;
    while(column < j){
        for(int row = 0; row<i+1; row++){
            printf("%c", k);
            if(row == i){
                printf("\n");
                
            }
        }
    column++;
    }
}
int main(){
    printf("Enter the numbers of rows, columns and the symbol: ");
    scanf("%d %d %c", &a,&b,&c);
    rectangle(a,b,c);

    return 0;
}
