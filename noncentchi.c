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
    return((sum-r/2)/sqrt(r/2));
}
double nor_var(double mu)
{
    //generating normal variates with mean mu.
    return(std_nor_var()+mu);
}
double non_cent_chi(double lbd, double n)
{
    //generating non-central chi-square distribution.
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        sum+=pow(nor_var(sqrt(lbd/n)),2);
    }
    return(sum);
}
int main()
{
    int i;
    double ran[N], sum=0, prod_sum=0, mean, var, cmean, cvar;
    srand(time(NULL));
    printf("The random numbers generated from non-central chi-square distribution is-\n");
    //displaying random numbers generated from non-central chi-square distribution.
    for(i=0;i<N;i++)
    {
        ran[i]=non_cent_chi(28,7);
        printf("%.2f\t", ran[i]);
    }
    //calculating mean of above samples
    for(i=0;i<N;i++)
    {
        sum+=ran[i];
    }
    mean=sum/N;
    //calculating variance of above samples
    for(i=0;i<N;i++)
    {
        prod_sum+=(ran[i]-mean)*(ran[i]-mean);
    }
    var=prod_sum/N;
    //calculating mean and variance using formula.
    double lbd=28, n=7;
    cmean=n+lbd;
    cvar=2*(n+2*lbd);
    printf("\nThe sample mean and sample variance obtained from the above data is %.2f and %.2f respectively.", mean, var);
    printf("\nThe mean and variance of non-central chi-square distribution using formula is %.2f and %.2f respectively.", cmean, cvar);

}