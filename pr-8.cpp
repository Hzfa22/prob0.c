#include<stdio.h>
#include<math.h>

int main()
{
	double x1, x2, n1, n2, p1, p2, P, zcal, ztab=1.96;
	printf("No. of men in sample:\n");
	scanf("%lf", &n1);
	printf("No. of women in sample:\n");
	scanf("%lf", &n2);
	printf("No. of men in favour in sample:\n");
	scanf("%lf", &x1);
	printf("No. of women in favour in sample:\n");
	scanf("%lf", &x2);
	p1=x1/n1;
	p2=x2/n2;
	P=((x1+x2)/(n1+n2));
	zcal=((p1-p2)/sqrt(P*(1-P)*((1/n1)+(1/n2))));
	printf("Test:\n\nHo:P1=P2 against H1:P1!=P2\n\nTest Statistic: Zcal=(p1-p2)/sqrt((PQ)*((1/n1)+(1/n2)))\n\nTest Criteria: Reject Ho, when |Zcal|>Ztab=1.96 at 0.05 LOS.");
	printf("\nObtain |Zcal|=%lf", fabs(zcal));
	if(fabs(zcal)>ztab)
	{
		printf("\n\nand therefore, we reject the null hypothesis.");
	}
	else
	{
		printf("\nand therefore, We accept Ho.");
	}
}	