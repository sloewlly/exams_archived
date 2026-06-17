#include <iostream>
#include <string>

template <typename T> class Stack {
    private:
    T* arr;
    int capacity;
    int topIndex;
    public:
    Stack(int size) : capacity(size), topIndex(), arr(nullptr) {
        arr = new T[capacity];
        topIndex = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    bool isEmpty() {
        return (topIndex < 0);
    }
    bool isFull() {
        return (topIndex >= capacity -1);
    }
    void push(T value) {
        if (isFull()) { throw std::runtime_error("Stack Overflow"); }
        arr[++topIndex] = value;

    }
    T pop() {
        if (isEmpty()) { throw std::runtime_error("Stack Underflow"); }
        return arr[topIndex--];
    }
    T peek() {
        if (isEmpty()) { throw std::runtime_error("There's nothing to peek at!"); }
        return arr[topIndex];
    }
};

int main() {
    Stack<std::string> s(3);
    std::cout << s.isEmpty() << std::endl;
    s.push("!");
    s.push("World");
    s.push("Hello");
    std::cout << s.isFull() << std::endl;
    std::cout << s.peek() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.peek() << std::endl;
    return 0;
}