#include <stdio.h>
#include <stdbool.h>

// Define PDA states
enum State {
    READ_W,
    READ_C,
    READ_REV_W,
    ACCEPT,
    REJECT
};

// Define PDA structure
typedef struct {
    char stack[100]; // Assuming a maximum stack size of 100
    int top;
    enum State currentState;
} PDA;

// Initialize PDA
void initPDA(PDA *pda) {
    pda->top = -1; // Initialize stack top
    pda->currentState = READ_W; // Set initial state
    pda->stack[++pda->top] = '#'; // Push '#' onto stack as bottom marker
}

// Push onto stack
void push(PDA *pda, char symbol) {
    pda->stack[++pda->top] = symbol;
}

// Pop from stack
void pop(PDA *pda) {
    if (pda->top >= 0)
        pda->top--;
}

// Check if stack is empty
bool isEmpty(PDA *pda) {
    return (pda->top == -1);
}

// Process input string
void processInput(PDA *pda, const char *input) {
    int i = 0;
    while (input[i] != '\0') {
        switch (pda->currentState) {
            case READ_W:
                if (input[i] != 'c') {
                    push(pda, input[i]);
                    i++;
                } else {
                    pda->currentState = READ_C;
                }
                break;
            case READ_C:
                i++; // Move to the next character after 'c'
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
                return; // Once in ACCEPT or REJECT state, stop processing input
        }
    }
    if (isEmpty(pda) && pda->currentState != REJECT) {
        pda->currentState = ACCEPT; // Accept if the stack is empty at the end
    } else {
        pda->currentState = REJECT; // Reject otherwise
    }
}

// Check if the input is accepted
bool isAccepted(PDA *pda) {
    return (pda->currentState == ACCEPT);
}

int main() {
    PDA pda;
    initPDA(&pda);
    char input[100]; // Assuming a maximum input length of 100
    printf("Enter a binary string followed by 'c': ");
    scanf("%s", input);
    processInput(&pda, input);
    if (isAccepted(&pda))
        printf("String accepted.\n");
    else
        printf("String rejected.\n");
    return 0;
}
