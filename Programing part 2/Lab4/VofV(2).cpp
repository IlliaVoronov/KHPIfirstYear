#include <iostream>
#include <vector>
#include <stdexcept>

class MatrixException : public std::runtime_error {
public:
    explicit MatrixException(const std::string& message) : std::runtime_error(message) {}
};

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(size_t rows, size_t cols) : data(rows, std::vector<int>(cols)) {}

    int& operator()(size_t row, size_t col) {
        if (row >= data.size() || col >= data[0].size()) {
            throw MatrixException("Index out of bounds");
        }
        return data[row][col];
    }

    const int& operator()(size_t row, size_t col) const {
        if (row >= data.size() || col >= data[0].size()) {
            throw MatrixException("Index out of bounds");
        }
        return data[row][col];
    }

    size_t rows() const {
        return data.size();
    }

    size_t cols() const {
        return data.empty() ? 0 : data[0].size();
    }

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    friend std::istream& operator>>(std::istream& in, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols()) {
        throw MatrixException("Matrices have different dimensions");
    }

    Matrix result(rows(), cols());
    for (size_t i = 0; i < rows(); ++i) {
        for (size_t j = 0; j < cols(); ++j) {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols()) {
        throw MatrixException("Matrices have different dimensions");
    }

    Matrix result(rows(), cols());
    for (size_t i = 0; i < rows(); ++i) {
        for (size_t j = 0; j < cols(); ++j) {
            result(i, j) = (*this)(i, j) - other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols() != other.rows()) {
        throw MatrixException("Matrices have incompatible dimensions");
    }

    Matrix result(rows(), other.cols());
    for (size_t i = 0; i < rows(); ++i) {
        for (size_t j = 0; j < other.cols(); ++j) {
            int sum = 0;
            for (size_t k = 0; k < cols(); ++k) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

std::istream& operator>>(std::istream& in, Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows(); ++i) {
        for (size_t j = 0; j < matrix.cols(); ++j) {
            in >> matrix(i, j);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows(); ++i) {
        for (size_t j = 0; j < matrix.cols(); ++j) {
            out << matrix(i, j) << " ";
 }
        out << std::endl;
    }
    return out;
}

void transformArray(Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows(); ++i) {
        for (size_t j = 0; j < matrix.cols(); ++j) {
            if (matrix(i, j) % 2 != 0) {
                matrix(i, j) *=2;
            }
        }
    }
}


int main() {
    try {
        Matrix m1(2, 3);
        std::cout << "Enter values for matrix 1:\n";
        std::cin >> m1;

        Matrix m2(2, 3);
        std::cout << "Enter values for matrix 2:\n";
        std::cin >> m2;

        std::cout << "Matrix 1:\n" << m1 << std::endl;
        std::cout << "Matrix 2n" << m2 << std::endl;

        Matrix m3 = m1 + m2;
        std::cout << "Matrix 1 + Matrix 2:\n" << m3 << std::endl;

        Matrix m4 = m1 - m2;
        std::cout << "Matrix 1 - Matrix 2:\n" << m4 << std::endl;

        Matrix m5 = m1 * m2;
        std::cout << "Matrix  * Matrix 2:\n" << m5 << std::endl;

        std::cout << "Transforming matrix 1...\n";
        transformArray(m1);
        std::cout << "Matrix 1 after transformation:\n" << m1 << std::endl;

    } catch (const MatrixException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}