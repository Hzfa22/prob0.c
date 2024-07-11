/*Problem-3 Write a program to find the product of two given Matrices.*/
#include<stdio.h>
int main() 
{
    int a[3][3], b[3][3], c[3][3], n, i, j, k;
    printf("Enter the value of N (N <= 3): ");
    scanf("%d", & n);
    printf("Enter the elements of Matrix-A: \n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", & a[i][j]);
        }
    }
    printf("Enter the elements of Matrix-B: \n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", & b[i][j]);
        }
    }
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
    printf("The product of the two matrices is: \n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
