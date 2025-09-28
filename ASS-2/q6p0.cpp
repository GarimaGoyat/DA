#include <iostream>
#include <vector>

// Use the standard namespace as requested
using namespace std;

// This structure holds the row, column, and value for a non-zero element.
struct Triplet {
    int row;
    int col;
    int value;
};

int main() {
    // A sample 2D matrix with many zeros
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // A vector to store our triplets (the sparse representation)
    vector<Triplet> sparseMatrix;

    // Loop through the 2D matrix to find non-zero elements
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                // If the element is not zero, add it to our list of triplets
                sparseMatrix.push_back({i, j, matrix[i][j]});
            }
        }
    }

    // Display the final sparse matrix in triplet format
    cout << "--- Sparse Matrix in Triplet Form ---" << endl;
    cout << "Row\tCol\tValue" << endl;
    cout << "---\t---\t-----" << endl;
    for (const auto& triplet : sparseMatrix) {
        cout << triplet.row << "\t" << triplet.col << "\t" << triplet.value << endl;
    }

    return 0;
}