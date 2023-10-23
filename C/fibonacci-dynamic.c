#include <stdio.h>

void fibonacci(int n){
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    printf("%d \n%d \n", fib[0], fib[1]);

    for (int i = 2; i <= n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%d \n", fib[i]);
    }
}

int main(){
    fibonacci(10);
}