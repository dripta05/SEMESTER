#include<stdio.h>

int main(){
int n,s=0,i=1,j=1;
printf("Enter n:");
scanf("%d",&n);

for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		if(i%j==0)
			s+=j;
	}
 }
printf("The sum of the series is:%d",s);

return 0;
}
