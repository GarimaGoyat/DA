#include <iostream>
#include <stack>
#include <string>

using namespace std;

// A helper function to check if a character is an operator
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

// The main function to perform the conversion
string postfixToInfix(string postfix) {
    stack<string> s;

    // 1. Scan the expression from left to right
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // 2. If it's an operand, push it onto the stack
        if (!isOperator(c)) {
            // Convert char to string and push
            s.push(string(1, c));
        }
        // 3. If it's an operator
        else {
            // Pop the top two operands
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Create the new infix string and push it back
            string new_expr = "(" + op2 + c + op1 + ")";
            s.push(new_expr);
        }
    }

    // 4. The final result is the only item left in the stack
    return s.top();
}


int main() {
    // Example 1: A simple expression
    string postfix_expr1 = "ab+c*";
    cout << "Postfix:  " << postfix_expr1 << endl;
    cout << "Infix:    " << postfixToInfix(postfix_expr1) << endl;
    cout << "--------------------------" << endl;

    // Example 2: From slide 32 of your PPT
    string postfix_expr2 = "abc-+de-fg-h+/*";
    cout << "Postfix:  " << postfix_expr2 << endl;
    cout << "Infix:    " << postfixToInfix(postfix_expr2) << endl;
    cout << "--------------------------" << endl;
    
    // Example 3: From slide 30 of your PPT
    string postfix_expr3 = "562+*124/-";
    cout << "Postfix:  " << postfix_expr3 << endl;
    cout << "Infix:    " << postfixToInfix(postfix_expr3) << endl;

    return 0;
}