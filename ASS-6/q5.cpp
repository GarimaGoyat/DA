#include <iostream>

using namespace std;

// The structure for each node in the linked list
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
public:
    Node* head;

    // Constructor to initialize an empty list
    SinglyLinkedList() {
        head = nullptr;
    }

    // Helper function to easily add nodes to the end of the list for setup
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Helper function to display the list (will loop infinitely if circular)
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    /**
     * @brief Checks if the linked list is circular using the slow/fast pointer method.
     * @return True if the list is circular, false otherwise.
     */
    bool isCircular() {
        // An empty or single-node list cannot be circular in this context.
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        Node* slow = head;
        Node* fast = head;

        // Traverse the list with two pointers
        // The condition must check fast AND fast->next to avoid errors on the jump
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move slow pointer by one
            fast = fast->next->next; // Move fast pointer by two

            // If the pointers meet, a cycle is detected
            if (slow == fast) {
                return true;
            }
        }

        // If the loop completes, it means 'fast' reached the end (NULL)
        return false;
    }
};

int main() {
    // --- Test Case 1: A normal, non-circular linked list ---
    SinglyLinkedList sll_linear;
    sll_linear.insertAtEnd(1);
    sll_linear.insertAtEnd(2);
    sll_linear.insertAtEnd(3);
    sll_linear.insertAtEnd(4);

    cout << "List 1: ";
    sll_linear.display();
    cout << "Is List 1 circular? " << (sll_linear.isCircular() ? "Yes" : "No") << endl;

    cout << "\n----------------------------------------\n" << endl;

    // --- Test Case 2: A circular linked list ---
    SinglyLinkedList sll_circular;
    sll_circular.insertAtEnd(10);
    sll_circular.insertAtEnd(20);
    sll_circular.insertAtEnd(30);
    sll_circular.insertAtEnd(40);

    cout << "List 2: 10 -> 20 -> 30 -> 40 -> (points back to head)" << endl;
    
    // Manually create the cycle for testing purposes
    // Get the last node and link it back to the head
    Node* temp = sll_circular.head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = sll_circular.head; // Creates the circle

    cout << "Is List 2 circular? " << (sll_circular.isCircular() ? "Yes" : "No") << endl;

    return 0;
}