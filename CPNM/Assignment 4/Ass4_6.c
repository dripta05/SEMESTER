#include<stdio.h>

int main(){
    int m1,n1,m2,n2,i,j,k;


    printf("Enter the dimensions of 1st matrix: ");
    scanf("%d%d",&m1,&n1);
    int mat1[m1][n1];
    printf("Enter the dimensions of 2nd matrix: ");
    scanf("%d%d",&m2,&n2);
    int mat2[m2][n2];


    if(n1!=m2){
        printf("Matrix Multiplication  is not possible...");
        return 0;
    }

    printf("Enter the value of 1st matrix elements: \n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the values of 2nd matrix elements: \n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            scanf("%d", &mat2[i][j]);
        }
    }


    int mat3[m1][n2];
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            mat3[i][j]=0;
            for( k=0;k<n1;k++){
                mat3[i][j]+=(mat1[i][k]*mat2[k][j]);
            }
        }
    }

    printf("Elements of the matrix is : \n");
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
 return 0;   
}
