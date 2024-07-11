#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

double func1(double x)
{
    return(pow(cos(x),2)*sqrt(1+pow(x,3)));
}
double func2(double x)
{
    return((exp(x)*sqrt(exp(x)-1))/(exp(x)+3));
}
double func3(double x)
{
    return(sqrt(x)/(sqrt(3-x)-sqrt(x)));
}
double func4(double x)
{
    return((sin(x)+cos(x))/(3+sin(2*x)));
}
double func5(double x)
{
    return(fabs(log(x)));
}

int main()
{
    int i,n;
    double l_limit, u_limit, width, rand_x, x, rand_y, y, sum=0, integral, m;
    printf("Enter the number of iterations.\n");
    scanf("%d", &n);
    //calculating for function1.
    l_limit=-1;
    u_limit=2;
    width = u_limit-l_limit;
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        rand_x=(double)rand()/(1+RAND_MAX);
        x=l_limit+width*rand_x;
        rand_y=(double)rand()/(1+RAND_MAX);
        y=func1(x);
        if(rand_y<y)
        {
            sum++;
        }
    }
    integral=((double)sum/n)*width;
    printf("The value of integral of the F1 for the given limits is %f.\n", integral);
    //Calculating for function2.
    l_limit=0;
    u_limit=log(5);
    width=u_limit-l_limit;
    srand(time(NULL));
    sum=0;
    for(i=0;i<n;i++)
    {
        rand_x=(double)rand()/(1+RAND_MAX);
        x=l_limit+width*rand_x;
        rand_y=(double)rand()/(1+RAND_MAX);
        y=func2(x);
        if(y<rand_y)
        {
            sum++;
        }
    }
    integral=((double)sum/n)*width;
    printf("The value of integral of F2 for the given limits is %f.\n", integral);
    //Calculating for function3.
    l_limit=1;
    u_limit=2;
    width=u_limit-l_limit;
    srand(time(NULL));
    sum=0;
    for(i=0;i<n;i++)
    {
        rand_x=(double)rand()/(1+RAND_MAX);
        x=l_limit+width*rand_x;
        rand_y=(double)rand()/(1+RAND_MAX);
        y=func3(x);
        if(y<rand_y)
        {
            sum++;
        }
    }
    integral=((double)sum/n)*width;
    printf("The value of integral of F3 for the given limits is %f.\n", integral);
    //Calculating for function4.
    l_limit=0;
    u_limit=3.14/4;
    width=u_limit-l_limit;
    srand(time(NULL));
    sum=0;
    for(i=0;i<n;i++)
    {
        rand_x=(double)rand()/(1+RAND_MAX);
        x=l_limit+width*rand_x;
        rand_y=(double)rand()/(1+RAND_MAX);
        y=func4(x);
        if(y<rand_y)
        {
            sum++;
        }
    }
    integral=((double)sum/n)*width;
    printf("The value of the integral of F4 for the given limits is %f.\n", integral);
    //Calculating for function5.
    l_limit=1/2.718;
    u_limit=2.718;
    width=u_limit-l_limit;
    srand(time(NULL));
    sum=0;
    for(i=0;i<n;i++)
    {
        rand_x=(double)rand()/(1+RAND_MAX);
        x=l_limit+width*rand_x;
        rand_y=(double)rand()/(1+RAND_MAX);
        y=func5(x);
        if(y<rand_y)
        {
            sum++;
        }
    }
    integral=((double)sum/n)*width;
    printf("The value of the integral of F5 for the given limits is %f.\n", integral);



}