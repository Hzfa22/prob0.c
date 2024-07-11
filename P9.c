#include<stdio.h>
#include<math.h>

int main()
{
    int i, j, k, p, q, m;
    double A[10][10][10], G=0, rss=0, a[10], b[10], ab[10], ssa=0, ssb=0;
    printf("Enter the no. of levels of Factor A, i.e Watering Frequency.\n");
    scanf("%d", &p);
    printf("Enter the no. of levels of Factor B, i.e Sunlight Exposure.\n");
    scanf("%d", &q);
    printf("Enter the no. of observations per cell.\n");
    scanf("%d", &m);
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("Enter the obs. corr. to %d level of Factor A and %d level of Factor B.\n", i+1, j+1);
            for(k=0;k<m;k++)
            {
                printf("A[%d][%d][%d]=", i+1, j+1, k+1);
                scanf("%lf", &A[i][j][k]);
                G+=A[i][j][k];
                rss+=A[i][j][k]*A[i][j][k];
                a[i]+=A[i][j][k];
            }
        }
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            for(k=0;k<m;k++)
            {
                ssa+=a[i]*a[i]/(m*q);
            }
        }
    }
    for(j=0;j<q;j++)
    {
        for(i=0;i<p;i++)
        {
            for(k=0;k<m;k++)
            {
                b[j]+=A[i][j][k];
            }
        }
    }
    for(j=0;j<q;j++)
    {
        for(i=0;i<p;i++)
        {
            for(k=0;k<m;k++)
            {
                ssb+=b[j]*b[j]/(m*p);
            }
        }
    }
    for(k=0;k<m;k++)
    {
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
            {
                ab[j]+=A[i][j][k];
            }
        }
    }
}