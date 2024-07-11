/*Problem-18 Write a C program to calculate the product of two integers and check whether the product lies within the range of integers and also check for overflow and underflow.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{

    int a,b;
    printf("\n Input the two integers a and b \n");
    scanf("%d%d",&a,&b);

    printf("\n2The numbers you entered are \n");
    printf("a=%d\tb=%d",a,b);

    if(-36768<=a*b&&36767>=b*a)
        printf("\nThe product of numbers is in range and product is %d \n",a*b);
    else if(-36768>a*b)
        printf("\nThe product underflows and the products is %.2f\n",(float)a*b);
    else if(36767<a*b)
        printf("\nThe product overflows and the products is %.2f\n",(float)a*b);
    return 0;
}
