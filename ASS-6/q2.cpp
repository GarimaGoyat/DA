#include <iostream>

using namespace std;

// The structure for each node in the circular linked list
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
private:
    // A single pointer to the last node is efficient
    CNode* last;

public:
    // Constructor to initialize an empty list
    CircularLinkedList() {
        last = nullptr;
    }

    // Helper function to easily add nodes to the end of the list for setup
    void insertAtEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last; // Points to itself
        } else {
            newNode->next = last->next; // New node points to the current head
            last->next = newNode;       // Old last node points to the new node
            last = newNode;             // Update the last pointer
        }
    }

    /**
     * @brief Displays all node values, repeating the head node's value at the end.
     */
    void displayWithHeadRepeated() {
        // Step 1: Handle the empty case
        if (last == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        // Step 2: Start a temporary pointer at the head
        CNode* head = last->next;
        CNode* temp = head;

        // Step 3: Traverse the entire circle once with a do-while loop
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        
        // Step 4: After the loop, print the head's value one more time
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Create the input list: 20 -> 100 -> 40 -> 80 -> 60
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    cout << "Input: 20 -> 100 -> 40 -> 80 -> 60" << endl;
    cout << "Output: ";
    
    // Call the function to display in the required format
    cll.displayWithHeadRepeated();

    return 0;
}