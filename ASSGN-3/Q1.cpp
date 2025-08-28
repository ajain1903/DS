#include <iostream>
using namespace std;

#define MAX 10   // maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Peek operation (top element)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Main menu-driven program
int main() {
    Stack s;
    int choice, value;

   
    while (choice != 0){
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << (s.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;
            break;
        case 4:
            cout << (s.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } 

    return 0;
}
