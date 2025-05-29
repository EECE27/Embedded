#include <iostream>

class Complex {
public:
    int real, imag;
    
    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the `+` operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3, 5), c2(2, 4);
    Complex sum = c1 + c2;
    sum.display(); // Output: 5 + 9i
    return 0;
}