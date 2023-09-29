#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, char item) {
    if (s->top < MAX_STACK_SIZE) {
        s->data[s->top++] = item;
    }
}

char pop(Stack *s) {
    if (s->top > 0) {
        return s->data[--s->top];
    }
    return '\0'; // Stack underflow
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For other characters, including '('
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

char* infixToPostfix(const char *infix) {
    Stack operator_stack;
    operator_stack.top = 0;

    char postfix[MAX_STACK_SIZE];
    int postfix_index = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isdigit(current)) {
            while (isdigit(infix[i]) || infix[i] == '.') {
                postfix[postfix_index++] = infix[i++];
            }
            postfix[postfix_index++] = ' ';
            i--;
        } else if (isOperator(current)) {
            while (isOperator(operator_stack.data[operator_stack.top - 1]) &&
                   precedence(current) <= precedence(operator_stack.data[operator_stack.top - 1])) {
                postfix[postfix_index++] = pop(&operator_stack);
                postfix[postfix_index++] = ' ';
            }
            push(&operator_stack, current);
        } else if (current == '(') {
            push(&operator_stack, current);
        } else if (current == ')') {
            while (operator_stack.top > 0 && operator_stack.data[operator_stack.top - 1] != '(') {
                postfix[postfix_index++] = pop(&operator_stack);
                postfix[postfix_index++] = ' ';
            }
            if (operator_stack.top > 0 && operator_stack.data[operator_stack.top - 1] == '(') {
                pop(&operator_stack); // Pop the '('
            }
        }
    }

    while (operator_stack.top > 0) {
        postfix[postfix_index++] = pop(&operator_stack);
        postfix[postfix_index++] = ' ';
    }

    postfix[postfix_index] = '\0';
    return strdup(postfix);
}

int evaluatePostfix(const char *postfix) {
    Stack stack;
    stack.top = 0;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            char number[32];
            int numIndex = 0;
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                number[numIndex++] = postfix[i++];
            }
            number[numIndex] = '\0';
            push(&stack, atof(number));
        } else if (postfix[i] == ' ') {
            // Ignore spaces
        } else if (isOperator(postfix[i])) {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&stack, operand1 / operand2);
                    } else {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    const char *infixExpression = "3 + (4 * 2)";
    char *postfixExpression = infixToPostfix(infixExpression);
    int result = evaluatePostfix(postfixExpression);

    printf("Infix Expression: %s\n", infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Result: %d\n", result);

    free(postfixExpression);
    return 0;
}
