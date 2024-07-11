#include<stdio.h>
#include<math.h>

int main()
{
	int i, j, k, m, n, r=1;
	double A[10][10], X[10], X_new[10], lbd;
	printf("no. of rows and column resp. of A matrix:\n");
	scanf("%d %d", &m, &n);
	printf("no. of rows of X vector:\n");
	scanf("%d", &n);
	printf("Enter elements of A matrix.\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &A[i][j]);
		}
	}
	printf("Enter elements of X vector:\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf", &X[i]);
	}
	do
	{
		for(i=0;i<m;i++)
		{
			X_new[i]=0;
			for(j=0;j<n;j++)
			{
				X_new[i]+=A[i][j]*X[j];
			}
		}
		lbd=fabs(X_new[0]);
		for(i=0;i<m;i++)
		{
			if(fabs(X_new[i])>lbd)
			{
				lbd=fabs(X_new[i]);
			}
		}
		for(i=0;i<m;i++)
		{
			X[i]=(1/lbd)*X_new[i];
		}
		printf("Iteration-%d\n", r);
		printf("Dominant Eigen value = %lf\n", lbd);
		printf("Eigen vector:\n");
		for(i=0;i<m;i++)
		{
			printf("%lf\n", X[i]);
		}
		r++;
	}
	while(r<=5);
	
}