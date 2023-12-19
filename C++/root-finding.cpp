#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<int,int>> list;

float f(float x) {
    return x*x*x - 5*x + 1;
}

bool oppSigns(int a, int b) {
    if (f(a) * f(b) < 0) {
        return 1;
    }
    return 0;
}

list initGuess() {
    list v;
    for (int i = -100; i < 100; i++) {
        if (oppSigns(i, i + 1) == 1) {
            v.push_back({i, i+1});
        }
    }
    return v;
}

float bisection(float a, float b, int n) {
    for (int i = 0; i < n; i++) {
        float c = (a + b) / 2;
        if (f(c)*f(a) < 0) {
            b = c;
        } else if(f(c)*f(b) < 0) {
            a = c;
        } else {
            return c;
        }
    }
    return (a+b)/2;
}

float regulaFalsi(float a, float b, int n) {
    float c, fa, fb, fc;
    for (int i = 0; i < n; i++) {
        fa = f(a);
        fb = f(b);
        c = (a*fb - b*fa)/(fb-fa);
        fc = f(c);
        if (fc == 0)
            return c;
        if (fa*fc < 0)
            b = c;
        if (fc*fb < 0)
            a = c; 
    }
    return c;
}

float derrivative(float x) {
    float h = 0.00001;
    return (f(x+h) - f(x))/h;
}

float newtonRaphson(float x, int n) {
    for (int i = 0; i < n; i++) {
        x -= f(x)/derrivative(x);
    }
    return x;
} 

int main(){
    int n = 10; //number of iterations
    list v = initGuess();
    cout << "Approximate roots after 10 iterations by bisection method: ";
    for (const auto& element : v) {
        cout << bisection(element.first, element.second, n) << ", ";
    }
    cout << '\n';
    cout << "Approximate roots after 10 iterations by regula-falsi method: ";
    for (const auto& element : v) {
        cout << regulaFalsi(element.first, element.second, n) << ", ";
    }
    cout << '\n';
    cout << "Approximate roots after 10 iterations by newton raphson method: ";
    for (const auto& element : v) {
        cout << newtonRaphson(element.first, n) << ", ";
    }
    return 0;
}