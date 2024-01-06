#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

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
    printf("%d pushed onto the stack \n", data);
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

Stack* reverse(Stack* stack){
    Stack* stack2;
    stack2 = (Stack*)malloc(sizeof(stack));

    if (stack2 == NULL){
        printf("Stack reversal failed due to memory allocation error");
        exit(1);
    }

    stack2 -> top = NULL;

    Node* current = stack->top;

    while (current != NULL){
        push(stack2, current->data);
        current = current->next;
    }
    return stack2;
}

int isEmpty(Stack* stack){
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

    push(stack, 15);
    push(stack, 20);
    push(stack, 25);

    printf("Top element of the stack : %d \n",peek(stack));
    printf("Element popped: %d \n", pop(stack));
    printf("Top element of the stack : %d \n",peek(stack));


    freeStack(stack);

    return 0;
}