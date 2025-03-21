#include<stdio.h>
#include<ctype.h>
int main(){
char string[100];
int i=0,length;

for(i=0;i<100;i++){
	scanf("%c",&string[i]);
	if(string[i]=='\0' || string[i]=='\n'){
		length=1;
		break;}
}
string[0]=toupper(string[0]);

for(i=0;i<length-1;i++){
	if(string[i]==' ' || string[i]=='.' || string[i]=='!' || string[i]=='?')
		string[i+1]=toupper(string[i+1]);
}
for(i=0;i<length;i++){
	printf("%c",string[i]);}
return 0;
}
