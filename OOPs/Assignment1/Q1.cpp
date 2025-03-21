#include<iostream>
using namespace std;

void swap(char arr[],char brr[]){
	char temp[100];
	int i=0;

	while(arr[i]!='\0' || brr[i]!='\0'){
		temp[i]=arr[i];
		arr[i]=brr[i];
		brr[i]=temp[i];
		i++;
	}

}


int main(){
	 char s1[100],s2[100];
	cout<<"Enter string1:";
	cin>>s1;
	cout<<"Enter string2:";
	cin>>s2;

	swap(s1,s2);
	cout<<"After swapping :\n";
	cout<<"String1: "<<s1<<endl;
	cout<<"String2: "<<s2<<endl;
	
	
return 0;
}
