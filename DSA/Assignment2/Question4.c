#include<stdio.h>
#include<math.h>

struct term{
  int coeff;
  int exp;
};

void multiplyPolynomial(struct term poly1[],int n1,struct term poly2[],int n2,struct term result[],int *n3){
	int k=0;
	int i=0;
	
	for(i=0;i<n1;i++){
		int j=0;
		for(j=0;j<n2;j++){
			int coeff=poly1[i].coeff*poly2[j].coeff;
			int exp=poly1[i].exp+poly2[j].exp;
			int found=0;
			int l=0;
			for(l=0;l<k;l++){
				if(result[l].exp==exp){
				  result[l].coeff+=coeff;
				  found=1;
				  break;
				}
			}
			if(!found){
			  result[k].coeff=coeff;
			  result[k].exp=exp;
			  k++;
			}
		}
	}
       *n3=k;
}

void printPolynomial(struct term poly[],int n){
  int i=0;
  for(i=0;i<n;i++){
	if(poly[i].coeff!=0){
		printf("%dx^%d",poly[i].coeff,poly[i].exp);
	if(i<n-1)  printf("+");
	}
  }
  printf("\n");
}

int main(){
  struct term poly1[]={{2,1},{3,0}};
  struct term poly2[]={{4,2},{5,1}};
  int n1=sizeof(poly1)/sizeof(poly1[0]);
  int n2=sizeof(poly2)/sizeof(poly2[0]);
  struct term result[n1*n2];
  int n3=0;
  multiplyPolynomial(poly1,n1,poly2,n2,result,&n3);
  printf("Resultant polynomial after multiplication:");
  printPolynomial(result,n3);
  
return 0;
}

