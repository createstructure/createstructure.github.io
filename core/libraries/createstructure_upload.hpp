/* createstructure_split library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_SPLIT
// If not imported yet
#define CREATESTRUCTURE_SPLIT

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
vector<string> split(string str, string del);

// Function(s)
vector <string> split (string str, string del) {
        /* Split: split a string by a delimitator
         *
         * inputs:
         *      - str: the string to elaborate
         *      - del: the delimitator
         *
         * output:
         *      - a vector containing the pieces of the slitted string
         */
        // Local varible(s)
        vector <string> splitted;
        size_t pos;

        // Split
        while ((pos = str.find(del)) != string::npos) {
                splitted.push_back(str.substr(0, pos));
                str.erase(0, pos + del.length());
        }
        splitted.push_back(str);

        // Return
        return splitted;
}


#endif
