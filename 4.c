#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() 
{
  int n, i;
  double x[100],sum=0,sumsqr=0,mean,variance;
  printf("Enter the no. of observations = ");
  scanf("%d",&n);
  printf("Enter each observation --\n");
  for (i=0;i<n;i++) {
    scanf("%lf",&x[i]);
    sum = sum+ x[i];
    sumsqr = sumsqr + pow(x[i],2);
  }
  mean = sum/n;
  variance = sumsqr/n - pow(mean,2);
  double t_tab = 2.16;
  double upper_limit = mean + (sqrt(variance/n)*t_tab);
  double lower_limit = mean - (sqrt(variance/n)*t_tab);
  printf("\nConfidence Interval for Mean is given by --\n(%.2f , %.2f)",lower_limit,upper_limit);
}