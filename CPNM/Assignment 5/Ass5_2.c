#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display(char arr[5][100]){
	int i;
	for(i=0;i<5;i++){
		printf("%s",arr[i]);
        }
	printf("\n");

}

int main(){

char arr[5][100];
int i,j;
printf("Enter 5 strings:\n");

for(i=0;i<5;i++){
	scanf("%s",&arr[i]);
}
printf("Original order:\n");
display(arr);
char temp[20];
for(i=0;i<5;i++){
	for(j=0;j<4-i;j++){
	    if(strcpy(arr[j],arr[j+1])>0){
		strcpy(temp,arr[j]);
		strcpy(arr[j],arr[j+1]);
		strcpy(arr[j+1],temp);}	
       }
}
printf("Order after sorting:\n");
display(arr);

return 0;
}
