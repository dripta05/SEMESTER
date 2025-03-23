import java.util.*;
class Complex{
	int r;int img;
	Complex(){
		System.out.println("Constructor with zero params called");
		r = 0;
		img = 0;
	}
	Complex (int x){
		System.out.println("Constructor with one param called");
		r = x;
		img = 0;
	}
	Complex(int x,int y){
		System.out.println("Constructor with both params called");
		r =x;
		img = y;
	}
	public static void main(String args[]){
		Complex a = new Complex(3,2);
		Complex b = new  Complex(4,-2);
		Complex add = new Complex();
		add.r = a.r + b.r ;
		add.img = a.img + b.img;
		Complex mul = new Complex();
		mul.r = a.r* b.r - (a.img*b.img);
		mul.img = a.r*b.img + b.r*a.img;
		System.out.println("Addition Result : " +add.r +"+"+ add.img+"i");
		System.out.println("Multiplication Result : "+mul.r+"+"+mul.img+"i");
	}

}

