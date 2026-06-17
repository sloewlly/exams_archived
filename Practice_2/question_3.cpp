#include <iostream>
#include <vector>
#include <string>

template <typename T> class Data {
    private:
    T x;
    T y;
    public:
    Data(T var1, T var2) : x(var1), y(var2){}
    T sum() {
        return x + y;
    }
};

class Circle{
    private:
    int a;
    public:
    Circle(int var): a(var){}

    Circle operator+(const Circle& other) {
        return Circle(a + other.a);
    }

    void describe() {
        std::cout << "The sum of 2 circles's radiuses: " << a << std::endl;
    }
};

int main () {
    Data<int> intData(5, 6);
    std::cout << "Sum: " << intData.sum() << std::endl;
    Circle circleA(5);
    Circle circleB(7);
    Data<Circle> circleData(circleA, circleB);
    Circle sumCircle = circleData.sum();
    sumCircle.describe();

    return 0;
}