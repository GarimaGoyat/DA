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
     * @brief Counts and deletes all occurrences of a given key in the list.
     * @param key The integer value to find and delete.
     * @return The total number of occurrences found.
     */
    int countAndDeleteAll(int key) {
        int count = 0;

        // --- Part 1: Handle the Head of the List ---
        // Continuously delete the head node if it contains the key.
        while (head != nullptr && head->data == key) {
            count++;
            Node* temp = head;
            head = head->next; // Move head to the next node
            delete temp;       // Free the old head's memory
        }

        // --- Part 2: Handle the Rest of the List ---
        Node* current = head;
        // We check current->next, so we need to ensure current is not null
        while (current != nullptr && current->next != nullptr) {
            // Check if the NEXT node needs to be deleted
            if (current->next->data == key) {
                count++;
                Node* temp = current->next; // Node to be deleted
                // Bypass the node to be deleted
                current->next = current->next->next; 
                delete temp;
                // IMPORTANT: Do NOT advance 'current' here.
                // The new 'current->next' could also have the key.
            } else {
                // Only advance 'current' if the next node was not deleted
                current = current->next;
            }
        }

        return count;
    }
};

int main() {
    SinglyLinkedList sll;
    int key = 1;

    // Setup the linked list as per the input
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(3);
    sll.insertAtEnd(1);

    cout << "Input Linked List: ";
    sll.display();
    cout << "Key to delete: " << key << endl;
    cout << "---------------------------------" << endl;

    // Call the function to count and delete
    int occurrences = sll.countAndDeleteAll(key);

    cout << "Count: " << occurrences << endl;
    cout << "Updated Linked List: ";
    sll.display();

    return 0;
}