#include<stdio.h>
void main(){
    int arr[10];int i,j;
    printf(" Enter 10 numbers: \n");
    for(i=0;i<10;i++){
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 10-1; i++) {
        for (j = 0; j < 10-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Sorted array in descending order...\n ");
    for(i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
}
