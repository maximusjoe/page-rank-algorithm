//Name: Benjamin Friedman & Maximus Joe
//Student# : A01248859(Benjamin) & A01256098(Maximus)

#include <iostream>
#include "ConnectivityMatrix.hpp"
#include "ProbabilityMatrix.hpp"
#include "TransitionMatrix.hpp"
#include "RankMatrix.hpp"

#define NO_FILE_ERROR_MSG "Unable to open file."
#define GENERAL_ERROR_MSG "Terminating the program..."
#define ERROR_CODE 1

constexpr double RANDOM_WALK_PROBABILITY{0.85};

using namespace std;

/**
 * Driver program for the shorthand version
 * of the Google page rank algorithm.
 * This program reads a file containing a connectivity
 * matrix and prints out the processed data in
 * order of rank.
 *
 * @return exit code
 */
int main() {
    try {
        // Open and check if connectivity.txt file exists.
        ifstream fin{"../connectivity.txt", ios_base::in};
        if (!fin) {
            cerr << NO_FILE_ERROR_MSG << endl;
            exit(ERROR_CODE);
        }

        // Separate constructors for the page rank algorithm.
        ConnectivityMatrix G(fin);
        ProbabilityMatrix S(G);
        TransitionMatrix M(S, RANDOM_WALK_PROBABILITY);
        RankMatrix R(M);

        // Print out appropriately ranked pages.
        cout << R;
        return 0;
    } catch (exception &e) {

        // Catch and print file not found exception
        cout << e.what() << endl;
        cout << GENERAL_ERROR_MSG << endl;
        exit(ERROR_CODE);
    }
}
