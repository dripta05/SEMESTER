#include <iostream>

class Sample {
private:
    int value;

public:
    Sample(int val) : value(val) {}

    // Constant member function
    int getValue() const {
        // value++; // Uncommenting this line will cause a compilation error
        return value;
    }

    // Non-constant member function
    void setValue(int val) {
        value = val;
    }
};

int main() {
    Sample obj(10);
    std::cout << "Initial Value: " << obj.getValue() << std::endl;

    obj.setValue(20); // This is allowed
    std::cout << "Updated Value: " << obj.getValue() << std::endl;

    return 0;
}
