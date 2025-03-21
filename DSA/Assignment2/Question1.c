#include<stdio.h>

int main(){
	int n,i;
	printf("Enter the size:");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the array element:");
	for(i=0;i<n;i++)   scanf("%d",&arr[i]);
	printf("The reversed array is:");
	for(i=0;i<(n/2);i++){
		int t=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=t;
	}
	
	for(i=0;i<n;i++)  printf("%d ",arr[i]);
 
return 0;
}
