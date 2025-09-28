#include <iostream>
#include <vector>
#include <utility> // Required for std::swap

using namespace std;

int main() {
    // --- Insertion Sort using swap ---
    cout << "--- Insertion Sort (using swap) ---" << endl;

    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    // Start from the second element
    for (int i = 1; i < n; i++) {
        // 'j' is the index of the element we want to insert correctly
        int j = i;

        // Keep swapping the element at 'j' with the one to its left
        // as long as it's smaller than its left neighbor.
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            // Move our focus one position to the left
            j--;
        }
    }

    cout << "Sorted array:   ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}


/*#include <iostream>
#include <vector>

using namespace std;

int main() {
    // --- Insertion Sort ---
    cout << "--- Insertion Sort ---" << endl;

    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    // Start from the second element (the first element is a sorted sub-array of size 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key,
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout << "Sorted array:   ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}*/