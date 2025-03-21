#include <iostream>
#include <algorithm>  // For std::sort and std::reverse
using namespace std;

class IntArray {
private:
    int *arr;
    int size;

public:
    // Constructor
    IntArray(int s) : size(s) {
        arr = new int[size];
    }

    // Parameterized constructor with initialization
    IntArray(int s, int values[]) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = values[i];
        }
    }

    // Copy constructor
    IntArray(const IntArray &other) : size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Destructor
    ~IntArray() {
        delete[] arr;
    }

    // Function to print the array
    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to add two arrays
    IntArray operator+(const IntArray &other) const {
        if (size != other.size) {
            cout << "Arrays must be of the same size for addition." << endl;
            return IntArray(0);
        }
        IntArray result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    // Function to reverse the array
    void reverse() {
        std::reverse(arr, arr + size);
    }

    // Function to sort the array
    void sort() {
        std::sort(arr, arr + size);
    }
};

int main() {
    int elements[] = {1, 2, 3};

    // Create an IntArray object with elements 1, 2, 3
    IntArray arr1(3, elements);
    cout << "Array 1: ";
    arr1.print();

    // Create another IntArray object as a copy of the first
    IntArray arr2(arr1);
    cout << "Array 2 (copy of Array 1): ";
    arr2.print();

    // Reverse the elements of the second array
    arr2.reverse();
    cout << "Array 2 after reversing: ";
    arr2.print();

    // Print elements of both arrays
    cout << "Final Array 1: ";
    arr1.print();
    cout << "Final Array 2: ";
    arr2.print();

    return 0;
}
