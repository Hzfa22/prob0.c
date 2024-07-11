#include<stdio.h>
#include<math.h>

int main()
{
    int i, n;
    double t, a[30], sum=0, sumsq=0, mean, sd, llim, ulim;
    printf("Enter the cardinal no. of your data.\n");
    scanf("%d", &n);
    printf("Enter the Data.\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=", i);
        scanf("%lf", &a[i]);
    }
    printf("Enter the value of student's t for given LOS and degree of freedom %d-1=%d.\n", n, n-1);
    scanf("%lf", &t);
    //calculation of mean and variance.
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        sumsq+=a[i]*a[i];
    }
    mean=sum/n;
    sd=sqrt((sumsq/n)-mean*mean);
    printf("Mean of the above data = %.3lf\n Variance of the data = %.3lf\n", mean, sd);
    //calculation of CI.
    //lower limit.
    llim=mean-(t*sd)/sqrt(n);
    //upper limit.
    ulim=mean+(t*sd)/sqrt(n);
    printf("95pc CI for mean = [%.3lf,%.3lf]", llim, ulim);
    return 0;
}