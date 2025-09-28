#include <iostream>
#include <queue>
#include <algorithm> // For std::swap

// Use the standard namespace as requested
using namespace std;

// --- Implementation (a): Using Two Queues ---
class StackWithTwoQueues {
private:
    queue<int> q1; // This will hold the stack elements in LIFO order
    queue<int> q2; // Helper queue

public:
    // Push operation is made costly (O(N))
    void push(int value) {
        // 1. Add the new element to the empty helper queue
        q2.push(value);

        // 2. Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // 3. Swap the names of q1 and q2 so q1 is the main queue again
        swap(q1, q2);
        
        cout << value << " pushed to the stack." << endl;
    }

    // Pop operation is efficient (O(1))
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        int popped_value = q1.front();
        q1.pop();
        cout << popped_value << " popped from the stack." << endl;
    }

    // Top operation is efficient (O(1))
    void top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << q1.front() << endl;
    }

    bool isEmpty() {
        return q1.empty();
    }
};
/*
Step 1: Push(1)
1 is added to the helper queue, q2.

We move everything from q1 (which is empty) to q2.

We swap the queues.

Final State:

q1: {1}

q2: {}

Step 2: Push(2)
2 is added to the helper queue, q2.

q1: {1}

q2: {2}

We move everything from q1 over to q2, behind 2.

q1: {}

q2: {2, 1}

We swap the queues.

Final State:

q1: {2, 1}

q2: {}

*/


// --- Implementation (b): Using One Queue ---
class StackWithOneQueue {
private:
    queue<int> q;

public:
    // Push operation is made costly (O(N))
    void push(int value) {
        // Get the original size of the queue
        int s = q.size();

        // Add the new element to the back
        q.push(value);

        // Rotate the queue 's' times to bring the new element to the front
        for (int i = 0; i < s; i++) {
            // Take the front element and move it to the back
            q.push(q.front());
            q.pop();
        }
        cout << value << " pushed to the stack." << endl;
    }

    // Pop operation is efficient (O(1))
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        int popped_value = q.front();
        q.pop();
        cout << popped_value << " popped from the stack." << endl;
    }

    // Top operation is efficient (O(1))
    void top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << q.front() << endl;
    }

    bool isEmpty() {
        return q.empty();
    }
};
/*
Let's build a stack by pushing the numbers 1, 2, and then 3.

Step 1: Push(1)
The queue is empty. We just add 1.

Queue State: {1}

Step 2: Push(2)
The queue is {1}. (There is 1 old element).

Action:

Add the new element 2 to the back: {1, 2}.

Rotate the 1 old element (1) from the front to the back.

Queue State: {2, 1}

*/

// --- Menu Functions for Demonstration ---

void menuForTwoQueues() {
    StackWithTwoQueues s;
    int choice, value;
    do {
        cout << "\n--- Stack with Two Queues ---" << endl;
        cout << "1. Push\n2. Pop\n3. Top\n0. Back to Main Menu\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; s.push(value); break;
            case 2: s.pop(); break;
            case 3: s.top(); break;
        }
    } while (choice != 0);
}

void menuForOneQueue() {
    StackWithOneQueue s;
    int choice, value;
    do {
        cout << "\n--- Stack with One Queue ---" << endl;
        cout << "1. Push\n2. Pop\n3. Top\n0. Back to Main Menu\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; s.push(value); break;
            case 2: s.pop(); break;
            case 3: s.top(); break;
        }
    } while (choice != 0);
}


int main() {
    int choice;
    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "Select the stack implementation to test:" << endl;
        cout << "1. Stack using TWO Queues" << endl;
        cout << "2. Stack using ONE Queue" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            menuForTwoQueues();
        } else if (choice == 2) {
            menuForOneQueue();
        } else if (choice == 0) {
            cout << "Exiting. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}