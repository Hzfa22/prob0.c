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
    int i, j, k, n, y;
    double a[10][10], temp[10][10], c[10][10], flag=0, e_cost;
    x:
    printf("Enter the order of TPM.\n");
    scanf("%d", &n);
    printf("Enter the elements of Initial TPM.\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]=", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
        
    }
    printf("Obtained TPM:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%.2lf\t", a[i][j]);
        }
        printf("\n");
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
        for (i=0;i<1;i++) 
        {
            flag=0;
            for (j=0;j<n;j++) 
            {
                if ((c[i][j]-c[i+1][j])< 0.000001 && (c[i+1][j]-c[i+2][j])<0.000001) 
            {
                flag += 1;
            }
            
            }
            
        }
        if(flag==3)
        {
            k=-1;
        }
    }
    printf("Steady State matrix:\n");
    for(i=0;i<1;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%.3lf\t", c[i][j]);
        }
    }
    e_cost=1000*c[0][0]+500*c[0][1];
    printf("\nExpected cost of hospital = %lf", e_cost);
    printf("\nFor another calculation.\nPress 1 else 0.\n");
    scanf("%d", &y);
    if(y==1)
    {
        goto x;
    }
    
}