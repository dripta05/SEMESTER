#include <iostream>
using namespace std;
inline int sum(int a,int b, int c)
{
    return a+b+c;
}
int main()
{
    int a,b,c;
    cout<< "Enter three numbers = ";
    cin>>a>>b>>c;
    cout<<endl<<"Sum of three numbers = "<<sum(a,b,c);
}