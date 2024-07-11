/*Problem-5 Write a C program to find the product moment correlation coefficient for the given data.*/
#include<stdio.h>
#include<math.h>

// function that returns correlation coefficient.
float correlationCoefficient(int X[], int Y[], int n)
{

    int sum_X = 0, sum_Y = 0, sum_XY = 0;
    int squareSum_X = 0, squareSum_Y = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X.
        sum_X = sum_X + X[i];

        // sum of elements of array Y.
        sum_Y = sum_Y + Y[i];

        // sum of X[i] * Y[i].
        sum_XY = sum_XY + X[i] * Y[i];

        // sum of square of array elements.
        squareSum_X = squareSum_X + X[i] * X[i];
        squareSum_Y = squareSum_Y + Y[i] * Y[i];
    }

    // use formula for calculating correlation coefficient.
    float corr = (float)(n * sum_XY - sum_X * sum_Y)
                  / sqrt((n * squareSum_X - sum_X * sum_X)
                      * (n * squareSum_Y - sum_Y * sum_Y));

    return corr;
}

// Driver function
int main()
{

    int X[] = {13,23};
    int Y[] = {21,23};

    //Find the size of array.
    int n = sizeof(X)/sizeof(X[0]);

    //Function call to correlationCoefficient.
    printf("\n%f is the correlation coefficient ",correlationCoefficient(X, Y, n));
    return 0;
}
