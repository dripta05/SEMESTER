#include <iostream>
#include <math.h>
using namespace std;

class rectangle{
	float width;
	float height;
	public :
	rectangle(float width,float height){
		this->width = width;
		this->height = height;
	}	
	void area(){
		cout << width*height << "\n";
	}
};

int main(){
	rectangle r1(2,10);
	rectangle r2(3,10);
	rectangle r3(20,30);
	rectangle r4(40.9,60.7);
	r1.area();
	r2.area();
	r3.area();
	r4.area();
}

