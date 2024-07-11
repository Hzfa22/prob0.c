#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, k, n, r=70;
    double mu, sigmasq, z, sample, sum, m_sum, v_sumsq, mean, var, llim_m, ulim_m, llim_v, ulim_v, m1, m2, v1, v2, m_count=0, v_count=0;
    printf("Enter the parameter of N(mean,variance) population from which you want to generate a random sample.\n");
    scanf("%lf %lf", &mu, &sigmasq);
    printf("Enter the size of sample you want to generate.\n");
    scanf("%d", &n);
    srand(time(NULL));
    for(k=0;k<100;k++)
    {
        m_sum=0;
        v_sumsq=0;
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<r;j++)
            {
                sum+=rand()/(1.0+RAND_MAX);//generating uniform random variable
            }
            z=(sum-(r/2))/sqrt(r/12);//generating standard normal
            sample=z*sqrt(sigmasq)+mu;//generating N(mu,sigmasq)
            m_sum+=sample;
            v_sumsq+=sample*sample;
        }
        mean=m_sum/n;
        var=((v_sumsq/n)-mean*mean)*n/(n-1);
        m1=mean-(1.96*sqrt(sigmasq/n));
        m2=mean+(1.96*sqrt(sigmasq/n));
        llim_m=llim_m+m1;
        ulim_m=ulim_m+m2;
        v1=(n-1)*var/40.64;
        v2=(n-1)*var/13.11;
        llim_v=llim_v+v1;
        ulim_v=ulim_v+v2;
        if(m1<-5 && m2>-5)
        {
            m_count=m_count+1;
        }
        if(v1<0.5 && v2>0.5)
        {
            v_count=v_count+1;
        }
    }
    printf("95pc Confidence Intervals using the random sample of size 25 is given as:\n");
    printf("For population mean = [%lf,%lf]\n", llim_m/100, ulim_m/100);
    printf("For population variance = [%lf,%lf]\n", llim_v/100, ulim_v/100);
    printf("And Convergence probability is given as:\n");
    printf("For CI of population mean = %lf\n", m_count/100);
    printf("For CI of population variance = %lf", v_count/100);

    return 0;
}