// Q2.

#include <stdio.h>

int main (){
  
    int n, i;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements into the array
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    printf("Reversed array: \n");
    for(i = n-1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}