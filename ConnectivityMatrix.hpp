//
// Created by subte on 2022-10-05.
//
#include "Matrix.hpp"
#include <fstream>

#pragma once

using namespace std;

/**
 * A connectivity matrix is a square matrix made up of 0s and 1s that summarizes how web pages link to each other.
 */
class ConnectivityMatrix : public Matrix {
public:
    /**
     * Constructs a ConnectivityMatrix object with one row and one column. The single cell value is set to 0.
     */
    ConnectivityMatrix();

    /**
     * Constructs a square ConnectivityMatrix object with n rows and n columns. All cell values are set to 0. Throws an
     * exception if n <= 0.
     * @param n int specifying the number of rows and columns the constructed matrix should have; must be > 0.
     */
    explicit ConnectivityMatrix(int n);

    /**
     * Constructs a square ConnectivityMatrix object from an input text file containing 1s and 0s separated by single
     * spaces, corresponding to a square matrix. Calculates the square matrix dimension from the input text file and fills
     * the matrix with a call to fillMatrix().
     * @param fin ifstream containing an opened text file with a square matrix made up of 0s and 1s (separated by single
     *            spaces).
     */
    explicit ConnectivityMatrix(ifstream &fin);

    /**
     * Copy constructor for a connectivity matrix.
     * @param g Reference to the connectivity matrix to be copied.
     */
    ConnectivityMatrix(const ConnectivityMatrix &g);

    /**
     * Swaps the matrix members of two connectivity matrices using the built-in swap function.
     * @param first Connectivity matrix whose matrix member is to be swapped with second.
     * @param second Connectivity matrix whose matrix member is to be swapped with first.
     */
    friend void matrixSwap(ConnectivityMatrix &first, ConnectivityMatrix &second);

    /**
     * Overloaded assignment operator. Sets the connectivity matrix on the left hand side of the operator's matrix
     * member to that of the connectivity matrix on the right hand side of the operator.
     * @param other Connectivity matrix to which the connectivity matrix on the left hand side of the operator is to be
     *              assigned.
     * @return Reference to the connectivity matrix with the correct (assigned) matrix member.
     */
    ConnectivityMatrix &operator=(ConnectivityMatrix other);

    /**
     * Destructor for the ConnectivityMatrix class.
     */
    ~ConnectivityMatrix();
};

/**
 * Helper function that fills the square (correctly-dimensioned) zero matrix with values corresponding to those in the
 * text file matrix.
 * @param fin Reference to ifstream with opened matrix text file.
 * @param zeroMatrix Reference to the zero matrix to be filled.
 */
void fillMatrix(ifstream &fin, Matrix &zeroMatrix);
