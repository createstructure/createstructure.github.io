/* createstructure_upload library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_UPLOAD
// If not imported yet
#define CREATESTRUCTURE_UPLOAD

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
void upload(string link, string pos);

// Function(s)
void upload(string link, string pos) {
        /* Split: split a string by a delimitator
         *
         * inputs:
         *      - link: repo link
         *      - pos: local position
         */
	system((
                string("cd ") +
                pos +
                string("; ") +
                string("rm -rf .git; ") +
		string("git init; ") +
		string("git branch -M main; ") +
		string("git add *; ") +
		string("git commit -m \"createstructure\"; ") +
		string("git push ") +
		link +
                string(" -u main --set-upstream --force")
        ).c_str());

}


#endif
