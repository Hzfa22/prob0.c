#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int i, j, k, r=70, n;
	double u, mu, sigmasq, sample[100], sum=0, sumsq=0, m_sum=0, mle_mean, mle_var, usum=0, usumsq=0, umean[100], uvar[100], smean, svar, umle_mean, umle_var;
	printf("Enter the sample size:\n");
	scanf("%d", &n);
	printf("Enter the parameter of Normal popn:\n");
	scanf("%lf %lf", &mu, &sigmasq);
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<r;j++)
		{
			sum+=rand()/(1.0+RAND_MAX);
		}
		u=(sum-(r/2))/sqrt(r/12);
		sample[i]=u*sqrt(sigmasq)+mu;
	}
	printf("generated sample:\n");
	for(i=0;i<n;i++)
	{
		printf("%.3lf\t", sample[i]);
	}
	//calc of mle mean, mle var.
	for(i=0;i<n;i++)
	{
		m_sum+=sample[i];
		sumsq+=sample[i]*sample[i];
	}
	mle_mean=m_sum/n;
	mle_var=(sumsq/n)-mle_mean*mle_mean;
	printf("\n mle of popn mean = %lf\nmle of popn var = %lf\n", mle_mean, mle_var);
	//calc of unbiased estimate of mle mean and mle var.
	for(i=0;i<100;i++)
	{
		usum=0;
		usumsq=0;
		for(j=0;j<n;j++)
		{
			sum=0;
			for(k=0;k<r;k++)
			{
				sum+=rand()/(1.0+RAND_MAX);
			}
			u=(sum-(r/2))/sqrt(r/12);
			sample[j]=u*sqrt(sigmasq)+mu;
			usum+=sample[j];
			usumsq+=sample[j]*sample[j];
		}
		umean[i]=usum/n;
		uvar[i]=(usumsq/n)-umean[i]*umean[i];
		smean+=umean[i];
		svar+=uvar[i];
	}
	umle_mean=smean/100;
	umle_var=svar/100;
	
	printf("Unbiased estimate:\nOf mle of mean = %lf\nOf mle of var = %lf\n", umle_mean, umle_var);
}