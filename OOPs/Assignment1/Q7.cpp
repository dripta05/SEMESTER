#include <iostream>
using namespace std;
long long int fact(const int n)
{
    if (n == 0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    int n;
    cout<<"Enter a number =";
    cin>>n;
    int const num=n;
    long long int factorial=fact(num);
    cout<<"Factorial of "<<num<<" ="<<factorial;
}
