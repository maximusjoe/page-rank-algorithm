//
// Created by subte on 2022-10-06.
//

#include "customExceptions.hpp"

using namespace std;

const char *
nonIntegerSqrt::what() const noexcept { return "Array size must have a square root that evaluates to an integer."; }

const char *
unreasonableValue::what() const noexcept { return "Row and column values must be reasonable."; }

const char *
matricesHaveDifferentDimensions::what() const noexcept { return "Matrices must have the same dimensions."; }

const char *
matrixProductNotComputable::what() const noexcept {
    return "Multiplied matrices must have corresponding numbers of columns (left-hand side) and rows (right-hand "
           "side).";
}
