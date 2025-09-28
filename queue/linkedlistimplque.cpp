#include <iostream>

using namespace std;

// The basic building block of the linked list
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(int value) {
        // 1. Create a new node
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        cout << "Enqueuing " << value << "..." << endl;

        // 2. If the queue is empty, the new node is both front and rear
        if (isEmpty()) {
            front = rear = newNode;
        } 
        // 3. Otherwise, add the new node at the end and update the rear pointer
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the front of the queue (dequeue)
    void dequeue() {
        // 1. Check for queue underflow (empty queue)
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        // 2. Store the front node to delete it later
        Node* temp = front;
        cout << "Dequeuing " << front->data << "..." << endl;

        // 3. Move the front pointer ahead to the next node
        front = front->next;

        // 4. If front becomes NULL, then the queue is empty, so also set rear to NULL
        if (front == nullptr) {
            rear = nullptr;
        }

        // 5. Free the memory of the old front node
        delete temp;
    }
    
    // Function to get the front element of the queue without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }

    // Function to display the contents of the queue
    void display() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue (front to rear): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.display(); // Display empty queue

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // Display queue with 3 elements

    q.peek();    // See the front element

    q.dequeue(); // Remove 10
    q.display();

    q.dequeue(); // Remove 20
    q.dequeue(); // Remove 30
    
    q.display(); // Display empty queue again
    q.dequeue(); // Try to dequeue from an empty queue

    return 0;
}