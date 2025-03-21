#include<stdio.h>
#include<math.h>

void armstrong(int num){
    int x=num,y=num;
    int sum=0;
    int digit=0;
    while(x>0){
    digit++;
    x/=10;
    }
   x=num;
    while(x>0){
    int k=0;
    k=pow((x%10),digit);
    sum+=k;
    x/=10;
    }
    
    if(sum==num){
	printf("Armstrong number");}
    else
        printf("Not a armstrong number");		
}

void perfect(int num){
	int i;int sum=0;
	for(i=1;i<num;i++){
		if(num%i==0)
			sum+=i;
	}
    if(sum==num){
	printf("Perfect Number");}
    else
	printf("Not a perfect number");
}
int main(){
	int number;
	printf("Enter a number:");
	scanf("%d",&number);
	armstrong(number);
	printf("\n");
	perfect(number);

return 0;
}
