/*Problem-13 Write a C program to print first alphabet of your name.*/
#include <stdio.h>

void alphabetA(int n) {
    int i, j,k,l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2*n-1; j++)
        {
            if(i + j == n )
                {
                    printf("*");
                    if(i!=n/2)
                    {
                        for(k=0,l=2*i-1;k<2*i;k++)
                        {
                            if(k==l)
                                printf("*");
                            else
                                printf(" ");
                        }
                    }
                    else
                    {
                        for(k=0;k<2*i;k++)
                            printf("*");

                    }

                }
            else
                {
                    printf(" ");
                }


        }
        printf("\n");


    }
}


int main() {
    printf("First alphabet of name:\n\n");
    alphabetA(8);
    return 0;
}
