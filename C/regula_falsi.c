#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6  // Tolerance for stopping the iteration

// Function to calculate the value of the equation
double func(double x) {
    return x * x * x - 5 * x + 1;
}

// Regula Falsi method to find the root
double regulaFalsi(double a, double b) {
    double c, fa, fb, fc;
    int maxIterations = 5;
    int iter = 0;

    
    do {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));
        fa = func(a);
        fb = func(b);
        fc = func(c);

        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iter, a, b, c, fc);

        if (fc == 0 || (b - a) / 2 < EPSILON) {
            printf("Root found at x = %.6lf\n", c);
            return c;
        }

        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }

        iter++;
    } while (iter < maxIterations);

    printf("Regula Falsi Method: Maximum iterations reached\n");
    return c;
}

int main() {
    double a = 0.0, b = 2.0; // Initial interval [a, b]

    printf("Solving the equation x^3 - 5x + 1 = 0 using Regula Falsi method:\n");
    printf("Iteration\ta\t\tb\t\tc\t\tf(c)\n");

    double root = regulaFalsi(a, b);
    printf("Approximate root: %.6lf\n", root);

    return 0;
}
