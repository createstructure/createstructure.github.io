/* createstructure_elaborate library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_ELABORATE
// If not imported yet
#define CREATESTRUCTURE_ELABORATE

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
void elaborateAll(string path, vector< pair <string, string> > changes);
void elaborateFile(string filename, vector< pair <string, string> > changes);

// Function(s)
void elaborateAll(string path, vector< pair <string, string> > changes) {
        /* Elaborate all: get and elaborate all file in the "path" directory or relative subdirectories
         *
         * inputs:
         *      - path: the path where start to scan
         *      - changes: a vector containing all the change to do in the file
         */

        for (const auto &file : filesystem::recursive_directory_iterator(path)) {
                elaborateFile(file.path(), changes);
        }
}

void elaborateFile(string filename, vector< pair <string, string> > changes) {
        /* Elaborate file: get and elaborate a file
         *
         * inputs:
         *      - filename: the file path
         *      - changes: a vector containing all the change to do in the file
         */

#ifdef DEBUG
        cout << filename << "\t" << filesystem::is_regular_file(filesystem::status(filename)) << endl;
#endif
        if(filesystem::is_regular_file(filesystem::status(filename))) {
                // Get original
                ifstream t(filename);
                string old((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());

                // Put the changed content in the same folder
                ofstream f(filename);
                f << replace(old, changes);
        }
}


#endif
