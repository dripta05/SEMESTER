import java.util.*;
class Stack {
	int arr[];
	int top ;
	int size;
	Stack(int sz){
	size = sz;	
	arr = new int [sz];
		top = -1;
	}
	void push(int x){
		if(top == size)
		{
			System.out.println("Overflow");
			return;
		}
		arr[++top] = x;
	}
	int pop(){
		int x = arr[top];
		top--;
		return x;
	}
	void print(){
		int x = top;
			System.out.println("Stack Elements : ");
			while(x!=-1)
			{
				System.out.print(arr[x--] + " " );
			}
			System.out.print("\n");
	}
	public static void main(String args[]){
		Stack s = new Stack(30);
		s.push(10);
		s.push(20);
		s.push(30);
		s.push(15);
		s.push(9);
		s.print();
		s.pop();
		s.pop();
		s.pop();
		s.print();
	}
}

