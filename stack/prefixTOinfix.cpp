#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Helper function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert Prefix to Infix
string prefixToInfix(string prefix) {
    stack<string> s;

    // 1. Scan the expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // 2. If it's an operand, push it
        if (!isOperator(c)) {
            s.push(string(1, c));
        }
        // 3. If it's an operator
        else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            string new_expr = "(" + op1 + c + op2 + ")";
            s.push(new_expr);
        }
    }

    return s.top();
}

int main() {
    string prefix_expr = "*-A/BC-/AKL";
    cout << "--- Prefix to Infix ---" << endl;
    cout << "Prefix: " << prefix_expr << endl;
    cout << "Infix:  " << prefixToInfix(prefix_expr) << endl; // Expected: ((A-(B/C))*((A/K)-L))
    return 0;
}