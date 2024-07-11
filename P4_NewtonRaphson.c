/*Problem-4 Write a Program to find the roots of non-linear equation using Newton-Raphson method.*/
#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(-x) - x;
}

double f_prime(double x) {
    return -exp(-x) - 1;
}

int main() {
    double x0 = 0.0;  // initial guess
    double TOL = 1e-4;  // tolerance
    int max_iter = 100;  // maximum number of iterations

    double x_n = x0;
    int i;
    for (i = 0; i < max_iter; i++) 
    {
        double x_n_plus_1 = x_n - f(x_n) / f_prime(x_n);
        if (fabs(x_n_plus_1 - x_n) < TOL) 
        {
            printf("The root is %.6f\n", x_n_plus_1);
            return 0;
        }
        x_n = x_n_plus_1;
    }

    printf("The Newton-Raphson method did not converge after %d iterations\n", max_iter);
    return 1;
}
