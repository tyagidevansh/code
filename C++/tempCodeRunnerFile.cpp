#include <iostream>
using namespace std;

template <typename T>
T square (T a) {
    return a*a;
}

int main() {
cout << square(5);
cout << square(4.2);

}