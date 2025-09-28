#include <iostream>

using namespace std;

// --- i. Doubly Linked List ---

struct DNode { // Node for Doubly Linked List
    int data;
    DNode* next;
    DNode* prev;
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() { head = nullptr; }

    // Helper to add nodes
    void insertAtEnd(int val) {
        DNode* newNode = new DNode{val, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to find the size
    int findSize() {
        int count = 0;
        DNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};


// --- ii. Circular Linked List ---

struct CNode { // Node for Circular List
    int data;
    CNode* next;
};

class CircularLinkedList {
private:
    CNode* last;

public:
    CircularLinkedList() { last = nullptr; }

    // Helper to add nodes
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
    
    // Function to find the size
    int findSize() {
        // Handle the empty list case
        if (last == nullptr) {
            return 0;
        }

        int count = 0;
        CNode* head = last->next;
        CNode* temp = head;

        // Use a do-while loop to traverse the circle once
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        
        return count;
    }
};


int main() {
    // --- Test Doubly Linked List ---
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    cout << "i. Doubly Linked List" << endl;
    cout << "   List contains: 10, 20, 30, 40" << endl;
    cout << "   Size of Doubly Linked List: " << dll.findSize() << endl;

    cout << "\n-------------------------------------\n" << endl;

    // --- Test Circular Linked List ---
    CircularLinkedList cll;
    cll.insertAtEnd(5);
    cll.insertAtEnd(15);
    cll.insertAtEnd(25);
    cout << "ii. Circular Linked List" << endl;
    cout << "    List contains: 5, 15, 25" << endl;
    cout << "    Size of Circular Linked List: " << cll.findSize() << endl;
    
    // --- Test empty Circular Linked List ---
    CircularLinkedList empty_cll;
    cout << "\n    Testing empty Circular Linked List:" << endl;
    cout << "    Size of empty Circular Linked List: " << empty_cll.findSize() << endl;


    return 0;
}