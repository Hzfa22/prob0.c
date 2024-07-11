#include<stdio.h>
#include<math.h>

double mult(int n, double a[10][10], double b[10][10], double c[10][10])
{
	int i, j, k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}

int main()
{
	int i, j, k, n;
	double a[10][10], q[10][10], a2[10][10], a3[10][10], a4[10][10], qa3[10][10];
	printf("Enter the size of tpm:\n");
	scanf("%d", &n);
	printf("Answer-1: Obtained TPM:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	printf("Enter the elements of initial vector:\n");
	for(i=0;i<1;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &q[i][j]);
		}
	}
	mult(n,a,a,a2);
	mult(n,a2,a,a3);
	mult(n,a3,a,a4);
	//mult. q and a3.
	for(i=0;i<1;i++)
	{
		for(j=0;j<n;j++)
		{
			qa3[i][j]=0;
			for(k=0;k<n;k++)
			{
				qa3[i][j]+=q[i][k]*a3[k][j];
			}
		}
	}
	printf("answer-2: %lf \n", a2[0][1]);
	printf("answer-3: %lf \n", a3[1][2]);
	printf("answer-4: %lf \n", a4[2][2]);
	printf("answer-5: %lf \t %lf \t %lf \t \n", qa3[0][0], qa3[0][1], qa3[0][2]);
}