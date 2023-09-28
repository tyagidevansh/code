#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6 


double func(double x) {
    return x * x * x - 5 * x + 1;
}

// Derivative of the equation
double derivative(double x, double h) {
    return (func(x + h) - func(x)) / (h);
}

double newtonRaphson(double x0) {
    int maxIterations = 1000;
    int iter = 0;
    double h = 0.0001;
        
    double x = x0;

    do {
        double fx = func(x);
        printf("%d\t\t%.6lf\t%.6lf\n", iter, x, fx);

        if (fabs(fx) < EPSILON) {
            printf("Root found at x = %.6lf\n", x);
            return x;
        }

        x = x - fx / derivative(x,h);
        
        iter++;
    } while (iter < maxIterations);

    printf("Newton-Raphson Method: Maximum iterations reached\n");
    return x;
}

int main() {
    double x0 = 1.0; 
 

    printf("Solving the equation x^3 - 5x + 1 = 0 using Newton-Raphson method:\n");
    printf("Iteration\t x\t\t f(x)\n");

    double root = newtonRaphson(x0);
    printf("Approximate root: %.6lf\n", root);

    return 0;
}
