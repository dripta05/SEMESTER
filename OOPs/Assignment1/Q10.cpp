#include <iostream>
using namespace std;
int factorial(const int &n)
{
    int f=1;
    for (int i=2; i<=n; i++){
        f *= i;
    }
    return f;
}
int main()
{
    int n;
    cout<<"Enter a number =";
    cin>>n;
    cout<<"The factorial is : "<<factorial(n)<<endl;
}