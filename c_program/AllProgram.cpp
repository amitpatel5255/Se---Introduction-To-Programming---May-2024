#include <iostream>
#include <vector>

using namespace std;

// Function to input a matrix
void inputMatrix(vector<vector<int>>& matrix, int rows, int cols, const string& name) {
    cout << "Enter elements for " << name << " matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix, int rows, int cols, const string& name) {
    cout << "\n" << name << " Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& mat1, int rows1, int cols1, 
                                     const vector<vector<int>>& mat2, int rows2, int cols2) {
    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    // Matrix multiplication logic
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    cout << "Enter rows and columns for the first matrix (e.g., 2 3): ";
    cin >> rows1 >> cols1;

    // Input dimensions for the second matrix
    cout << "Enter rows and columns for the second matrix (e.g., 3 2): ";
    cin >> rows2 >> cols2;

    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Number of columns of the first matrix must equal the number of rows of the second matrix." << endl;
        return 0;
    }

    // Initialize matrices with given dimensions
    vector<vector<int>> mat1(rows1, vector<int>(cols1));
    vector<vector<int>> mat2(rows2, vector<int>(cols2));

    // Input elements for both matrices
    inputMatrix(mat1, rows1, cols1, "First");
    inputMatrix(mat2, rows2, cols2, "Second");

    // Display both matrices
    displayMatrix(mat1, rows1, cols1, "First");
    displayMatrix(mat2, rows2, cols2, "Second");

    // Multiply matrices
    vector<vector<int>> result = multiplyMatrices(mat1, rows1, cols1, mat2, rows2, cols2);

    // Display the result matrix
    displayMatrix(result, rows1, cols2, "Result");

    return 0;
}
