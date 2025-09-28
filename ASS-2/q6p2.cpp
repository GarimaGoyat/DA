#include <iostream>
#include <vector>

using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
};

int main() {
    // Two sparse matrices to be added
    vector<Triplet> matrixA = {{0, 0, 1}, {1, 2, 3}, {2, 1, 5}};
    vector<Triplet> matrixB = {{0, 0, 2}, {1, 1, 4}, {2, 1, 6}};

    vector<Triplet> result;
    int i = 0, j = 0; // Pointers for matrixA and matrixB

    while (i < matrixA.size() && j < matrixB.size()) {
        // Case 1: If triplet from A is at an earlier position
        if (matrixA[i].row < matrixB[j].row || (matrixA[i].row == matrixB[j].row && matrixA[i].col < matrixB[j].col)) {
            result.push_back(matrixA[i]);
            i++;
        }
        // Case 2: If triplet from B is at an earlier position
        else if (matrixB[j].row < matrixA[i].row || (matrixB[j].row == matrixA[i].row && matrixB[j].col < matrixA[i].col)) {
            result.push_back(matrixB[j]);
            j++;
        }
        // Case 3: Both triplets are at the same position
        else {
            int sum = matrixA[i].value + matrixB[j].value;
            if (sum != 0) {
                result.push_back({matrixA[i].row, matrixA[i].col, sum});
            }
            i++;
            j++;
        }
    }

    // Add any remaining elements from either matrix
    while (i < matrixA.size()) result.push_back(matrixA[i++]);
    while (j < matrixB.size()) result.push_back(matrixB[j++]);

    // Display the result
    cout << "--- Result of Addition ---" << endl;
    cout << "Row\tCol\tValue" << endl;
    cout << "---\t---\t-----" << endl;
    for (const auto& triplet : result) {
        cout << triplet.row << "\t" << triplet.col << "\t" << triplet.value << endl;
    }

    return 0;
}