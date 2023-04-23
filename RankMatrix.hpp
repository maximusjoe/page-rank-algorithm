//
// Created by maxim on 2022-10-06.
//

#include "Matrix.hpp"
#include "TransitionMatrix.hpp"
#include <fstream>
#include <iomanip>

#pragma once

using namespace std;

/**
 * Rank Matrix
 *
 * This class is used to find the ranks
 * of the pages within the matrix and
 * extract that data to percentage values.
 */
class RankMatrix : public Matrix {
public:
    /**
     * Constructs a RankMatrix object with one row and one column. The single cell value is set to 0.
     */
    RankMatrix();

    /**
    * Constructs a single column RankMatrix object from an input Transition matrix object.
    * Multiplies a rank matrix with n rows and 1 column with the transition matrix until a
    * convergence threshold is met and store that new matrix as the RankMatrix.
    *
    * @param m Reference to the input transition matrix.
    */
    explicit RankMatrix(const TransitionMatrix &m);

    /**
     * Copy constructor for a rank matrix.
     * @param r Reference to the rank matrix to be copied.
     */
    [[maybe_unused]] RankMatrix(const RankMatrix &r);

    /**
     * Swaps the matrix members of two rank matrices using the built-in swap function.
     * @param first Rank matrix whose matrix member is to be swapped with second.
     * @param second Rank matrix whose matrix member is to be swapped with first.
     */
    friend void matrixSwap(RankMatrix &first, RankMatrix &second);

    /**
     * Overloaded assignment operator <<. Places the page percentage and the page index
     * into a row of the ostream for each of the pages given in the matrix.
     *
     * @return os ostream that contains the custom output for the PageRank algorithm
     */
    friend ostream &operator<<(ostream &os, const RankMatrix &rankMatrix);

    /**
      * Overloaded assignment operator =. Sets the rank matrix on the left hand side of the operator's matrix
      * member to that of the rank matrix on the right hand side of the operator.
      *
      * @param other rank matrix to which the rank matrix on the left hand side of the operator is to be assigned.
      * @return Reference to the rank matrix with the correct (assigned) matrix member.
      */
    RankMatrix &operator=(RankMatrix other);

    /**
     * Destructor for the RankMatrix class.
     */
    ~RankMatrix();
};