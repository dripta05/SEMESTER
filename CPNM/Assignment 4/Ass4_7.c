#include<stdio.h>
#include<string.h>

int main(){
	char str[1000];
	int i;
	printf("Enter a string:");
	gets(str);

	int len;
	len=strlen(str);
	for(i=0;i<(len/2);i++){
	   int x;
	   x=str[len-1-i];
	   str[len-1-i]=str[i];
	   str[i]=x;
	   
	}
printf("The reversed string willbe:\n");
puts(str);

 return 0;
}
