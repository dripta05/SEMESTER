#include<stdio.h>

void main(){
    int arr[2][2][2][2];
    int i,j,k,l;

    printf("Enter elements of the 4-d array: \n");
    for(i=0;i<2;i++){
        for(j=0;j< 2;j++){
            for( k=0;k<2;k++){
                for(l=0;l<2;l++){
                    scanf("%d ", arr[i][j][k][l]);
                }
            }
        }
    }
    printf("The Array : \n");
    for(i=0;i<2;i++){
        for(j=0;j< 2;j++){
            for(k=0;k<2;k++){
                for(l=0;l<2;l++){
                    printf("%d ", arr[i][j][k][l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}
