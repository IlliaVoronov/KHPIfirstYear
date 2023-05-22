#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows);
        for (int i = 0; i < rows; i++) {
            data[i].resize(cols);
        }
    }

    // Destructor
    ~Matrix() {}

    // Overload addition operator
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Overload subtraction operator
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Overload multiplication operator
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Get item by index
    int& operator()(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of range.");
        }
        return data[row][col];
    }

    // Overload stream input operator
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    // Overload stream output operator
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix.data[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }
  int rows;
  int cols;
private:
    
    std::vector<std::vector<int>> data;
};

void transformArray(Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (matrix(i,j) % 2 == 1) { 
                matrix(i,j) *= 2;
            }
        }
    }
}

int main() {
    // Create a 2x2 matrix
    Matrix matrix(2, 2);

    // Set the values of the matrix
    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;

    // Print the original matrix
    std::cout << "Original matrix:\n" << matrix << '\n';

    // Transform the array using the transformArray function
    transformArray(matrix);

    // Print the transformed matrix
    std::cout << "Transformed matrix:\n" << matrix << '\n';

    return 0;
}