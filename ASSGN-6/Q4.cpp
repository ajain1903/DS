#include <iostream>
#include <string>

// Node structure for a Doubly Linked List of characters
struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Helper function to easily add nodes to the end of the list
    void insertAtEnd(char data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            // List is empty
            head = newNode;
            tail = newNode;
        } else {
            // List is not empty
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Helper function to create a list from a string (for easy testing)
    void createFromString(std::string s) {
        for (char c : s) {
            insertAtEnd(c);
        }
    }
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        std::cout << "NULL <- ";
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) {
                std::cout << " <-> ";
            }
            temp = temp->next;
        }
        std::cout << " -> NULL" << std::endl;
    }

    bool isPalindrome() {
        
        if (head == nullptr || head == tail) {
            return true;
        }

        Node* left = head;
        Node* right = tail;
        
        while (left != right && left->prev != right) {
            
            if (left->data != right->data) {
                return false; 
            }

            
            left = left->next;
            right = right->prev;
        }

        
        return true;
    }
};

int main() {
    
    DoublyLinkedList list1;
    list1.createFromString("LEVEL");
    
    std::cout << "List 1: ";
    list1.display();
    std::cout << "Output: " << (list1.isPalindrome() ? "True" : "False") << std::endl;

    return 0;
}