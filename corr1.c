#include<stdio.h>
#include<math.h>

int main()
{
	int i,n;
	float x[100], y[100];
	double sum_x=0, sum_y=0, sumsqr_x=0, sumsqr_y=0, sum_xy=0, mean_x, mean_y, meansqr_x, meansqr_y, mean_xy, corr_coeff;
	printf("Enter the cardinal number of your observation of x and y.\n");
	scanf("%d", &n);
	printf("Enter your observations of x variate.\n");
	for(i=1;i<=n;i++)
	{
		printf("x[%d]=", i);
		scanf("%f", &x[i]);
	}
	printf("Enter your observations of y variate.\n");
	for(i=1;i<=n;i++)
	{
		printf("y[%d]=", i);
		scanf("%f", &y[i]);
	}	
	
	for(i=1;i<=n;i++)
	{
		sum_x+=x[i];
		sum_y+=y[i];
		sumsqr_x+=x[i]*x[i];
		sumsqr_y+=y[i]*y[i];
		sum_xy+=x[i]*y[i];
	}
	mean_x=sum_x/n;
	mean_y=sum_y/n;
	meansqr_x=sumsqr_x/n;
	meansqr_y=sumsqr_y/n;
	mean_xy=sum_xy/n;
	
	corr_coeff=(mean_xy-mean_x*mean_y)/sqrt((meansqr_x-mean_x*mean_x)*(meansqr_y-mean_y*mean_y));
	printf("\nThe correlation coefficient between x and y variates is %f.", corr_coeff);
}