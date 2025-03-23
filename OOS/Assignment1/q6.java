import java.util.*;
class Employee{
	String name;
	int id;
	String address;
	double salary;
	void write(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Name : ");
		String s = sc.nextLine();
		name = s;
		int i ;
		System.out.println("Enter ID : ");
		i = sc.nextInt();
		sc.nextLine();
		System.out.println("Enter the Address : ");
		String a = sc.nextLine();
		address = a;
		System.out.println("Enter the Salary ");
		double d = sc.nextDouble();
		salary = d;
	}
	void read(){
		System.out.println("Name : "+name+" Address : " + address+ " Salary : "+salary);
	}

}

class Dept{
	double total;
	int ind ;
	Employee e[];
	int max_size = 100;
	Dept(){
		total = 0.0;
		e = new Employee[max_size];
		ind = -1;
	}
	void add(){
		e[++ind] = new Employee();
		e[ind].write();
		total+=e[ind].salary;
	}
	void remove(){
		System.out.println("Employee Remove : ");
		e[ind].read();
		total-=e[ind].salary;
		ind--;
		
	}
	/*public static void main(String args[]){
		System.out.println("Information Technology Department");
		int n = 5;
		Dept d = new Dept();
		for(int i=1;i<=n;i++){
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter 1 to add 2 to remove ");
			int ch;
			ch = sc.nextInt();
			if(ch == 1 )
			{
				d.add();
			}
			else{
				n++;
				d.remove()
			;}
		}

	}*/
}



class Main{
        public static void main(String args[]){
                System.out.println("Information Technology Department");
                int n = 5;
                Dept d = new Dept();
                for(int i=1;i<=n;i++){
                        Scanner sc = new Scanner(System.in);
                        System.out.println("Enter 1 to add 2 to remove ");
                        int ch;
                        ch = sc.nextInt();
                        if(ch == 1 )
                        {
                                d.add();
                        }
                        else{
                                n++;
                                d.remove()
                        ;}
               }
		System.out.println("TOTAL EXPENDITURE : " +d.total);

	}

}







