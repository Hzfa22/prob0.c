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
	int i, j, rank, n;
	double a[10][10], m[10][10], m_inv[10][10], t[10][10], g[10][10], det, ag[10][10], aga[10][10], x;
	printf("Order of matrix:\n");
	scanf("%d", &n);
	printf("enter your matrix (A):\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	//obtaining minor
	printf("Minor:\n");
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			m[i][j]=a[i][j];
			printf("%.4lf\t", m[i][j]);
		}
		printf("\n");
	}
	det=m[0][0]*m[1][1] - m[0][1]*m[1][0];
	if(det!=0)
	{
		printf("since, det(minor) is not equal to zero, we can proceed further for calc. GI\n");
	}
	else
	{
		printf("det(minor) is zero, can't calc GI'");
	}
	t[0][0]=m[0][0];
	m[0][0]=m[1][1];
	m[1][1]=t[0][0];
	m[0][1]=-m[0][1];
	m[1][0]=-m[1][0];
	printf("Inverse of minor:\n");
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			m_inv[i][j]=(1/det)*m[i][j];
			printf("%lf\t", m_inv[i][j]);
			g[i][j]=m_inv[i][j];
		}
		printf("\n");
	}
	// putting all other elemnets as 0 in original matrix to get GI
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			g[i][n-1]=0;
		}
		else
		{
			for(j=0;j<n;j++)
			{
				g[i][j]=0;
			}
		}
	}
	printf("Generalized inverse (G) is given by:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf\t", g[i][j]);
		}
		printf("\n");
	}
	//verification
	mult(n,a,g,ag);
	mult(n,ag,a,aga);
	printf("A*G*A is given by:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf\t", aga[i][j]);
		}
	}
		printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(aga[i][j]==a[i][j])
			{
				x=0;
			}
		}
	}
	if(x==0)
	{
		printf("since, A*G*A=A, hence, verified");
	}

	
	
	
	
	
	
	
	
}