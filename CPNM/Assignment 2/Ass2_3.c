#include<stdio.h>
int main(){
int i,number;
printf("Enter number:");
scanf("%d",&number);
int sum=0;
for(i=1;i<=number;i++){
	sum+=i*i*(i+1);
} 
printf("The sum s is %d",sum);

return 0;
}
