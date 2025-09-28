#include <iostream>
#include <queue>    // Include the queue library
#include <vector>   // Used for easy initialization of the queue

// Use the standard namespace as requested
using namespace std;

/**
 * @brief Interleaves the first half of a queue with its second half.
 *
 * This function modifies the queue in-place.
 * It assumes the queue has an even number of elements.
 *
 * @param q The queue to be interleaved (passed by reference).
 */
void interleaveQueue(queue<int>& q) {
    // Pre-condition: The queue must have an even number of elements.
    if (q.size() % 2 != 0) {
        cout << "Cannot interleave a queue with an odd number of elements." << endl;
        return;
    }

    // 1. Create a temporary queue to store the first half.
    queue<int> first_half;
    int half_size = q.size() / 2;

    // 2. Dequeue the first half of the original queue and enqueue it
    //    into the temporary 'first_half' queue.
    cout << "Step 1: Separating the first half..." << endl;
    for (int i = 0; i < half_size; i++) {
        first_half.push(q.front());
        q.pop();
    }
    // At this point:
    // 'q' contains the second half: 20 5 9
    // 'first_half' contains the first half: 4 7 11

    // 3. Now, interleave. Re-build the original queue by taking one
    //    element from each half alternately.
    cout << "Step 2: Interleaving the halves..." << endl;
    while (!first_half.empty()) {
        // Enqueue an element from the first half
        q.push(first_half.front());
        first_half.pop();

        // Enqueue an element from the second half
        // (by moving it from the front to the back of 'q')
        q.push(q.front());
        q.pop();
    }
    cout << "Interleaving complete." << endl;
}

/**
 * @brief A helper function to print the contents of a queue without modifying it.
 * @param q The queue to be printed.
 */
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    // Initialize a queue with the sample data
    vector<int> data = {4, 7, 11, 20, 5, 9};
    queue<int> myQueue;
    for (int item : data) {
        myQueue.push(item);
    }

    cout << "Original Queue: ";
    printQueue(myQueue);

    cout << "\nStarting the interleaving process...\n" << endl;
    interleaveQueue(myQueue);

    cout << "\nFinal Interleaved Queue: ";
    printQueue(myQueue);

    return 0;
}