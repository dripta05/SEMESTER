#include <iostream>
using namespace std;
int main()
{
    for(int temp_c=0;temp_c<=100;temp_c++)
    {
        double temp_f=9*(temp_c/5.0) + 32;
        cout<<"Temperature in Celsius ="<<temp_c<<"----"<<"Fahrenheit ="<<temp_f<<endl;
    }
}