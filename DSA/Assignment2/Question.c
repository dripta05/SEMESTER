 #include<stdio.h>

int main(){
	int i;
	int arr[10];
	printf("Enter the array elements:");
	for(i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	for(i=2;i<10;i++)  arr[i]=arr[i+1];
	for(i=4;i<10;i++)  arr[i]=arr[i+1];

	printf("The 5th element of the array is:%d",arr[4]);

return 0;
}
