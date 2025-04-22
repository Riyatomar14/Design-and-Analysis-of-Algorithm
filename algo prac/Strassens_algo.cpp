#include <iostream>
using namespace std;

// Function to dynamically allocate a matrix
int** createMatrix(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    return matrix;
}

// Function to delete a dynamically allocated matrix
void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to add two matrices
void add(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtract(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen's matrix multiplication function
void strassen(int** A, int** B, int** C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int** A11 = createMatrix(newSize);
    int** A12 = createMatrix(newSize);
    int** A21 = createMatrix(newSize);
    int** A22 = createMatrix(newSize);
    int** B11 = createMatrix(newSize);
    int** B12 = createMatrix(newSize);
    int** B21 = createMatrix(newSize);
    int** B22 = createMatrix(newSize);
    int** M1 = createMatrix(newSize);
    int** M2 = createMatrix(newSize);
    int** M3 = createMatrix(newSize);
    int** M4 = createMatrix(newSize);
    int** M5 = createMatrix(newSize);
    int** M6 = createMatrix(newSize);
    int** M7 = createMatrix(newSize);
    int** T1 = createMatrix(newSize);
    int** T2 = createMatrix(newSize);

    // Splitting matrices into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    add(A11, A22, T1, newSize);
    add(B11, B22, T2, newSize);
    strassen(T1, T2, M1, newSize);

    // M2 = (A21 + A22) * B11
    add(A21, A22, T1, newSize);
    strassen(T1, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtract(B12, B22, T1, newSize);
    strassen(A11, T1, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtract(B21, B11, T1, newSize);
    strassen(A22, T1, M4, newSize);

    // M5 = (A11 + A12) * B22
    add(A11, A12, T1, newSize);
    strassen(T1, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtract(A21, A11, T1, newSize);
    add(B11, B12, T2, newSize);
    strassen(T1, T2, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtract(A12, A22, T1, newSize);
    add(B21, B22, T2, newSize);
    strassen(T1, T2, M7, newSize);

    // Computing final submatrices of result
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];       // C11
            C[i][j + newSize] = M3[i][j] + M5[i][j];                   // C12
            C[i + newSize][j] = M2[i][j] + M4[i][j];                   // C21
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j]; // C22
        }
    }

    // Free memory
    deleteMatrix(A11, newSize);
    deleteMatrix(A12, newSize);
    deleteMatrix(A21, newSize);
    deleteMatrix(A22, newSize);
    deleteMatrix(B11, newSize);
    deleteMatrix(B12, newSize);
    deleteMatrix(B21, newSize);
    deleteMatrix(B22, newSize);
    deleteMatrix(M1, newSize);
    deleteMatrix(M2, newSize);
    deleteMatrix(M3, newSize);
    deleteMatrix(M4, newSize);
    deleteMatrix(M5, newSize);
    deleteMatrix(M6, newSize);
    deleteMatrix(M7, newSize);
    deleteMatrix(T1, newSize);
    deleteMatrix(T2, newSize);
}

// Utility to print matrix
void printMatrix(int** A, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter size of matrix (power of 2): ";
    cin >> size;

    int** A = createMatrix(size);
    int** B = createMatrix(size);
    int** C = createMatrix(size);

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> B[i][j];

    strassen(A, B, C, size);

    cout << "Product Matrix:\n";
    printMatrix(C, size);

    // Free memory
    deleteMatrix(A, size);
    deleteMatrix(B, size);
    deleteMatrix(C, size);

    return 0;
}
