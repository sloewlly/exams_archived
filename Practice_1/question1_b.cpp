#include <iostream>
#include <string>

class Manufacturer {
    protected:
    int id;
    std::string location;
    public:
    Manufacturer(int id, std::string loc) : id(id), location(loc) {}
    void describe() {
        std::cout << "ID: " << id << " - " << "Made in: " << location << std::endl;
    }
};

class Device {
    private:
    std::string name;
    double price;
    Manufacturer* manufacturer;
    public:
    Device(std::string name, double price, int id, std::string loc) {
        this->name = name;
        this->price = price;
        this->manufacturer = new Manufacturer(id, loc);
    }

    ~ Device() {
        delete manufacturer;
    }

    void describe() {
        std::cout << "Product name: " << name << " - " << "Price: $" << price << std::endl;
        manufacturer->describe();
    }
};

int main() {
    Device myDevice("Computer mouse", 10.99f, 101, "United States");
    myDevice.describe();
}