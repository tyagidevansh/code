#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define SEP ','
#define MAX 100

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initialize(Stack *stack) {
    stack->top = NULL;
}

int is_empty(Stack *stack) {
    return stack->top == NULL;
}

// Function to push data onto the stack
void push(Stack *stack, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop data from the stack
void *pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!");
        exit(1);
    }
    Node *topNode = stack->top;
    stack->top = topNode->next;
    void *data = topNode->data;
    free(topNode);
    return data;
}

// Function to peek at the top of the stack
void *peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!");
        exit(1);
    }
    return stack->top->data;
}

// Function to get the precedence of an operator
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to convert infix to postfix
void infix_to_postfix(Stack *stackOp, const char *infix, char *postfix) {
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // Handle operands
        if (isalnum(c)) {
            while (isalnum(c)) {
                postfix[j++] = c;
                c = infix[++i];
            }
            postfix[j++] = SEP;
        }

        // Handle operators and parentheses
        if (c == '(') {
            push(stackOp, &c);
        } else if (c == ')') {
            while (!is_empty(stackOp) && *((char *)peek(stackOp)) != '(') {
                postfix[j++] = *((char *)pop(stackOp));
            }
            if (!is_empty(stackOp) && *((char *)peek(stackOp) == '(')) {
                pop(stackOp);
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!is_empty(stackOp) && precedence(c) <= precedence(*((char *)peek(stackOp))) && *((char *)peek(stackOp) != '(')) {
                postfix[j++] = *((char *)pop(stackOp));
            }
            push(stackOp, &c);
        }
    }

    // Pop any remaining operators
    while (!is_empty(stackOp)) {
        postfix[j++] = *((char *)pop(stackOp));
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    Stack stackOp;
    initialize(&stackOp);

    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(&stackOp, infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
