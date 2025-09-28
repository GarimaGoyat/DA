#include <iostream>
#include <stack>   // Include the stack library
#include <string>  // Include the string library

// Use the standard namespace as requested
using namespace std;

// This function takes a string and returns its reversed version
string reverseString(string str) {
    // 1. Create an empty stack of characters
    stack<char> charStack;

    // 2. Push every character of the input string into the stack
    //    For "Data", the stack will look like this (from bottom to top): D -> a -> t -> a
    for (char c : str) {
        charStack.push(c);
    }

    string reversedString = ""; // This will store our result

    // 3. Pop characters from the stack until it's empty
    //    and add them to the result string.
    while (!charStack.empty()) {
        // Get the top character (e.g., 'a')
        reversedString += charStack.top();
        
        // Remove the top character from the stack
        charStack.pop();
    }

    return reversedString;
}

int main() {
    string myString = "DataStructure";

    cout << "Original string: " << myString << endl;

    string reversed = reverseString(myString);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}