#include <iostream>

using namespace std;

// Node structure for the circular linked list
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
private:
    CNode* head;

public:
    // Constructor
    CircularLinkedList() { head = nullptr; }

    // Helper function to insert nodes at the end to build the list
    void insertAtEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself to make it circular
            return;
        }
        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Helper function to display the contents of the circular list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head " << head->data << ")" << endl;
    }

    /**
     * @brief Splits the circular linked list into two halves.
     * The original list object becomes the first half.
     * The second half is returned via the 'list2' reference parameter.
     */
    void splitList(CircularLinkedList &list2) {
        // Handle edge cases: 0, 1, or 2 nodes cannot be meaningfully split
        if (head == nullptr || head->next == head) {
            return;
        }

        // 1. Initialize slow and fast pointers
        CNode* slow_ptr = head;
        CNode* fast_ptr = head;

        // 2. Move pointers to find the middle. This loop finds the node that will be
        //    the end of the first half.
        while (fast_ptr->next != head && fast_ptr->next->next != head) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }

        // 3. If the list has an even number of nodes, the fast pointer will be at the
        //    second-to-last node. Move it to the last node.
        if (fast_ptr->next->next == head) {
            fast_ptr = fast_ptr->next;
        }

        // 4. Set the head for the first list (it's the original head)
        // CNode* head1 = head; // Not needed, already have 'this->head'

        // 5. Set the head for the second list
        list2.head = slow_ptr->next;

        // 6. Make the second list circular.
        // The last node of the original list now points to the head of the second list.
        fast_ptr->next = list2.head;

        // 7. Make the first list circular.
        // The end of the first half now points back to its own head.
        slow_ptr->next = this->head;
    }
};

int main() {
    // --- Test Case 1: Odd number of nodes ---
    cout << "--- Test Case: Odd Number of Nodes ---" << endl;
    CircularLinkedList cll_odd;
    CircularLinkedList half2_odd;
    cll_odd.insertAtEnd(1);
    cll_odd.insertAtEnd(2);
    cll_odd.insertAtEnd(3);
    cll_odd.insertAtEnd(4);
    cll_odd.insertAtEnd(5);

    cout << "Original List: ";
    cll_odd.display();

    cll_odd.splitList(half2_odd);

    cout << "First half (3 nodes):  ";
    cll_odd.display();
    cout << "Second half (2 nodes): ";
    half2_odd.display();
    
    cout << "\n----------------------------------------\n" << endl;

    // --- Test Case 2: Even number of nodes ---
    cout << "--- Test Case: Even Number of Nodes ---" << endl;
    CircularLinkedList cll_even;
    CircularLinkedList half2_even;
    cll_even.insertAtEnd(10);
    cll_even.insertAtEnd(20);
    cll_even.insertAtEnd(30);
    cll_even.insertAtEnd(40);
    cll_even.insertAtEnd(50);
    cll_even.insertAtEnd(60);

    cout << "Original List: ";
    cll_even.display();

    cll_even.splitList(half2_even);
    
    cout << "First half (3 nodes):  ";
    cll_even.display();
    cout << "Second half (3 nodes): ";
    half2_even.display();

    return 0;
}