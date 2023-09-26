#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

Node* createNode(int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Memory allocation failed");
        exit(1);
    }

    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

Stack* intializeStack(){
    Stack* stack;
    stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL){
        printf("Memory allocation failed");
        exit(1);
    }

    stack -> top = NULL;
    return stack;
}

void push(Stack* stack, int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Stack));

    newNode -> next = stack->top;
    newNode -> data = data;
    stack -> top = newNode;
}

int pop(Stack* stack){
    if (stack -> top == NULL){
        printf("The stack is empty! No elements can be popped. ");
        exit(1);
    }

    Node* topNode = stack -> top;
    int data = topNode -> data;
    stack -> top = topNode -> next;
    free(topNode);
    return data;
}

int peek(Stack* stack){
    if (stack -> top == NULL){
        printf("The stack is empty");
    }
    return stack->top->data;
}

bool isEmpty(Stack* stack){
    return (stack->top == NULL);
}

void freeStack(Stack* stack){
    while(!isEmpty(stack)){
        pop(stack);
    }
    free(stack);
}

int main(){
    Stack* stack = intializeStack();

    push(stack, 5);
    push(stack, 10);
    push(stack, 20);

    printf("First element in the stack: %d \n", peek(stack));

    while(!isEmpty(stack)){
        printf("Element popped: %d \n", pop(stack));
    }

    freeStack(stack);

    return 0;
}