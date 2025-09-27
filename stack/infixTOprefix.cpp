#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// We reuse the precedence() and infixToPostfix() functions from above

int precedence(char op) { /* ... same as above ... */ }
string infixToPostfix(string infix) { /* ... same as above ... */ }

// Function to convert Infix to Prefix
string infixToPrefix(string infix) {
    // 1. Reverse the infix string
    reverse(infix.begin(), infix.end());

    // 2. Swap parentheses
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // 3. Get the postfix of the modified string
    string postfix = infixToPostfix(infix);

    // 4. Reverse the postfix string to get the prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix_expr = "(A+B^C)*D+E^5";
    cout << "--- Infix to Prefix ---" << endl;
    cout << "Infix:  " << infix_expr << endl;
    cout << "Prefix: " << infixToPrefix(infix_expr) << endl; // Expected: +*+A^BCD^E5
    return 0;
}