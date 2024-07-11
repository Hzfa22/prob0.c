#include<stdio.h>

#define size 100
int main()
{
    int i, j, k, Rb, Cb;
    int Ra, Ca;
    float a[size][size], b[size][size], prod[size][size];
    printf("Enter the number of rows of matrix A.\n");
    scanf("%d", &Ra);
    printf("Enter the number of coloumns of matrix A.\n");
    scanf("%d", &Ca);
    printf("Enter the number of rows of matrix B.\n");
    scanf("%d", &Rb);
    printf("Enter the number of coloumns of matrix B.\n");
    scanf("%d", &Cb);
    
    if(Ca!=Rb)
    {
        printf("Matrix A and Matrix B cannot be multiplied.\n");
    }
    else if(Ca==Rb)
	
	{
		printf("Enter the elements of Matrix A.\n");
		for(i=1;i<=Ra;i++)
	    {
	        for(j=1;j<=Ca;j++)
	        {
	            printf("a[%d][%d]=", i, j);
	            scanf("%f", &a[i][j]);
	        }
	    }
	    printf("Your Matrix A is-\n");
	    for(i=1;i<=Ra;i++)
	    {
	        for(j=1;j<=Ca;j++)
	        {
	            printf("%.2f\t", a[i][j]);
	        }
	        printf("\n");
	    }
	    printf("Enter the elements of Matrix B.\n");
	    for(i=1;i<=Rb;i++)
	    {
	        for(j=1;j<=Cb;j++)
	        {
	            printf("b[%d][%d]=", i, j);
	            scanf("%f", &b[i][j]);
	        }
	    }
	    printf("Your Matrix B is-\n");
	    for(i=1;i<=Rb;i++)
	    {
	        for(j=1;j<=Cb;j++)
	        {
	            printf("%.2f\t", b[i][j]);
	        }
	        printf("\n");
	    }
	    for(i=1;i<=Ca;i++)
	    {
	    	for(j=1;j<=Rb;j++)
	    	{
	    		prod[i][j]=0;
	    		for(k=1;k<=Ca;k++)
	    		{
	    			prod[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
		printf("The product of Matrix A and Matrix B is-\n");
		for(i=1;i<=Ca;i++)
		{
			for(j=1;j<=Rb;j++)
			{
				printf("%.2f\t", prod[i][j]);
			}
			printf("\n");
		}
    }
    return 0;

}


