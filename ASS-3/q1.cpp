#include <iostream>

using namespace std;

// Define the maximum size of the stack.
// It's a good practice to define this at the top so it's easy to change.
#define MAX_SIZE 5

class Stack {
private:
    int top;             // Index of the top-most element
    int arr[MAX_SIZE];   // The array to store stack elements

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1; // -1 indicates that the stack is initially empty
    }

    // (i) push(): Adds an element to the top of the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << "." << endl;
            return;
        }
        // Increment top, then insert the value
        top++;
        arr[top] = value;
        cout << value << " has been pushed to the stack." << endl;
    }

    // (ii) pop(): Removes and shows the top element of the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        // Get the top value, then decrement top
        int popped_value = arr[top];
        top--;
        cout << popped_value << " has been popped from the stack." << endl;
    }

    // (iii) isEmpty(): Checks if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // (iv) isFull(): Checks if the stack is full
    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    // (v) display(): Displays all elements in the stack from top to bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (from top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    // (vi) peek(): Returns the top element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return;
        }
        cout << "The top element is: " << arr[top] << endl;
    }
};

int main() {
    Stack myStack; // Create an object of the Stack class
    int choice, value;

    // The do-while loop ensures the menu runs at least once
    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Peek (See Top)" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                myStack.push(value);
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                if (myStack.isEmpty()) {
                    cout << "Result: Stack is Empty." << endl;
                } else {
                    cout << "Result: Stack is NOT Empty." << endl;
                }
                break;
            case 4:
                if (myStack.isFull()) {
                    cout << "Result: Stack is Full." << endl;
                } else {
                    cout << "Result: Stack is NOT Full." << endl;
                }
                break;
            case 5:
                myStack.display();
                break;
            case 6:
                myStack.peek();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}