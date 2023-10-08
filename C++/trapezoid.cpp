#include <iostream>
#include <cmath>

using namespace std;

float f(float x) {
    return cos(x) * log(sin(x)) / (1 + sin(x) * sin(x));
}

float trapezoid(int n) {
    float a = M_PI / 2;  
    float b = M_PI / 4;  
    float h = (a - b) / n;

    float result = h / 2 * (f(a) + f(b));

    for (int i = 1; i < n; i++) {
        a -= h;
        result += h * f(a);
    }

    return result;
}

int main() {
    float integral = trapezoid(100);
    cout << "Approximate integral: " << integral << endl;

    return 0;
}
