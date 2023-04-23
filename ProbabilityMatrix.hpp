//
// Created by subte on 2022-10-05.
//
#include "Matrix.hpp"
#include "ConnectivityMatrix.hpp"
#include <fstream>

#pragma once

using namespace std;

/**
 * A probability matrix is a connectivity matrix whose cell values have all been divided by their column sums. Note
 * that if a column is comprised entirely of 0s, that column's values are set to 1 divided by the connectivity matrix's
 * dimensions.
 */
class ProbabilityMatrix : public Matrix {
public:
    /**
     * Constructs a ProbabilityMatrix object with one row and one column. The single cell value is set to 0.
     */
    ProbabilityMatrix();

    /**
     * Constructs a square ProbabilityMatrix object from an input ConnectivityMatrix object. Creates a vector of the input
     * matrix's column sums and transform said matrix into a proper probability matrix with a call to
     * convertIntoProbabilityMatrix().
     * @param g Reference to the input connectivity matrix.
     */
    explicit ProbabilityMatrix(const ConnectivityMatrix &g);

    /**
     * Copy constructor for a probability matrix.
     * @param s Reference to the probability matrix to be copied.
     */
    ProbabilityMatrix(const ProbabilityMatrix &s);

    /**
     * Swaps the matrix members of two probability matrices using the built-in swap function.
     * @param first Probability matrix whose matrix member is to be swapped with second.
     * @param second Probability matrix whose matrix member is to be swapped with first.
     */
    friend void matrixSwap(ProbabilityMatrix &first, ProbabilityMatrix &second);

    /**
      * Overloaded assignment operator. Sets the probability matrix on the left hand side of the operator's matrix
      * member to that of the probability matrix on the right hand side of the operator.
      * @param other Probability matrix to which the connectivity matrix on the left hand side of the operator is to be
      *              assigned.
      * @return Reference to the probability matrix with the correct (assigned) matrix member.
      */
    ProbabilityMatrix &operator=(ProbabilityMatrix other);

    /**
     * Destructor for the ProbabilityMatrix class.
     */
    ~ProbabilityMatrix();
};

/**
 * Helper function that creates a proper probability matrix by dividing cell values by their column sums. If a column
 * is made up entirely of 0s, sets each value in that column to 1 divided by the square matrix's dimension.
 * @param columnSums vector<double> containing column sums.
 * @param emptyColumnValue double corresponding to 1 divided by the square matrix's dimension.
 * @param s Reference to the matrix whose cell values are to be modified.
 * @param matrixDimension int containing the square matrix's dimension.
 */
void convertIntoProbabilityMatrix(const vector<double> &columnSums, const double &emptyColumnValue,
                                  ProbabilityMatrix &s, int matrixDimension);
