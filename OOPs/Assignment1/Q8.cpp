#include <iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int x,y;
    cout<<"Enter two numbers :";
    cin>>x>>y;
    cout<<"Before swapping a="<<x<<" and b="<<y<<endl;
    swap(x,y);
    cout<<"After swapping a="<<x<<" and b="<<y<<endl;
}