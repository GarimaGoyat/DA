#include <iostream>
#include <stack>
#include <string>

using namespace std;

// This function returns true if the expression has balanced parentheses
bool areParenthesesBalanced(string expr) {
    stack<char> s;

    // Iterate through each character in the expression
    for (char ch : expr) {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty, there is no matching opening bracket
            if (s.empty()) {
                return false;
            }

            // Check if the top of the stack matches the current closing bracket
            if ((ch == ')' && s.top() == '(') ||
                (ch == '}' && s.top() == '{') ||
                (ch == ']' && s.top() == '[')) {
                // It's a match, so pop the opening bracket
                s.pop();
            } else {
                // Mismatch, so parentheses are not balanced
                return false;
            }
        }
    }

    // After the loop, if the stack is empty, all brackets were matched.
    // If not, there are unclosed opening brackets.
    return s.empty();
}

int main() {
    string expr1 = "{[a+b]*(c-d)}";
    string expr2 = "{[a+b]*(c-d)}}"; // Extra '}' at the end
    string expr3 = "([(a+b)]";       // Missing ')'
    string expr4 = "([)]";           // Mismatched pair

    cout << expr1 << " is " << (areParenthesesBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " is " << (areParenthesesBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << expr3 << " is " << (areParenthesesBalanced(expr3) ? "Balanced" : "Not Balanced") << endl;
    cout << expr4 << " is " << (areParenthesesBalanced(expr4) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}