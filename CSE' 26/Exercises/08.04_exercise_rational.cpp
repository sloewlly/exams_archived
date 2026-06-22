#include <iostream>

class Rational {
    private:
    int n;
    int d;
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    void simplify() { if (d <= 0) { std::cerr << "Denumerator must be something larger than 0 (Requirement)!" << std::endl; return; }
        int divisor = gcd(n, d);
        n = n / divisor;
        d = d / divisor;
    } 
    
    public:
    Rational() { n = 1; d = 1; }
    Rational(int n) : n(n), d(1) {}
    Rational(int n, int d) : n(n), d(d) { simplify(); }
    
    
    int denumerator() { return d; }
    int numerator(){ return n; }
    
    void describe() {
        std::cout << "The rational number is: " << n << "/" << d << std::endl; 
    }
};

int main() {
    Rational myRational1(2,8);
    Rational myRational2(6,7);
    Rational myRational3(5);
    Rational myRational4;
    
    myRational1.describe();
    myRational2.describe();
    myRational3.describe();
    myRational4.describe();
    
    return 0;
}