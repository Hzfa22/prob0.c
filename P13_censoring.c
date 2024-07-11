/*Censoring*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
  float u,x[300],t,s,temp,sum=0.0;
  int n,r,i,j,ch,m=0;

  printf("\n Enter the total number of observations put on life test (n) : ");
  scanf("%d",&n);
  printf("\n Enter the mean life of the observations (sigma) : ");
  scanf("%f",&s);


  printf("\n The generated values are  : \n\t");
  for(i=0; i<n; i++) {
    u=rand()/(1.0+RAND_MAX);
    x[i]=-1*(log(1-u))*s;
    printf("%f\t",x[i]);
  }

  for(i=0; i<n-1; i++) {
    for(j=0; j<n-i-1; j++) {
      if(x[j] > x[j+1]) {
        temp = x[j];
        x[j] = x[j+1];
        x[j+1] = temp;
      }
    }
  }

  printf("\n The generated values in ascending order are  : \n\t");
    for(i=0; i<n; i++) {
    printf("%f\t",x[i]);
  }




  printf("\n For Type-I Censoring enter 1\n For Type-II Censoring enter 2\n Enter 0 to exit\n");
  start: printf("\n Enter your choice: ");
  scanf("%d",&ch);
  switch(ch) {
    case 1: printf("\n Type-I Censoring\n");
    printf("\n Enter the preassigned time t0 : ");
    scanf("%f",&t);
    printf("\n The censored data under Type-I censoring is :\n\n\t");
    sum=0.0;
    m=0;
    for(i=0; x[i]<t; i++) {
      printf("%f\t",x[i]);
      sum += x[i];
      m++;
    }
    sum = (sum + (n-m)*t)/m;
    printf("\n\n The MLE of sigma under Type-I Censoring is : %f\n\n\n", sum);
    goto start;
    case 2: printf("\n Type-II Censoring\n");
    printf("\n Enter the number of items that have failed : ");
    scanf("%d",&r);
    printf("\n The censored data under Type-II censoring is :\n\n\t");
    sum=0.0;
    for(i=0; i<r; i++) {
      printf("%f\t",x[i]);
      sum += x[i];
    }
    sum = (sum + (n-r)*x[r-1])/r;
    printf("\n\n The MLE and UMVUE of sigma under Type-II Censoring is : %f\n\n\n",sum);
    goto start;
    case 0: break;
    default: printf("\n Invalid choice\n");
    goto start;
  }
  getch();
}
