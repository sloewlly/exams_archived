#include <iostream>

class Beverage {
    private:
    float price;
    float topping_price;
    float condiment_price;
    public:
    Beverage() { price = 0.0; topping_price = 0.0; condiment_price - 0.0; }
    Beverage(float p, float t_p, float c_p) : price(p), topping_price(t_p), condiment_price(c_p) {}
    Beverage(const Beverage& other) : price(other.price), topping_price(other.topping_price), condiment_price(other.condiment_price) {}

    Beverage operator+(const Beverage& other) { return Beverage(price + other.price, topping_price + other.topping_price, condiment_price + other.condiment_price); }
    bool operator==(const Beverage& other) { return (price == other.price) && (topping_price == other.topping_price) && (condiment_price == other.condiment_price); }

    void describe() {
        std::cout << "Price: $" << price << " - Topping price: $" << topping_price << " - Condiment price: $" << condiment_price << std::endl;
    }
};

int main() {
    Beverage b0, b1(10.5f, 2.3f, 1.2f), b2(15.0f, 2.2f, 0.5f), b3;

    b3 = b1;

    b0.describe();
    b1.describe();
    b2.describe();

    b3 = b1 + b2;
    b3.describe();

    std::cout << "Is b3 = b1? " << (b3 == b1) << std::endl;

    b3 = b1;
    std::cout << "Is b3 = b1? " << (b3 == b1) << std::endl;
    return 0;
}