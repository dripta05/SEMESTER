import java.util.*;
class student{
	String name;
        int marks1,marks2,marks3;
	void init(String n,int a,int b,int c){
		name = n;
		marks1 = a;
		marks2 = b;
		marks3 = c;
	}
	void calAvg(){
		double avg = (marks1 + marks2 + marks3)/3.0;
		System.out.println("Average = "+avg);
	}
	void display(){
		int total = marks1 + marks2 + marks3;
		System.out.println("Name = "+name); 
		System.out.println("Total = "+total);
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		String st;
		int a,b,c;
		System.out.println("Enter the Name");
		st = sc.nextLine();
		System.out.println("Enter The Three Marks ");
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt() ;
		student obj = new student();
		obj.init(st,a,b,c);
		obj.display();
		obj.calAvg();

	}
}


