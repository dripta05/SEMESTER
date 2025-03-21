#include <iostream>
using namespace std;

class Queue {
private:
    int *data;
    int front;
    int rear;
    int maxSize;
    int count;

public:
    // Constructor to create a queue with a specified size
    Queue(int size) : maxSize(size), front(0), rear(-1), count(0) {
        data = new int[maxSize];
    }

    // Destructor to clean up the allocated memory
    ~Queue() {
        delete[] data;
    }

    // Add an element to the queue
    void add(int item) {
        if (count >= maxSize) {
            cout << "Queue overflow! Cannot add " << item << endl;
        } else {
            rear = (rear + 1) % maxSize;
            data[rear] = item;
            count++;
        }
    }

    // Remove and return an element from the queue
    int remove() {
        if (count <= 0) {
            cout << "Queue underflow! No elements to remove." << endl;
            return -1; // Return an invalid value to indicate underflow
        } else {
            int item = data[front];
            front = (front + 1) % maxSize;
            count--;
            return item;
        }
    }

    // Display all elements in the queue from front to rear
    void disp() const {
        if (count <= 0) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements from front to rear:" << endl;
            for (int i = 0; i < count; i++) {
                int index = (front + i) % maxSize;
                cout << data[index] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue myQueue(10); // Create a queue of size 10

    // Add elements to the queue
    myQueue.add(2);
    myQueue.add(3);
    myQueue.add(4);
    myQueue.add(5);

    // Remove two elements
    int removedElement1 = myQueue.remove();
    cout << "Removed element: " << removedElement1 << endl;

    int removedElement2 = myQueue.remove();
    cout << "Removed element: " << removedElement2 << endl;

    // Display the current queue
    myQueue.disp();

    return 0;
} 