/*Problem-11 Write a program to calculate spearman's rank correlation coefficient.*/
#include <stdio.h>
#include <math.h>

#define N 10

void printArray(float arr[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    printf("%.2f ", arr[i]);
  }
  printf("\n\n");
}

void rankify(float X[], int size, float Rank_X[]) 
{
  for (int i = 0; i < size; i++) 
  {
    int r = 1, s = 1;

    for (int j = 0; j < i; j++) 
    {
      if (X[j] < X[i]) r++;
      if (X[j] == X[i]) s++;
    }

    for (int j = i + 1; j < size; j++) 
    {
      if (X[j] < X[i]) r++;
      if (X[j] == X[i]) s++;
    }

    Rank_X[i] = size-(r + (s - 1) * 0.5)+1;
  }
}

float correlationCoefficient(float X[], float Y[], int size) 
{
  float sum_X = 0, sum_Y = 0, sum_XY = 0;
  float squareSum_X = 0, squareSum_Y = 0;

  for (int i = 0; i < size; i++) 
  {
    sum_X += X[i];
    sum_Y += Y[i];
    sum_XY += X[i] * Y[i];
    squareSum_X += X[i] * X[i];
    squareSum_Y += Y[i] * Y[i];
  }

  float corr = (float)(size * sum_XY - sum_X * sum_Y) /
               sqrt((size * squareSum_X - sum_X * sum_X) *
                    (size * squareSum_Y - sum_Y * sum_Y));

  return corr;
}

int main() 
{

  float X[N] = {68,64,75,50,64,80,75,40,55,64};
  float Y[N] = {62,58,68,45,81,60,68,48,50,70};

  float rank_x[N];
  float rank_y[N];

  rankify(X, N, rank_x);
  rankify(Y, N, rank_y);

  printf("Vector X\n");
  printArray(X, N);

  printf("Rankings of X\n");
  printArray(rank_x, N);

  printf("Vector Y\n");
  printArray(Y, N);

  printf("Rankings of Y\n");
  printArray(rank_y, N);

  printf("Spearman's Rank correlation:\n");
  printf("%f\n", correlationCoefficient(rank_x, rank_y, N));

  return 0;
}
