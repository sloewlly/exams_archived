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
    Manufacturer manufacturer;
    public:
    Device(std::string name, double price, Manufacturer manufacturer) : name(name), price(price), manufacturer(manufacturer) {}
    void describe() {
        std::cout << "Product name: " << name << " - " << "Price: $" << price << std::endl;
        manufacturer.describe();
    }
};

int main() {
    Manufacturer myManufacturer(101, "United States");
    Device myDevice("Computer mouse", 10.99f, myManufacturer);

    myDevice.describe();
}