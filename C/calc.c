#include <stdio.h>

struct Calculator {
    double num1;
    double num2;
    char operator;
};

double calculate(struct Calculator calc) {
    switch (calc.operator) {
        case '+':
            return calc.num1 + calc.num2;
        case '-':
            return calc.num1 - calc.num2;
        case '*':
            return calc.num1 * calc.num2;
        case '/':
            if (calc.num2 != 0) {
                return calc.num1 / calc.num2;
            } else {
                printf("Error: Division by zero\n");
                return 0;
            }
        default:
            printf("Error: Invalid operator\n");
            return 0;
    }
}

int main() {
    struct Calculator calc;

    printf("Enter first number: ");
    scanf("%lf", &calc.num1);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &calc.operator); 
    printf("Enter second number: ");
    scanf("%lf", &calc.num2);

    double result = calculate(calc);

    printf("Result: %lf\n", result);

    return 0;
}


