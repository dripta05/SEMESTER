#include<stdio.h>

int main(){
int a,b,c,*ptr_a,*ptr_b;
printf("Enter a:");
scanf("%d",&a);
printf("Enter b:");
scanf("%d",&b);

ptr_a=&a;
ptr_b=&b;
c=*ptr_a;

//Swapping
*ptr_a=*ptr_b;
*ptr_b=c;
printf("Swapping value of a and b is:%d ,%d",a,b);

return 0;
}
