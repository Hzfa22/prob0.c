#include <stdio.h>
#include <math.h>

double mult(int n, double a[10][10], double b[10][10], double c[10][10])
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
    return 0;
}

int main()
{
    int i, j, n, k = 1, ask;
    double a[10][10], c[10][10], temp[10][10], cost;
    x:
    printf("Order of TPM:\n");
    scanf("%d", &n);
    printf("Elements of TPM:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    mult(n, a, a, c);
    while (k > 0)
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
        int flag = 1; // Initialize the flag
        for (i = 0; i < n && flag; i++) // Check if flag is true
        {
            for (j = 0; j < n && flag; j++)
            {
                if (fabs(c[i][j] - temp[i][j]) >= 0.0000001)
                {
                    flag = 0; // If any element differs, set flag to false
                }
            }
        }
        if (flag == 1) // If all elements are within threshold, exit loop
        {
            k = -1;
        }
    }
    printf("Steady State:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf\t", c[i][j]);
        }
        printf("\n");
    }
    cost = 1000 * c[0][0] + 500 * c[0][1];
    printf("Expected Hospital cost = %lf\n", cost);
    printf("for another TPM, press 1, else 0:\n");
    scanf("%d", &ask);

    if (ask == 1)
    {
        goto x;
    }
    return 0;
}
