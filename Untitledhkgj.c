#include<stdio.h>
#include<math.h>
double fn1 (double x)
{
double h;
h=pow(x,2)+x;
return(h);
}
double fn2 (double y)
{
double f;
f=y*exp(-y);
return(f);
}
double fn3 (double z)
{
	double g;
	z=exp((pow(z,2)));
	return(z);
}
double fn4 (double t)
{
	double e;
	e=exp(t)*log(t);
	return(e);
}
int main()
{
double h=0.00001;
double x, derivative_1,derivative_2,derivative_3,derivative_4;


derivative_1=(fn1(1+h)-fn1(1))/h;
derivative_2=(fn2(0.5+h)-fn2(0.5))/h;
derivative_3=(fn3(2+h)-fn3(2))/h;
derivative_4=(fn4(2+h)-fn4(2))/h;
printf("The derivative of %f\n",derivative_1);
printf("The derivative of %f\n",derivative_2);
printf("The derivative of %f\n",derivative_3);
printf("The derivative of %f\n",derivative_4);
return 0;
}
