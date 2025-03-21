#include<stdio.h>

int main(){
int upper,lower,i,j,flag;
printf("Enter limits:");
scanf("%d %d",&lower,&upper);
printf("Prime numbers are:");

for(i=lower+1;i<upper;i++){
	flag=0;
	for(j=2;j<=i/2;j++){
		if(i%j==0){
			flag++;
			break;
		}
	}
	if(flag==0)
		printf("%d ",i);
  }

return 0;
}
