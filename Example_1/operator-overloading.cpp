#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> 
class myVariables {
private:
    std::vector<T> variables;

public:
    myVariables(const std::vector<T>& initVariables) : variables(initVariables) {}
    
    myVariables& operator++() {
        for (auto& num : variables) {
            ++num;
        }
        return *this;
    }

    myVariables operator++(int) {
        myVariables temp = *this;
        ++(*this);
        return temp;
    }

    myVariables& operator--() {
        for (auto& num : variables) {
            --num;
        }
        return *this;
    }

    myVariables operator--(int) {
        myVariables temp = *this;
        --(*this);
        return temp;
    }

    myVariables operator+(const myVariables& other) const {
        std::vector<T> resultVector;
        size_t minSize = std::min(variables.size(), other.variables.size());

        for (size_t i = 0; i < minSize; ++i){
            resultVector.push_back(variables[i] + other.variables[i]);
        }

        return myVariables(resultVector);
    }

    myVariables operator-(const myVariables& other) const {
        std::vector<T> resultVector;
        size_t minSize = std::min(variables.size(), other.variables.size());

        for (size_t i = 0; i < minSize; ++i){
            resultVector.push_back(variables[i] - other.variables[i]);
        }

        return myVariables(resultVector);
    }

    void print() const {
        std::cout << "[ ";
        for (const auto& num : variables) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }
};

int main() {
    // 1. Create two sets of variables (with different sizes to test std::min logic)
    myVariables<int> setA({10, 20, 30});
    myVariables<int> setB({1, 2, 3, 4});

    std::cout << "Initial Set A: ";
    setA.print();
    std::cout << "Initial Set B: ";
    setB.print();
    std::cout << "-----------------------\n";

    // 2. Test Addition (+)
    std::cout << "Set A + Set B: ";
    myVariables<int> sum = setA + setB;
    sum.print(); // Should print [ 11 22 33 ]

    // 3. Test Subtraction (-)
    std::cout << "Set A - Set B: ";
    myVariables<int> diff = setA - setB;
    diff.print(); // Should print [ 9 18 27 ]
    std::cout << "-----------------------\n";

    // 4. Test Prefix Increment (++A)
    std::cout << "Prefix ++Set A: ";
    (++setA).print(); // Should print [ 11 21 31 ]

    // 5. Test Postfix Increment (B++)
    std::cout << "Postfix Set B++ (returns old): ";
    setB++.print(); // Should print [ 1 2 3 4 ]
    
    std::cout << "Set B after postfix finishes: ";
    setB.print(); // Should print [ 2 3 4 5 ]

    return 0;
}