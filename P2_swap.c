/*Problem-2 Write a C program to swap values of two variables with and without using temporary variables */
#include <stdio.h>

// This function swaps values referred by
// x and y, using temp variable
void swap1(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// This function swaps values referred by
// x and y, using sum of variable
void swap2(int *x, int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}

int main()
{
    int NUM1, NUM2;
    printf("Enter Value of x ");
    scanf("%d", &NUM1);
    printf("\nEnter Value of y ");
    scanf("%d", &NUM2);
    int operation;

    /* telling the user to choose any type of swap */
      printf("please choose how you want to swap numbers\n");
      printf("1- Using Temp variable \n");
      printf("2- Using sum of variables \n");
      scanf("%d",&operation);//input a
      switch(operation)
    {
        case 1:
            swap1(&NUM1, &NUM2);
            break;

        case 2:
            swap2(&NUM1, &NUM2);
            break;

        default:
            printf("wrong choice\n");
    }

    printf("\nAfter Swapping: x = %d, y = %d", NUM1, NUM2);
    return 0;
}
