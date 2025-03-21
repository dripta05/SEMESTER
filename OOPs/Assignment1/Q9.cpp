#include <iostream>
using namespace std;
void swap(char* s1, char* s2,int l)
{
    char temp;
    for (int i=0; i<l; i++){
        temp = s1[i];
        s1[i] =s2[i];
        s2[i] = temp;
    }
}
void swap_using_reference(string &s1, string &s2)
{
    string temp;
    temp=s1;
    s1=s2;
    s2=temp;
}
int main()
{
    int l1,l2;
    cout<<"Enter the length of two strings =";
    cin>>l1>>l2;
    if (l1 == l2)
    {
        char str1[l1],str2[l2];
        cout<<"Enter string 1:";
        for(int i=0;i<l1;i++)
            cin>>str1[i]; 
        cout<<"Enter string 2:";         
        for(int i=0;i<l2;i++)
            cin>>str2[i];
        string s1=str1,s2=str2;
        cout<<"Before swapping String1 = "<<str1<<" and String2 = "<<str2<<endl;
        swap(str1,str2,l1);
        cout<<"After swapping without reference String1 = "<<str1<<"and String2 = "<<str2<<endl;
        swap_using_reference(s1,s2);
        cout<<"After swapping with reference String1 = "<<str1<<"and String2 = "<<str2<<endl;
    }
    else{
        cout<<"Cannot swap due to unequal length"<<endl;
    }

}
