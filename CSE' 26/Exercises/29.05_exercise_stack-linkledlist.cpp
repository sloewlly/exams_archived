#include <iostream>
#include <string>

template <typename T> struct Node {
  public:
  T data;
  Node<T>* next;
  Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T> class Stack {
    private:
    Node<T>* top;
    public:
    Stack() : top(nullptr) {}
    
    void push(T data) {
        Node<T>* temp = new Node<T>(data);
        temp->next = top;
        top = temp;
    }
    
    T pop() {
        if (top == nullptr) {
            std::cerr << "Stack Underflow!" << std::endl;
        }
        Node<T>* temp = top;
        top = top->next;
        T data = temp->data;
        
        delete temp;
        return data;
    }
    
    bool isEmpty() const{
        return top == nullptr;
    }
    
    T peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is Empty!" << std::endl;
        }
        return top->data;
    }
    
    ~Stack() {
        Node<T>* current = top;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        top = nullptr;
    }
};

int main()
{
    Stack<std::string> myStack;
    
    myStack.push("Rickrolled!");
    myStack.push("Never Gonna Give You Up!");
    
    std::cout << "The top of this stack is: " << myStack.peek() << std::endl;

    return 0;
}