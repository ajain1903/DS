#include <iostream>

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};


class DoublyLinkedList {
private:
    DLLNode* head;
    DLLNode* tail;

public:
    
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    
    void insertAtEnd(int data) {
        DLLNode* newNode = new DLLNode();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr) {
            
            head = newNode;
            tail = newNode;
        } else {
            
            tail->next = newNode;
            tail = newNode;
        }
    }


    int getSize() {
        int count = 0;
        DLLNode* temp = head; 

        
        while (temp != nullptr) {
            count++;           
            temp = temp->next;  
        }
        return count;
    }
};


int main() {
    DoublyLinkedList dll;
    
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    std::cout << "size: " << dll.getSize() << std::endl;
    return 0;
}