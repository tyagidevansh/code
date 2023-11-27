//Write a program to demonstrate the use of special functions, constructor and destructor in the class template. The program is used to 
//calculate the bigger of two entered numbers.

#include <iostream>
using namespace std;

template <typename T>
class Compare{
private:
    T num1, num2;

public:
    Compare(T a, T b) : num1(a), num2(b) {
        cout << "Object created." << endl;
    }

    ~Compare() {
        cout << "Object destroyed. " << endl;
    }

    T getBigger() {
        return (num1 > num2) ? num1 : num2;
    }
};

int main(){
    Compare<int> compareIntegers(10,30);
    cout << "Bigger number is: " << compareIntegers.getBigger() << endl;

    Compare<float> compareFloats(5.5, 10.7);
    cout << "Bigger number is: " << compareFloats.getBigger() << endl;

    return 0;
}