#include<stdio.h>
#include<math.h>
double mean(double a[], int n)
{
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    return(sum/n);
}
double var(double a[], int n)
{
    int i;
    double sumsq=0;
    for(i=0;i<n;i++)
    {
        sumsq+=a[i]*a[i];
    }
    return((sumsq/n)-mean(a,n)*mean(a,n));
}
double sd(double a[], int n)
{
    return(sqrt(var(a,n)));
}
double mode(double a[], int n)
{
    int i, j, maxcount=0, mo_val=0;
    for(i=0;i<n;i++)
    {
        int count=0;
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }
        }
        if(count>maxcount)
        {
            maxcount=count;
            mo_val=a[i];
        }
    }
    return(mo_val);
}

int main()
{
    int n;
    double a[]={39,29,48,55,50,41,61,69,30,42,58,41,48,50}, meanvalue, varvalue, sdvalue, modevalue;
    n=sizeof(a)/sizeof(a[0]);
    meanvalue=mean(a,n);
    varvalue=var(a,n);
    sdvalue=sd(a,n);
    modevalue=mode(a,n);
    printf("mean of the given data is %f\n", meanvalue);
    printf("var of the given data is %f\n", varvalue);
    printf("sd of the given data is %f\n", sdvalue);
    printf("mode of the given data is %f", modevalue);
}