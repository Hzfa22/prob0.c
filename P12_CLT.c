/*problem-12 Write a Program to generate random numbers from gamma distribution and verify central limit theorem.*/
#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include <time.h>

#define N 100

double exponential_rand(double scale)
{
  //return -log((double) rand() /(1.0+ RAND_MAX))/scale;
  return -log((double) rand() /(1.0+ RAND_MAX))/scale;
}

double gamma_rand(double scale, double shape)
{
  int i;
  double sum = 0;
  for (i = 0; i < shape; i++) {
    sum += exponential_rand(scale);
  }
  return sum;
}

int main()
{

  srand(time(NULL));
  int i;
  double data[N],z[N];
  double mean = 0, variance = 0;
  double mean_z = 0, variance_z = 0;

  printf("\nThe Random Numbers from G(shape=7,scale=2) are\n");

  //Finding the mean
  for (i = 0; i < N; i++)
  {
    data[i] = gamma_rand(2, 7);
    printf("%.2f \t", data[i]);
    mean += data[i];
  }
  mean /= N;

  // Finding the variance
  for (i = 0; i < N; i++)
  {
    variance += (data[i] - mean) * (data[i] - mean);
  }
  variance /= N;

  printf("\nMean: %.2f\n", mean);
  printf("Standard deviation: %.2f\n", variance);

  printf("\nThe standarised values are\n");


  for (i = 0; i < N; i++) {
    z[i]= (data[i]-mean)/(sqrt(variance));
    mean_z+=z[i];
    printf("%.2f \t", z[i]);
  }

  for (i = 0; i < N; i++)
  {
    variance_z += (z[i] - mean_z) * (z[i] - mean_z);
  }
  variance_z /= N;

  printf("\nMean of Z: %.2f\n", mean_z);
  printf("Standard deviation of Z: %.2f\n", variance_z);

  return 0;
}
