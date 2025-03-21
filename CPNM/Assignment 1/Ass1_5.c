#include<stdio.h>

int main(){
int i,number,factor;
factor=0;
printf("Enter a number:");
scanf("%d",&number);

for(i=1;i<=number;i++){
	if(number%i==0)
		factor++;
}
if(factor==2)
	printf("Prime number");
else
	printf("Not prime number");

return 0;
}
