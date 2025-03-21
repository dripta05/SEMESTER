#include <iostream>

class Complex {
private:
    float real;
    float img;

public:
    // Member functions to set real and imaginary parts
    void setReal(float r) {
        real = r;
    }

    void setImg(float i) {
        img = i;
    }

    // Member functions to get real and imaginary parts
    float getReal() const {
        return real;
    }

    float getImg() const {
        return img;
    }

    // Function to display the complex number
    void disp() const {
        if (img >= 0) {
            std::cout << real << " + " << img << "i" << std::endl;
        } else {
            std::cout << real << " - " << -img << "i" << std::endl;
        }
    }

    // Function to sum two complex numbers
    Complex sum(const Complex &c) const {
        Complex result;
        result.real = this->real + c.real;
        result.img = this->img + c.img;
        return result;
    }
};

int main() {
    // Creating three Complex number objects
    Complex c1, c2, c3;

    // Setting values for the first two objects
    c1.setReal(3.5);
    c1.setImg(2.5);

    c2.setReal(1.5);
    c2.setImg(4.5);

    // Calculating the sum of the first two complex numbers and assigning to the third
    c3 = c1.sum(c2);

    // Displaying all complex numbers
    std::cout << "Complex Number 1: ";
    c1.disp();

    std::cout << "Complex Number 2: ";
    c2.disp();

    std::cout << "Sum of Complex Number 1 and 2: ";
    c3.disp();

    return 0;
}
