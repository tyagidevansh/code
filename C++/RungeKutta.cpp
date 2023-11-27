#include <iostream>
using namespace std;

float f(float x, float y){
    return x + y;
}

float RK(float x0, float y0, float h, float target){
    while (x0 <= target){
        float p1 = h*f(x0, y0);
        float p2 = h*f((x0 + h/2), (y0 + p1/2));
        float p3 = h*f((x0 + h/2),(y0 + p2/2));
        float p4 = h*f((x0 + h), (y0 + p3));
        float delY = (p1 + 2*p2 + 2*p3 + p4) / 6;

        y0 += delY;
        x0 += h;
    }
    return y0;
}

int main(){
    float x0 = 0, y0 = 1;
    float h = 0.001;
    float target = 0.1;

    cout << "Result: " << RK(x0, y0, h, target);

    return 0;
}