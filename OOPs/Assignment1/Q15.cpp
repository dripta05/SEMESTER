#include <iostream>
using namespace std;
inline int sum(int a, int b=0, int c=0)
{
    return a+b+c;
}
int main()
{
    int a,b,c;
    cout<<"Enter three numbers = ";
    cin>>a>>b>>c;
    cout<<"Sum when three arguments are passed = "<<sum(a,b,c)<<endl;
    cout<<"Sum when two arguments are passed = "<<sum(a,b)<<endl;
    cout<<"Sum when only one argument is passed = "<<sum(a);
}