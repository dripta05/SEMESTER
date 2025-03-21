#include<stdio.h>

int main(){
 int i,j,n;
printf("Enter n:");
scanf("%d",&n);

int a[n],b[n];
printf("Enter elements of array a:\n");
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
	b[n-1-i]=a[i];
}
printf("The reversed array elements are:\n");
for(i=0;i<n;i++){
	a[i]=b[i];
	printf("%d ",a[i]);
}

return 0;
}
