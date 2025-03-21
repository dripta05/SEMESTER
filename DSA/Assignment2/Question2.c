#include<stdio.h>

struct term{
	int coef;
	int exp;
};

void addpolynomial(struct term poly1[],int n1,struct term poly2[],int n2,struct term result[],int *n3)
{
 int i=0,j=0,k=0;
 while(i<n1 && j<n2){
	if(poly1[i].exp==poly2[j].exp){
		result[k].coef=poly1[i].coef+poly2[j].coef;
		result[k].exp=poly1[i].exp;
		i++;
		j++;
		}
	else if(poly1[i].exp>poly2[j].exp){
		result[k]=poly1[i];
		i++;
	}
	else{
		result[k]=poly2[j];
		j++;
	}
   k++;
 }
 
 while(i<n1){
	result[k]=poly1[i];
	i++;
	k++;
 }

 while(j<n2){
	result[k]=poly2[j];
	j++;
	k++;
 }
 
 *n3=k;
}

void printpolynomial(struct term poly[],int n){
 int i;
 for(i=0;i<n;i++){
	if(poly[i].coef != 0){
		printf("%dX^%d",poly[i].coef,poly[i].exp);
		if(i<n-1)  printf(" + ");
  	}
 }
  printf("\n");
}

int main(){
	struct term poly1[]={{5,3},{4,2},{2,0}};
	struct term poly2[]={{3,4},{1,3},{2,1}};

	int n1=sizeof(poly1)/sizeof(poly1[0]);
	int n2=sizeof(poly2)/sizeof(poly2[0]);
	
	struct term result[n1+n2];
	int n3=0;
	
	addpolynomial(poly1,n1,poly2,n2,result,&n3);
	printf("Resultant polynomial:\n");
	printpolynomial(result,n3);

  

  return 0;
}
