#include<iostream>
using namespace std ;
 

class Integer{

private:
int value;

public:
Integer():value(0){}
Integer(int v):value(v){}
Integer(const Integer& other):value(other.value){}

Integer& operator=(const Integer& other){

if(this !=&other){
	value=other.value;
}
return *this;
}
Integer operator+(const Integer& other)const
{
return Integer(value+other.value);}

Integer operator++(int){

Integer temp=*this;
value++;
return temp;
}
void disp()const{
cout<<value;}
friend ostream& operator<<(ostream& os ,const Integer& obj){
os<<obj.value;
return os;

}
};

int main(){

int a=4,b=a,c;
c=a+b++;
int i=a;
cout<<a<<b<<c;
return 0;
}
 

