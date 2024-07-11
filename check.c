#include<stdio.h>
#define N 4
int main()
{
    int i;
    float a[N];
    for(i=0;i<N;i++)
    {
        printf("a[%d]=", i);
        scanf("%f", &a[i]);
    }
    printf("%f", a[0]);
}