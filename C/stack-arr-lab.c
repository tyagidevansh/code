#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initialize(Stack *s){
    s->top = -1;
}

int is_empty(Stack *s){
    return s->top == -1;
}

int is_full(Stack *s){
    return s-> top == MAX-1;
}

void push(Stack *s, int data){
    if (is_full(s)) {
        printf("Stack overflow!");
        return;
    }
    s->data[++s->top] = data;
}

int pop(Stack *s){
    if (is_empty(s)){
        printf("Stack underflow!");
        return 1;
    }
    return s->data[s->top--];
}

int peek(Stack *s){
    if (is_empty(s)){
        printf("Stack empty!");
        return 1;
    }
    return s->data[s->top];
}

void display(Stack *s){
    if (is_empty(s)){
        printf("Stack empty!");
        return;
    }
    printf("All the stack elements: ");
        for (int i = 0; i <= s->top;i++){
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }

int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    display(&s);

    printf("Popped element: %d\n", pop(&s));
    display(&s);

    return 0;
}