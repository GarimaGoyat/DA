// USING ARRAY IMPLEMENTATION

#include <iostream>

using namespace std;

#define MAX_SIZE 5 // Defining a small size for easy testing

class ArrayDeque {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor to initialize an empty deque
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    // Check if the deque is full
    bool isFull() {
        // Condition for a full circular array
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Insert an element at the front
    void insertFront(int value) {
        if (isFull()) {
            cout << "OVERFLOW: Deque is full. Cannot insert at front." << endl;
            return;
        }

        // If deque is initially empty
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        // If front is at the first position, wrap around to the end
        else if (front == 0) {
            front = MAX_SIZE - 1;
        }
        // Decrement front pointer
        else {
            front = front - 1;
        }

        arr[front] = value;
        cout << value << " inserted at the front." << endl;
    }

    // Insert an element at the rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "OVERFLOW: Deque is full. Cannot insert at rear." << endl;
            return;
        }

        // If deque is initially empty
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        // If rear is at the last position, wrap around to the beginning
        else if (rear == MAX_SIZE - 1) {
            rear = 0;
        }
        // Increment rear pointer
        else {
            rear = rear + 1;
        }

        arr[rear] = value;
        cout << value << " inserted at the rear." << endl;
    }

    // Delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "UNDERFLOW: Deque is empty. Cannot delete from front." << endl;
            return;
        }

        cout << arr[front] << " deleted from the front." << endl;
        // If there is only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        // If front is at the last position, wrap around
        else if (front == MAX_SIZE - 1) {
            front = 0;
        }
        // Increment front pointer
        else {
            front = front + 1;
        }
    }

    // Delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "UNDERFLOW: Deque is empty. Cannot delete from rear." << endl;
            return;
        }

        cout << arr[rear] << " deleted from the rear." << endl;
        // If there is only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        // If rear is at the first position, wrap around
        else if (rear == 0) {
            rear = MAX_SIZE - 1;
        }
        // Decrement rear pointer
        else {
            rear = rear - 1;
        }
    }

    // Display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: [ ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << "]" << endl;
    }
};

int main() {
    ArrayDeque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display(); // Deque elements: [ 5 10 20 ]

    dq.deleteRear();
    dq.display(); // Deque elements: [ 5 10 ]

    dq.insertRear(30);
    dq.insertRear(40);
    dq.insertRear(50);
    dq.display(); // Deque elements: [ 5 10 30 40 50 ]
    
    dq.insertFront(100); // Should cause overflow

    dq.deleteFront();
    dq.deleteFront();
    dq.display(); // Deque elements: [ 30 40 50 ]

    return 0;
}


// USING STL

#include <iostream>
#include <deque>

// Use the standard namespace as requested
using namespace std;

// Helper function to print the contents of the deque
void printDeque(const deque<int>& d) {
    cout << "Deque: [ ";
    for (int item : d) {
        cout << item << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Create a deque of integers
    deque<int> d;

    cout << "--- Adding elements ---" << endl;
    // Add to the back (like a regular queue)
    d.push_back(10);
    d.push_back(20);
    printDeque(d);

    // Add to the front
    d.push_front(5);
    d.push_front(1);
    printDeque(d);

    cout << "\n--- Accessing elements ---" << endl;
    cout << "Front element is: " << d.front() << endl; // Access the first element
    cout << "Back element is: " << d.back() << endl;   // Access the last element

    cout << "\n--- Removing elements ---" << endl;
    // Remove from the front
    d.pop_front();
    printDeque(d);

    // Remove from the back
    d.pop_back();
    printDeque(d);

    return 0;
}