#include <iostream>

#define MAX_SIZE 100

class LinearQueue {
private:
    int elements[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor to initialize an empty queue
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Add an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "OVERFLOW: Queue is full!" << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // Set front to 0 for the first element
        }
        rear++;
        elements[rear] = value;
        std::cout << value << " enqueued to queue." << std::endl;
    }

    // Remove an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "UNDERFLOW: Queue is empty!" << std::endl;
            return -1; // Return an error value
        }
        int value = elements[front];
        front++;
        std::cout << value << " dequeued from queue." << std::endl;
        // If last element was dequeued, reset the queue
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return value;
    }

    // Get the front element without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1; // Return an error value
        }
        return elements[front];
    }
    
    // Get the current size of the queue
    int size() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }
};