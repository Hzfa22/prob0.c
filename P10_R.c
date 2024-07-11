/*finding inverse using standard method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3 //size of matrix

void printMatrix(double mat[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%.2lf\t ", mat[i][j]);
        }
        printf("\n");
    }
}

double determinant(double mat[N][N], int n) 
{
    double det = 0;
    if (n == 2) 
    {
        return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
    } 
    else 
    {
        double submat[N][N];
        for (int x = 0; x < n; x++) 
        {
            int subi = 0;
            for (int i = 1; i < n; i++) 
            {
                int subj = 0;
                for (int j = 0; j < n; j++) 
                {
                    if (j == x) 
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            det += (pow(-1, x) * mat[0][x] * determinant(submat, n - 1));
        }
    }
    return det;
}


void getAdjoint(double mat[N][N], double adj[N][N]) {
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    double submat[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int subi = 0;
            for (int k = 0; k < N; k++) {
                if (k == i) {
                    continue;
                }
                int subj = 0;
                for (int l = 0; l < N; l++) {
                    if (l == j) {
                        continue;
                    }
                    submat[subi][subj] = mat[k][l];
                    subj++;
                }
                subi++;
            }
            adj[j][i] = pow(-1, i + j) * determinant(submat, N - 1);
        }
    }
}

void invertMatrix(double mat[N][N]) {
    double det = determinant(mat, N);
    double adj[N][N];
    getAdjoint(mat, adj);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j] = adj[i][j] / det;
        }
    }
    printf("Inverse matrix: \n");
    printMatrix(adj);
}



int main()
{

    double mat[3][3] = {{3,4,1},{2,1,3},{4,3,1}};
    printf("The original matrix is\n");
    printMatrix(mat);

    printf("\nThe inverted matrix is\n");
    invertMatrix(mat);

    return 0;
}


