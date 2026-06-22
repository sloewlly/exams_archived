#include <iostream>
#include <string>
#include <chrono>
#include <format>

class Wallet {
    private:
    std::string name;
    double fund;
    public:
    Wallet() : name("John Doe"), fund(0) {} // default wallet
    Wallet(std::string name, double f) : name(name), fund(f) {}
    
    double getFund() {
        return fund;
    } 
    
    double addFund(double f) {
        if (f < 0) { std::cerr << "Cannot add a negative amount!" << std::endl; return -1; } 
        else { fund = fund + f; return fund; }
    }
    
    double withdrawFund (double f) {
        if (f > fund) { std::cerr << "Cannot withdraw, insufficient for this transfer!" << std::endl; return -1; }
        else { fund = fund - f; return fund; }
    }
    
    void transfer(Wallet& other, double f) {
        auto now = std::chrono::system_clock::now();
        if (f < 0) {
            std::cerr << "Cannot transfer a negative amount!" << std::endl;
        }
        if (fund < f) {
            std::cerr << "Insufficient funds for this transfer!" << std::endl;
        }
        
        other.fund = other.fund + f;
        fund = fund - f;
        
        std::cout << "\n" << std::format("{:%Y-%m-%d %H:%M}", now) << " " << name << " has transferred $" << f << " to " << other.name << "!" << std::endl;
    }
    
    void display() {
        std::cout << "-----" << std::endl;
        std::cout << name << "'s Wallet" << std::endl;
        std::cout << "Balance: $" << fund << std::endl;
    }
};

int main() {
    Wallet myWallet("Bjorn Andersson", 10000);
    Wallet friendWallet("Colin O'Hara", 500);
    
    myWallet.display();
    friendWallet.display();
    
    myWallet.transfer(friendWallet, 500);
    return 0;
}