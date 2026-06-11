#include <iostream>

class Complex{
    private:
    float real;
    float imaginary;
    public:
    Complex(float r, float i) : real(r), imaginary(i) {}
    
    float getReal() const { return real; }
    float getImaginary() const { return imaginary; }
    
    Complex operator+(const Complex& others) { return Complex(real + others.real, imaginary + others.imaginary); }
    bool operator==(const Complex& others) { return (real == others.real) && (imaginary == others.imaginary); }
    Complex operator=(const Complex& others) { if (this == &others) return *this; real = others.real; imaginary = others.imaginary; }
    
    void display() {
        if (imaginary < 0) {
            std::cout << real << " - " << -imaginary << "i" << std::endl;
        }
        else {
            std::cout << real << " + " << imaginary << "i" << std::endl;
        }
    }
};

int main() {
    Complex myComplex1(1.0f, 6.7f);
    Complex myComplex2(42.0f, -11.9f);
    
    std::cout << "Displaying first number:" << std::endl;
    myComplex1.display();
    std::cout << "Displaying second number:" << std::endl;
    myComplex2.display();
    
    Complex myComplex3 = myComplex1 + myComplex2;
    std::cout << "Displaying result after addition:" << std::endl;
    myComplex3.display();
    
    return 0;
}