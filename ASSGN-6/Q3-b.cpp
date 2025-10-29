#include <iostream>

struct CLLNode {
    int data;
    CLLNode* next;
};

class CircularLinkedList {
private:
    CLLNode* last; 

public:
    
    CircularLinkedList() {
        last = nullptr;
    }

    
    void insertAtEnd(int data) {
        CLLNode* newNode = new CLLNode();
        newNode->data = data;

        if (last == nullptr) {
            
            last = newNode;
            newNode->next = last; 
        } else {
            
            newNode->next = last->next; 
            last->next = newNode;       
            last = newNode;             
        }
    }

    int getSize() {
        
        if (last == nullptr) {
            return 0;
        }

        int count = 0;
        CLLNode* temp = last->next; 

        do {
            count++;
            temp = temp->next;
        } while (temp != last->next); 

        return count;
    }
};


int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(100);
    cll.insertAtEnd(200);
    cll.insertAtEnd(300);

    std::cout << "size: " << cll.getSize() << std::endl;
    return 0;
}