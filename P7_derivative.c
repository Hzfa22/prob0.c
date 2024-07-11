/*Problem-7 Write a Program to obtain the derivative of the given function.*/
#include <conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Finding derivatives of a polynomial function :
double funct1(double x){return (5*x + x*x);}

double funct2(double x){return (6*pow(x,4)-2*pow(x,3)+x-1);}

double funct3(double x){return (x*exp(pow(x,2)));}

int main()
{
    // Declare the value of x at which derivative is to be calculated

    // Calculating derivative of function 5x + x^2 at x=2
	double x1=2.0,h=0.00001;
    double fxd1 = (funct1(x1+h)-funct1(x1))/h;
    printf("\nThe value of derivate for 5x+x^2 at x=2 is = %.2f  ",fxd1);

    // Calculating derivative of function 6x^4 - 2x^3 + x - 1 at x=3
    double x2=3.0;
    double fxd2 = (funct2(x2+h)-funct2(x2))/h;
    printf("\nThe value of derivate for 6*pow(x,4)-2*pow(x,3)+x-1 at x=3 is = %.2f  ",fxd2); //595

    // Calculating derivative of function x*exp(x^2) at x=1
    double x3=1.0;
    double fxd3 = (funct3(x3+h)-funct3(x3))/h;
    printf("\nThe value of derivate for x*exp(x*x) at x=1 is = %.2f  ",fxd3);

	return 0;
}
