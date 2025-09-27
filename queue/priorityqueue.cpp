// USING ARRAY IMPLEMENTATION

#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

// The structure for an item, as shown in the PDF
struct Item {
    int value;
    int priority;
};

class ArrayPriorityQueue {
private:
    // Using a vector for dynamic resizing, but the logic is the same
    vector<Item> pq;

public:
    // Check if the queue is empty
    bool isEmpty() {
        return pq.empty();
    }

    // Enqueue: Adds an item to the end of the array (O(1))
    void enqueue(int value, int priority) {
        Item newItem;
        newItem.value = value;
        newItem.priority = priority;
        pq.push_back(newItem);
        cout << "Enqueued {value: " << value << ", priority: " << priority << "}" << endl;
    }

    // Peek: Finds the index of the highest priority item (O(N))
    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return -1;
        }

        int highestPriority = INT_MIN;
        int index = -1;

        // Loop through the entire array to find the highest priority
        for (int i = 0; i < pq.size(); i++) {
            // If priorities are the same, the PDF's code gives precedence
            // to the one with the larger value. We will replicate that.
            if (highestPriority == pq[i].priority && index > -1 && pq[index].value < pq[i].value) {
                highestPriority = pq[i].priority;
                index = i;
            } else if (highestPriority < pq[i].priority) {
                highestPriority = pq[i].priority;
                index = i;
            }
        }
        return index;
    }

    // Dequeue: Removes the highest priority item (O(N))
    void dequeue() {
        if (isEmpty()) {
            cout << "UNDERFLOW: Queue is empty, cannot dequeue." << endl;
            return;
        }

        // Find the position of the element to remove
        int indexToRemove = peek();
        
        cout << "Dequeued {value: " << pq[indexToRemove].value 
             << ", priority: " << pq[indexToRemove].priority << "}" << endl;

        // Remove the element by shifting subsequent elements
        // The erase function of vector handles this shifting
        pq.erase(pq.begin() + indexToRemove);
    }
};

int main() {
    ArrayPriorityQueue myPQ;
    myPQ.enqueue(10, 2);
    myPQ.enqueue(20, 3);
    myPQ.enqueue(5, 1);
    myPQ.enqueue(100, 3); // Same priority as 20, but higher value

    cout << "\n--- Processing Queue ---" << endl;
    myPQ.dequeue(); // Should remove {100, 3} because it has the highest priority (and higher value)
    myPQ.dequeue(); // Should remove {20, 3}
    myPQ.dequeue(); // Should remove {10, 2}
    myPQ.dequeue(); // Should remove {5, 1}

    return 0;
}



// USING HEAP

/*#include <iostream>
#include <queue> // For priority_queue

// Use the standard namespace as requested
using namespace std;

int main() {
    // By default, priority_queue is a Max-Heap (larger numbers have higher priority)
    priority_queue<int> pq;

    cout << "--- Pushing elements in random order ---" << endl;
    cout << "Pushing 10..." << endl;
    pq.push(10);
    cout << "Top is now: " << pq.top() << endl;

    cout << "\nPushing 30..." << endl;
    pq.push(30); // 30 will become the new top
    cout << "Top is now: " << pq.top() << endl;

    cout << "\nPushing 5..." << endl;
    pq.push(5);
    cout << "Top is still: " << pq.top() << endl;

    cout << "\nPushing 20..." << endl;
    pq.push(20);
    cout << "Top is still: " << pq.top() << endl;


    cout << "\n--- Popping elements ---" << endl;
    // The loop will extract elements in descending order of priority (value)
    while (!pq.empty()) {
        cout << "Highest priority element: " << pq.top() << ". Popping it." << endl;
        pq.pop();
    }

    return 0;
}*/