/*Problem-6 Write a program to generate Poisson distribution using recurrence relation.*/
#include <stdio.h> // This line includes the standard input/output library, which contains functions such as printf() and scanf()
#include <math.h> // This line includes the math library, which contains functions such as exp()

// Function poisson() calculates the probability distribution for Poisson(λ)
void poisson(double lambda)
{
    printf("\n Probability distribution for Poisson(%.2f) \n",lambda);
    printf("---------------------------------------------------\n");
    int x = 0; // Initialize x to zero
    double pprev, pnext, cdf; // Declare variables pprev, pnext, cdf
    pprev = exp(-lambda); // Calculate the probability for the first x value
    pnext = pprev;
    cdf = pprev;
    printf(" X \t P(X=x) \t F(x) \t\t 1-F(x) "); // Print headers for the table
    printf("\n\n");
    while(1-cdf >= 0.0001) // Loop until the cumulative distribution function is less than 0.0001
    {
        printf(" %d \t %lf \t %lf \t %lf ", x, pnext, cdf, 1-cdf); // Print the values of x, P(X=x), F(x), and 1-F(x)
        pnext = (pnext) * (lambda/(double)++x); // Calculate the next probability
        cdf+=pnext; // Add the probability to the cumulative distribution function
        printf("\n");
    }
}

int main()
{
    float lambda;
    printf("\n Enter the value of lambda = "); // Prompt the user to enter the value of lambda
    scanf("%f",&lambda); // Read the value of lambda
    poisson(lambda); // Call the poisson() function
    printf("----------------------------------------------------"); // Print a separator
    return 0;
}
