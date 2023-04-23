//
// Created by subte on 2022-10-05.
//

#include "ProbabilityMatrix.hpp"

ProbabilityMatrix::ProbabilityMatrix() : Matrix() {
}

void convertIntoProbabilityMatrix(const vector<double> &columnSums, const double &emptyColumnValue,
                                  ProbabilityMatrix &s, int matrixDimension) {
    for (int col = 0; col < matrixDimension; ++col) {
        for (int row = 0; row < matrixDimension; ++row) {
            columnSums[col] == 0
            ? s.setValue(row, col, emptyColumnValue)
            : s.setValue(row, col, s.getValue(row, col) / columnSums[col]);
        }
    }
}

ProbabilityMatrix::ProbabilityMatrix(const ConnectivityMatrix &g) : Matrix(g) {
    int matrixDimension{(int) matrix.size()};
    vector<double> columnSums(matrixDimension, 0);

    for (int col = 0; col < matrixDimension; ++col) {
        for (int row = 0; row < matrixDimension; ++row) {
            columnSums[col] += getValue(row, col);
        }
    }

    convertIntoProbabilityMatrix(columnSums, 1 / (double) matrixDimension, *this,
                                 matrixDimension);
}

ProbabilityMatrix::ProbabilityMatrix(const ProbabilityMatrix &s) : Matrix(s) {
}

void matrixSwap(ProbabilityMatrix &first, ProbabilityMatrix &second) {
    swap(first.matrix, second.matrix);
}

ProbabilityMatrix &ProbabilityMatrix::operator=(ProbabilityMatrix other) {
    matrixSwap(*this, other);
    return *this;
}

ProbabilityMatrix::~ProbabilityMatrix() = default;
