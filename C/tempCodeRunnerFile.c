#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100
#define SEP ','

int nums[MAX];
int top = -1;

void push_(int data){
    if (top == MAX-1){
        printf("Stack overflow");
        exit(1);
    }
    nums[++top] = data;
}

int pop_(){
    if (top == -1){
        printf("Stack empty");
        exit(1);
    }
    return nums[top--];
}

int eval(char *postfix) {
    int i = 0, op1 = 0, op2 = 0;

    

    while (postfix[i] != '\0') {
        char c = postfix[i];

        if (isdigit(c)) {
            int num = 0;
            while (c!= SEP) {
                num = num * 10 + (c - '0');
                i++;
                c = postfix[i];
            }
            push_(num);
        }
        else if (c == SEP){
            i++;
        }else {
            op2 = pop_();
            op1 = pop_();

            switch (c) {
                case '+' :
                    push_(op1+op2);
                    break;
                case '-' :
                    push_(op1-op2);
                    break;
                case '*' :
                    push_(op1*op2);
                    break;
                case '/' :
                    push_(op1/op2);
                    break;
                case '^' :
                    push_(pow(op1, op2));
                    break;
                default:
                    printf("Invalid operation!");
                    exit(1);
            }
            i++; 
        }
    }
    return pop_();
}

int main(){
    char postfix[] = {'5', ',', '5', ',', '^', '\0'};
    printf("%d", eval(postfix));
    return 0;
}