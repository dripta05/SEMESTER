#include <iostream>
#include <stdexcept>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    Complex& operator=(const Complex& other) {
        if (this == &other) return *this;
        real = other.real;
        imag = other.imag;
        return *this;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) throw runtime_error("Division by zero");
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }

    void print() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i";
        else cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main() {
    Complex c1(3.0, 2.0);
    Complex c2(1.0, 7.0);
    Complex result;

    result = c1 + c2;
    cout << "c1 + c2 = "; result.print();

    result = c1 - c2;
    cout << "c1 - c2 = "; result.print();

    result = c1 * c2;
    cout << "c1 * c2 = "; result.print();

    result = c1 / c2;
    cout << "c1 / c2 = "; result.print();

    return 0;
}
