#include <iostream>
using namespace std;

struct DLLNode {
    int data;
    DLLNode *next;
    DLLNode *prev;
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

    DLLNode* searchNode(int key) {
        DLLNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; // Not found
    }

    void insertAtBeginning(int data) {
        DLLNode* newNode = new DLLNode();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head == nullptr) {
            // List was empty
            head = newNode;
            tail = newNode;
        } else {
            // List was not empty
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << data << " at the beginning." << endl;
    }
    void insertAtEnd(int data) {
        DLLNode* newNode = new DLLNode();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr) {
            // List was empty
            head = newNode;
            tail = newNode;
        } else {
            // List was not empty
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Inserted " << data << " at the end." << endl;
    }

    void insertAfterNode(int key, int data) {
        DLLNode* prevNode = searchNode(key);
        if (prevNode == nullptr) {
            cout << "Error: Node with key " << key << " not found." << endl;
            return;
        }

        if (prevNode == tail) {
            // It's the last node, so just insert at end
            insertAtEnd(data);
        } else {
            DLLNode* newNode = new DLLNode();
            newNode->data = data;
            
            newNode->next = prevNode->next;
            newNode->prev = prevNode;
            
            prevNode->next->prev = newNode;
            prevNode->next = newNode;

            cout << "Inserted " << data << " after " << key << "." << endl;
        }
    }
    void insertBeforeNode(int key, int data) {
        DLLNode* nextNode = searchNode(key);
        if (nextNode == nullptr) {
            cout << "Error: Node with key " << key << " not found." << endl;
            return;
        }

        if (nextNode == head) {
            // It's the first node, so just insert at beginning
            insertAtBeginning(data);
        } else {
            DLLNode* newNode = new DLLNode();
            newNode->data = data;

            newNode->prev = nextNode->prev;
            newNode->next = nextNode;

            nextNode->prev->next = newNode;
            nextNode->prev = newNode;

            cout << "Inserted " << data << " before " << key << "." << endl;
        }
    }

    void deleteNode(int key) {
        DLLNode* nodeToDel = searchNode(key);
        if (nodeToDel == nullptr) {
            cout << "Error: Node with key " << key << " not found." << endl;
            return;
        }

        if (nodeToDel == head) {
            // Deleting the head node
            head = nodeToDel->next;
        }
        
        if (nodeToDel == tail) {
            // Deleting the tail node
            tail = nodeToDel->prev;
        }

        if (nodeToDel->next != nullptr) {
            // Not the tail node
            nodeToDel->next->prev = nodeToDel->prev;
        }

        if (nodeToDel->prev != nullptr) {
            // Not the head node
            nodeToDel->prev->next = nodeToDel->next;
        }

        delete nodeToDel;
        cout << "Deleted node with key " << key << "." << endl;
    }
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        DLLNode* temp = head;
        cout << "List (Head to Tail): NULL <- ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

struct CLLNode {
    int data;
    CLLNode* next;
};

class CircularLinkedList {
private:
    CLLNode* last; // 

public:
    
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtBeginning(int data) {
        CLLNode* newNode = new CLLNode();
        newNode->data = data;

        if (last == nullptr) {
            // List is empty
            last = newNode;
            newNode->next = last; // Points to itself
        } else {
            // List is not empty
            newNode->next = last->next; // New node points to old head
            last->next = newNode;       // Last node points to new head
        }
        cout << "Inserted " << data << " at the beginning." << endl;
    }

    void insertAtEnd(int data) {
        CLLNode* newNode = new CLLNode();
        newNode->data = data;

        if (last == nullptr) {
            // List is empty
            last = newNode;
            newNode->next = last;
        } else {
            // List is not empty
            newNode->next = last->next; // New node points to head
            last->next = newNode;       // Old last node points to new node
            last = newNode;             // Update last pointer
        }
        cout << "Inserted " << data << " at the end." << endl;
    }


    CLLNode* searchNode(int key) {
        if (last == nullptr) {
            return nullptr;
        }

        CLLNode* temp = last->next; // Start at head
        do {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        } while (temp != last->next); // Loop until we return to head

        return nullptr; // Not found
    }
    void insertAfterNode(int key, int data) {
        CLLNode* prevNode = searchNode(key);
        if (prevNode == nullptr) {
            cout << "Error: Node with key " << key << " not found." << endl;
            return;
        }

        CLLNode* newNode = new CLLNode();
        newNode->data = data;

        newNode->next = prevNode->next;
        prevNode->next = newNode;

        // If we inserted after the 'last' node, the new node becomes 'last'
        if (prevNode == last) {
            last = newNode;
        }
        cout << "Inserted " << data << " after " << key << "." << endl;
    }

