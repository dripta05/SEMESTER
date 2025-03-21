#include<stdio.h>
#include<math.h>

int main(){
int lower,upper,i;
printf("Enter limits:");
scanf("%d %d",&lower,&upper);

printf("Armstrong number in the range are:");
for(i=lower;i<=upper;i++){
	//Digit count
	int a=i,c=0;
	while(a>0){
		c++;
		a=a/10;
	}
	//Armstrong check
	int b=i,s=0;
	while(b>0){
		s+=pow((b%10),c);
		b=b/10;
	}
	
	if(s==i)
	   printf("%d ",i);
 }

return 0;
}
