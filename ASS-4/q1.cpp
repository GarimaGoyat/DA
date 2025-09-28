#include <iostream>

using namespace std;

// Define the maximum size for the queue array
#define MAX_SIZE 5

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // (i) enqueue(): Adds an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add " << value << "." << endl;
            return;
        }
        
        if (isEmpty()) {
            // If it's the first element, set front to 0
            front = 0;
        }
        
        rear++; // Move rear to the next position
        arr[rear] = value;
        cout << value << " has been enqueued." << endl;
    }

    // (ii) dequeue(): Removes an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove from an empty queue." << endl;
            return;
        }

        int dequeued_value = arr[front];
        cout << dequeued_value << " has been dequeued." << endl;

        if (front >= rear) {
            // If the last element was dequeued, reset the queue
            front = -1;
            rear = -1;
        } else {
            // Move front to the next element
            front++;
        }
    }

    // (iii) isEmpty(): Checks if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // (iv) isFull(): Checks if the queue is full
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // (v) display(): Displays all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // (vi) peek(): Shows the front element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return;
        }
        cout << "The front element is: " << arr[front] << endl;
    }
};

int main() {
    Queue myQueue;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue (Add)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Peek (See Front)" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                myQueue.enqueue(value);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                if (myQueue.isEmpty()) {
                    cout << "Result: Queue is Empty." << endl;
                } else {
                    cout << "Result: Queue is NOT Empty." << endl;
                }
                break;
            case 4:
                if (myQueue.isFull()) {
                    cout << "Result: Queue is Full." << endl;
                } else {
                    cout << "Result: Queue is NOT Full." << endl;
                }
                break;
            case 5:
                myQueue.display();
                break;
            case 6:
                myQueue.peek();
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