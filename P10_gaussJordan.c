/*Problem-10 Write a C program to compute the inverse of a given matrix using Gauss-Jordan Method.*/
#include <stdio.h>
#define N 3

// function to reduce matrix to reduced row echelon form
void reduceToRREF(float mat[N][N+N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        // Search for maximum in this column
        int maxEl = i;
        for (j = i+1; j < N; j++)
        {
            if (fabs(mat[j][i]) > fabs(mat[maxEl][i]))
                maxEl = j;
        }

        // Swap maximum row with current row (column by column)
        for (k = i; k < N+N; k++)
        {
            float tmp = mat[maxEl][k];
            mat[maxEl][k] = mat[i][k];
            mat[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (j = i+1; j < N; j++)
        {
            float factor = mat[j][i] / mat[i][i];
            for (k = i; k < N+N; k++)
                mat[j][k] -= factor * mat[i][k];
        }
    }

    // Make all rows above this one 0 in current column
    for (i = N-1; i >= 0; i--)
    {
        // Make all rows above this one 0 in current column
        for (j = i-1; j >= 0; j--)
        {
            float factor = mat[j][i] / mat[i][i];
            for (k = i; k < N+N; k++)
                mat[j][k] -= factor * mat[i][k];
        }
    }

    // Divide each row by its diagonal element
    for (i = 0; i < N; i++)
    {
        float div = mat[i][i];
        for (j = 0; j < N+N; j++)
            mat[i][j] /= div;
    }
}

// function to display the matrix
void display(float mat[N][N+N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N; j < N+N; j++)
            printf("%0.3f \t", mat[i][j]);
        printf("\n");
    }
}

// Driver code
int main()
{
    float mat[N][N+N] = {{3, 4, 1, 1, 0, 0},
                         {2, 1, 3, 0, 1, 0},
                         {4, 3, 1, 0, 0, 1}};

    //printf("\Original matrix is:\n");


    reduceToRREF(mat);

    printf("\nInverse matrix is:\n");
    display(mat);

    return 0;
}
