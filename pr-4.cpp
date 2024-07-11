#include<stdio.h>
#include<math.h>

int main()
{
	int i, n;
	double sum=0, sumsq=0, mean, var, a[100], llim, ulim, ttab;
	printf("Enter cardinal no. of obs.:\n");
	scanf("%d", &n);
	printf("Enter Obs.:\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=", i);
		scanf("%lf", &a[i]);
	}
	//calc. of mean and var.
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		sumsq+=a[i]*a[i];
	}
	mean=sum/n;
	var=(sumsq/n)-mean*mean;
	ttab=2.16;
	llim=mean-(ttab*sqrt(var/n));
	ulim=mean+(ttab*sqrt(var/n));
	printf("\n95pc CI for popn mean: [%lf,%lf].", llim, ulim);
}