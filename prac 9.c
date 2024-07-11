#include<stdio.h>
int main()
{
	int i,n,first=0,second=1,third;
	printf("\n Enter the value of number of terms:");
	scanf("%d",&n);
	printf("\nFibonacci series is:");
	printf("\n%d,%d",first,second);
	for(i=2;i<n;i++)
	{
		third=first+second;
		printf(",%d",third);
		first=second;
		second=third;
	}
}
