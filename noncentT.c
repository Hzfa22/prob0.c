#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 30

double std_nor_var()
{
    //generating standard normal variates.
    int i, r=700;
    double sum=0;
    for(i=0;i<r;i++)
    {
        sum+=(double)rand()/(1+RAND_MAX);
    }
    return(((double)sum-(r/2))/sqrt(r/2));
}
double nor_var(double mu)
{
    //generating normal variate with mean mu and variance 1.
    return(std_nor_var()+mu);
}
double chi_sqr_var(int n)
{
    //generating chi-square variate.
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        sum+=pow(std_nor_var(), 2);
    }
    return(sum);
}
double non_centT(double mu, int n)
{
    //generating non-central t distribution.
    return(nor_var(mu)/sqrt(chi_sqr_var(n)/n));
}
int main()
{
    int i;
    double ran[N], sum=0, prod_sum=0, mean, variance;
    printf("The random numbers generated from non-central t distribution is--\n");
    srand(time(NULL));
    //displaying random numbers from non-central t distribution.
    for(i=0;i<N;i++)
    {
        ran[i]=non_centT(3,7);
        printf("%.2f\t", ran[i]);
    }
    //calculating sample mean.
    for(i=0;i<N;i++)
    {
        sum+=ran[i];
    }
    mean=sum/N;
    //calculating sample variance.
    for(i=0;i<N;i++)
    {
        prod_sum+=(ran[i]-mean)*(ran[i]-mean);
    }
    variance=prod_sum/N;
    printf("\nThe sample mean and sample variance of the above generated random numbers are %.2f and %.2f respectively.", mean, variance);
    //Calculation for popn mean and popn variance.
    double par=3, df=7, pmean, pvar;
    pmean=par*sqrt(df/2)*tgamma((df-1)/2)/tgamma(df/2);
    pvar=(df*(1+pow(par,2))/(df-2))-((pow(par,2)*df)/2)*pow(tgamma((df-1)/2)/tgamma(df/2), 2);
    printf("\nThe Population mean and population variance for the given non-central t distribution is %.2f and %.2f respectively.", pmean, pvar);

}