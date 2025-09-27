#include <iostream>
#include <stack> // <-- You just need to include the stack header

using namespace std;

int main() {
    cout << "\n--- STL Stack Demo ---" << endl;
    stack<int> s; // Create a stack that holds integers

    // Push elements
    s.push(1);
    s.push(2);
    s.push(3);

    // Get the top element
    cout << "Top element is: " << s.top() << endl;

    // Pop an element
    s.pop();
    cout << "Top element after pop is: " << s.top() << endl;

    // Check if it's empty
    while (!s.empty()) {
        cout << s.top() << " is being popped." << endl;
        s.pop();
    }

    if (s.empty()) {
        cout << "The stack is now empty." << endl;
    }
    
    return 0;
}