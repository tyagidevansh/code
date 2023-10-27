#include <iostream>
using namespace std;

float f(float x, float y){
    return x+y;
}

float euler(float h, float x, float y, float target) {
    for (x; x < target; x+=h) {
        y = y+ h*f(x,y);
    }
    return y;
}

float euler_modified(float h, float x, float y, float target, float y0){
    float y1;
    for (x; x < target; x+=h) {
        y1 = f(x,y);
        y = y + h/2 * (y1 + y0);
        y0 = y1;
    }
    return y;
}

int main(){
    float h = 0.02;
    float x = 0, y = 0, y0 = 0;
    cout << "h = " << h << endl;
    cout << "Euler's method: " << endl;
    float target = 0.4;
    cout << "Approximate solution at 0.4: " << euler(h,x,y,target) << endl;

    target = 0.6;
    cout << "Approximate solution at 0.6: " << euler(h,x,y,target) << endl;

    cout << "Modified Euler's method: " << endl;
    target = 0.4;
    cout << "Approximate solution at 0.4: " << euler_modified(h,x,y,target,y0) << endl;

    target = 0.6;
    cout << "Approximate solution at 0.6: " << euler_modified(h,x,y,target,y0);
}