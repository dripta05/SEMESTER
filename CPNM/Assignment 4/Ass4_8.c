#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    int i, length = 1;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if(str[i]==' ')
            length++;
    }
    
    printf("There are %d words in the string ...", length);
    return 0;
}
