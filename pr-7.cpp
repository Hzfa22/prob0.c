#include<stdio.h>
#include<math.h>

int main()
{
	double x, n, p, P, zcal, ztab=3.0, llim, ulim;
	printf("No. of times dice is thrown.\n");
	scanf("%lf", &n);
	printf("No. of times 3 or 4 comes up.\n");
	scanf("%lf", &x);
	p=x/n;
	P=1.0/3.0;
	zcal=(x-n*P)/sqrt(n*P*(1-P));
	printf("\nTest:\nHo:p=1/3=P against H1:p!=1/3.\nTest Statistic: Zcal=(x-n*P)/sqrt(n*P*(1-P)).\nTest Criteria: Reject Ho when |Zcal|>3.\n");
	if(fabs(zcal)>ztab)
	{
		printf("Since, |Zcal|=%lf > 3, therefore, we reject Ho.\n", fabs(zcal));
		llim=p-sqrt((p*(1-p))/n);
		ulim=p+sqrt((p*(1-p))/n);
		printf("\n Confidence limits is [%lf,%lf]", llim, ulim);
	}
	else
	{
		printf("Since, |Zcal|=%lf < 3, therefore, we accept Ho.\n", fabs(zcal));
		llim=P-sqrt((P*(1-P))/n);
		ulim=P+sqrt((P*(1-P))/n);
		printf("\n Confidence limits is [%lf,%lf]", llim, ulim);
	}
	 
}