#include <iostream>
#include <cstring>

using namespace std;

class student{
    int rno;
    char name[50];
    double fee;
public:
    student(int, const char[], double);
    student (const student &t);

    void display();
};

student :: student(int no, const char n[], double f){
    rno = no;
    strcpy(name,n);
    fee = f;
}

student :: student(const student &t){
    rno = t.rno;
    strcpy(name, t.name);
    fee = t.fee;
}

void student::display(){
    cout << endl << rno << "\t" << name << "\t" << fee;
}

int main(){
    student s(1001, "Manjeet", 10000);
    s.display();

    student manjeet(s);
    manjeet.display();

    return 0;
}

