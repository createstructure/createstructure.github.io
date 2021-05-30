/* createstructure_positive library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_POSITIVE
// If not imported yet
#define CREATESTRUCTURE_POSITIVE

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
bool isPositive(string str);
bool isNegative(string str);

// Function(s)
bool isPositive (string str) {
        /* Is Positive: check if a string is positive
         *
         * inputs:
         *      - str: the string to scan
         *
         * output:
         *      - true if the string is rappresents a positive value
         */
        // Local varible(s)
        vector <string> positive = {"Y", "y", "Yes", "yes", "YES", "1"};

	// Return if the given string is contained in the vector of positive answers
        return find(positive.begin(), positive.end(), str) != positive.end();
}

bool isNegative (string str) {
        /* Is Negative: check if a string is negative
         *
         * inputs:
         *      - str: the string to scan
         *
         * output:
         *      - true if the string is rappresents a negative value
         */
        // Local varible(s)
        vector <string> negative = {"N", "n", "No", "no", "NO", "0"};

	// Return if the given string is contained in the vector of positive answers
        return find(negative.begin(), negative.end(), str) != negative.end();
}

#endif
