#include<stdio.h>

int main(){

int i,j,n;
printf("Enter n:");
scanf("%d",&n);

int arr[n];
printf("Enter the array elements:\n");
for(i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
int dup=0;
for(i=0;i<n;i++){
	int flag=0;
	for(j=i+1;j<n;j++){
		if(arr[i]==arr[j])
			flag++;
	}
	if(flag>0)
	    dup++;
}
printf("The number of duplicate elements is: %d",dup);

int cpy[n-dup];
dup=0;
for(i=0;i<n;i++){
	int c=0;
	for(j=i+1;j<n;j++){
		if(arr[i]==arr[j])
		    c++;
	}
	if(c==0)
	   cpy[dup++]=arr[i];
}
for(i=0;i<(int)(dup/2);i++){
	int t;
	t=cpy[i];
	cpy[i]=cpy[dup-1-i];
	cpy[dup-1-i]=t;
}
printf("\nElements in reverse order:");
for(i=0;i<dup;i++){
	printf("%d ",cpy[i]);
}

return 0;
}
