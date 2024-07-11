#include<stdio.h>
#include<math.h>

void poisson(double lambda)
{
	int x=0;
	double pprev, pnext, cdf;
	pprev=exp(-lambda);
	pnext=pprev;
	cdf=pprev;
	printf("The poisson distribution with parameter %f is give as\n", lambda);
	printf("\n\n");
	printf("x\tP(X=x)\t\tF(X=x)\t\t1-F(X=x)\n");
	while(1-cdf>=0.0001)
	{
		printf("%d\t%lf\t%lf\t%lf", x, pnext, cdf, 1-cdf);
		pnext=pnext*(lambda)/(double)(++x);
		cdf+=pnext;
		printf("\n");
	}
}
int main()
{
	float lambda;
	printf("enter the value of lambda.\n");
	scanf("%f", &lambda);
	poisson(lambda);
	return 0;
}