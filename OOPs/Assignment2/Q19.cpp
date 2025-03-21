#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
    vector<int> data;

public:
    // Default constructor
    Vector() {}

    // Parameterized constructor
    Vector(int size, int value = 0) : data(size, value) {}

    // Copy constructor
    Vector(const Vector &other) : data(other.data) {}

    // Addition operator
    Vector operator+(const Vector &other) const {
        Vector result;
        if (data.size() == other.data.size()) {
            result.data.resize(data.size());
            for (size_t i = 0; i < data.size(); ++i) {
                result.data[i] = data[i] + other.data[i];
            }
        }
        return result;
    }

    // Subtraction operator
    Vector operator-(const Vector &other) const {
        Vector result;
        if (data.size() == other.data.size()) {
            result.data.resize(data.size());
            for (size_t i = 0; i < data.size(); ++i) {
                result.data[i] = data[i] - other.data[i];
            }
        }
        return result;
    }

    // Equality operator
    bool operator==(const Vector &other) const {
        return data == other.data;
    }

    // Less than operator
    bool operator<(const Vector &other) const {
        return data < other.data;
    }

    // Greater than operator
    bool operator>(const Vector &other) const {
        return data > other.data;
    }

    // Function to print the vector
    void print() const {
    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

};

int main() {
    Vector v1(3, 1);  
    Vector v2(3, 2);  
    Vector v3(v1);

    Vector v4 = v1 + v2;  
    Vector v5 = v2 - v1;  

    v1.print();  
    v2.print();  
    v3.print();  
    v4.print();  
    v5.print();  

    // Check equality
    if (v1 == v3) cout << "v1 is equal to v3" << endl;
    if (v2 > v1) cout << "v2 is greater than v1" << endl;
    if (v1 < v2) cout << "v1 is less than v2" << endl;

    return 0;
}
