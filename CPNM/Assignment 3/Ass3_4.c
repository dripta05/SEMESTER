#include<stdio.h>

int main(){
int i,size;
printf("Enter size:");
scanf("%d",&size);

int a[size],b[size];
printf("Enter elements of array a:\n");
for(i=0;i<size;i++){
	scanf("%d",&a[i]);
	b[i]=a[i];
}
printf("The elements of array b are: ");
for(i=0;i<size;i++){
	printf("%d ",b[i]);
}

return 0;
}
