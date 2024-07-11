#include <stdio.h>
#include <math.h>

void mult(int n, double a[10][10], double b[10][10], double c[10][10])
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int i, j, k, n;
    double a[10][10], temp[10][10], c[10][10], flag = 0;
    printf("Enter the order of TPM.\n");
    scanf("%d", &n);
    printf("Enter the elements of Initial TPM.\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d]=", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
    }
    printf("Obtained TPM:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2lf\t", a[i][j]);
        }
        printf("\n");
    }
    mult(n, a, a, c);
    k = 1;
    while (k > 0 && flag != 3)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = c[i][j];
            }
        }
        mult(n, temp, temp, c);
        k++;
        flag = 0;
        for (i = 0; i < 1; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (fabs(c[i][j] - c[i + 1][j]) < 0.000001 && fabs(c[i + 1][j] - c[i + 2][j]) < 0.000001)
                {
                    flag += 1;
                }
            }
        }
        if (flag == 3)
        {
            k = -1;
        }
    }
    printf("Steady State matrix:\n");
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf\t", c[i][j]);
        }
    }
    return 0;
}
