#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<math.h>

#define N 30

double std_nor()
{
	int i, r=700;
	double sum=0;
	for(i=0;i<r;i++)
	{
		sum+=(double)rand()/(1+RAND_MAX);
	}
	return((sum-r/2)/sqrt(r/2));
}
double nor(double mu)
{
	return(std_nor()+mu);
}
double noncent_chi(double lambda, double n)
{
	int i;
	double sum=0;
	for(i=0;i<n;i++)
	{
		sum+=pow(nor(sqrt(lambda/n)),2);
	}
	return(sum);
}

int main()
{
	int i;
	double var[N], sum=0, sumsqr=0, smean, svar, pmean, pvar;
	printf("The random numbers generated from non-central chi square distribution is\n");
	for(i=0;i<N;i++)
	{
		var[i]=noncent_chi(28,7);
		printf("%.2f\t", var[i]);
	}
	
	for(i=0;i<N;i++)
	{
		sum+=var[i];
		sumsqr+=var[i]*var[i];
	}
	smean=sum/N;
	svar=(sumsqr/N)-smean*smean;
	printf("\nThe sample mean and sample variance is given as %f and %f respectively.\n", smean, svar);
	double lambda=28;
	double n=7;
	pmean=n+lambda;
	pvar=2*(n+2*lambda);
	printf("The popn mean and var is %f and %f respectively.\n", pmean, pvar);
	
	
	
}
