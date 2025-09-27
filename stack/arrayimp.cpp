#include <iostream>

using namespace std;

#define MAX_SIZE 10 // Let's define a maximum size for our stack

class ArrayStack {
private:
    // --- Data Members (the class's private variables) ---
    int arr[MAX_SIZE]; // The array that holds the stack elements [cite: 149]
    int top;           // An index that points to the top element [cite: 151]

public:
    // --- Member Functions (the class's public methods) ---

    // Constructor: Initializes the stack
    ArrayStack() {
        top = -1; // -1 means the stack is initially empty 
    }

    // Method to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1; // It's full if top is at the last index [cite: 153]
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == -1; // It's empty if top is -1 [cite: 167]
    }

    // Method to push (add) an element to the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack OVERFLOW! Cannot push " << value << endl;
            return;
        }
        top++;            // Move the top index up [cite: 158]
        arr[top] = value; // Place the new value at the top [cite: 160]
        cout << value << " pushed to stack." << endl;
    }

    // Method to pop (remove) an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack UNDERFLOW! Cannot pop." << endl;
            return;
        }
        int popped_value = arr[top]; // Get the top value [cite: 173]
        top--;                       // Move the top index down [cite: 175]
        cout << popped_value << " popped from stack." << endl;
    }

    // Method to peek at the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1; // Return an error value
        }
        return arr[top]; // Return the element at the top index [cite: 133]
    }

    // Method to display the stack contents
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Array Stack Demo ---" << endl;
    ArrayStack myStack; // Create a stack object from our class

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