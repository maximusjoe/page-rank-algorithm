//
// Created by subte on 2022-10-05.
//
#include "Matrix.hpp"
#include "ProbabilityMatrix.hpp"
#include <fstream>

#pragma once

using namespace std;

/**
 * A transition matrix (M) is a probability matrix (S) that has been subjected to the formula
 * M = p * S + (1 - p) * Q. Note that p is the random walk probability, and Q is a square matrix with the same dimension
 * as S, comprised entirely of cell values equal to 1 / said dimension.
 */
class TransitionMatrix : public Matrix {
private:
    double p;
public:
    /**
     * Constructs a TransitionMatrix object with one row and one column. The single cell value is set to 0, and random
     * walk probability is also set to 0.
     */
    TransitionMatrix();

    /**
     * Constructs a square ProbabilityMatrix object from an input TransitionMatrix object. Creates a square matrix whose
     * cells are populated with the random walk probability factor (p), and a matrix whose cells are populated with
     * the value (1 - p), so that the input probability matrix can be subjected to the formula M = p * S + (1 - p) * Q.
     * Note that the p * S part of this formula is carried out through a call to
     * multiplyMatrixValuesByRandomWalkProbability().
     * @param g Reference to the input probability matrix.
     * @param randomWalkProbability double holding the desired random walk probability to be used in the transition matrix
     *                              formula.
     */
    explicit TransitionMatrix(const ProbabilityMatrix &s, const double randomWalkProbability);

    /**
     * Copy constructor for a probability matrix.
     * @param s Reference to the probability matrix to be copied.
     */
    TransitionMatrix(const TransitionMatrix &m);

    /**
     * Returns the value stored in the transition matrix's p member.
     * @return double containing the value stored in the transition matrix's p member.
     */
    [[nodiscard]] double getRandomWalkProbability() const;

    /**
     * Swaps the matrix members of two transition matrices using the built-in swap function.
     * @param first Transition matrix whose matrix member is to be swapped with second.
     * @param second Transition matrix whose matrix member is to be swapped with first.
     */
    friend void matrixSwap(TransitionMatrix &first, TransitionMatrix &second);

    /**
      * Overloaded assignment operator. Sets the transition matrix on the left hand side of the operator's matrix
      * member to that of the transition matrix on the right hand side of the operator.
      * @param other Transition matrix to which the connectivity matrix on the left hand side of the operator is to be
      *              assigned.
      * @return Reference to the transition matrix with the correct (assigned) matrix member.
      */
    TransitionMatrix &operator=(TransitionMatrix other);

    /**
     * Destructor for the TransitionMatrix class.
     */
    ~TransitionMatrix();
};

/**
 * Helper function that multiplies each of cells in the input probability matrix by the random walk probability.
 * @param m Reference to the matrix whose cells are to be multiplied by the random walk probability.
 */
void multiplyMatrixValuesByRandomWalkProbability(TransitionMatrix &m);
