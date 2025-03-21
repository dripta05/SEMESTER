#include<stdio.h>

int main(){

int choice,a,b;
//Add-1,Multiply-3,substraction-2,division-4
printf("Enter choice:");
scanf("%d",&choice);
printf("Enter numbers:");
scanf("%d %d",&a,&b);

switch(choice){
 case 1: printf("Addition is%d",a+b);
    	   break;
 case 2: printf("The substraction is %d",a-b);
	   break;	
 case 3: printf("The multiplication is %d",a*b);
	   break;
 case 4: printf("The division is%d",a/b);
	   break;
 default: printf("INVALID INPUT");
 } 
return 0;
}
