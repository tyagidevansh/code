#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define SEP ','
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;


void initialize(Stack *s) {
    s->top = -1;
}

bool is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = c;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

char pop(Stack *s) {
    if (!is_empty(s)) {
        return s->data[s->top--];
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

char peek(Stack *s) {
    if (!is_empty(s)) {
        return s->data[s->top];
    } else {
        printf("Stack underflow!\n");
        exit(2);
    }
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infix_to_postfix(char *infix, char *postfix) {
    Stack operator_stack;
    initialize(&operator_stack);
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
            push(&operator_stack, c);
        } else if (c == ')') {
            while (!is_empty(&operator_stack) && peek(&operator_stack) != '(') {
                postfix[j++] = pop(&operator_stack);
            }
            if (!is_empty(&operator_stack) && peek(&operator_stack) == '(') {
                pop(&operator_stack);
            }
        } else {
            while (!is_empty(&operator_stack) && precedence(c) <= precedence(peek(&operator_stack))) {
                postfix[j++] = pop(&operator_stack);
            }
            push(&operator_stack, c);
        }
    }

    while (!is_empty(&operator_stack)) {
        postfix[j++] = pop(&operator_stack);
    }

    postfix[j] = '\0';
}

int eval(char *postfix) {
    Stack evaluate;
    initialize(&evaluate);

    int i = 0, op1 = 0, op2 = 0;

    while (postfix[i] != '\0') {
        char c = postfix[i];

        if (isdigit(c)) {
            int num = 0;
            while (c != SEP) {
                num = num * 10 + (c - '0');
                i++;
                c = postfix[i];
            }
            push(&evaluate, num);
        } else if (c == SEP) {
            i++;
        } else {
            op2 = pop(&evaluate);
            op1 = pop(&evaluate);
            switch (c) {
                case '+':
                    push(&evaluate, op1 + op2);
                    break;
                case '-':
                    push(&evaluate, op1 - op2);
                    break;
                case '*':
                    push(&evaluate, op1 * op2);
                    break;
                case '/':
                    push(&evaluate, op1 / op2);
                    break;
                case '^':
                    push(&evaluate, (int)pow(op1, op2));
                    break;
                default:
                    printf("Invalid operation!");
                    exit(1);
            }
            i++;
        }
    }
    return pop(&evaluate);
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    printf("Answer: %d\n", eval(postfix));

    return 0;
}
