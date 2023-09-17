#include <stdio.h>
#include <math.h>

float func(float x);
void bounds(float *lower, float *upper);
void bisection(float a, float b, int iter);

int main(void) {

    int iter = 10;
    float lower, upper;
    bounds(&lower, &upper);
    printf("Lower Bound: %.0f\n", lower);
    printf("Upper Bound: %.0f\n", upper);
    bisection(lower, upper, iter);
 

    return 0;
}

float func(float x) {
    return pow(x, 3) - 5 * x + 1;
}

void bounds(float *lower, float *upper) {
    float diff = 200;
    for (float a = 10; a > -10; a--) {
        for (float b = a - 1; b > -10; b--) {
            if (func(a) * func(b) < 0) {
                if ((a - b) < diff) {
                    *lower = b;
                    *upper = a;
                    diff = a - b;
                }
            }
        }
    }
}

void bisection(float a, float b, int iter) {
    float c, fa, fb, fc;

    if (func(a) * func(b) >= 0) {
        printf("No roots to this equation exist from -10 to 10\n");
        return;
    }

    while (iter != 0) {
        c = (a + b) / 2;
        fa = func(a);
        fb = func(b);
        fc = func(c);

        if (fc * fa < 0) {
            printf("a = %.4f, b = %.4f, c = %.4f f = %.4f\n", a, b,c, fc);
            b = c;
        }
        if (fc * fb < 0) {
            printf("a = %.4f, b = %.4f, c = %.4f, f = %.4f\n", a, b, c, fc);
            a = c;
        }
        if (fc == 0) {
            printf("Exact root found at %.4f \n", c);
            return;
        }
        iter--;
    }
}
