#include <iostream>
#include <stack>
#include <string>
#include <cctype> // Required for the isalnum() function

using namespace std;

// A helper function to determine the precedence of an operator.
// A higher value means higher precedence.
int getPrecedence(char op) {
    if (op == '^') {
        return 3;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0; // For non-operators
}

// The main function to convert the infix expression to postfix.
string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";

    for (char ch : infix) {
        // Rule 1: If the character is an operand, add it to the postfix string.
        //if (isalnum(ch)) {
        //    postfix += ch;
        //}
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        // Rule 3: If it's an opening parenthesis, push it onto the stack.
        else if (ch == '(') {
            operatorStack.push('(');
        }
        // Rule 4: If it's a closing parenthesis...
        else if (ch == ')') {
            // ...pop operators from the stack until the matching '(' is found.
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Discard the '('
        }
        // Rule 2: If the character is an operator.
        else {
            // Pop operators with higher or equal precedence from the stack.
            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(ch) <= getPrecedence(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Push the current operator onto the stack.
            operatorStack.push(ch);
        }
    }

    // Rule 5: Pop any remaining operators from the stack.
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infix_expression;

    cout << "Enter an Infix Expression: ";
    // Example: (A+B)*C-(D/E)^F
    getline(cin, infix_expression);

    string postfix_expression = infixToPostfix(infix_expression);

    cout << "\nInfix   : " << infix_expression << endl;
    cout << "Postfix : " << postfix_expression << endl;

    return 0;
}