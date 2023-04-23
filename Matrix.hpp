//
// Created by maxim on 2022-10-02.
//

#include <vector>
#include <iostream>

#pragma once

using namespace std;

/**
 * The matrix class consists of a matrix member that stores doubles in a vector of vector<double>. The outer vector's
 * size corresponds to the matrix's row dimension, while each inner vector's size corresponds to the matrix's column
 * dimension.
 */
class Matrix {
protected:
    vector<vector<double>> matrix;
public:
    /**
     * Constructs a Matrix object with one row and one column. The single cell value is set to 0.
     */
    Matrix();

    /**
     * Constructs a square Matrix object with n rows and n columns. All cell values are set to 0. Throws an exception if
     * n <= 0.
     * @param n int specifying the number of rows and columns the constructed matrix should have; must be > 0.
     */
    explicit Matrix(int n);

    /**
     * Constructs a Matrix object with r rows and c columns. All cell values are set to 0. Throws an exception if either of
     * r or n are <= 0.
     * @param r int specifying the number of rows the constructed matrix should have; must be > 0.
     * @param c int specifying the number of columns the constructed matrix should have; must be > 0.
     */
    Matrix(int r, int c);

    /**
     * Constructs a square Matrix object with sqrt(arraySize) rows and columns. Cell values are set along each row, and
     * correspond directly to the values the the input array. For example, an input array of {1, 2, 3, 4} would result
     * in the matrix [r1: {1, 2}; r2: {3, 4}]. An exception is thrown if the input array's size isn't a perfect square
     * (e.g. 1, 4, 9, 25, etc.).
     * @param array Input array of values to be entered into the constructed matrix.
     * @param arraySize int containing the size of the input array; must be a perfect square.
     */
    Matrix(const double array[], int arraySize);

    /**
     * Copy constructor for a matrix.
     * @param theMatrix Reference to the matrix to be copied.
     */
    Matrix(const Matrix &theMatrix);

    /**
     * Sets the value of the matrix at the specified row and column to the specified value. Throws an exception if the
     * row or column values are < 0 or fall outside of the matrix's dimensions. Note that matrix dimensions start at 0.
     * @param row int containing the row of the cell whose value should be changed sits.
     * @param column int containing the column of the cell whose value should be changed sits.
     * @param value double containing the value to which the cell at (row, column) should be set to.
     */
    void setValue(int row, int column, double value);

    /**
     * Returns the value of the matrix at the specified row and column. Throws an exception if the row or column values
     * are < 0 or fall outside of the matrix's dimensions. Note that matrix dimensions start at 0.
     * @param row int containing the row of the cell whose value is to be returned.
     * @param column int containing the column of the cell whose value is to be returned.
     * @return double containing the value of the cell at the specified row and column.
     */
    [[nodiscard]] double getValue(int row, int column) const;

    /**
     * Sets all cell values in the matrix to 0.
     */
    [[maybe_unused]] void clear();

    /**
     * Returns the Matrix object's matrix member.
     * @return vector<vector<double>> stored in the Matrix object's matrix member.
     */
    [[nodiscard]] vector<vector<double>> getMatrix() const;

    /**
     * Overloaded insertion operator that prints the animal's information to the console.
     * @param os Reference to an output stream.
     * @param theMatrix Reference to the matrix to be printed.
     * @return Reference to an output stream containing the information to be printed to the console.
     */
    friend ostream &operator<<(ostream &os, const Matrix &theMatrix);

    /**
     * Overloaded equality operator that checks whether two Matrix objects are equal. Note that there is a tolerance of
     * 0.01 between cell values. In other words, if corresponding cell values between two matrices differ by <= 0.01, they
     * are considered equal. Otherwise, they are considered unequal.
     * @param lhs Reference to the matrix being compared to rhs.
     * @param rhs Reference to the matrix being compared to lhs.
     * @return true if the matrices are equal; false otherwise.
     */
    friend bool operator==(const Matrix &lhs, const Matrix &rhs);

    /**
     * Overloaded inequality operator that checks whether two Matrix objects are equal. Note that there is a tolerance of
     * 0.01 between cell values. In other words, if corresponding cell values between two matrices differ by <= 0.01, they
     * are considered equal. Otherwise, they are considered unequal.
     * @param lhs Reference to the matrix being compared to rhs.
     * @param rhs Reference to the matrix being compared to lhs.
     * @return true if the matrices are unequal; false otherwise.
     */
    friend bool operator!=(const Matrix &lhs, const Matrix &rhs);

    /**
     * Overloaded prefix unary increment operator (i.e. ++variableName). Increments every cell value in the matrix by one
     * and returns a reference to said matrix.
     * @return Reference to the matrix whose cell values have been incremented by one.
     */
    Matrix &operator++();

    /**
     * Overloaded postfix unary increment operator (i.e. variableName++). Increments every cell value in the matrix by one,
     * but returns a copy of the original matrix, whose values have not yet been incremented.
     * @return Copy of the original matrix, whose cell values have not yet been incremented.
     */
    Matrix operator++(int);

