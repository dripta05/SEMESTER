#include <iostream>
using namespace std;
int max_of_three(int a, int b, int c)
{
    if(a>b && a>c)
        return a;
    else if (b>c)
        return b;
    else 
        return c;
}
int max_element(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if (arr[i] > max)
            max=arr[i];
    }
    return max;
}
int main()
{
    int a,b,c,n;
    cout<<"Enter three numbers = ";
    cin>>a>>b>>c;
    cout<<"Max of three elements = "<<max_of_three(a,b,c)<<endl;
    cout<<"Enter the size of array = ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array :";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Max element of the array = "<<max_element(arr,n);
}