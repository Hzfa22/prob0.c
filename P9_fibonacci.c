/*Problem-9 Write a program to compute numbers in Fibonacci Series.*/
#include<stdio.h>

//Generating first n Fibonacci numbers :

int main()
{
	int i ,n, term1=0, term2=1;
	int next_term = term1+term2;
	printf("\nEnter the number of terms n = ");
	scanf("%d", &n);
	printf("\nThe first %d Fibonacci numbers are \n", n);
	printf("%d\n", term1);
	printf("%d\n", term2);
	for(i=3;i<=n;i++)
	{
		printf("%d\n", next_term);
		term1=term2;
		term2=next_term;
		next_term=term1+term2;
	}
	return(0);


}
