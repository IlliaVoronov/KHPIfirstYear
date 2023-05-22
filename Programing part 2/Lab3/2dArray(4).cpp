#include <iostream>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    int rows;
    int cols;
    T** data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = other.rows;
            cols = other.cols;

            data = new T*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new T[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Number of columns in first matrix must match number of rows in second matrix");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    T& operator()(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[row][col];
    }

    const T& operator()(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[row][col];
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    void doubleOddValues() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] % 2 == 1) {
                    data[i][j] *= 2;
                }
            }
        }
    }
};

template <typename T>
T findMinimum(const T* arr, int size) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

class SimpleFraction {
private:
    int numerator;
    int denominator;

public:
    SimpleFraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int numerator) {
        this->numerator = numerator;
        simplify();
    }

    void setDenominator(int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        this->denominator = denominator;
        simplify();
    }

    SimpleFraction operator+(const SimpleFraction& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return SimpleFraction(newNumerator, newDenominator);
    }

    SimpleFraction operator-(const SimpleFraction& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return SimpleFraction(newNumerator, newDenominator);
    }

    SimpleFraction operator*(const SimpleFraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return SimpleFraction(newNumerator, newDenominator);
    }

    SimpleFraction operator/(const SimpleFraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return SimpleFraction(newNumerator, newDenominator);
    }

    bool operator<(const SimpleFraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator==(const SimpleFraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    friend std::ostream& operator<<(std::ostream& os, const SimpleFraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, SimpleFraction& fraction) {
        char slash;
        is >> fraction.numerator >> slash >> fraction.denominator;
        fraction.simplify();
        return is;
    }

private:
    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int gcd = getGcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int getGcd(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return getGcd(b, a % b);
    }
};

int main() {
    try {
        Matrix<int> intMatrix(3, 3);
        intMatrix(0, 0) = 1;
        intMatrix(0, 1) = 2;
        intMatrix(0, 2) = 3;
        intMatrix(1, 0) = 4;
        intMatrix(1, 1) = 5;
        intMatrix(1, 2) = 6;
        intMatrix(2, 0) = 7;
        intMatrix(2, 1) = 8;
        intMatrix(2, 2) = 9;

        std::cout << "Int matrix:" << std::endl;
        std::cout << intMatrix << std::endl;

        Matrix<double> doubleMatrix(2, 2);
        doubleMatrix(0, 0) = 1.5;
        doubleMatrix(0, 1) = 2.5;
        doubleMatrix(1, 0) = 3.5;
        doubleMatrix(1, 1) = 4.5;

        std::cout << "Double matrix:" << std::endl;
        std::cout << doubleMatrix << std::endl;

        Matrix<SimpleFraction> fractionMatrix(2, 2);
        fractionMatrix(0, 0) = SimpleFraction(1, 2);
        fractionMatrix(0, 1) = SimpleFraction(3, 4);
        fractionMatrix(1, 0) = SimpleFraction(5, 6);
        fractionMatrix(1, 1) = SimpleFraction(7, 8);

        std::cout << "Fraction matrix:" << std::endl;
        std::cout << fractionMatrix << std::endl;

        int intArray[] = { 3, 1, 4, 1, 5, 9 };
        double doubleArray[] = { 3.14, 2.71, 1.41 };
        SimpleFraction fractionArray[] = { SimpleFraction(1, 2), SimpleFraction(3, 4), SimpleFraction(5, 6) };

        std::cout << "Minimum int value: " << findMinimum(intArray, 6) << std::endl;
        std::cout << "Minimum double value: " << findMinimum(doubleArray, 3) << std::endl;
        std::cout << "Minimum fraction value: " << findMinimum(fractionArray, 3) << std::endl;

        intMatrix.doubleOddValues();
        std::cout << "Int matrix after doubling odd values:" << std::endl;
        std::cout << intMatrix << std::endl;

        Matrix<int> invalidMatrix(2, 3);
        invalidMatrix(0, 0) = 1;
        invalidMatrix(0, 1) = 2;
        invalidMatrix(0, 2) = 3;
        invalidMatrix(1, 0) = 4;
        invalidMatrix(1, 1) = 5;
        invalidMatrix(1, 2) = 6;

        Matrix<int> resultMatrix = intMatrix + invalidMatrix;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
