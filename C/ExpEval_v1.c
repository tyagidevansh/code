#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define SEP ',' 
#define MAX 100

char operator_stack[MAX];
int operator_top = -1;

int numeric_stack[MAX];
int numeric_top = -1;

bool is_operator_empty() {
    return operator_top == -1;
}

void push_operator(char c) {
    if (operator_top < MAX - 1) {
        operator_stack[++operator_top] = c;
    } else {
        printf("Operator stack overflow!\n");
        exit(1);
    }
}

char pop_operator() {
    if (!is_operator_empty()) {
        return operator_stack[operator_top--];
    } else {
        printf("Operator stack underflow!\n");
        exit(1);
    }
}

char peek_operator() {
    if (!is_operator_empty()) {
        return operator_stack[operator_top];
    } else {
        printf("Operator stack underflow!\n");
        exit(2);
    }
}

bool is_numeric_empty() {
    return numeric_top == -1;
}

void push_numeric(int value) {
    if (numeric_top < MAX - 1) {
        numeric_stack[++numeric_top] = value;
    } else {
        printf("Numeric stack overflow!\n");
        exit(1);
    }
}

int pop_numeric() {
    if (!is_numeric_empty()) {
        return numeric_stack[numeric_top--];
    } else {
        printf("Numeric stack underflow!\n");
        exit(1);
    }
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infix_to_postfix(const char *infix, char *postfix) {
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            while (isalnum(c)) {
                postfix[j++] = c;
                c = infix[++i];
            }
            postfix[j++] = SEP;
        }

        if (c == '(') {
            push_operator(c);
        } else if (c == ')') {
            while (!is_operator_empty() && peek_operator() != '(') {
                postfix[j++] = pop_operator();
            }
            if (!is_operator_empty() && peek_operator() == '(') {
                pop_operator();
            }
        } else {
            while (!is_operator_empty() && precedence(c) <= precedence(peek_operator())) {
                postfix[j++] = pop_operator();
            }
            push_operator(c);
        }
    }

    while (!is_operator_empty()) {
        postfix[j++] = pop_operator();
    }

    postfix[j] = '\0';
}

int eval(const char *postfix) {
    int i = 0;

    while (postfix[i] != '\0') {
        char c = postfix[i];

        if (isdigit(c)) {
            int num = 0;
            while (c != SEP) {
                num = num * 10 + (c - '0');
                i++;
                c = postfix[i];
            }
            push_numeric(num);
        } else if (c == SEP) {
            i++;
        } else {
            int op2 = pop_numeric();
            int op1 = pop_numeric();

            switch (c) {
                case '+':
                    push_numeric(op1 + op2);
                    break;
                case '-':
                    push_numeric(op1 - op2);
                    break;
                case '*':
                    push_numeric(op1 * op2);
                    break;
                case '/':
                    push_numeric(op1 / op2);
                    break;
                case '^':
                    push_numeric((int)pow(op1, op2));
                    break;
                default:
                    printf("Invalid operation!\n");
                    exit(1);
            }
            i++;
        }
    }

    return pop_numeric();
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    //printf("Postfix expression: %s\n", postfix);

    printf("Answer: %d\n", eval(postfix));

    return 0;
}
