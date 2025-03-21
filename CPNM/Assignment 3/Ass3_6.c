#include<stdio.h>

int main(){
int i,n;
printf("Enter n:");
scanf("%d",&n);

int arr[n];
printf("Enter array elements:\n");
for(i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
 //Finding the max and min
int max,min;
max=arr[0];
min=arr[0];
for(i=0;i<n;i++){
      if(arr[i]>max)
	max=arr[i];
      if(arr[i]<min)
	min=arr[i];	
}
printf("The maximum element in the array is %d",max);
printf("\nThe minimum element of the array is %d",min);

return 0;
}

