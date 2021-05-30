/* createstructure_download library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_DOWNLOAD
// If not imported yet
#define CREATESTRUCTURE_DOWNLOAD

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
void download(string link, string position);

// Function(s)
void download(string link, string position) {
        /* Download: downloads the GitHub repo
         *
         * inputs:
         *      - link: the link of the repo
         *      - position: the position to download the repo
         */
        // Local varible(s)
	system(
			(
				string("git clone ") +
				link +
				string(" ") +
				position
			).c_str()
		);
}


#endif
