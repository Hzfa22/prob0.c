#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

double func1(double x)
{
	return(pow(cos(x),2)*sqrt(1+pow(x,3)));
}
double func2(double x)
{
	return((exp(x)*sqrt(exp(x)-1))/(exp(x)+3));
}
double func3(double x)
{
	return(sqrt(x)/(sqrt(3-x)+sqrt(x)));
}
double func4(double x)
{
	return((sin(x)+cos(x))/(3+sin(2*x)));
}
double func5(double x)
{
	return(fabs(log(x)));
}

int main()
{
	int i, n;
	double x, rand_x, y, rand_y, l_limit, u_limit, width, sum=0, integral;
	printf("Enter the number of iteration.\n");
	scanf("%d", &n);
	//integrating func1.
	l_limit=-1;
	u_limit=2;
	width=u_limit-l_limit;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		rand_x=(double)rand()/(1+RAND_MAX);
		x=l_limit+width*rand_x;
		rand_y=(double)rand()/(1+RAND_MAX);
		y=func1(x);
		if(y<rand_y)
		{
			sum++;
		}
	}
	integral=(double)(sum/n)*width;
	printf("The integral of func1 is %f", integral);
}