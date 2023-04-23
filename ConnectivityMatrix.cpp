//
// Created by subte on 2022-10-05.
//

#include "ConnectivityMatrix.hpp"
#include <sstream>

ConnectivityMatrix::ConnectivityMatrix() : Matrix() {
}

ConnectivityMatrix::ConnectivityMatrix(int n) : Matrix(n) {
}

void fillMatrix(ifstream &fin, Matrix &zeroMatrix) {
    string line;
    double matrixRowEntry{0};
    int row{0};
    int col;
    istringstream iss;

    fin.seekg(ios::beg);
    while (getline(fin, line)) {
        col = 0;
        iss.clear();
        iss.str(line);
        while (iss >> matrixRowEntry) {
            zeroMatrix.setValue(row, col, matrixRowEntry);
            col++;
        }
        row++;
    }
}

ConnectivityMatrix::ConnectivityMatrix(ifstream &fin) : Matrix() {
    string line;
    double matrixRowEntry{0};
    int matrixDimension{0};
    istringstream iss;

    getline(fin, line);
    iss.str(line);
    while (iss >> matrixRowEntry) {
        matrixDimension++;
    }

    *this = ConnectivityMatrix(matrixDimension);
    fillMatrix(fin, *this);
}

ConnectivityMatrix::ConnectivityMatrix(const ConnectivityMatrix &g) : Matrix(g) {
}

void matrixSwap(ConnectivityMatrix &first, ConnectivityMatrix &second) {
    swap(first.matrix, second.matrix);
}


ConnectivityMatrix &ConnectivityMatrix::operator=(ConnectivityMatrix other) {
    matrixSwap(*this, other);
    return *this;
}


ConnectivityMatrix::~ConnectivityMatrix() = default;
