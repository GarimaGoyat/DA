#include <iostream>
#include <stack>
#include <string>
#include <cmath> // For the pow() function used in exponentiation (^)

using namespace std;

// This function evaluates a given postfix expression.
int evaluatePostfix(string expression) {
    stack<int> s;

    // 1. Scan the expression from left to right
    for (char ch : expression) {
        // If the character is a whitespace or comma, ignore it
        if (ch == ' ' || ch == ',') {
            continue;
        }
        
        // 2. If the character is a digit (operand)...
        else if (isdigit(ch)) {
            // ...convert it to an integer and push it onto the stack.
            // The trick 'ch - '0'' converts char digit to int.
            s.push(ch - '0');
        }
        
        // 3. If the character is an operator...
        else {
            // ...pop the top two operands from the stack.
            // Note: The first pop is the second operand.
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            // Perform the operation based on the operator character
            switch (ch) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
                case '^':
                    s.push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Error: Invalid operator encountered." << endl;
                    return -1; // Indicate an error
            }
        }
    }

    // 4. The final result is the only element left in the stack.
    return s.top();
}

int main() {
    string postfix_expression;

    cout << "Enter a Postfix Expression (e.g., 23*5+): ";
    getline(cin, postfix_expression);

    int result = evaluatePostfix(postfix_expression);

    cout << "\nPostfix Expression: " << postfix_expression << endl;
    cout << "Result of Evaluation: " << result << endl;

    return 0;
}