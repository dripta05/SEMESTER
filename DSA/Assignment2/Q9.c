#include<stdio.h>

int main(){
    int a[4][4]={ {2,3,4,5},
                {8,5,6,2},
                {9,7,6,5},
                {4,5,6,1}};

    int ans[4*4];
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            ans[4*i+j]=a[i][j];
        }
    }

    for (i = 0; i < 16; i++)
    {
        printf("%d ",ans[i]);
    }
    
    return 0;
}