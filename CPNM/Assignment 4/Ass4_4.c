#include<stdio.h>
void main(){
    int m,n,i,j;
    printf("Enter the dimensions of your matrix: ");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int count=0;
    printf("Enter the elements of your matrix: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]=0){
                count++;
            }
        }
    }
    if(3*count>=2*m*n)
        printf("sparse matrix " );
    else
        printf("not a sparse matrix ");
}
