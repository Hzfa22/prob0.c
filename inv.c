#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i,j,k,n;
    
    /* Inputs */
    /* 1. Reading order of matrix */
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    /* 2. Reading Matrix */
    printf("Enter coefficients of Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%f", &a[i][j]);
        }
    }
    /* Augmenting Identity Matrix of Order n */
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                    a[i][j+n] = 1;
            }
            else
            {
                    a[i][j+n] = 0;
            }
        }
    }
    /* Applying Gauss Jordan Elimination */
    for(i=1;i<=n;i++)
    {
        if(a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for(j=1;j<=n;j++)
        {
            if(i!=j)
            {
                    ratio = a[j][i]/a[i][i];
                    for(k=1;k<=2*n;k++)
                    {
                        a[j][k] = a[j][k] - ratio*a[i][k];
                    }
            }
        }
    }
    /* Row Operation to Make Principal Diagonal to 1 */
    for(i=1;i<=n;i++)
    {
        for(j=n+1;j<=2*n;j++)
        {
            a[i][j] = a[i][j]/a[i][i];
        }
    }
    /* Displaying Inverse Matrix */
    printf("\nInverse Matrix is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=n+1;j<=2*n;j++)
        {
            printf("%0.3f\t",a[i][j]);
        }
        printf("\n");
    }
    
    return(0);
}
