#include<iostream>
using namespace std;

class Intarray{
private:
int*arr;
int size;
public:
Intarray(int s):size(s){
arr=new int[size];
}

~Intarray(){
delete[]arr;
}

int& operator[](int index){
if(index>=0 && index<size){
return arr[index];
}
else{cout<<" throw out_of_range";
}
}

friend ostream& operator<<(ostream& os,const Intarray& obj){
for(int i=0;i<obj.size;i++){
os<<obj.arr[i]<<" ";
}
return os;
}
};

int main(){
Intarray i(10);
for(int k=0;k<10;k++)
i[k]=k;
cout<<i;
return 0;
}
  
