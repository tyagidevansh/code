#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typdedef struct Node{
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
        return 1;
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
        return 1;
    }

    stack -> top = NULL;
    return stack;
}

void push(Stack* stack, int data){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Stack));

    newNode -> next = stack->top;
    stack -> top = newNode;
}

void pop(Stack* stack){
    if (stack -> top == NULL){
        printf("The stack is empty! No elements can be popped. ");
        return 1;
    }

    Node* topNode = stack -> top;
    stack -> top = topNode -> next;
    free(topNode);
    return data;
}