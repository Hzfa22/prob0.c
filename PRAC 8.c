//SRISHTI KANOJIA//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159265
float func1(float x)
{
float f1_x;
f1_x=pow(cos(x),2)*sqrt(1+pow(x,3));
return f1_x;
}
float func2(float x)
{
float f2_x;
f2_x=sqrt(x)/(sqrt(3-x)+sqrt(x));
return f2_x;
}
float func3(float x)
{
float f3_x;
f3_x=(exp(x)*sqrt(exp(x)-1))/(exp(x)+3);
return f3_x;
}
float func4(float x)
{
float f4_x;
f4_x=(sin(x)+cos(x))/(3+sin(2*x));
return f4_x;
}
float func5(float x)
{
float f5_x;
f5_x=fabs(log(x));
return f5_x;
}
main()
{
int i, n, a1, b1, a2, b2, a3, a4;
float b3, b4, a5, b5, sum1, sum2, sum3, sum4, sum5, igl1, igl2, igl3, igl4, igl5;
float u[1500], x1[1500], x2[1500], x3[1500], x4[1500], x5[1500];
sum1=sum2=sum3=sum4=sum5=0;
a1=-1; b1=2; a2=1; b2=2; a3=0; b3=log(5); a4=0; b4=pi/4; a5=1/exp(1); b5=exp(1);
printf("Enter the no. of random numbers to be generated: ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
u[i]=rand()/(1.0+RAND_MAX);
x1[i]=a1+((b1-a1)*u[i]);
x2[i]=a2+((b2-a2)*u[i]);
x3[i]=a3+((b3-a3)*u[i]);
x4[i]=a4+((b4-a4)*u[i]);
x5[i]=a5+((b5-a5)*u[i]);
sum1=sum1+func1(x1[i]);
sum2=sum2+func2(x2[i]);
sum3=sum3+func3(x3[i]);
sum4=sum4+func4(x4[i]);
sum5=sum5+func5(x5[i]);
}
igl1=sum1*((b1-a1)/(float)n);
igl2=sum2*((b2-a2)/(float)n);
igl3=sum3*((b3-a3)/(float)n);
igl4=sum4*((b4-a4)/(float)n);
igl5=sum5*((b5-a5)/(float)n);
printf("\nThe value of integral for the function f1(x) is %f", igl1);
printf("\nThe value of integral for the function f2(x) is %f", igl2);
printf("\nThe value of integral for the function f3(x) is %f", igl3);
printf("\nThe value of integral for the function f4(x) is %f", igl4);
printf("\nThe value of integral for the function f5(x) is %f", igl5);
}
