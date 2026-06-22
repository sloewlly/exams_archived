#include <iostream>
#include <string>

template <typename T> struct Node {
  public:
  T data;
  Node<T>* next;
  Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T> class LinkedList {
    private:
    Node<T>* head;
    public:
    LinkedList() : head(nullptr) {}
    
    void prepend(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }
    
    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }
    
    head = prev; 
    }
    
    T findMid() const {
    if (head == nullptr) {
        std::cerr << "Cannot find the middle of an empty list." << std::endl;
    }

    Node<T>* slow = head;
    Node<T>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          
        fast = fast->next->next;    
    }

    return slow->data; 
}
    
    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }
    
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

int main()
{
    LinkedList<std::string> list;
    
    list.append("Hello");
    list.append("World!");
    list.prepend("I can see you!");
    
    list.display(); 
    
    std::cout << "The middle Node is: " << list.findMid() << std::endl;

    return 0;
}