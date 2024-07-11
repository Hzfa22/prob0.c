/*Problem-15 Write a program to generate random sample from non-central t-distribution.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 30

double stnd_normal_rand()
{
	double r = 700;
	double sum = 0;
	for (int i = 0; i < r; i++)
	{
		sum += rand() / (1.0 + RAND_MAX);
	}

	return ((sum - r / 2) / sqrt(r / 12));
}

double normal_rand(double mu)
{
	return (stnd_normal_rand() + mu);
}

double central_chi(double n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += pow(stnd_normal_rand(), 2);
	}

	return (sum);
}

double non_central_T(double mu, double n)
{
	return (normal_rand(mu) / sqrt(central_chi(n) / n));
}

int main(void)
{
	srand(time(NULL));
	int i;
	double data[N];
	double mean = 0, variance = 0;

	printf("\nThe random numbers are:\n");

	// Finding the mean
	for (i = 0; i < N; i++)
	{
		data[i] = non_central_T(3, 7);
		printf("%.2f\t", data[i]);
		mean += data[i];
	}

	mean /= N;

	// Finding the variance
	for (i = 0; i < N; i++)
	{
		variance += (data[i] - mean) *(data[i] - mean);
	}

	variance /= N;

	double u = 3, n = 7;

	float Pmean = u* sqrt(n / 2) *tgamma((n - 1) / 2) / tgamma(n / 2);
	float Pvari = (n / 2) *(2 *(1 + u *u) / (n - 2) - u *u* pow(tgamma((n - 1) / 2) / tgamma(n / 2), 2));

	printf("\n\nThe Sample Mean: %.2f\n", mean);
	printf("The Sample Variance is: %.2f\n", variance);

	printf("\n\nThe population Mean: %.2f\n", Pmean);
	printf("The population Variance is: %.2f\n", Pvari);

	return 0;
}
