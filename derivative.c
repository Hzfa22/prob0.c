#include<stdio.h>
#include<conio.h>
#include<math.h>
float fn1( float x, float h)
{
	float k1, k2, dy1;
	k1=5*(x+h)+pow(x+h,2);
	k2=5*(x-h)+pow(x-h,2);
	dy1= k1-k2;
	return dy1 ;
}
float fn2 ( float x, float h)
{
	float k1, k2, dy2;
	k1=6*pow(x+h,4)-2*pow(x+h,3)+(x+h)-1;
	k2=6*pow(x-h,4)-2*pow(x-h,3)+(x-h)-1;
	dy2= k1-k2;
	return dy2 ;
}

float fn3 ( float x, float h)
{
	float k1, k2, dy3;
	k1= (x+h)*exp((x+h)*(x+h));
	k2= (x-h)*exp((x-h)*(x-h));
	dy3= k1-k2;
	return dy3 ;
}


int main()
{

	float xo,yo,zo, d1,d2,d3,h=0.000001;

	printf("Select the point for 5x+x^2 \n");
	scanf("%f",&xo);
    printf("Select the point for 6x^4-2x^3+x-1 \n");
	scanf("%f",&yo);
	printf("Select the point for xexp(x^2) \n");
	scanf("%f",&zo);
	
	d1=fn1(xo,h)/ (2*h);
	d2=fn2(yo,h)/ (2*h);
	d3=fn3(zo,h)/ (2*h);
	
	printf(" derivative of function1 is: %f ", d1);
	printf(" \n derivative of function2 is: %f ", d2);
	printf(" \n derivative of function3 is: %f ", d3);
	
getch();
}
