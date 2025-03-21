#include<stdio.h>
int main(){
char string[100];
int i=0;
int len;
printf("Enter the string;\n");
for(i=0;i<100;i++){
	scanf("%c",&string[i]);
	if(string=='\0'||string[i]=='\n'){
		len=i;
		break;}
}
int wordlen=0;
for(i=0;i<len;i++){
	if(string[i]==' '){
		printf("%d",wordlen);
		wordlen=-1;}
	if(i==len-1){
		printf("%d",++wordlen);}
     wordlen++;
}

return 0;
}
