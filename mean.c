
#include<conio.h>
#include<stdio.h>
#include<math.h>
int main()
{
int n;
float sum1 =0, var,std,arr[100], mean, sum2=0,cof;
printf("Enter size of the data \n");
scanf("%d",&n);
printf(" Enter data \n");
for(int i=0;i<n;i++)
scanf("%f",&arr[i]);
printf("Your data is: \n");
for(int i=0;i<n;i++)
printf("%f \t", arr[i]);

for(int i=0;i<n;i++)
{ sum1+= arr[i];
sum2+= arr[i]*arr[i];
	}
mean=sum1/n; 
var=(sum2/n)-(mean*mean); 
std=sqrt(var);
cof=(std/mean)*100;

printf(" \n mean of the numbers is %f and variance is %f", mean,var);
printf("\n standard deviation is %f and coefficient of variation is %f",std,cof);

getch();
  }
	



