#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct{
    char data[MAX];
    int top;
} Stack;

void intialize(Stack *s){
    s->top = -1;
}

int is_empty(Stack *s){
    return s-> top == -1;
}

void push(Stack *s, char c){
    if (s->top < MAX - 1 ){
        s->data[++s->top] = c;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

char pop(Stack *s){
    if (!is_empty(s)){
        return s->data[s->top--];
    }else{
        printf("Stack underflow!\n");
        exit(1);
    }
}

// void peek(Stack *s){
//     if (!is_empty(s)){
//         printf("%d \n", s->data[s->top]);
//     }else{
//         printf("Stack underflow!");
//     }
// }

int precedence(char c){
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infix_to_postfix(char *infix, char *postfix){
    Stack operator_stack;
    intialize(&operator_stack);
    int i,j = 0;

    for (int i = 0; infix[i] != '\0';i++){
        char c = infix[i];

        if (isalnum(c)){
            postfix[j++] = c;
        }
        else if (c == '('){
            push(&operator_stack, c);
        }
        else if (c == ')'){
            while(!is_empty(&operator_stack) && operator_stack.data[operator_stack.top] != '('){
                postfix[j++] = pop(&operator_stack);
            }
            if (!is_empty(&operator_stack) && operator_stack.data[operator_stack.top] == '('){
                pop(&operator_stack);
            }
        }
        else{
            while(!is_empty(&operator_stack) && precedence(c) <= precedence(operator_stack.data[operator_stack.top])) {
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

int eval(char* postfix){
    Stack* evaluate;
    intialize(evaluate);

    int i = 0, j = 0;

    while (postfix[i] != '\0'){
        char c = postfix[i];

        if (isalnum(c)){
            push(evaluate, c);
        }
        else{
            //wait imma commit first
        }
    }
}

int main(){
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}