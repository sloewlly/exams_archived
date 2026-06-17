#include <iostream>

class IceCream {
    private:
    float ice_price;
    float topping_price;
    float flavor_price;
    public:
    IceCream() {
        ice_price = 0.0;
        topping_price = 0.0;
        flavor_price = 0.0;
    }

    IceCream(float i_p, float t_p, float f_p) : ice_price(i_p), topping_price(t_p), flavor_price(f_p) {}
    IceCream(const IceCream& other_icecream) : IceCream(other_icecream.ice_price, other_icecream.topping_price, other_icecream.flavor_price) {}
    void describe() {
        std::cout << "Ice price: $" << ice_price << std::endl; 
        std::cout << "Topping price: $" << topping_price << std::endl; 
        std::cout << "Flavor price: $" << flavor_price << std::endl; 
    }
    
    IceCream operator-(const IceCream& other_icecream) {
        return IceCream(ice_price - other_icecream.ice_price, topping_price - other_icecream.topping_price, flavor_price - other_icecream.flavor_price);
    }

    bool operator<=(const IceCream& other_icecream) {
        return ((ice_price <= other_icecream.ice_price) && (topping_price <= other_icecream.topping_price) && (flavor_price <= other_icecream.flavor_price));
    }

};

int main() {
    IceCream ic0;
    ic0.describe();
    IceCream ic1(10.5f, 2.3f, 1.2f);
    ic1.describe();
    IceCream ic2(15, 5.2f, 7.5f);
    ic2.describe();
    IceCream ic3;
    ic3 = ic1;
    ic3.describe();
    ic3 = ic2 - ic1;
    ic3.describe();
    std::cout << "Is ic2 <= ic3? " << (ic2 <= ic3) << std::endl;
    ic3 = ic1;
    ic3.describe();
    std::cout << "Is ic1 <= ic3? " << (ic1 <= ic3) << std::endl;
    return 0;
}