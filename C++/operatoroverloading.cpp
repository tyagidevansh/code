#include <iostream>
using namespace std;

class Complex{
    int real, imag;
public:
    Complex(int real = 0, int imag = 0) : real(real), imag(imag){}

    Complex operator+(Complex const &obj){
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() {cout << real << " + i" << imag << endl;}
};

int main(){
    Complex c1(10,5), c2(3,7);
    Complex c3 = c1 + c2;
    c3.print();
}