#include<stdio.h>
#include<math.h>

int main()
{
	int n, i, j, count, maxcount=0;
	double a[100], temp, sum=0, sumsq=0, mean, var, sd, cv, median, mode, q1, q3, min, max, range;
	printf("Enter the cardinal no. of obs:\n");
	scanf("%d", &n);
	printf("Enter your obs:\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=", i);
		scanf("%lf", &a[i]);
	}
	//calc. mean, var, sd, cv
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		sumsq+=a[i]*a[i];
	}
	mean=sum/n;
	var=(sumsq/n)-mean*mean;
	sd=sqrt(var);
	cv=100*(sd/mean);
	//calc mode
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(a[i]==a[j])
			{
				count++;
			}
		}
		if(count>maxcount)
		{
			maxcount=count;
			mode=a[i];
		}
	}
	//calc median
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	if(n%2==0)
	{
		median=(a[(n/2)-1]+a[n/2])/2;
	}
	else
	{
		median=a[((n+1)/2)-1];
	}
	printf("\n\nmean = %lf\nvar = %lf\nsd = %lf\ncv = %lf\nmode = %lf\nmedian = %lf", mean, var, sd, cv, mode, median);
}