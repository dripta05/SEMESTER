#include<stdio.h>

int main(){
    int *p;
    int m,n,i,j;
    printf("Enter the dimensions of your 2-D Array : ");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    printf("Enter the elements of your 2-D Array : \n");
    for(i=0;i<m;i++){
        p=*(arr+i);
        for(j=0;j<n;j++){
            scanf("%d", p+j);
        }
    }
    printf("The 2-D Array : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
