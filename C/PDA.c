#include <stdio.h>
#include <stdbool.h>

enum State {
    READ_W,
    READ_C,
    READ_REV_W,
    ACCEPT,
    REJECT
};

typedef struct {
    char stack[100];
    int top;
    enum State currentState;
} PDA;

void initPDA(PDA *pda) {
    pda->top = -1;
    pda->currentState = READ_W;
    pda->stack[++pda->top] = '#';
}

void push(PDA *pda, char symbol) {
    pda->stack[++pda->top] = symbol;
}

void pop(PDA *pda) {
    if (pda->top >= 0) 
        pda->top--;
}

bool isEmpty(PDA *pda) {
    return (pda->top == 0);
}

void processInput(PDA *pda, const char* input) {
    int i = 0;
    while (input[i] != '\0') {
        switch (pda->currentState) {
            case READ_W:
                if (input[i] == '1' || input[i] == '0') {
                    push(pda, input[i]);
                    i++;
                } else {
                    pda->currentState = READ_C;
                }
                break;
            case READ_C:
                i++;
                pda->currentState = READ_REV_W;
                break;
            case READ_REV_W:
                if (input[i] == pda->stack[pda->top]) {
                    pop(pda);
                    i++;
                } else {
                    pda->currentState = REJECT;
                }
                break;
            case ACCEPT:
            case REJECT:
                return;
        }
    }
    if (isEmpty(pda) && pda->currentState != REJECT) {
        pda->currentState = ACCEPT;
    } else {
        pda->currentState = REJECT;
    }
}

bool isAccepted(PDA *pda) {
    return (pda->currentState == ACCEPT);
}

int main() {
    PDA pda;
    initPDA(&pda);

    char input[100];
    printf("Enter a binary string in WCWR format: ");
    scanf("%s", input);
    processInput(&pda, input);
    if (isAccepted(&pda)) 
        printf("String accepted. ");
    else
        printf("String rejected ");
}