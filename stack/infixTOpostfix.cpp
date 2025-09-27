#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // Needed for std::reverse

using namespace std;

// Helper function to determine the precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1; // For parentheses
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        // If the character is an operand, add it to the output
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is an '(', push it to the stack
        else if (c == '(') {
            s.push('(');
        }
        // If the character is a ')', pop until '(' is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '('
        }
        // If an operator is encountered
        else {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all the remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix_expr = "A+(B*(C-D)/E)";
    cout << "--- Infix to Postfix ---" << endl;
    cout << "Infix:    " << infix_expr << endl;
    cout << "Postfix:  " << infixToPostfix(infix_expr) << endl; // Expected: ABCD-*E/+
    return 0;
}