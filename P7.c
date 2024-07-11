#include<stdio.h>
#include<math.h>

int main()
{
    int n, x;
    double p, q, po=1.0/3.0, qo=2.0/3.0, z_cal, z_tab=1.96, llim, ulim;
    printf("Here, we have to test the hypothesis of whether die is unbiased or not.\n");
    printf("Ho: p=po, where p is the probability of obs. occ. of 3 or 4.\n and po is probability of 3 or 4 for unbiased case.\n");
    printf("H1:p!=po, the die is biased\n");
    printf("Here, test statistic is given by:\nZcal=(p-po)/sqrt(pq/n), n is no. of throws of die.\n");
    printf("Test Criteria:\n We reject Ho when Zcal>Ztab=1.96, where Ztab=1.96 is the critical value of Z at alpha=0.05.\n");
    printf("Testing:\n\n");
    printf("No. of times die is thrown = \n");
    scanf("%d", &n);
    printf("No. of times 3 or 4 appears on die = \n");
    scanf("%d", &x);
    p=(double)x/n;
    q=1-p;
    printf("So, p is given as %d/%d = %lf\n", x, n, p);
    z_cal=fabs((p-po))/sqrt(po*qo/n);
    printf("Therefore, Zcal = %lf\n", z_cal);
    if(z_cal>z_tab)
    {
        printf("since, Zcal=%lf>Ztab=1.96, we reject our null hypothesis and conclude that the die is biased.\n");
    }
    else
    {
        printf("since, Zcal=%lf<Ztab=1.96, we fail to reject our null hypothesis and conclude that the die is unbiased.\n");
    }
    llim=p-3*sqrt(p*q/n);
    ulim=p+3*sqrt(p*q/n);
    printf("\nAnd confidence limits between the throw of 3 or 4 = [%.3lf,%.3lf]", llim, ulim);
    return 0;
}