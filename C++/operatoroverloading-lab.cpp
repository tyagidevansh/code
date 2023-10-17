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
    String s1("Lorem ");
    String s2("Ipsum");

    cout << "Original strings s1 and s2:" << endl;
    s1.print();
    s2.print();

    String s3;
    s3 = s1 + s2;
    cout << "Concatenated string:";
    s3.print();

    cout << "Is s1 <= s2? (1 if true) " << (s1 <= s2) << endl;

    cout << "Length of the concatenated string: " << s3.len() << endl;

    s1.toLower();
    cout << "s1 to lowercase: ";
    s1.print();

    s2.toUpper();
    cout << "s2 to uppercase: ";
    s2.print();

    return 0;
}




