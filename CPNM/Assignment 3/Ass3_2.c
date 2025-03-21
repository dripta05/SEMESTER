#include<stdio.h>
int main(){
int i,size;
printf("Enter size:");
scanf("%d",&size);

int arr[size];
printf("Enter the elements of the array:\n");
for(i=0;i<size;i++){
	scanf("%d",&arr[i]);
 }

int *ptr=arr;
printf("The array is: ");
for(i=0;i<size;i++){
	printf("%d ,",*(ptr+i));
 }

return 0;
}
