#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n, i, j, k, r=70;
	double mu, sigmasq, sum, u, sample, m_sum, sumsq, mean, var, m1, m2, llim_mean, ulim_mean, v1, v2, llim_var, ulim_var, mcount=0, vcount=0;
	printf("Enter the parameter of N(mu,sigmasq):\n");
	scanf("%lf %lf", &mu, &sigmasq);
	printf("Enter the size of sample:\n");
	scanf("%d", &n);
	srand(time(NULL));
	for(i=0;i<100;i++)
	{
		m_sum=0;
		sumsq=0;
		for(j=0;j<n;j++)
		{
			sum=0;
			for(k=0;k<r;k++)
			{
				sum+=rand()/(1.0+RAND_MAX);
			}
			u=(sum-(r/2))/sqrt(r/12);
			sample=u*sqrt(sigmasq)+mu;
			m_sum+=sample;
			sumsq+=sample*sample;
		}
		mean=m_sum/n;
		var=((sumsq/n)-mean*mean)*n/(n-1);
		m1=mean-(1.96*sqrt(sigmasq/n));
		m2=mean+(1.96*sqrt(sigmasq/n));
		llim_mean=llim_mean+m1;
		ulim_mean=ulim_mean+m2;
		v1=(n-1)*var/40.64;
		v2=(n-1)*var/13.11;
		llim_var=llim_var+v1;
		ulim_var=ulim_var+v2;
		if(m1<mu && m2>mu)
		{
			mcount++;
		}
		if(v1<sigmasq && v2>sigmasq)
		{
			vcount++;
		}
			
	}
	printf("95pc CI is given as:\n");
	printf("for popn mean = [%lf,%lf]\n", llim_mean/100, ulim_mean/100);
	printf("for popn var = [%lf,%lf]\n", llim_var/100, ulim_var/100);
	printf("Coverage prob:\n");
	printf("for popn mean = %lf\n", mcount/100);
	printf("for popn var = %lf\n", vcount/100);
	  
}