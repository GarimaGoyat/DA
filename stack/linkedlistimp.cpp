#include <iostream>

using namespace std;

// A node in the linked list
class Node {
public:
    int data;     // The data value of the node
    Node* next;   // Pointer to the next node in the list
};

class LinkedListStack {
private:
    // --- Data Member ---
    Node* top; // A pointer that always points to the top of the stack

public:
    // --- Member Functions ---

    // Constructor: Initializes an empty stack
    LinkedListStack() {
        top = nullptr; // nullptr means the stack is initially empty
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == nullptr; // It's empty if top points to nothing
    }

    // Method to push (add) an element to the stack
    void push(int value) {
        // 1. Create a new node
        Node* newNode = new Node();
        newNode->data = value;

        // 2. Link the new node to the current top
        newNode->next = top;

        // 3. Update top to be the new node
        top = newNode;

        cout << value << " pushed to stack." << endl;
    }

    // Method to pop (remove) an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack UNDERFLOW! Cannot pop." << endl;
            return;
        }
        // 1. Store the current top to delete it later
        Node* temp = top;
        int popped_value = top->data;

        // 2. Move the top pointer to the next node
        top = top->next;

        // 3. Free the memory of the old top node
        delete temp;

        cout << popped_value << " popped from stack." << endl;
    }

    // Method to peek at the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1; // Return an error value
        }
        return top->data; // Return the data from the top node
    }

    // Method to display the stack contents
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* current = top; // Start from the top
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next; // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Linked List Stack Demo ---" << endl;
    LinkedListStack myStack; // Create a stack object from our class

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display();

    cout << "Top element is: " << myStack.peek() << endl;

    myStack.pop();
    myStack.display();

    myStack.pop();
    myStack.pop();
    myStack.pop(); // This will trigger an underflow

    return 0;
}