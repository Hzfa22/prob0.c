
//srishti kanojia//
#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
	int a[3][3],i,j;
	float det=0;
	printf("\nEnter elements of matrix: \n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		scanf("%d",&a[i][j]);
		
		printf("\n The matrix is \n");
		for(i=0;i<3;i++)
		{
			printf("\n");
		for(j=0;j<3;j++)
		printf("%d\t",a[i][j]);
		}
	for(i=0;i<3;i++)
		det=det+(a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3]-a[1][(i+2)%3]*a[2][(i+1)%3]));
	
	printf("\n Inverse of the matrix A :\n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
				printf("%.2f\t",((a[(i+1)%3][(j+1)%3]*a[(i+2)%3][(j+2)%3])-(a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/det);
		printf("\n");
}
}
