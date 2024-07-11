/*Problem-8 Write a program to compute the given integrals using Monte-Carlo method.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double funct1(double x)
{
	return(pow(cos(x),2)*sqrt(1+pow(x,3)));
}
double funct2(double x)
{
	return(sqrt(x)/(sqrt(3-x)+sqrt(x)));
}
double funct3(double x)
{
	return((exp(x)*sqrt(exp(x)-1))/(exp(x)+3));
}
double funct4(double x)
{
	return((sin(x)+cos(x))/(3+sin(2*x)));
}
double funct5(double x)
{
	return(fabs(log(x)));
}   



int main() {

    int i, n;
    double x, y, sum = 0;
    double integral, width, random_x;
    double lower_bound, upper_bound;
    double random_y;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    //-------------1

    lower_bound = -1; // lower bound of integral
    upper_bound = 2; // upper bound of integral
    width = upper_bound - lower_bound;
    sum=0;

    srand(time(NULL)); // seed the random number generator

    for (i = 0; i < n; i++) 
    {
        random_x = (double)rand()/(1.0 + RAND_MAX);
        x = lower_bound + width*random_x;
        random_y = (double)rand()/(1.0 + RAND_MAX);
        y = funct1(x);
        if (random_y < y) 
        {
            sum++;
        }
    }

    integral = (double)sum/n*width;
    printf("The integral of pow(cos(x),2)*sqrt(1+pow(x,3)) from \t%.2f to %.2f is: %.5f\n", lower_bound,upper_bound,integral);

    //------------2


    lower_bound = 1; // lower bound of integral
    upper_bound = 2; // upper bound of integral
    width = upper_bound - lower_bound;
    sum=0;

    srand(time(NULL)); // seed the random number generator

    for (i = 0; i < n; i++) {
        random_x = (double)rand()/(1.0 + RAND_MAX);
        x = lower_bound + width*random_x;
        random_y = (double)rand()/(1.0 + RAND_MAX);
        y = funct2(x);
        if (random_y < y) {
            sum++;
        }
    }

    integral = (double)sum/n*width;
    printf("The integral of sqrt(x)/(sqrt(3-x)+sqrt(x)) from \t%.2f to %.2f is: %.5f\n", lower_bound,upper_bound,integral);

    //------------3


    lower_bound = 0; // lower bound of integral
    upper_bound = 1.6094; // upper bound of integral
    width = upper_bound - lower_bound;
    sum=0;

    srand(time(NULL)); // seed the random number generator

    for (i = 0; i < n; i++) {
        random_x = (double)rand()/(1.0 + RAND_MAX);
        x = lower_bound + width*random_x;
        random_y = (double)rand()/(1.0 + RAND_MAX);
        y = funct3(x);
        if (random_y < y) {
            sum++;
        }
    }

    integral = (double)sum/n*width;
    printf("The integral of (exp(x)*sqrt(exp(x)-1))/(exp(x)+3) from %.2f to %.2f is: %.5f\n", lower_bound,upper_bound,integral);

    //------------4


    lower_bound = 0; // lower bound of integral
    upper_bound = 0.7857; // upper bound of integral
    width = upper_bound - lower_bound;
    sum=0;

    srand(time(NULL)); // seed the random number generator

    for (i = 0; i < n; i++) {
        random_x = (double)rand()/(1.0 + RAND_MAX);
        x = lower_bound + width*random_x;
        random_y = (double)rand()/(1.0 + RAND_MAX);
        y = funct4(x);
        if (random_y < y) {
            sum++;
        }
    }

    integral = (double)sum/n*width;
    printf("The integral of (sin(x)+cos(x))/(3+sin(2*x)) from \t%.2f to %.2f is: %.5f\n", lower_bound,upper_bound,integral);

    //------------5


    lower_bound = 0.3679; // lower bound of integral
    upper_bound = 2.718; // upper bound of integral
    width = upper_bound - lower_bound;
    sum=0;

    srand(time(NULL)); // seed the random number generator

    for (i = 0; i < n; i++) {
        random_x = (double)rand()/(1.0 + RAND_MAX);
        x = lower_bound + width*random_x;
        random_y = (double)rand()/(1.0 + RAND_MAX);
        y = funct5(x);
        if (random_y < y) {
            sum++;
        }
    }

    integral = (double)sum/n*width;
    printf("The integral of (fabs(log(x))) from \t\t\t%.2f to %.2f is: %.5f\n", lower_bound,upper_bound,integral);

    //-------------
    return 0;
}
