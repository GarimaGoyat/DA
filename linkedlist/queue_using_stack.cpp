#include <iostream>
#include <stack>

// Use the standard namespace as requested
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1; // The "inbox" stack
    stack<int> s2; // The "outbox" stack

public:
    // Enqueues an integer i at the rear of the queue.
    void enqueue(int i) {
        cout << "enqueue(" << i << ")" << endl;
        // Always push new elements onto the first stack (inbox).
        s1.push(i);
    }

    // Deletes an integer from the front of the queue and returns its value.
    int dequeue() {
        cout << "dequeue()... ";
        
        // If the second stack (outbox) is empty, we need to transfer
        // elements from the first stack to reverse their order.
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // If s2 is still empty after the potential transfer, the queue is empty.
        if (s2.empty()) {
            cout << "Error: Queue is empty." << endl;
            return -1; // Return an error code
        }

        // The top of s2 is now the oldest element (the front of the queue).
        int front_value = s2.top();
        s2.pop();
        
        cout << "-> returned " << front_value << endl;
        return front_value;
    }

    // Helper function to see the state of the stacks
    void printStacks() {
        // Create copies to print without modifying the originals
        stack<int> temp1 = s1;
        stack<int> temp2 = s2;
        
        cout << "  State -> s1 (inbox): ";
        while(!temp1.empty()) { cout << temp1.top() << " "; temp1.pop(); }
        cout << " | s2 (outbox): ";
        while(!temp2.empty()) { cout << temp2.top() << " "; temp2.pop(); }
        cout << endl << "---------------------------------------------" << endl;
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(4);
    q.printStacks();

    q.enqueue(6);
    q.printStacks();

    q.enqueue(1);
    q.printStacks();
    
    q.dequeue();
    q.printStacks();

    q.enqueue(9);
    q.printStacks();

    q.enqueue(5);
    q.printStacks();

    q.dequeue();
    q.printStacks();

    return 0;
}