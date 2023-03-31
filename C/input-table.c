#include <stdio.h>

int main(){
    int i = 1;
    int j;

    printf("Enter the number you want to print a table of: ");
    scanf("%d", &j);
    while (i<11){
        printf("%d x %d = %d\n", i, j, i*j);
        i++;
    }

    return 0;
}