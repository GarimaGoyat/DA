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

    // (a) Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning." << endl;
    }

    // (b) Insertion at the end
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
        cout << value << " inserted at the end." << endl;
    }

    // (c) Insertion in between (after a specific node)
    void insertAfterNode(int targetValue, int newValue) {
        Node* temp = head;
        // Find the node with the target value
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << targetValue << " not found." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = newValue;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << newValue << " inserted after " << targetValue << "." << endl;
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning." << endl;
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (head->next == nullptr) {
            // Only one node in the list
            deleteFromBeginning();
            return;
        }

        Node* second_last = head;
        while (second_last->next->next != nullptr) {
            second_last = second_last->next;
        }

        Node* lastNode = second_last->next;
        second_last->next = nullptr;
        cout << lastNode->data << " deleted from the end." << endl;
        delete lastNode;
    }

    // (f) Deletion of a specific node
    void deleteSpecificNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* temp = head;
        // If the head node itself needs to be deleted
        if (temp->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        prev->next = temp->next;
        cout << temp->data << " has been deleted." << endl;
        delete temp;
    }

    // (g) Search for a node and display its position
    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Found " << value << " at position " << position << "." << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Node with value " << value << " not found in the list." << endl;
    }

    // (h) Display all the node values
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: HEAD -> ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    int choice, value, target;

    do {
        cout << "\n--- Singly Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After a Node" << endl;
        cout << "4. Delete from Beginning" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete a Specific Node" << endl;
        cout << "7. Search for a Node" << endl;
        cout << "8. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                sll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                sll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter the new value: ";
                cin >> value;
                cout << "Enter the value of the node to insert after: ";
                cin >> target;
                sll.insertAfterNode(target, value);
                break;
            case 4:
                sll.deleteFromBeginning();
                break;
            case 5:
                sll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                sll.deleteSpecificNode(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                sll.search(value);
                break;
            case 8:
                sll.display();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}