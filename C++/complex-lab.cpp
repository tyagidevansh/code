#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;
public:
    Complex() : real(0.0), imag(0.) {}

    Complex (float value) : real(value), imag(value) {}

    Complex (float real, float imag) : real(real), imag(imag) {}

    Complex operator+(const Complex& other) {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main(){
    Complex num;
    Complex num2(3.0);
    Complex num3(1.5, 2.5);
    Complex sum = num2+ num3;

    num2.display();
    num3.display();
    sum.display();

    return 0;
}
