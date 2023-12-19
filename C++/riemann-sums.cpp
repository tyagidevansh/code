#include <iostream>
#include <cmath>
using namespace std;

float f(float x) {
    return pow((1+pow(x,2)),-1);
}

float trapezoidal(float a, float b, int n) {
    float h = (b-a)/n;
    float area;
    area += h*f(a)/2;
    while(a < b ) {
        a += h;
        if (a == b) {
            area += h*f(a)/2;
        } else {
            area += h*f(a);
        }
    }
    return area;
}

float simpson13(float a, float b, int n) {
    float h = (b-a)/n;
    float area;
    area += h*f(a)/3;
    while (a < b) {
        a+=h;
        area += 4*h*f(a)/3;
        a+=h;
        area += 2*h*f(a)/3;
    }
    area += h*f(a)/3;
    return area;
}

float simpson38(float a, float b, int n) {
    float h = (b-a)/n;
    float area = 0;
    for (int i = 0; i <= n; i++) {
        float x = a + i*h;
        if (i == 0 || i == n){ 
            area += f(x);
        } else if (i % 3 == 0) {
            area += 2*f(x); 
        } else {
            area += 3*f(x);
        } 
    }
    area = (3*h/8)*area;
    return area;
}

int main() {
    float a = 0;
    float b = 6;
    int n = 100;
    cout << trapezoidal(a,b,n) << '\n';
    cout << simpson13(a,b,n) << '\n';
    cout << simpson38(a,b,n) << '\n';
    return 0;
}