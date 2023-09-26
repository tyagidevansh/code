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
    }
}

int peep(){
    if(!isEmpty()){
        return stack[top];
    }else{
        printf("Stack is empty! No elements can be read.");
    }
}

int main(){
    push(10);
    push(20);
    printf("%d \n", peep());
    pop();
    printf("%d \n", peep());
    return 0;
}