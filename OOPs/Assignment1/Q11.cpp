#include<iostream>
using namespace std;
void strcpy(const string &str, char* ch)
{
    int i;
    for(i = 0; i < str.length(); i++)
    *(ch+i) = str[i];
    *(ch+i) ='\0';
}
int main()
{
    string s;
    cout<<"Enter a string :";
    cin>>s;
    char ch[s.length()+1];
    strcpy(s,ch);
    cout << ch;
}