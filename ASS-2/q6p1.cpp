#include <iostream>
#include <vector>

using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
};

int main() {
    // Our original sparse matrix from the example above
    vector<Triplet> original = {
        {0, 2, 3},
        {0, 4, 4},
        {1, 2, 5},
        {1, 3, 7},
        {3, 1, 6}
    };

    vector<Triplet> transposed;

    // Loop through each triplet of the original matrix
    for (const auto& triplet : original) {
        // Create a new triplet with row and col swapped
        transposed.push_back({triplet.col, triplet.row, triplet.value});
    }

    // Display the transposed matrix
    cout << "--- Transposed Sparse Matrix ---" << endl;
    cout << "Row\tCol\tValue" << endl;
    cout << "---\t---\t-----" << endl;
    for (const auto& triplet : transposed) {
        cout << triplet.row << "\t" << triplet.col << "\t" << triplet.value << endl;
    }

    return 0;
}