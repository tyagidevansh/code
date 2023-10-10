#include <iostream>
#include <cstring>

using namespace std;

class student{
    int rno;
    char name[50];
    double fee;
public:
    student();
    student(int rno, const char n[], double f) : rno(rno), fee(f) {
        strcpy(name,n);
    }
    student(const student &t) : rno(t.rno), fee(t.fee) {
        strcpy(name, t.name);
    }

    void display(){
        cout << endl << rno << '\t' << name << '\t' << fee;
    }
};

int main(){
    student s(1001, "Manjeet", 10000);
    s.display();

    student manjeet(s);
    manjeet.display();

    return 0;
}

