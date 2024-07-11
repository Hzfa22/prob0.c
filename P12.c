#include<stdio.h>
#include<math.h>

double mult(int p, int q, double A[10][10], double B[10][10], double C[10][10])
{
    int i, j, k;
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            C[i][j]=0;
            for(k=0;k<q;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

int main()
{
    int p, q, i, j;
    double A[10][10], I[10][10];
    printf("Enter the no. rows of your matrix.\n");
    scanf("%d", &p);
    printf("Enter the no. column of your matrix.\n");
    scanf("%d", &q);
    printf("Enter the elements of your matrix row-wise.\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", A[i][j]);
        }
    }
    printf("Enter the elements of the identity matrix row-wise.\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", I[i][j]);
        }
    }
    printf("You've entered the following matrix.\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%lf\t");
        }
        printf("\n");
    }
    printf("And your entered identity matrix.\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%lf\t");
        }
        printf("\n");
    }
    printf("The Characteristic function is given by\n")


}