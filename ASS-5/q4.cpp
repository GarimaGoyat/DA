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
        cout << " -> NULL" << endl;
    }

    /**
     * @brief Reverses the linked list in-place using an iterative approach.
     */
    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            // A list with 0 or 1 node is already reversed.
            return;
        }

        Node* previous = nullptr;
        Node* current = head;
        Node* next_node = nullptr;

        while (current != nullptr) {
            // 1. Store the next node before we break the link
            next_node = current->next;
            
            // 2. Reverse the link of the current node
            current->next = previous;
            
            // 3. Move the pointers one position ahead for the next iteration
            previous = current;
            current = next_node;
        }

        // 4. After the loop, 'previous' will be the new head
        head = previous;
    }
};

int main() {
    SinglyLinkedList sll;

    // Setup the linked list as per the input
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.insertAtEnd(4);

    cout << "Input: ";
    sll.display();

    // Reverse the linked list
    sll.reverse();

    cout << "Output: ";
    sll.display();

    return 0;
}