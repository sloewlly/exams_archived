#include <iostream>

class Product {
    private:
    float price;
    float weight;
    float discount;
    public:
    Product() { price = 0.0; weight = 0.0; discount = 0.0; }
    Product(float p, float w, float d) : price(p), weight(w), discount(d) {}
    Product(const Product& other) : price(other.price), weight(other.weight), discount(other.discount) {}
    void describe() {
        std::cout << "Price: " << price << " Weight: " << weight << " Discount: " << discount << std::endl;
    }
    Product operator+(const Product& other) { return Product(price + other.price, weight + other.weight, discount + other.discount); }
    void operator=(const Product& other) { if (this == &other) return; price = other.price; weight = other.weight; discount = other.discount; }
    bool operator==(const Product& other) { return (price == other.price) && (weight == other.weight) && (discount == other.discount); }
};

int main() {
    Product m0, m1(10.5f, 2.3f, 1.2f), m2(15.0f, 2.2f, 0.5f), m3;
    m0.describe();
    m1.describe();
    m2.describe();

    m3 = m1;
    m3.describe();
    m3 = m1 + m2;
    m3.describe();

    std::cout << "Is m3 = m1? " << (m3 == m1) << std::endl;

    m3 = m1;
    m3.describe();

    std::cout << "Is m3 = m1? " << (m3 == m1) << std::endl;
    return 0;
}