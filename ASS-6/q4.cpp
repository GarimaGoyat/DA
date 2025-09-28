#include <iostream>

using namespace std;

// The structure for each node in the doubly linked list
struct DNode {
    char data;
    DNode* next;
    DNode* prev;
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Helper function to easily add nodes to the end for setup
    void insertAtEnd(char val) {
        DNode* newNode = new DNode{val, nullptr, tail};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Helper function to display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * @brief Checks if the doubly linked list of characters is a palindrome.
     * @return True if it is a palindrome, false otherwise.
     */
    bool isPalindrome() {
        // An empty list or a list with a single node is always a palindrome.
        if (head == nullptr || head == tail) {
            return true;
        }

        DNode* start = head;
        DNode* end = tail;

        // Loop until the pointers meet or cross each other
        // `start->prev != end` handles the even-length case when they cross
        while (start != end && start->prev != end) {
            // If characters at the two ends do not match, it's not a palindrome
            if (start->data != end->data) {
                return false;
            }

            // Move pointers one step closer to the middle
            start = start->next;
            end = end->prev;
        }

        // If the loop completes without finding a mismatch, it is a palindrome
        return true;
    }
};

int main() {
    // --- Test Case 1: Palindrome with odd length ---
    DoublyLinkedList dll1;
    dll1.insertAtEnd('m');
    dll1.insertAtEnd('a');
    dll1.insertAtEnd('d');
    dll1.insertAtEnd('a');
    dll1.insertAtEnd('m');
    cout << "List 1: ";
    dll1.display();
    cout << "Is it a palindrome? " << (dll1.isPalindrome() ? "Yes" : "No") << endl;

    cout << "\n----------------------------------------\n" << endl;

    // --- Test Case 2: Palindrome with even length ---
    DoublyLinkedList dll2;
    dll2.insertAtEnd('n');
    dll2.insertAtEnd('o');
    dll2.insertAtEnd('o');
    dll2.insertAtEnd('n');
    cout << "List 2: ";
    dll2.display();
    cout << "Is it a palindrome? " << (dll2.isPalindrome() ? "Yes" : "No") << endl;
    
    cout << "\n----------------------------------------\n" << endl;

    // --- Test Case 3: Not a palindrome ---
    DoublyLinkedList dll3;
    dll3.insertAtEnd('h');
    dll3.insertAtEnd('e');
    dll3.insertAtEnd('l');
    dll3.insertAtEnd('l');
    dll3.insertAtEnd('o');
    cout << "List 3: ";
    dll3.display();
    cout << "Is it a palindrome? " << (dll3.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}