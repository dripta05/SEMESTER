#include<stdio.h>
int main(){
int n,i,j,k;
printf("Enter n:");
scanf("%d",&n);
for(i=1;i<=n;i++){
	if(i%2==1)
	    k=(int)(i/2)+1;
	for(j=n-1;j>=i;j--){
 		printf(" ");
	}
	for(j=1;j<=k;j++){
		printf("%d ",j);
	}
	for(j=k-(i%2);j>=1;j--){
		printf("%d ",j);
	}
	
	printf("\n");
 }

return 0;
}
