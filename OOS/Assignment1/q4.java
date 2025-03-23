import java.util.*;
class BankAccount{

	int accountNumber  ;
	float balance ;
	String ownerName;

	BankAccount(int x,float y,String n){
		accountNumber = x;
		balance = y;
		ownerName = n;
	}

	BankAccount(){}

	void balance(){

		System.out.println("Balance = "+balance);
	}

	void add(float x){
		balance+=x;
	}

	void subtract(float x){
		balance-=x;
	}

} 

class AccountManager{
	BankAccount account[];
	int size;
	int ind ;

	AccountManager(int sz){
		size = 100;
		ind = -1;
		account = new BankAccount[size];
	}
	void create(){
		Scanner sc = new Scanner(System.in);
		int acno;
		float b;
		String st;
		System.out.println("Enter Name : ");
		st = sc.nextLine();
		System.out.println("Enter account number : ");
		acno = sc.nextInt();
		System.out.println("Enter Balance : ");
		b = sc.nextFloat();
		account[++ind] = new BankAccount(acno,b,st);
	}
	void delete(){
		BankAccount obj = account[ind];
		ind--;
		System.out.println("Deleted account Details : ");
		System.out.println("Name : "+obj.ownerName + "\nAccount Number : "+obj.accountNumber);
	}

	void deposit(){                Scanner sc = new Scanner(System.in);
		System.out.println("Enter the account number for deposit");
		int i = sc.nextInt();
		System.out.println("Enter Amount to be deposited");
		float x;
		//Scanner sc = new Scanner(System.in);
		x = sc.nextFloat();
		account[i-1].add(x);
	}

	void withdraw(){
		Scanner sc = new Scanner(System.in);		
		System.out.println("Enter the account number for withdraw");
		int i = sc.nextInt();
		System.out.println("Enter Amount to be Withdrawn");
		float x;
		//Scanner sc = new Scanner(System.in);
		x = sc.nextFloat();
		account[i-1].subtract(x);
	}
	void display(){
		for(int i=0;i<ind;i++)
		{
			System.out.println("Name : " +account[i].ownerName + "\n Account No : " + account[i].accountNumber +"\n Balance : "+ account[i].balance);
		}
	}
}
class Bank{
	public static void main(String args[])
			{
				AccountManager ob = new AccountManager(5);
				Scanner sc = new Scanner(System.in);
				System.out.println("Enter the detals of the 5 Bank Accounts : Please  add account Numbers sequentially from (1-5)");
				for(int i=1;i<=5;i++)
				{
					ob.create();
				}
				while(true){
					System.out.println("Enter 1: for delete, 2: for deposit, 3: for withdraw and 0: to exit");
					int ch = sc.nextInt();
					if(ch == 1)
						ob.delete();
					else if(ch == 2)
						ob.deposit();
					else if(ch == 3)
						ob.withdraw();
					else
						break;
				}
ob.display();
			}


		}





















