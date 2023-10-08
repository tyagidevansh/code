#include <iostream>
#include <string.h>

using namespace std;

class student{
    int rno;
    char name[50];
    double fee;
public:
    student(int, char[], double);
    student (student &t){
        rno=t.rno;
        strcpy(name,t.name);
        fee=t.fee;
    }
    void display();
};

