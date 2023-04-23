//
// Created by subte on 2022-10-05.
//

#include "TransitionMatrix.hpp"
#include <cmath>

TransitionMatrix::TransitionMatrix() : Matrix(), p(0) {
}

void multiplyMatrixValuesByRandomWalkProbability(TransitionMatrix &m) {
    int matrixDimension{(int) m.getMatrix().size()};

    for (int row = 0; row < matrixDimension; ++row) {
        for (int col = 0; col < matrixDimension; ++col) {
            m.setValue(row, col, m.getRandomWalkProbability() * m.getValue(row, col));
        }
    }
}

TransitionMatrix::TransitionMatrix(const ProbabilityMatrix &s, const double randomWalkProbability) :
        Matrix(s), p(randomWalkProbability) {
    vector<double> randomWalkVector((int) pow((int) matrix.size(), 2), (1 - randomWalkProbability) *
                                                                       (1 / (double) matrix.size()));
    // need to convert vector to array in order to call constructor below
    double *randomWalkArray = randomWalkVector.data();
    Matrix q(randomWalkArray, (int) randomWalkVector.size());

    multiplyMatrixValuesByRandomWalkProbability(*this);
    *this += q;
}

TransitionMatrix::TransitionMatrix(const TransitionMatrix &m) : Matrix(m),
                                                                p(m.getRandomWalkProbability()) {
}

double TransitionMatrix::getRandomWalkProbability() const {
    return p;
}

void matrixSwap(TransitionMatrix &first, TransitionMatrix &second) {
    swap(first.matrix, second.matrix);
}

TransitionMatrix &TransitionMatrix::operator=(TransitionMatrix other) {
    matrixSwap(*this, other);
    return *this;
}

TransitionMatrix::~TransitionMatrix() = default;
