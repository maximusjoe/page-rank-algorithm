//
// Created by maxim on 2022-10-02.
//

#include "Matrix.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "customExceptions.hpp"

#define GENERAL_ERROR_MSG "Terminating the program..."
#define ERROR_CODE 1

constexpr double TOLERANCE = 001;
constexpr int NUM_SPACES = 9;

using namespace std;

Matrix::Matrix() : matrix(vector<vector<double>>(1, vector<double>(1, 0))) {
}

Matrix::Matrix(int n) try: matrix(vector<vector<double>>(n, vector<double>(n, 0))) {} catch (...) {
    cout << "Matrix argument must be greater than 0." << endl;
    cout << GENERAL_ERROR_MSG << endl;
    exit(ERROR_CODE);
}

Matrix::Matrix(int r, int c) try: matrix(vector<vector<double>>(r, vector<double>(c, 0))) {} catch (...) {
    cout << "Matrix arguments must be greater than 0." << endl;
    cout << GENERAL_ERROR_MSG << endl;
    exit(ERROR_CODE);
}

Matrix::Matrix(const double array[], int arraySize) : matrix(
        vector<vector<double>>((int) sqrt(arraySize), vector<double>((int) sqrt(arraySize), 0))) {
    double sqrtArraySize = sqrt(arraySize);
    matrix.resize((int) sqrtArraySize, vector<double>((int) sqrtArraySize));
    if (trunc(sqrtArraySize) == sqrtArraySize) {
        for (int i = 0; i < sqrtArraySize; ++i) {
            for (int j = 0; j < sqrtArraySize; ++j) {
                matrix[i][j] = array[i * (int) sqrtArraySize + j];
            }
        }
    } else {
        throw nonIntegerSqrt();
    }
}

Matrix::Matrix(const Matrix &theMatrix) : matrix(
        vector<vector<double>>((int) theMatrix.getMatrix().size(),
                               vector<double>((int) theMatrix.getMatrix()[0].size(), 0))) {
    vector matrixToCopy = theMatrix.getMatrix();
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            matrix[i][j] = matrixToCopy[i][j];
        }
    }
}

void Matrix::setValue(int row, int column, double value) {
    int numRows = (int) matrix.size();
    int numCols = (int) matrix[0].size();
    if (row < 0 || row > numRows - 1 || column < 0 || column > numCols - 1) {
        throw unreasonableValue();
    } else {
        matrix[row][column] = value;
    }
}

double Matrix::getValue(int row, int column) const {
    int numRows = (int) matrix.size();
    int numCols = (int) matrix[0].size();
    if (row < 0 || row > numRows - 1 || column < 0 || column > numCols - 1) {
        throw unreasonableValue();
    } else {
        return matrix[row][column];
    }
}

[[maybe_unused]] void Matrix::clear() {
    for (vector<double> &row: matrix) {
        for (double &cell: row) {
            cell = 0;
        }
    }
}

vector<vector<double>> Matrix::getMatrix() const {
    return matrix;
}

ostream &operator<<(ostream &os, const Matrix &theMatrix) {
    for (vector<double> &row: theMatrix.getMatrix()) {
        for (double &cell: row) {
            os << setw(NUM_SPACES) << left << cell;
        }
        os << endl;
    }
    os << endl;
    return os;
}

bool operator==(const Matrix &lhs, const Matrix &rhs) {
    vector<vector<double>> lhsMatrix = lhs.getMatrix();
    vector<vector<double>> rhsMatrix = rhs.getMatrix();
    int lhsRows = (int) lhsMatrix.size();
    int lhsCols = (int) lhsMatrix[0].size();
    int rhsRows = (int) rhsMatrix.size();
    int rhsCols = (int) rhsMatrix[0].size();

    if (lhsRows != rhsRows || lhsCols != rhsCols) {
        return false;
    } else {
        for (int row = 0; row < lhsRows; ++row) {
            for (int column = 0; column < lhsCols; ++column) {
                if (abs(rhs.getValue(row, column) - lhs.getValue(row, column)) > TOLERANCE) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool operator!=(const Matrix &lhs, const Matrix &rhs) {
    return !operator==(lhs, rhs);
}

Matrix &Matrix::operator++() {
    for (vector<double> &row: matrix) {
        for (double &cell: row) {
            cell += 1.0;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix tmp(*this);
    operator++();
    return tmp;
}

Matrix &Matrix::operator--() {
    for (vector<double> &row: matrix) {
        for (double &cell: row) {
            cell -= 1.0;
        }
    }
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix tmp(*this);
    operator--();
    return tmp;
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
    vector<vector<double>> rhsMatrix = rhs.getMatrix();
    int rhsRows = (int) rhsMatrix.size();
    int rhsCols = (int) rhsMatrix[0].size();

    if ((int) matrix.size() != rhsRows || (int) matrix[0].size() != rhsCols) {
        throw matricesHaveDifferentDimensions();
    } else {
        for (int i = 0; i < rhsRows; ++i) {
            for (int j = 0; j < rhsCols; ++j) {
                matrix[i][j] += rhsMatrix[i][j];
            }
        }
    }
    return *this;
}

Matrix operator+(Matrix lhs, const Matrix &rhs) {
    lhs += rhs;
    return lhs;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
    vector<vector<double>> rhsMatrix = rhs.getMatrix();
    int rhsRows = (int) rhsMatrix.size();
    int rhsCols = (int) rhsMatrix[0].size();

    if ((int) matrix.size() != rhsRows || (int) matrix[0].size() != rhsCols) {
        throw matricesHaveDifferentDimensions();
    } else {
        for (int i = 0; i < rhsRows; ++i) {
            for (int j = 0; j < rhsCols; ++j) {
                matrix[i][j] -= rhsMatrix[i][j];
            }
        }
    }
    return *this;
}

Matrix operator-(Matrix lhs, const Matrix &rhs) {
    lhs -= rhs;
    return lhs;
}

void matrixSwap(Matrix &first, Matrix &second) {
    swap(first.matrix, second.matrix);
}

Matrix &Matrix::operator=(Matrix other) {
    matrixSwap(*this, other);
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &rhs) {
    vector<vector<double>> rhsMatrix = rhs.getMatrix();
    int rhsRows = (int) rhsMatrix.size();
    int rhsCols = (int) rhsMatrix[0].size();

    if ((int) matrix[0].size() != rhsRows) {
        throw matrixProductNotComputable();
    } else {
        Matrix matrixToReturn = Matrix((int) matrix.size(), rhsCols);
        for (int i = 0; i < (int) matrix.size(); ++i) {
            for (int j = 0; j < (int) rhsCols; ++j) {
                for (int k = 0; k < (int) matrix[0].size(); ++k) {
                    matrixToReturn.setValue(i, j,
                                            matrixToReturn.getValue(i, j) + matrix[i][k] * rhsMatrix[k][j]);
                }
            }
        }
        *this = matrixToReturn;
    }
    return *this;
}

Matrix operator*(Matrix lhs, const Matrix &rhs) {
    lhs *= rhs;
    return lhs;
}

Matrix::~Matrix() = default;
