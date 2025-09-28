#include <iostream>
#include <vector>

using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
};

int main() {
    // Dimensions of the matrices
    int rowsA = 4, colsA = 3;
    int rowsB = 3, colsB = 4;

    // A(4x3) * B(3x4) -> C(4x4)
    vector<Triplet> matrixA = {{0, 0, 1}, {1, 1, 2}, {2, 2, 3}, {3, 0, 4}};
    vector<Triplet> matrixB = {{0, 0, 5}, {1, 1, 6}, {2, 2, 7}};

    // Create a normal 2D result matrix, initialized to zeros
    vector<vector<int>> resultMatrix(rowsA, vector<int>(colsB, 0));

    // Perform the multiplication logic
    for (const auto& tA : matrixA) {
        for (const auto& tB : matrixB) {
            // The key condition for matrix multiplication
            if (tA.col == tB.row) {
                resultMatrix[tA.row][tB.col] += tA.value * tB.value;
            }
        }
    }

    // Convert the 2D result matrix back to a sparse triplet list
    vector<Triplet> finalResult;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            if (resultMatrix[i][j] != 0) {
                finalResult.push_back({i, j, resultMatrix[i][j]});
            }
        }
    }

    // Display the final result
    cout << "--- Result of Multiplication ---" << endl;
    cout << "Row\tCol\tValue" << endl;
    cout << "---\t---\t-----" << endl;
    for (const auto& triplet : finalResult) {
        cout << triplet.row << "\t" << triplet.col << "\t" << triplet.value << endl;
    }

    return 0;
}