//
// Created by subte on 2022-10-06.
//

#pragma once

#include <stdexcept>

using namespace std;

/**
 * Custom exception that is intended to be thrown when the size of an array isn't a perfect square.
 * @return String containing the appropriate error message.
 */
struct nonIntegerSqrt : public exception {
    [[nodiscard]] const char *what() const noexcept override;
};

/**
 * Custom exception that is intended to be thrown when matrix indices are out of bounds.
 * @return String containing the appropriate error message.
 */
struct unreasonableValue : public exception {
    [[nodiscard]] const char *what() const noexcept override;
};

/**
 * Custom exception that is intended to be thrown when two matrices have different dimensions.
 * @return String containing the appropriate error message.
 */
struct matricesHaveDifferentDimensions : public exception {
    [[nodiscard]] const char *what() const noexcept override;
};

/**
 * Custom exception that is intended to be thrown when two matrices have incompatible inner dimensions.
 * @return String containing the appropriate error message.
 */
struct matrixProductNotComputable : public exception {
    [[nodiscard]] const char *what() const noexcept override;
};
