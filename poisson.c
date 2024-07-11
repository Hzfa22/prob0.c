#include<stdio.h>
#include<math.h>

void poisson(double lambda)
{
    int x=0;
    double pprev, pnext, cdf;
    pprev=exp(-lambda);
    pnext=pprev;
    cdf=pprev;
    printf("Poisson Distribution generated using Recurrence relation for lambda = %f is given as-\n", lambda);
	printf("x\tP(x)\t\tF(x)\t\t1-F(x)");
    printf("\n\n");
    while(1-cdf >= 0.0001)
    {
        printf("%d\t%lf\t%lf\t%lf", x, pnext, cdf, 1-cdf);
        pnext=pnext*(lambda)/(double)(++x);
        cdf+=pnext;
        printf("\n");
    }
}
int main()
{
    double lambda;
    printf("Enter the Value of lambda.\n");
    scanf("%lf", &lambda);
    poisson(lambda);
    return 0;
}