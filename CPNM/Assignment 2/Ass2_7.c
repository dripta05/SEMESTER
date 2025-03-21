#include<stdio.h>

int main(){
 int i,space,j,r,coeff=1;
 printf("Enter number of rows:");
 scanf("%d",&r);
 
 for(i=0;i<r;i++){
	for(space=1;space<=r-i;space++){
		printf(" ");
	}
	for(j=0;j<=i;j++){
		if(j==0 || i==0){
		    coeff=1;
		    printf("%d ",coeff);
		}	
	        else{
	  	    coeff=coeff*(i-j+1)/j;
	            printf("%d ",coeff);
		}
	}
	
     printf("\n");
 }

return 0;
}
