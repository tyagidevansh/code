/*
implement a class string containing the following functions:
a) overload + operator to carry out the concatenation of strings
b) overload = to carry out string copy
c) overload <= to carry out the comparison of strings
d) function to display the length of the string
e) function tolower() to convert upper case letters to lower case
f) function toupper() to convert lower case letters to upper case
*/

#include <iostream>

using namespace std;

class String{
    string str;
public:
    String(string st = "") : str(st) {}

    string operator+(String const &other){
        string concat;
        concat = str + other.str;
        return concat;
    }

    String& operator=(const String &other){
        if (this == &other){
            return *this;
        }

        str = other.str;
        return *this;
    }

    bool operator<=(const String& other) const {
        return str <= other.str;
    }

    int len(){
        return str.length();
    }

    void toLower(){
        for (int i = 0; str[i]; i++){
            if (str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + 32;
            }
        }
    }

    void toUpper(){
        for (int i = 0; str[i]; i++){
            if (str[i] >= 'a' && str[i] <= 'z'){
                str[i] = str[i] - 32;
            }
        }
    }

    void print(){
        cout << str << endl;
    }

};

int main(){
    String s1("Hello, ");
    String s2("World!");

    String s3;
    //s3 = s1 + s2;
    //s3 = s1;
    
    s1.toLower();
    s1.print();

    s2.toUpper();
    s2.print();

    return 0;
}