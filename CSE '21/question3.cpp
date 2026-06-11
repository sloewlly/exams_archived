#include <iostream>
#include <cmath>
#include <vector>
#include <memory> // used for unique_ptr

class Point{
  private:
  double x;
  double y;
  public:
  Point(double x, double y) : x(x), y(y) {}
  double getX() const{ return x; }
  double getY() const{ return y; }
};

class Shape2D{
    protected:
    double x;
    double y;
    public:
    Shape2D(double x, double y) : x(x), y(y) {}
    double distance(const Shape2D& others) const {
        double dx = this->x - others.x;
        double dy = this->y - others.y;
        
        return std::sqrt(dx * dx + dy * dy);
    }
    virtual bool isValid() = 0;
    virtual double area() = 0;
};

class Circle : public Shape2D{
    private:
    double radius;
    public:
    Circle(double x, double y, double radius) : Shape2D(x, y), radius(radius) {}
    bool isValid() { if (radius < 0) return false; return true;}
    double perimetre() { return radius*3.14*2; }
    double area() override { return pow(radius, 2)*3.14; }
    void display() {
        std::cout << "The radius is: " << radius << std::endl;
        std::cout << "The centre point is: " << "(" << x << ", " << y << ")" << std::endl;
        std::cout << "The perimetre is: " << perimetre() << std::endl;
        std::cout << "The area is: " << area() << std::endl;
    }
};

class Rectangle : public Shape2D{
    private:
    double height;
    double width;
    public:
    Rectangle(double x, double y, double w, double h) : Shape2D(x, y), width(w), height(h) {}
    bool isValid() { if ((height < 0) || (width < 0)) return false; return true;}
    double perimetre() { return (width + height)*2; }
    double area() override { return width*height; }
    void display() {
        std::cout << "The height is: " << height << std::endl;
        std::cout << "The width is: " << width << std::endl;
        std::cout << "The centre point is: " << "(" << x << ", " << y << ")" << std::endl;
        std::cout << "The perimetre is: " << perimetre() << std::endl;
        std::cout << "The area is: " << area() << std::endl;
    }
};

class Triangle : public Shape2D{ // assuming this one is a equilateral
    private:
    double side;
    public:
    Triangle(double x, double y, double s) : Shape2D(x, y), side(s) {}
    bool isValid() { if (side < 0) return false; return true;}
    double perimetre() { return side*3; }
    double area() override { return ((std::pow(side, 2)*std::sqrt(3))/4); }
    void display() {
        std::cout << "The side is: " << side << std::endl;
        std::cout << "The centre point is: " << "(" << x << ", " << y << ")" << std::endl;
        std::cout << "The perimetre is: " << perimetre() << std::endl;
        std::cout << "The area is: " << area() << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape2D>> Shapes;

    Shapes.emplace_back(std::make_unique<Triangle>(-1.9f, 9.1f, 8.7f));
    Shapes.emplace_back(std::make_unique<Circle>(-7.8f, -8.9f, 1.7f));
    Shapes.emplace_back(std::make_unique<Rectangle>(14.5f, 8.9f, 12.6, 2.8));
    
    double total_area = 0.0;
    for (const auto& shape :  Shapes){
        if (shape->isValid()) total_area += shape->area(); else throw std::runtime_error("One of the shape contains an invalid value!");
    }

    std::cout << "The total area of all the shapes included in the vector is: " << total_area << std::endl;
    return 0;
}
