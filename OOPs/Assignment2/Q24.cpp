#include <iostream>
using namespace std;

class Stack {
private:
    int *buffer;
    int top;
    int maxSize;

public:
    // Constructor to create a stack with a specified size
    Stack(int size) : maxSize(size), top(-1) {
        buffer = new int[maxSize];
    }

    // Destructor to clean up the allocated memory
    ~Stack() {
        delete[] buffer;
    }

    // Push the specified item onto the stack
    void push(int item) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow! Cannot push " << item << endl;
        } else {
            buffer[++top] = item;
        }
    }

    // Return and remove the top element from the stack
    int pop() {
        if (top < 0) {
            cout << "Stack underflow! No elements to pop." << endl;
            return -1; // Return an invalid value to indicate underflow
        } else {
            return buffer[top--];
        }
    }

    // Display elements in the stack from top to bottom
    void disp() const {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements from top to bottom:" << endl;
            for (int i = top; i >= 0; i--) {
                cout << buffer[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack(10); // Create a stack of size 10

    // Push elements onto the stack
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Pop one element
    int poppedElement = myStack.pop();
    cout << "Popped element: " << poppedElement << endl;

    // Display the current stack
    myStack.disp();

    return 0;
}
