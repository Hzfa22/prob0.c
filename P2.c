#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>

#define N 25

double std_normal_var()
{
    int i;
    double sum=0, r=200;
    for(i=0;i<r;i++)
    {
        sum+=rand()/(1.0+RAND_MAX);
    }
    return((sum-(r/2))/sqrt(r/12));
}
double normal_var(double mu, double sigma)
{
    return(std_normal_var()*sqrt(sigma)+mu);
}

int main()
{
    int i,j,k;
    srand(time(NULL));
    double mu, sigma, sample[N], sum=0, sumsq=0, mle_m, mle_var, usum, usumsq, umean[100], uvar[100], sumean=0, suvar=0, umle_mean, umle_var;
    printf("Enter the mean and variance of the normal population from which you have to draw a sample of size 25.\n");
    scanf("%lf %lf", &mu, &sigma);
    for(i=0;i<N;i++)
    {
        sample[i]=normal_var(mu, sigma);
        printf("%.3f\t", sample[i]);
    }
    //Mle estimator population mean and population variance.
    for(i=0;i<N;i++)
    {
        sum+=sample[i];
        sumsq+=sample[i]*sample[i];
    }
    mle_m=sum/N;
    mle_var=sumsq/N-mle_m*mle_m;
    printf("\nThe MLE of population mean and population variance for N(%.2lf,%.2lf) is-\nMLE of P.mean = %.3f\nMLE of P.variance = %.3f", mu, sigma, mle_m, mle_var );
    //unbiased estimate of mle estimators.
    for(i=0;i<100;i++)
    {
        usum=0;
        usumsq=0;
        for(k=0;k<N;k++)
           {
                sample[k]=normal_var(mu,sigma);
                usum+=sample[k];
                usumsq+=sample[k]*sample[k];
           }
        umean[i]=usum/N;
        uvar[i]=(usumsq/N)-umean[i]*umean[i];
        sumean+=umean[i];
        suvar+=uvar[i];
    }
    umle_mean=sumean/100;
    umle_var=suvar/100;
    printf("\nThe expectation of the mle estimator of p.mean is %.3f\n and of p.var is %.3f\n", umle_mean, umle_var);
    if(round(umle_mean)==mu)
    {
        printf("The mle estimator of population mean is also unbiased.\n");
    }
    else
    {
        printf("The mle estimator of population mean is biased.\n");
    }
    if(round(umle_var)==sigma)
    {
        printf("The mle estimator of population variance is also unbiased.\n");
    }
    else
    {
        printf("The mle estimator of population variance is biased.\n");
    }
    return 0;
}