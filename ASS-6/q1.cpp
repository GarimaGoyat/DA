#include <iostream>

using namespace std;

// --- Doubly Linked List Implementation ---

struct DNode { // Node for Doubly Linked List
    int data;
    DNode* next;
    DNode* prev;
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode{val, head, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }
        cout << val << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode{val, nullptr, tail};
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << val << " inserted at the end." << endl;
    }
    
    void insertAfter(int target, int val) {
        DNode* temp = search(target);
        if (!temp) {
            cout << "Node " << target << " not found." << endl;
            return;
        }
        if (temp == tail) {
            insertAtEnd(val);
            return;
        }
        DNode* newNode = new DNode{val, temp->next, temp};
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << val << " inserted after " << target << "." << endl;
    }

    void insertBefore(int target, int val) {
        DNode* temp = search(target);
         if (!temp) {
            cout << "Node " << target << " not found." << endl;
            return;
        }
        if (temp == head) {
            insertAtBeginning(val);
            return;
        }
        DNode* newNode = new DNode{val, temp, temp->prev};
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << val << " inserted before " << target << "." << endl;
    }

    void deleteSpecific(int val) {
        DNode* nodeToDelete = search(val);
        if (!nodeToDelete) {
            cout << "Node " << val << " not found." << endl;
            return;
        }
        if (nodeToDelete == head) head = head->next;
        if (nodeToDelete == tail) tail = tail->prev;
        if (nodeToDelete->next != nullptr) nodeToDelete->next->prev = nodeToDelete->prev;
        if (nodeToDelete->prev != nullptr) nodeToDelete->prev->next = nodeToDelete->next;
        
        delete nodeToDelete;
        cout << "Node " << val << " deleted." << endl;
    }

    DNode* search(int val) {
        DNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    
    void display() {
        if (!head) { cout << "List is empty." << endl; return; }
        DNode* temp = head;
        cout << "HEAD <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "TAIL" << endl;
    }
};


// --- Circular Singly Linked List Implementation ---

struct CNode { // Node for Circular List
    int data;
    CNode* next;
};

class CircularLinkedList {
private:
    CNode* last;

public:
    CircularLinkedList() { last = nullptr; }

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next; // New node points to old head
            last->next = newNode;       // Last node points to new head
        }
        cout << val << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next; // New node points to head
            last->next = newNode;       // Old last points to new last
            last = newNode;             // Update last pointer
        }
        cout << val << " inserted at the end." << endl;
    }

    void deleteSpecific(int val) {
        if (!last) { cout << "List is empty." << endl; return; }

        CNode* current = last->next; // Head
        CNode* prev = last;
        
        do {
            if (current->data == val) {
                if (current == last && current->next == last) { // Only one node
                    last = nullptr;
                } else {
                    prev->next = current->next;
                    if (current == last) { // Deleting last node
                        last = prev;
                    }
                }
                delete current;
                cout << "Node " << val << " deleted." << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != last->next);
        cout << "Node " << val << " not found." << endl;
    }

    CNode* search(int val) {
        if (!last) return nullptr;
        CNode* temp = last->next;
        do {
            if (temp->data == val) return temp;
            temp = temp->next;
        } while (temp != last->next);
        return nullptr;
    }
    
    void display() {
        if (!last) { cout << "List is empty." << endl; return; }
        CNode* temp = last->next;
        cout << "HEAD -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "HEAD" << endl;
    }
};


// --- Main Menu Functions ---

void doublyMenu() {
    DoublyLinkedList dll;
    int choice, value, target;
    // ... Menu logic for DLL ...
    do {
        cout << "\n--- Doubly Linked List Menu ---\n1. Insert\n2. Delete Specific\n3. Search\n4. Display\n0. Back\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Insert (1-Begin, 2-End, 3-After, 4-Before): ";
                int insChoice; cin >> insChoice;
                cout << "Enter value: "; cin >> value;
                if (insChoice == 1) dll.insertAtBeginning(value);
                else if (insChoice == 2) dll.insertAtEnd(value);
                else if (insChoice == 3 || insChoice == 4) {
                    cout << "Enter target node value: "; cin >> target;
                    if (insChoice == 3) dll.insertAfter(target, value);
                    else dll.insertBefore(target, value);
                }
                break;
            case 2: cout << "Enter value to delete: "; cin >> value; dll.deleteSpecific(value); break;
            case 3: cout << "Enter value to search: "; cin >> value; 
                    if (dll.search(value)) cout << "Node " << value << " found." << endl;
                    else cout << "Node " << value << " not found." << endl;
                    break;
            case 4: dll.display(); break;
        }
    } while (choice != 0);
}

void circularMenu() {
    CircularLinkedList cll;
    int choice, value;
    // ... Menu logic for CSLL ...
    do {
        cout << "\n--- Circular Linked List Menu ---\n1. Insert at Beginning\n2. Insert at End\n3. Delete Specific\n4. Search\n5. Display\n0. Back\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; cll.insertAtBeginning(value); break;
            case 2: cout << "Enter value: "; cin >> value; cll.insertAtEnd(value); break;
            case 3: cout << "Enter value to delete: "; cin >> value; cll.deleteSpecific(value); break;
            case 4: cout << "Enter value to search: "; cin >> value; 
                    if (cll.search(value)) cout << "Node " << value << " found." << endl;
                    else cout << "Node " << value << " not found." << endl;
                    break;
            case 5: cll.display(); break;
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        cout << "\n--- MAIN MENU ---\n1. Doubly Linked List\n2. Circular Linked List\n0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) doublyMenu();
        else if (choice == 2) circularMenu();
    } while (choice != 0);
    
    cout << "Exiting. Goodbye!" << endl;
    return 0;
}