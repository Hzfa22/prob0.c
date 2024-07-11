#include<stdio.h>
#include<math.h>

double func1(double x)
{
    return(5*x+pow(x,2));
}
double func2(double x)
{
    return(6*pow(x,4)-2*pow(x,3)+x-1);
}
double func3(double x)
{
    return(x*exp(pow(x,2)));
}
int main()
{
    double der, h=0.00000001, x, y, yh;
    x=2;
    yh = func1(x + h);
    y = func1(x);
    der = (yh-y)/h;
    printf("The derivative of the first function is %f.\n", der);
    x=3;
    yh = func2(x + h);
    y = func2(x);
    der = (yh-y)/h;
    printf("The derivative of the second function is %f.\n", der);
    x=1;
    yh = func3(x + h);
    y = func3(x);
    der = (yh-y)/h;
    printf("The derivative of the third function is %f", der);

}