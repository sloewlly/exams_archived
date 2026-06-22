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
    
    int get(T target) {
        Node<T>* current = head;
        int pos = 0;
        while (current != nullptr) {
            if (current->data == target) {
                return pos;
            }
        current = current->next;
        pos++;
        }
        return -1;
    }
    
    void replace(T target, T replacement) {
        Node<T>* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->data == target) {
                current->data = replacement;
                found = true;
            }
        current = current -> next;
        }
        if (!found) {
            std::cout << "Can't find the target for replacement!" << std::endl;
        }
    }
    
    void removeNode(T target) {
    // 1. Safety Check: Is the list entirely empty?
        if (head == nullptr) {
            return; 
        }

    // 2. Special Edge Case: What if the target is the HEAD node?
    // We can't use a "previous" node because there is nothing before the head!
        if (head->data == target) {
            Node<T>* nodeToDelete = head; // Mark the current head for deletion
            head = head->next;            // Officially make the second node the new head
            delete nodeToDelete;          // Safely destroy the old head
            return; 
        }

    // 3. Standard Case: The target is somewhere in the middle or end
        Node<T>* current = head;
        Node<T>* previous = nullptr;

    // Walk down the list until we find the target (or hit the end)
        while (current != nullptr && current->data != target) {
            previous = current;       // The previous pointer trails one step behind
            current = current->next;  // The current pointer steps forward
        }

    // 4. Did we actually find it?
        if (current != nullptr) {
        // SURGERY: Tell the previous node to skip 'current' and point to the next one
            previous->next = current->next; 
        
        // Now that the list is safely bridged, we can destroy the target
            delete current; 
            } else {
                std::cout << "Target not found in the list." << std::endl;
        }
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
    
    bool isEmpty() {
        return head == nullptr;
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
    std::cout << "The position of 'World! is: " << list.get("World!") << std::endl;
    
    list.removeNode("World!");
    list.display();
    
    list.replace("I can see you!", "This is me!");
    list.display();
    
    std::cout << "The middle Node is: " << list.findMid() << std::endl;
    std::cout << "Is the list empty? " << list.isEmpty() << std::endl;

    return 0;
}