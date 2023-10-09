#include <iostream>

using namespace std;

class number1{
    int num1;
public:
    number1(){
        cout << "Enter the first number: ";
        cin >> num1;
    }
    friend void find_max();
};

class number2{
    int num2;
public:
    number2(){
        cout << "Enter the second number: ";
        cin >> num2;
    }
    friend void find_max();
};

void find_max(){
    number1 num1;
    number2 num2;

    if (num1.num1 > num2.num2){
        cout << "Number 1 is larger than number 2" << endl;
    }
    else if (num1.num1 == num2.num2){
        cout << "Number 1 is equal to number 2." << endl;
    }
    else {
        cout << "Number 2 is larger than number 1" << endl;
    }
}

int main(){
    find_max(); 

    return 0;
}