    /**
     * Overloaded prefix unary decrement operator (i.e. --variableName). Decrements every cell value in the matrix by one
     * and returns a reference to said matrix.
     * @return Reference to the matrix whose cell values have been decremented by one.
     */
    Matrix &operator--();

    /**
     * Overloaded postfix unary decrement operator (i.e. variableName--). Decrements every cell value in the matrix by one,
     * but returns a copy of the original matrix, whose cell values have not yet been decremented.
     * @return Copy of the original matrix, whose cell values have not yet been decremented.
     */
    Matrix operator--(int);

    /**
     * Overloaded addition assignment operator. Adds every cell value in the matrix to its corresponding cell value in the
     * matrix on the right hand side of the operator. Throws an exception if the matrices are of different dimensions.
     * @param rhs Matrix whose cell values are to be added to the matrix on the left hand side of the addition assignment
     *            operator. Must have the same dimensions as said matrix.
     * @return Reference to the matrix whose original cell values have been added to corresponding cell values in the rhs
     *         matrix.
     */
    Matrix &operator+=(const Matrix &rhs);

    /**
     * Overloaded unary plus operator. Adds every cell value on the left hand side of an addition equation to the
     * corresponding cell value in the matrix on the right hand side of the operator. Throws an exception if the matrices
     * are of different dimensions.
     * @param rhs Matrix whose cell values are to be added to the matrix on the left hand side of the plus operator. Must
     *        have the same dimensions as said matrix.
     * @return Matrix whose original cell values have been added to corresponding cell values in the rhs matrix.
     */
    friend Matrix operator+(Matrix lhs, const Matrix &rhs);

    /**
     * Overloaded subtraction assignment operator. Subtracts every cell value in the matrix on the right hand side of the
     * operator from its corresponding cell value in the matrix on the left hand side of the operator. Throws an exception
     * if the matrices are of different dimensions.
     * @param rhs Matrix whose cell values are to be subtracted from the matrix on the left hand side of the subtraction
     *            assignment operator. Must have the same dimensions as said matrix.
     * @return Reference to the matrix whose original cell values have been decreased by corresponding cell values in the
     *         rhs matrix.
     */
    Matrix &operator-=(const Matrix &rhs);

    /**
     * Overloaded unary minus operator. Decreases every cell value on the left hand side of an addition equation by the
     * corresponding cell value in the matrix on the right hand side of the operator. Throws an exception if the matrices
     * are of different dimensions.
     * @param rhs Matrix whose cell values are to be subtracted from the matrix on the left hand side of the minus operator.
     *            Must have the same dimensions as said matrix.
     * @return Matrix whose original cell values have been decreased by corresponding cell values in the rhs matrix.
     */
    friend Matrix operator-(Matrix lhs, const Matrix &rhs);

    /**
     * Swaps the matrix members of two matrices using the built-in swap function.
     * @param first Matrix whose matrix member is to be swapped with second.
     * @param second Matrix whose matrix member is to be swapped with first.
     */
    friend void matrixSwap(Matrix &first, Matrix &second);

    /**
     * Overloaded assignment operator. Sets the matrix on the left hand side of the operator's matrix member to that of
     * the matrix on the right hand side of the operator.
     * @param other Matrix to which the matrix on the left hand side of the operator is to be assigned.
     * @return Reference to the matrix with the correct (assigned) matrix member.
     */
    Matrix &operator=(Matrix other);

    /**
     * Overloaded multiplication assignment operator. Performs matrix multiplication between the matrix on the left hand
     * side of the operator and that on the right hand side of the operator. Throws an exception if the left hand side
     * matrix's column dimension doesn't correspond to the right hand side matrix's row dimension (i.e. the inner dimensions
     * of the two matrices must match).
     * @param rhs Matrix that the matrix on the left hand side of the multiplication assignment operator is to be multiplied
     *            by.
     * @return Reference to the matrix whose original cell values have been correctly multiplied with corresponding (in the
     *         context of matrix multiplication) cell values in the rhs matrix.
     */
    Matrix &operator*=(const Matrix &rhs);

    /**
     * Overloaded unary multiplication operator. Performs matrix multiplication between the matrix on the left hand
     * side of the operator and that on the right hand side of the operator. Throws an exception if the left hand side
     * matrix's column dimension doesn't correspond to the right hand side matrix's row dimension (i.e. the inner dimensions
     * of the two matrices must match).
     * @param rhs Matrix that the matrix on the left hand side of the unary multiplication operator is to be multiplied
     *            by.
     * @return Matrix whose original cell values have been correctly multiplied with corresponding (in the context of matrix
     * multiplication) cell values in the rhs matrix.
     */
    friend Matrix operator*(Matrix lhs, const Matrix &rhs);

    /**
     * Destructor for the Matrix class.
     */
    ~Matrix();
};
