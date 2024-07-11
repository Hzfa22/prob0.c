#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n, N, i, j, r=70;
	double u, sum, srswr[100], srswor[100], popn[100], mean, sumsq=0, var;
	printf("Size of population N(0,1):");
	scanf("%d", &N);
	printf("Population is generated as:\n");
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=0;j<r;j++)
		{
			sum+=rand()/(1.0+RAND_MAX);
		}
		popn[i]=(sum-(r/2))/sqrt(r/12);
		printf("%.3lf\t", popn[i]);
	}
	sum=0;
	for(i=0;i<N;i++)
	{
		sum+=popn[i];
		sumsq+=popn[i]*popn[i];
	}
	mean=sum/N;
	var=(sumsq/N)-mean*mean;
	printf("\n%lf\n%lf", mean, var);
	//generating srswor
	printf("\n Size of sample you want to generate.\n");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		j=rand()%(N-i);
		srswor[i]=popn[j];
		popn[j]=popn[N-i-1];
		printf("%.3lf\t", srswor[i]);
	}
	//generating srswr
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		j=rand()%(N);
		srswr[i]=popn[j];
		printf("%.3lf\t", srswr[i]);
	}
	
}