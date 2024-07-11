#include<stdio.h>
#include<math.h>

int main()
{
    double x1, x2, n1, n2, p1, p2, p, q, zcal, ztab=1.96;
    printf("Here, we have to test the hypothesis of difference of prop.\n");
    printf("Ho:P1=P2, i.e proportion of men and women in favour of proposal is same.\nH1:P1!=P2, i.e theu are not. \n");
    printf("Test Statistic:\nZcal=(p1-p2)/sqrt(P*Q((1/n1)+(1/n2)).\n");
    printf("Test Criteria:\nWe reject Ho, if Zcal>Ztab=1.96, where Ztab is the critical value of Z at alpha=0.05\n");
    printf("Enter the total no. of men in the area.\n");
    scanf("%lf", &n1);
    printf("Enter the total no. of women in the area.\n");
    scanf("%lf", &n2);
    printf("Enter the no. of men in favour of proposal:\n");
    scanf("%lf", &x1);
    printf("Enter the no. of women in favour of proposal:\n");
    scanf("%lf", &x2);
    p1=x1/n1;
    p2=x2/n2;
    p=(x1+x2)/(n1+n2);
    q=1-p;
    zcal=fabs((p1-p2)/sqrt(p*q*((1/n1)+(1/n2))));
    if(zcal>ztab)
    {
        printf("\nSince Zcal=%lf>Ztab=1.96, we reject the null hypothesis and conclude that proportion of men and women in favour of proposal are not same.\n", zcal);
    }
    else
    {
        printf("Since, Zcal=%lf<Ztab=1.96, we fail to reject the null hypothesis and conclude that the proportion of men and women in favour of the proposal are same.\n", zcal);
    }
    return 0;
}