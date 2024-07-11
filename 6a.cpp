#include <stdio.h>
#include <math.h>

float mult(int n, float a[10][10],float b[10][10],float c[10][10]) {
  int i,j,k;
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      c[i][j] = 0;
      for (k=0;k<n;k++) {
        c[i][j] = c[i][j] + a[i][k]*b[k][j];
      }
    }
  }
}
int main() {
  int n,i,j,k;
  float P[10][10],Q[10][10],P2[10][10],P3[10][10],P4[10][10],Q3[10][10];
  printf("Enter the order of the TPM = ");
  scanf("%d",&n);
  printf("Enter the Elements of TPM row wise = \n");
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      scanf("%f",&P[i][j]);
    }
  }
  printf("Enter the Elements of Initial PM row wise = \n");
  for (i=0;i<1;i++) {
    for (j=0;j<n;j++) {
      scanf("%.3f",&Q[i][j]);
    }
  }
  mult (n,P,P,P2);
  printf("Matrix P^2 --\n");
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      printf("%.3f  ",P2[i][j]);
    }
    printf("\n");
  }
  mult (n,P2,P,P3);
  printf("Matrix P^3 --\n");
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      printf("%.3f  ",P3[i][j]);
    }
    printf("\n");
  }
  mult (n,P3,P,P4);
  printf("Matrix P^4 --\n");
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      printf("%.3f  ",P4[i][j]);
    }
    printf("\n");
  }
  mult (n,Q,P3,Q3);
  printf("Matrix Q*P^3 --\n");
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      printf("%.3f  ",Q3[i][j]);
    }
    printf("\n");
  }
  printf("\nAnswer-(i) = %.3f",P2[0][1]);
  printf("\nAnswer-(ii) = %.3f",P3[1][2]);
  printf("\nAnswer-(iii) = %.3f",P4[2][2]);
  printf("\nAnswer-(iv) = %.3f",Q3[0][0]);
  printf("\nAnswer-(v) = %.3f",Q3[0][1]);
  printf("\nAnswer-(vi) = %.3f",Q3[0][2]);
}