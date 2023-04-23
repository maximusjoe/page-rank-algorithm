//
// Created by maxim on 2022-10-06.
//

#include "RankMatrix.hpp"

constexpr double CONVERGENCE_THRESHOLD{0.0001};
constexpr int OUTPUT_WIDTH{5};
constexpr int CAPITAL_A{65};
constexpr int PERCENT{100};

void multiplyMatrixMarkov(RankMatrix &r) {

    // Create the rank matrix with column values set to 0.0.
    int matrixLength = (int) r.getMatrix().size();
    Matrix rankMatrix(matrixLength, 1);
    for (int i = 0; i < matrixLength; ++i) {
        rankMatrix.setValue(i, 0, 1.0);
    }

    // Matrix used to compare convergence.
    Matrix oldMatrix(matrixLength, 1);

    // Is the convergence less than the threshold?
    bool isConverged{false};

    // Multiply M * column matrix rank until result converge.
    while (!isConverged) {

        // Store previous matrix values.
        for (size_t i = 0; i < r.getMatrix().size(); ++i) {
            oldMatrix.setValue((int) i, 0, rankMatrix.getValue((int) i, 0));
        }

        // Multiply the matrices.
        rankMatrix = r * rankMatrix;

        // Set isConverged to true if threshold is reached.
        for (size_t i = 0; i < r.getMatrix().size(); ++i) {
            if (abs(rankMatrix.getValue((int) i, 0) - oldMatrix.getValue((int) i, 0)) < CONVERGENCE_THRESHOLD) {
                isConverged = true;
            }
        }
    }

    // Set the ranked matrix to the proper value.
    matrixSwap(rankMatrix, r);
}

void extractMatrixPercentages(RankMatrix &r) {

    // Sum of the column.
    double columnSum{0};

    // Loop through matrix once for column sum calculations and once for percentage conversion.
    for (int i = 0; i < 2; ++i) {
        for (size_t j = 0; j < r.getMatrix().size(); ++j) {
            if (i == 0) {

                // Calculate the sum of the columns
                columnSum += r.getValue((int) j, 0);
            } else {

                // Change the column values to percentages.
                r.setValue((int) j, 0, r.getValue((int) j, 0) / columnSum);
            }
        }
    }
}

RankMatrix::RankMatrix() : Matrix() {

}

RankMatrix::RankMatrix(const TransitionMatrix &m) : Matrix(m) {

    // Perform Markov process on transition matrix.
    multiplyMatrixMarkov(*this);
    extractMatrixPercentages(*this);
}

[[maybe_unused]] RankMatrix::RankMatrix(const RankMatrix &r) : Matrix(r) {
    cout << "rank matrix copy constructor\n" << endl;
}

void matrixSwap(RankMatrix &first, RankMatrix &second) {
    swap(first.matrix, second.matrix);
}

RankMatrix &RankMatrix::operator=(RankMatrix other) {
    matrixSwap(*this, other);
    return *this;
}

RankMatrix::~RankMatrix() = default;

ostream &operator<<(ostream &os, const RankMatrix &rankMatrix) {
    // ASCII char A
    char pageLetter = CAPITAL_A;

    // Print out percentages by page.
    for (size_t i = 0; i < rankMatrix.getMatrix().size(); ++i) {
        os << "Page " << (char) (pageLetter + i) << ": " << setw(OUTPUT_WIDTH) << fixed << setprecision(2)
           << (rankMatrix.getValue((int) i, 0) * PERCENT) << "%" << endl;
    }
    return os;
}
