/*Problem-19 Write a Program to sort a set of string in dictionary order.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{

    int n,temp;
    char string1[30];

    printf("How many strings do you want to sort?\n");
    scanf("%d",&n);

    char Strings[n][30];

    printf("Enter the strings\n");

    for(int i=0; i<n; i++)
    {
     scanf("%s", Strings[i]);
    }

    printf("\nThe strings are \n");
    for(int i=0;i<n;i++)
    {
        printf("%s\n", Strings[i]);
    }

    printf("\nThe sorted strings are  \n");

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {

            if(strcmp(Strings[i],Strings[j])>0)
            {
                strcpy(string1,Strings[i]);
                strcpy(Strings[i],Strings[j]);
                strcpy(Strings[j],string1);
                break;
            }
			
		}
    }

        for(int i=0;i<n;i++)
    {
        printf("%s\n", Strings[i]);
    }

}
