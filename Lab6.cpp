#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 10; // Maximum size of the square matrix

// Function to read matrix data from a file
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    file >> size; // Read matrix size
    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "Error: Invalid matrix size." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read matrix elements
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> matrix[i][j];

    file.close();
}

// Function to display a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << std::setw(4) << matrix[i][j];
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

// Function to update an element of the matrix
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int value, int size) {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        std::cerr << "Error: Invalid row or column index." << std::endl;
        return;
    }
    matrix[row][col] = value;
}

// Function to find the maximum value in the matrix
int findMax(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (matrix[i][j] > maxVal)
                maxVal = matrix[i][j];
    return maxVal;
}

// Function to transpose a matrix
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int transposed[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            transposed[j][i] = matrix[i][j];
    printMatrix(transposed, size);
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    // Read matrices from file
    readMatrix(matrix1, size, "matrix_input.txt");
    readMatrix(matrix2, size, "matrix_input.txt"); // Reading the same file 

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(matrix2, size);

    std::cout << "\nAdding Matrix 1 and Matrix 2:" << std::endl;
    addMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    std::cout << "\nMultiplying Matrix 1 and Matrix 2:" << std::endl;
    multiplyMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    std::cout << "\nSubtracting Matrix 2 from Matrix 1:" << std::endl;
    subtractMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    std::cout << "\nUpdating element at (0, 0) in Matrix 1 with value 10:" << std::endl;
    updateElement(matrix1, 0, 0, 10, size);
    printMatrix(matrix1, size);

    std::cout << "\nMax value in Matrix 1: " << findMax(matrix1, size) << std::endl;

    std::cout << "\nTransposing Matrix 1:" << std::endl;
    transposeMatrix(matrix1, size);

    return 0;
}
