#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

double std_norm()
{
    int i, r=70;
    double sum=0;
    for(i=0;i<r;i++)
    {
        sum+=rand()/(1.0+RAND_MAX);
    }
    return((sum-(r/2))/sqrt(r/12));
}
double norm(double mu, double sigmasq)
{
    return(std_norm()*sqrt(sigmasq)+mu);
}

int main()
{
    int i, n;
    double a[100], mu, sigmasq, sum=0, dsumsq=0, mean, var, sd, chi_u, chi_l, t, llim_mean, ulim_mean, llim_var, ulim_var;
    printf("Enter the popn mean and popn variance of the Normal population you want to generate.\n");
    scanf("%lf %lf", &mu, &sigmasq);
    printf("Enter the size of sample you want to generate.\n");
    scanf("%d", &n);
    //generation random sample of N(mu,sigmasq)
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        a[i]=norm(mu,sigmasq);
    }
    printf("Required random sample from N(%lf,%lf) is generated as:\n", mu, sigmasq);
    for(i=0;i<n;i++)
    {
        printf("%.3lf\t", a[i]);
    }
    //calculation of CI
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    mean=sum/n;
    for(i=0;i<n;i++)
    {
        dsumsq+=(a[i]-mean)*(a[i]-mean);
    }
    var=dsumsq/(n-1);
    sd=sqrt(var);
    printf("\nMean of the above sample = %lf\nVariance of the above sample = %lf\nStandard deviation of the above sample = %lf\n", mean, var, sd);
    printf("Enter the value of chi-square for prob=0.025 and df=%d(mean is known).\n", n);
    scanf("%lf", &chi_l);
    printf("Enter the value of chi-square for given probabiity = 0.975 and df=%d(mean is known).\n", n, n-1);
    scanf("%lf", &chi_u);
    printf("Enter the value of Z(variance is known) for given probability = 0.05.\n");
    scanf("%lf", &t);
    //CI of mean.
    llim_mean=mean-(t*sqrt(sigmasq))/sqrt(n);
    ulim_mean=mean+(t*sqrt(sigmasq))/sqrt(n);
    //CI of var.
    llim_var=((n-1)*var)/chi_l;
    ulim_var=((n-1)*var)/chi_u;
    printf("The 95pc CI for mean = [%.3lf,%.3lf]\n", llim_mean, ulim_mean);
    printf("The 95pc CI for variance = [%.3lf,%.3lf]", llim_var, ulim_var);
    //convergence prob.
    int k;
    double c_sum, c_dsumsq, c_mean[100], c_var[i], c_llim_mean[100], c_ulim_mean[100], c_llim_var[100], c_ulim_var[100];
    for(i=0;i<100;i++)
    {   
        c_sum=0;
        for(k=0;k<n;k++)
        {
            a[k]=norm(mu,sigmasq);
            c_sum+=a[k];
        }
        c_mean[i]=c_sum/n;
        c_llim_mean[i]=c_mean[i]-(t*sqrt(sigmasq))/sqrt(n);
        c_ulim_mean[i]=c_mean[i]+(t*sqrt(sigmasq))/sqrt(n);
    }
}