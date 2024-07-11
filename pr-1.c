#include<stdio.h>
#include<math.h>

void root(double a, double b, double c)
{
    double x1, x2, d, rex, imgx;
    d = b*b-4*a*c;
    if (d>0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf("The roots of the given equation is real and is given as X1=%f and X2=%f\n", x1, x2);
    }
    else if (d==0)
    {   x1=(-b/(2*a));
        printf("The roots of the given equaton are real and equal and is given as x1=%f and x2=%f\n", x1, x2);
    }
    else
    {
        rex=(-b)/(2*a);
        imgx=sqrt(-d)/(2*a);
        printf("The roots of the given equation are imaginary and is given as x1=%.2f+i%.2f and x2=%.2f-i%.2f\n", rex, imgx, rex, imgx);
    }
}
void verify(double a, double b, double c, double x1, double x2)
{
    int y1, y2;
    y1=a*x1*x1+b*x1+c;
    y2=a*x2*x2+b*x2+c;
    if (y1==0 && y2==0)
    {
        printf("The equation for the obtained root is verified and the value of error is %f", y1);
    }
    else
    {
        printf("The equation for the obtained root is not verified and the value of error is %f", y2);
    }
}

int main()
{
    double a, b, c, x1, x2;
    printf("Enter the coefficient of your quadratic equation of the form ax^2+bx+c=0\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    root(a , b, c);
    if (b*b-4*a*c>=0)
    {
        x1=(-b+sqrt(b*b-4*a*c))/(2*a);
        x2=(-b-sqrt(b*b-4*a*c))/(2*a);
        verify(a, b, c, x1, x2);
    }
    
    return 0;
}
        
        