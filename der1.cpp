#include<stdio.h>
#include<math.h>

double func1(double x)
{
	return(5*x+x*x);
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
	double y, yh, h=0.00001, der;
	//calculating derivative of func1.
	double x=2;
	y=func1(x);
	yh=func1(x+h);
	der=(yh-y)/h;
	printf("The derivative of function 1 is %f\n", der);
	//calculating derivative of func2.
	x=3;
	y=func2(x);
	yh=func2(x+h);
	der=(yh-y)/h;
	printf("The derivative of function 2 is %f\n", der);
	//calculating derivative of function 3.
	x=1;
	y=func3(x);
	yh=func3(x+h);
	der=(yh-y)/h;
	printf("The derivative of function 3 is %f\n", der);
	
}