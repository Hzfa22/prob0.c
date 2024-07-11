#include<stdio.h>
#include<math.h>

double mult(int m, int n, double a[10][10], double b[10][10], double c[10][10])
{
    int i, j, k;
    for(i=0;i<m;i++)
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
    int i, j, k, m, n;
    double a[10][10], det;
    printf("Enter the no. of rows and columns of matrix.\n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the matrix.\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    printf("\nYour entered matrix is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%lf\t", a[i][j]);
        }
        printf("\n");
    }
    //calculation of determinant.
    det=(a[0][0]*((a[1][1]*a[2][2])-(a[2][1]*a[1][2])))-(a[0][1]*((a[1][0]*a[2][2])-(a[2][0]*a[1][2])))+(a[0][2]*((a[1][0]*a[2][1])-(a[2][0]*a[1][1])));
    printf("\n%lf", det);


}