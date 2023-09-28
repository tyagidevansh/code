#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == MAX_SIZE-1;
}

void push(int value){
    if(!isFull()){
        stack[++top] = value;
    }else{
        printf("Stack full! No more elements can be inserted.");
    }
}

int pop(){
    if(!isEmpty()){
        return stack[top--];
    }else{
        printf("Stack is empty! No elements can be popped.");
        return 1;
    }
}

int peep(){
    if(!isEmpty()){
        return stack[top];
    }else{
        printf("Stack is empty! No elements can be read.");
        return 1;
    }
}

int* reverse_iter(){
    int* stack_rev = (int*)calloc(top, sizeof(int));

    if (stack_rev == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }

    for (int i = top; i <= 0; i++){
        stack_rev[i] = stack[top-i]; 
    }

    return stack_rev;
}

int main(){
    push(10);
    push(20);
    printf("%d \n", peep());
    pop();
    printf("%d \n", peep());

    int* stack_rev = reverse_iter();

    for (int i = 0; i < top; i++){
        printf("%d", stack_rev[i]);
    }

    return 0;
}