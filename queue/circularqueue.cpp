#include <iostream>

#define MAX_SIZE 5 // Using a smaller size for easier testing

class CircularQueue {
private:
    int elements[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        // Condition for a full queue
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Add an element
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "OVERFLOW: Queue is full!" << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // First element
        }
        // Increment rear circularly
        rear = (rear + 1) % MAX_SIZE;
        elements[rear] = value;
        std::cout << value << " enqueued to queue." << std::endl;
    }

    // Remove an element
    int dequeue() {
        if (isEmpty()) {
            std::cout << "UNDERFLOW: Queue is empty!" << std::endl;
            return -1;
        }
        int value = elements[front];
        
        // If this is the last element in the queue
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Increment front circularly
            front = (front + 1) % MAX_SIZE;
        }
        std::cout << value << " dequeued from queue." << std::endl;
        return value;
    }

    // Get the front element
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return elements[front];
    }
};