#include<stdio.h>

int main(){
int fib1,fib2,number,sum,flag=0;
fib1=0;
fib2=1;

printf("Enter number:");
scanf("%d",&number);

while(fib2<=number){
	sum=fib1+fib2;
	fib1=fib2;
	fib2=sum;
	if(fib2==number)
		flag=1;
}
if(flag==1)
	printf("It belongs to fibonacci series");
else
	printf("It doesn't belongs to fibonacci series");

return 0;
}
