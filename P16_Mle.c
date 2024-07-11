/*Problem-16 Write a program to find the mle under type-1 and type-2 censoring.*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
main()
{
    srand(time(NULL));
    float u[40], x[40], t, lbd, temp, sum, mle_1, mle_2;
    int n, m, i, j;
    printf("Enter the total number of observations, n=");
    scanf("%d",&n);
    printf("Enter the mean lifetime of exponential distribution, lambda=");
    scanf("%f",&lbd);
    printf("Random sample generated is given below:\n");
    for(i=0;i<n;i++)
    {
        u[i]=rand()/(1.0+RAND_MAX);
        x[i]=-log(1-u[i])/lbd;
        printf("%f ", x[i]);
    }
    printf("\n\nOrdered sample is given below:\n");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%f ", x[i]);
    }
    printf("\n\nType-I Censoring\n");
    printf("Enter the preassigned time, t=");
    scanf("%f",&t);
    printf("The censored data under Type-I censoring is:\n\n");
    sum=0;
    m=0;
    for(i=0;i<n;i++)
    {
        if(x[i]<t)
        {
            sum+=x[i];
            m++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(x[i]>t)
        {
            printf("%f ", x[i]);
        }
    }
    printf("\n\nNo. of failed items in given time t are found to be m=%d", m);
    mle_1=(sum+((n-m)*t))/m;
    printf("\nThe MLE of lambda under Type-I Censoring is %f\n\n", mle_1);
    printf("Type-II Censoring\n");
    printf("Enter the number of failed items, m=");
    scanf("%d",&m);
    printf("The censored data under Type-II censoring is:\n\n");
    sum=0;
    for(i=0;i<m;i++)
    {
        sum+=x[i];
    }
    for(i=m;i<n;i++)
    {
        printf("%f ", x[i]);
    }
    mle_2=(sum+((n-m)*x[m-1]))/m;
    printf("\n\nThe MLE of lambda under Type-II Censoring is %f",mle_2);
}