    void insertBeforeNode(int key, int data) {
        if (last == nullptr) {
            cout << "Error: List is empty, cannot find node." << endl;
            return;
        }

        CLLNode* temp = last->next; // Head
        CLLNode* prev = last;

        do {
            if (temp->data == key) {
                // Found the node
                CLLNode* newNode = new CLLNode();
                newNode->data = data;
                
                newNode->next = temp;
                prev->next = newNode;
                
                cout << "Inserted " << data << " before " << key << "." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next); // Loop until we return to head

        cout << "Error: Node with key " << key << " not found." << endl;
    }

    void deleteNode(int key) {
        if (last == nullptr) {
            cout << "Error: List is empty." << endl;
            return;
        }

        CLLNode* curr = last->next; // Head
        CLLNode* prev = last;

        do {
            if (curr->data == key) {
                // Found the node to delete
                
                if (curr == last && curr == prev) {
                    // Only one node in the list
                    last = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == last) {
                        // Deleting the 'last' node, update 'last'
                        last = prev;
                    }
                }
                
                delete curr;
                cout << "Deleted node with key " << key << "." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next); // Loop until we return to head

        cout << "Error: Node with key " << key << " not found." << endl;
    }

    void displayList() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CLLNode* temp = last->next; // Start at head
        cout << "List (circular): Head -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next); // Loop until we return to head
        cout << "(Back to Head " << last->next->data << ")" << endl;
    }
};
void doublyLinkedListMenu() {
    DoublyLinkedList dll;
    int choice, data, key;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After a Node" << endl;
        cout << "4. Insert Before a Node" << endl;
        cout << "5. Delete a Specific Node" << endl;
        cout << "6. Search for a Node" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                dll.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                dll.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter the key (data) of the node to insert after: ";
                cin >> key;
                cout << "Enter data to insert: ";
                cin >> data;
                dll.insertAfterNode(key, data);
                break;
            case 4:
                cout << "Enter the key (data) of the node to insert before: ";
                cin >> key;
                cout << "Enter data to insert: ";
                cin >> data;
                dll.insertBeforeNode(key, data);
                break;
            case 5:
                cout << "Enter the key (data) of the node to delete: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            case 6:
                cout << "Enter the key (data) to search for: ";
                cin >> key;
                if (dll.searchNode(key) != nullptr) {
                    cout << "Node with key " << key << " was found." << endl;
                } else {
                    cout << "Node with key " << key << " was not found." << endl;
                }
                break;
            case 7:
                dll.displayList();
                break;
            case 8:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}


void circularLinkedListMenu() {
    CircularLinkedList cll;
    int choice, data, key;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After a Node" << endl;
        cout << "4. Insert Before a Node" << endl;
        cout << "5. Delete a Specific Node" << endl;
        cout << "6. Search for a Node" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                cll.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                cll.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter the key (data) of the node to insert after: ";
                cin >> key;
                cout << "Enter data to insert: ";
                cin >> data;
                cll.insertAfterNode(key, data);
                break;
            case 4:
                cout << "Enter the key (data) of the node to insert before: ";
                cin >> key;
                cout << "Enter data to insert: ";
                cin >> data;
                cll.insertBeforeNode(key, data);
                break;
            case 5:
                cout << "Enter the key (data) of the node to delete: ";
                cin >> key;
                cll.deleteNode(key);
                break;
            case 6:
                cout << "Enter the key (data) to search for: ";
                cin >> key;
                if (cll.searchNode(key) != nullptr) {
                    cout << "Node with key " << key << " was found." << endl;
                } else {
                    cout << "Node with key " << key << " was not found." << endl;
                }
                break;
            case 7:
                cll.displayList();
                break;
            case 8:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n============================" << endl;
        cout << "      MAIN MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Doubly Linked List" << endl;
        cout << "2. Circular Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                doublyLinkedListMenu();
                break;
            case 2:
                circularLinkedListMenu();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}