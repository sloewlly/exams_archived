#include <iostream>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    
    virtual void draw() const = 0;
    virtual double area() const = 0; 
    virtual void print() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }

    double area() const override {
        return radius * radius * 3.14159;
    }
    
    void print() const override {
        std::cout << "Circle Area: " << area() << std::endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    void draw() const override {
        std::cout << "Drawing a Triangle" << std::endl;
    }

    double area() const override {
        return (base * height) / 2.0;
    }
    
    void print() const override {
        std::cout << "Triangle Area: " << area() << std::endl;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void draw() const override {
        std::cout << "Drawing a Square" << std::endl;
    }

    double area() const override {
        return side * side;
    }

    void print() const override {
        std::cout << "Square Area: " << area() << std::endl;
    }
};

int main() {
    std::vector<Shape*> myShapes;
    myShapes.push_back(new Circle(5.0));
    myShapes.push_back(new Triangle(4.0, 3.0));
    myShapes.push_back(new Square(4.0));
    
    for (Shape* s : myShapes) {
        s->draw();
        s->print(); 
        std::cout << "---" << std::endl;
    }
    for (Shape* s : myShapes) {
        delete s;
    }
    myShapes.clear();

    return 0;
}