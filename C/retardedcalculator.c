#include <stdio.h>
#include <math.h>
const float pi = 3.14159;

int add(){
    int i, j;
    printf("Enter the first number: ");
    scanf("%d", &i);
    printf("\nEnter the second number: ");
    scanf("%d", &j);
    int result = i+j;
    printf("%d",result);
}

int sub(){
    int i, j;
    printf("Enter the first number: ");
    scanf("%d", &i);
    printf("\nEnter the second number: ");
    scanf("%d", &j);
    int result = i-j;
    printf("%d",result);
}

int mul(){
    int i, j;
    printf("Enter the first number: ");
    scanf("%d", &i);
    printf("\nEnter the second number: ");
    scanf("%d", &j);
    int result = i*j;
    printf("%d",result);
}

int div (){
    int i, j;
    printf("Enter the first number: ");
    scanf("%d", &i);
    printf("\nEnter the second number: ");
    scanf("%d", &j);
    int result = i/j;
    printf("%d",result);
}

int power(){
    int i, j;
    printf("Enter the first number: ");
    scanf("%d", &i);
    printf("\nEnter the second number: ");
    scanf("%d", &j);
    int result = pow(i,j);
    printf("%d",result);
}

int rou(){
    int i;
    printf("Enter the number you want to round: ");
    scanf("%d", i);
    int result = round(i);
    printf("%d", result);
}

int cir(){
    int i;
    printf("Enter the radius of your circle: ");
    scanf("%d", &i);
    float result = 2*pi*i;
    printf("The circumference of the circle is %f", result);
}

int logarithm(){
    int i;
    printf("Enter the number: ");
    scanf("%d", i);
    float result = log(i);
    printf("The natural log of the number is %f", result); 
}

int squareroot(){
    int i;
    printf("Enter the number: ");
    scanf("%d", i);
    float result = sqrt(i);
    printf("The square root is %f", result);
}

int main(){
    int a;
    printf("Basic Calculator!\nPress 1 for adding2 numbers \nPress 2 for subtracting 2 numbers \nPress 3 for multiplying 2 numbers \nPress 4 for dividing two numbers \nPress 5 for calculating powers \nPress 6 for rounding a number \nPress 7 for calculating the circumference of a circle \nPress 8 for calculating the natural log of a number \nPress 9 for calculating the square root of a number \n");
    scanf("%c", &a);
    
    switch(a){
        case '1':
            add();
            break;
        case '2':
            sub();
            break;
        case '3':
            mul();
            break;
        case '4':
            div();
            break;
        case '5':
            power();
            break;
        case '6':
            rou();
            break;
        case '7':
            cir();
            break;
        case '8':
            logarithm();
            break;
        case '9':
            squareroot();
            break;
    }
}