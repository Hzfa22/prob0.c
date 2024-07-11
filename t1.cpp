#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

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
double nor_var(double mu)
{
	return(std_nor()+mu);
}
double chi_sqr(double n)
{
	int i;
	double sum=0;
	for(i=0;i<n;i++)
	{
		sum+=pow(std_nor(),2);
	}
	return(sum);
}
double noncent_t(double mu, double n)
{
	return(nor_var(mu)/sqrt(chi_sqr(n)/n));
}

int main()
{
	int i;
	double var[N];
	printf("The random numbers generated from non-central t dist is\n");
	for(i=0;i<N;i++)
	{
		var[i]=noncent_t(3,7);
		printf("%.2f\t", var[i]);
	}
	
}

