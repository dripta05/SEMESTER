import java.util.*;
class Room{
	int height,width,breadth;
	Room(int a, int b,int c){
		height = a;
		width = b;
		breadth = c;
	}
	void volume(){
		int vol = height * width* breadth;
		System.out.println("Volume = "+vol);
	}
}

class RoomDemo{
	public static void main(String args[]){

		Scanner sc=new Scanner(System.in);
		int l1,b1,h1,l2,b2,h2;
		
		System.out.println("Enter dimensions for first room:");
		l1=sc.nextInt();
		b1=sc.nextInt();
		h1=sc.nextInt();

		System.out.println("Enter dimensions for second room:");
		l2=sc.nextInt();
		b2=sc.nextInt();
		h2=sc.nextInt();
		Room r1 = new Room(l1,b1,h1);
		r1.volume();
		Room r2 = new Room(l2,b2,h2);
		r2.volume();
	}
}

