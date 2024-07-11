#include <stdio.h>
#include<math.h>
int main(){
	int i, j, k, n1,n2,r;
	float A[10][10][10], a[10], b[10], ab[10][10],ss=0,mean=0,ssab=0,ssa=0,ssb=0;
	printf("\n Enter the no. of levels of Factor A (watering frequency) : ");
	scanf("%d", &n1);
	printf("\n Enter the no. of levels of Factor B (sunlight exposure): ");
	scanf("%d", &n2);
	printf("\n Enter the no. of observations in each cell: ");
	scanf("%d", &r);
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			printf("\n Observation corresponding to %d level A and %d level B:\n",i+1,j+1);
			for(k=0;k<r;k++){
				scanf("%f",&A[i][j][k]);
				ss = ss + A[i][j][k]*A[i][j][k];
				mean = mean + A[i][j][k]/(r*n1*n2);
				a[i] = a[i] + A[i][j][k]/(r*n2);
				b[j] = b[j] + A[i][j][k]/(r*n1);
			}
		}
	}
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			for(k=0;k<r;k++){
				ab[i][j] = ab[i][j] + A[i][j][k]/r;
			}
			ssab =  ssab + pow(ab[i][j]-a[i]-b[j]+mean,2);
		}
	}
	float tss = ss - (r*n1*n2)*(mean)*(mean);
	ssab = r*ssab;
	for (i=0;i<n1;i++) {
		ssa = ssa + r*n2*pow(a[i]-mean,2);
	}
	for (j=0;j<n2;j++) {
		ssb = ssb + r*n1*pow(b[j]-mean,2);
	}
	float sse = tss - ssab - ssa - ssb;
	float msa = ssa/(n1-1);
	float msb = ssb/(n2-2);
	float msab = ssab/((n1-1)*(n2-1));
	float mse = sse/(n1*n2*(r-1));
	float F_tab1 = 4.1491;
	float F_tab2 = 2.9011;
	float F_tab3 = 2.9011;
	
	printf("\t\t\t\t ANOVA TABLE \n");
	printf("Source of Variation\tD.o.f.\t\tS.S\t\tM.S.S.\t\tF_cal\t\tF_tab\n");
	printf("Watering Frequency \t%d\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",n1-1,ssa,msa,msa/mse,F_tab1);
	printf("Sunlight Exposure  \t%d\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",n2-1,ssb,msb,msb/mse,F_tab2);
	printf("Interaction        \t%d\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n",(n1-1)*(n2-1),ssab,msab,msab/mse,F_tab3);
	printf("Error              \t%d\t\t%.4f\t\t%.4f\n",n1*n2*(r-1),sse,mse);
	printf("Total              \t%d\t\t%.4f\n",n1*n2*r-1,tss);
}

