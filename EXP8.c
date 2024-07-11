#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define PI (3.141592653589793)
double f1(double x){
	return(pow(cos(x),2)*sqrt(1+pow(x,3)));
}
double f2(double x){
	return(sqrt(x)/(sqrt(3-x)+sqrt(x)));
}
double f3(double x){
	return((exp(x)*sqrt(exp(x)-1))/(exp(x)+3));
}
double f4(double x){
	return((sin(x)+cos(x))/(3+sin(2*x)));
}
double f5(double x){
	return(fabs(log(x)));
}
int main(){
  double n,u,x1[100],x2[100],x3[100],x4[100],x5[100],y1[100],y2[100],y3[100],y4[100],y5[100],a1,b1,a2,b2,a3,b3,a4,b4,a5,b5,i1,i2,i3,i4,i5;
  int i;
  a1=-1;b1=2; a2=1,b2=2;  a3=0,b3=log(5);a4=0,b4=PI/4; a5=exp(-1),b5=exp(1);
  for (i=0;i<100;i++){
	u=rand()/(1.0 + RAND_MAX);    
    x1[i]=a1+(b1-a1)*u ;x2[i]=a2+(b2-a2)*u ; x3[i]=a3+(b3-a3)*u ;x4[i]=a4+(b4-a4)*u ;
	x5[i]=a5+(b5-a5)*u ;
}
	double sum1,sum2,sum3,sum4,sum5;
	
	for (i=0;i<100;i++) {
		sum1+=f1(x1[i]);
		sum2+=f2(x2[i]);
		sum3+=f3(x3[i]);
		sum4+=f4(x4[i]);
		sum5+=f5(x5[i]);	
	}
	i1=(b1-a1)*sum1/100.0;
	i2=(b2-a2)*sum2/100.0;
	i3=(b3-a3)*sum3/100.0;
	i4=(b4-a4)*sum4/100.0;
	i5=(b5-a5)*sum5/100.0; 
printf(" Definite Integral of f1(x) is %lf\n ",i1);
printf(" Definite Integral of f2(x) is %lf\n ",i2);
printf(" Definite Integral of f3(x) is %lf\n ",i3);
printf(" Definite Integral of f4(x) is %lf\n ",i4);
printf(" Definite Integral of f5(x) is %lf\n ",i5);

  }

