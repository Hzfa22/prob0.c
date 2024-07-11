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
	return 0;
}

int main()
{
	int i, j, n, k, ask, flag;
	double a[10][10], c[10][10], temp[10][10],  cost;
	x:
	printf("Order of TPM:\n");
	scanf("%d", &n);
	printf("Elements of TPM:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	mult(n,a,a,c);
	k=1;
	while(k>0)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				temp[i][j]=c[i][j];
			}
		}
		mult(n,temp,temp,c);
		k++;
		for(i=0;i<1;i++)
		{
			flag=0;
			for(j=0;j<n;j++)
			{
				if((c[i][j]-c[i+1][j])<0.0000001 &&(c[i+1][j]-c[i+2][j])<0.0000001)
				{
					flag+=1;
				}
			
			}
			
		}
		if(flag==3)
			{
				k=-1;
			}
	}
	printf("Steady State:\n");
	for(i=0;i<1;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf\t", c[i][j]);
		}
	}
	cost = 1000*c[0][0]+500*c[0][1];
	printf("Expected Hospital cost = %lf", cost);
	printf("for another TPM, press 1, else 0:\n");
	scanf("%d", &ask);
	
	if(ask==1)
	{
		goto x;
	}
	return 0;
	 
}