#include<stdio.h>
#include<math.h>
main() {
	
	float A[4][4],X[4],X_new[4],lbd;
	int i,j,n,itr=1;
	printf("Enter order of matrix: ");
	scanf("%d",&n);
	printf("Enter the elements rowwise:\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
	   		scanf("%f",&A[i][j]);
		}
	}
	printf("Enter initial column vector:\n");
	for(i=0;i<n;i++) {
		scanf("%f",&X[i]);
	}
		
	do {
	  	for(i=0;i<n;i++) {
	   		X_new[i]=0;
	   		for(j=0;j<n;j++) {
	    		X_new[i] = X_new[i] + A[i][j]*X[j];
	   		}
	   	}
	 	lbd=fabs(X_new[0]);
	 	for(i=1;i<n;i++) {
	  		if(fabs(X_new[i]>lbd)) {
	   			lbd=fabs(X_new[i]);
	  		}	
	 	}
	 	for(i=0;i<n;i++) {
	  		X[i]=X_new[i]/lbd;
	 	}
	 	printf("\nIteration %d:\n",itr);
	 	printf("Eigen Value : %.3f\n",lbd);
	 	printf("Eigen Vector : ");
	 	for(i=0;i<n;i++) {
	  		printf("%.3f ",X[i]);
	 	}
	 	itr++;
	}
	while(itr<=5); 
}
