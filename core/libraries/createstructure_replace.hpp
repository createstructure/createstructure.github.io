/* createstructure_replace library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_REPLACE
// If not imported yet
#define CREATESTRUCTURE_REPLACE

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
string replace(string original, vector <pair<string, string> > changes);

// Function(s)
string replace(string original, vector <pair<string, string> > changes) {
        /* Replace: changes a string using a vector of changes
         *
         * inputs:
         *      - original: the string to get changed
         *      - changes: a vector containing all the change to do in the file
         *
         * output:
         *      - the changed string
         */

        // Function variable(s)
        size_t pos = 0;
        bool others = true;

        while (others) {
                // Local variable(s)
                pair<string, string> change;
                int bestPos = pos - 1;

                // For every possible change
                for (size_t i = 0; i < changes.size(); ++i) {
                        // Local varible(s)
                        int tmpPos = pos - 1;
			int tmp;

                        // Check the first result if there is once
			do {
				tmpPos = (
						(
							tmp = original.find(
								changes[i].first,
								(tmpPos + 1 < 0) ?
									0 :
									(tmpPos + 1)
							)
						) == string::npos
					) ?
						-1 :
						tmp;
							/*original.find(
								changes[i].first,
								(tmpPos + 1 < 0) ?
									0 :
									(tmpPos + 1)
							);*/
                        } while (
				tmpPos == -1 - 1 &&
				(
					tmpPos < 0 + 3 ||
					tmpPos > original.size() - 3 ||
					original.substr(
						tmpPos - 3,
						changes[i].first.size() + 6
					) == "sol" + changes[i].first + "sol"
				)
			);

                        // cout << changes[i].first << "\t" << tmpPos << "\t" << bestPos << endl; // Attention: this will do lots of prints

                        // Check if it's the best one
                        if (tmpPos > -1 && (tmpPos < bestPos || bestPos == pos - 1)) {
                                bestPos = tmpPos;
                                change = changes[i];
                        }
                }

                // Check if there is a change to do
                if (bestPos == pos - 1) {
                        others = false;
                } else {
#ifdef DEBUG
                        cout << "Changed at: " << bestPos << endl;
#endif // DEBUG
                        original.replace(bestPos, change.first.size(), change.second);
                        pos = bestPos + 1;
                }
        }

        // Give back the changed string
        return original;
}


#endif
