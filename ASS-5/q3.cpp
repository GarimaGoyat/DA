#include <iostream>

using namespace std;

// The structure for each node in the linked list
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
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

    // Helper function to display the list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * @brief Finds the middle node of the linked list using the slow/fast pointer method.
     */
    void findMiddle() {
        // Handle empty or single-node lists
        if (head == nullptr) {
            cout << "The list is empty, so there is no middle node." << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        // Traverse the list. The loop condition handles both even and odd length lists.
        // 1. `fast != nullptr`: For even lists, fast will become null.
        // 2. `fast->next != nullptr`: For odd lists, fast->next will become null.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move slow pointer by one
            fast = fast->next->next; // Move fast pointer by two
        }

        // When the loop ends, 'slow' will be pointing to the middle node.
        cout << "The middle of the linked list is: " << slow->data << endl;
    }
};

int main() {
    // --- Test Case 1: Odd number of elements ---
    SinglyLinkedList sll_odd;
    sll_odd.insertAtEnd(1);
    sll_odd.insertAtEnd(2);
    sll_odd.insertAtEnd(3);
    sll_odd.insertAtEnd(4);
    sll_odd.insertAtEnd(5);

    cout << "Input (Odd): ";
    sll_odd.display();
    sll_odd.findMiddle();

    cout << "\n-------------------------------------\n" << endl;

    // --- Test Case 2: Even number of elements ---
    SinglyLinkedList sll_even;
    sll_even.insertAtEnd(1);
    sll_even.insertAtEnd(2);
    sll_even.insertAtEnd(3);
    sll_even.insertAtEnd(4);
    sll_even.insertAtEnd(5);
    sll_even.insertAtEnd(6);
    
    cout << "Input (Even): ";
    sll_even.display();
    sll_even.findMiddle();

    return 0;
}