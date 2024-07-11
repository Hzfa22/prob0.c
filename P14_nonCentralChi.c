/*problem-14 Write a program to draw random sample from non-central chi-square distribution.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 30

double stnd_normal_rand()
{
  //return -log((double) rand() /(1.0+ RAND_MAX))/scale;
  double r=70;
  double sum=0;

  for(int i=0; i< r; i++)
  {
      sum+=rand() /(1.0+ RAND_MAX);
  }
  return (sum-r/2)/(sqrt(r/12));
}

double normal_rand(double mu)
{
    return (stnd_normal_rand()+mu);
}

double non_central_chi_rand(int  lambda, int  n)
{
    double sum=0;
    for(int i=0;i<7;i++)
    {
        sum+=pow(normal_rand(sqrt(lambda/n)),2);
    }
    return(sum);
}


int main(void) {

    srand(time(NULL));
    int i;
    double data[N];
    double mean = 0, variance = 0;

    printf("\n The random numbers are\n", mean);

    //Finding the mean
      for (i = 0; i < N; i++)
      {
        data[i] = non_central_chi_rand(28,7);
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

    double n=7, l=28;



    float Pmean = n+l;
	float Pvari = 2*(n+2*l);

    printf("\n\nMean: %.2f\n", mean);
    printf("Variance is : %.2f\n", variance);

    printf("\n\nThe population Mean: %.2f\n", Pmean);
	printf("The population Variance is: %.2f\n", Pvari);


    //printf("%.2f",non_central_chi_rand(28,7));
    return 0;
}

