#include <iostream>
#include <stack>
#include <string>

using namespace std;

enum State {
    READ_W,
    READ_C,
    READ_REV_W,
    ACCEPT,
    REJECT
};

class PDA {
private:
    stack<char> stack;
    State currentState;

public:
    PDA() {
        currentState = READ_W;
        stack.push('#'); 
    }

    void processInput(const string& input) {
        size_t inputLength = input.length();
        size_t halfLength = inputLength / 2;
        size_t i = 0;
        while (i < inputLength) {
            switch (currentState) {
                case READ_W:
                    if (input[i] != 'c') {
                        stack.push(input[i]);
                        i++;
                    } else {
                        currentState = READ_C;
                    }
                    break;
                case READ_C:
                    i++; 
                    currentState = READ_REV_W;
                    break;
                case READ_REV_W:
                    if (input[i] == stack.top()) {
                        stack.pop();
                        i++;
                    } else {
                        currentState = REJECT;
                    }
                    break;
                case ACCEPT:
                case REJECT:
                    return; 
            }
        }
        if (stack.top() == '#' && currentState != REJECT) {
            currentState = ACCEPT;
        } else {
            currentState = REJECT; 
        }
    }

    bool isAccepted() {
        return currentState == ACCEPT;
    }
};

int main() {
    PDA pda;
    string input;
    cout << "Enter a binary string followed by 'c': ";
    cin >> input;
    pda.processInput(input);
    if (pda.isAccepted())
        cout << "String accepted.\n";
    else
        cout << "String rejected.\n";
    return 0;
}
