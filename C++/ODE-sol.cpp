#include <iostream>
using namespace std;

float f(float x, float y) {
    return x+y;
}

float euler(float x, float y, float h, float target) {
    while (x < target) {
        y += h*f(x, y);
        x+=h;
    }
    return y;
}

float eulerModified(float x0, float y0, float h, float target) {
    float x1, yp, y1 = y0;
    for (x0; x0 < target; x0+= h){
        yp = y0 + h*f(x0,y0);
        y1 += (h/2)*(f(x0,y0) + f(x0+h, yp));
    }
    return y1;
}

float RK(float x0, float y0, float h, float target) {
    float K1, K2, K3, K4;
    for (x0; x0 < target; x0+=h) {
        K1 = h*f(x0,y0);
        K2 = h*f(x0+h/2, y0 + K1/2);
        K3 = h*f(x0+h/2, y0 + K2/2);
        K4 = h*f(x0+h, y0 + K3);

        y0 += (K1 + 2*K2 + 3*K3 + K4)/6;
    }
    return y0;
}

int main() {
    float h = 0.02;
    float x = 0, y = 0, target = 0.4;
    cout << euler(x,y,h,target) << '\n';
    cout << eulerModified(x,y,h,target) << '\n';
    cout << RK(x,y,h,target) << '\n';
    return 0;
}