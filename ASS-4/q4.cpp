#include <iostream>
#include <string>
#include <queue>
#include <vector>

// Use the standard namespace as requested
using namespace std;

/**
 * @brief Finds the first non-repeating character for each character in a stream.
 * * @param stream A string representing the stream of characters (without spaces).
 */
void findFirstNonRepeating(string stream) {
    // 1. Initialize data structures
    // Queue to store characters in the order they appear.
    queue<char> q;
    
    // Frequency array to count character occurrences (ASCII has 256 characters).
    vector<int> frequency(256, 0); 
    
    cout << "Output Stream: ";

    // 2. Process the stream character by character
    for (char ch : stream) {
        // Increment the frequency of the current character
        frequency[ch]++;
        
        // Push the character to the queue
        q.push(ch);

        // 3. Clean the queue: Remove all repeating characters from the front.
        // A character is repeating if its frequency is > 1.
        while (!q.empty() && frequency[q.front()] > 1) {
            q.pop();
        }

        // 4. Determine the output for the current step
        if (q.empty()) {
            // If the queue is empty, all characters seen so far are repeating.
            cout << "-1 ";
        } else {
            // The front of the queue is the first non-repeating character.
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input_with_spaces;
    cout << "Enter the character stream (e.g., a a b c): ";
    getline(cin, input_with_spaces);

    // Create a new string without spaces to simulate the stream
    string stream = "";
    for (char ch : input_with_spaces) {
        if (ch != ' ') {
            stream += ch;
        }
    }

    cout << "\nProcessed Input Stream: " << stream << endl;
    findFirstNonRepeating(stream);

    return 0;
}