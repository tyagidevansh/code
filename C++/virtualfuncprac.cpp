#include <iostream>
using namespace std;

class base {
public:
    virtual void print() { cout << "print base class \n";}

    void show() { cout << "show base class \n";}
};

class derived : public base {
public:
    void print() { cout << "print derived class \n";}

    void show() { cout << "show derived class \n";}
};

int main(){
    base* bptr;
    derived d;
    bptr = &d;

    //when you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function and execture the derived class's version of the funtcion
    bptr -> print();
    bptr->show();

    return 0;

}