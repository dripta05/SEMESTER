#include <stdio.h>
int main() {
int arr[10] ;
int i ;
printf(" Enter 10 elements in the array : \n") ;
for(i=0;i<10;i++) 
    scanf("%d",&arr[i]) ;
int l=0;
int new_arr[8];
for(i=0;i<10;i++)
{
    if(i!=2 && i!=5){
        new_arr[l]=arr[i];
        l++;
    }
}
printf("the 5th element of this array is : %d\n",new_arr[4]) ;
return 0 ;	
}