#include <stdio.h>

int fibonacci(int i)
{
    if (i<=1) return i;
    else return fibonacci(i-1) + fibonacci(i-2);
}


int fib_series(int n)
{
    printf("Fibonacci series: \n");
    for(int i = 0; i< n; i++)
    {
        printf("%d, ", fibonacci(i));
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    fib_series(n);

    return 0;
}