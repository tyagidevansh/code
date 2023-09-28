#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - 5 * x + 1;
}

void regula_falsi(double a, double b){
    double c, fa, fb, fc;

    fa = f(a);
    fb = f(b);
    if ((fa*fb) == 0) {
        if (fa == 0){
            printf("Exact root found at %d", a);
        }
        if (fb == 0){
            printf("Exact root found at %d", b);
        }
        
    }
    else if (fa*fb > 0) {
        printf("Root does not exist within this interval");
    }
    else{
        int n = 0, iter = 10;
        while (n < iter){
            c = (a * f(b) - b * f(a))/(f(b) - f(a));
            fc = f(c);
            printf("f(c): %d", fc);

            if ((fa*fc) < 0){
                b = c;
            }
            if ((fb*fc) < 0){
                a = c;
            }
            if (fc == 0){
                printf("Exact root found at %d", c);
            }
        n++; 
        }
    }
    
    
}

int main() {
    float a = 0;
    float b = 1;

    regula_falsi(a,b);

    return 0;
}
