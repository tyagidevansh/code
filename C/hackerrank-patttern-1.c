#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    
    int size = (2*n-1);
    int start = 0;
    int end = size -1;
    int a[size+2][size+2];
    
    while (n!=4){
        for (int i = start; i <= end;i++){
        for (int j = start; j<=end; j++){
            
            if ( i == start || i == end ||
            j == start || j == end){
                a[i][j] = n;
            }
        }
        }
        ++start;
        --end;
        --n;
        
    }
    for (int i = start; i < size; i++){
    for (int j = start; j<size; j++){
        printf("%d ", a[i][j]);
    }
    }

    return 0;
}