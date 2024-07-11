#include<stdio.h>
#include<math.h>

double mult(int n, double a[10][10], double b[10][10], double ab[10][10])
{
	int i, j, k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ab[i][j]=0;
			for(k=0;k<n;k++)
			{
				ab[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}

 
int main()
{
	int i, j, n, x;
	double a[10][10], a2[10][10], a3[10][10], a4[10][10], I[10][10], result[10][10];
	printf("order of matrix:\n");
	scanf("%d", &n);
	printf("enter the matrix A:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	printf("\nenter the Identity matrix I:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &I[i][j]);
		}
	}
	printf("Characteristic function:\nlbd^4-8lbd^3+21lbd^2-20lbd+5=0\n");
	mult(n,a,a,a2);
	mult(n,a2,a,a3);
	mult(n,a3,a,a4);
	
	printf("On putting A in char. function we get:\nA^4-8A^3+21A^2-20A+5=0\n, which is obtained as\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			result[i][j]=a4[i][j]-8*a3[i][j]+21*a2[i][j]-20*a[i][j]+5*I[i][j];
			printf("%.5lf\t", result[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(result[i][j]==0)
			{
				x=0;
			}
			else
			{
				x=1;
			}
		}
	}
	if(x==0)
	{
		printf("\nhence, cayley-hamilton theorem satisfied.\n");
	}
	else
	{
		printf("\nnot satisfied");
	}

	
}