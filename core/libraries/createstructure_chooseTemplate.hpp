/* createstructure_chooseTemplate library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_CHOOSETEMPLATE
// If not imported yet
#define CREATESTRUCTURE_CHOOSETEMPLATE

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Declared functions
bool hasInit (string fullString, string init);
bool hasEnding (string fullString, string ending);
string chooseTemplate (string givenTemplate, string token, string username);

// Function(s)
bool hasInit (string fullString, string init) {
	/* Choose Template: get the url of the choosed template
         *
         * inputs:
         *      - fullString: the string to scann the eventually end
         *      - ending: the end test
         *
         * output:
         *      - if ending is the end of fullString
         */
	if (fullString.length() >= init.length()) {
		return (0 == fullString.compare(
				0,
				init.length(),
				init)
			);
	} else {
		return false;
	}
}

bool hasEnding (string fullString, string ending) {
	/* Choose Template: get the url of the choosed template
         *
         * inputs:
         *      - fullString: the string to scann the eventually end
	 *	- ending: the end test
         *
         * output:
         *      - if ending is the end of fullString
         */
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(
				fullString.length() - ending.length(),
				ending.length(),
				ending)
			);
	} else {
		return false;
	}
}

string chooseTemplate (string givenTemplate, string token, string username) {
        /* Choose Template: get the url of the choosed template
         *
         * inputs:
         *      - givenTemplate: the given template
         *      - token: to get access to the repo infos
         *      - username: to get access to the repo infos
         *
         * output:
         *      - template url
         */
        // Local varible(s)
	string urlTemplate = givenTemplate;

	// Elaborate

	// Change spaces with "-"
	replace(urlTemplate.begin(), urlTemplate.end(), ' ', '-');

	// Add "-template" if not exists yet
	if (!hasEnding(urlTemplate, "-template")) {
		urlTemplate += "-template";
	}

	// Add initial part of the url
	try {
		if (urlTemplate.find('/') != string::npos) {
			// External template
			json data = jsonRequest(string("https:\u002F\u002Fapi.github.com/repos/") + urlTemplate, token, nullptr, "GET");
			assert(data["private"].get<bool>());
			urlTemplate = string("https:\u002F\u002F") + username + string(":") + token + string("@github.com/") + urlTemplate;
		} else {
			// Internal template
			json data = jsonRequest(string("https:\u002F\u002Fapi.github.com/repos/createstructure/") + urlTemplate, token, nullptr, "GET");
			assert(!data["private"].get<bool>());
			urlTemplate = string("https:\u002F\u002Fgithub.com/createstructure/") + urlTemplate;
		}
	} catch (...) {
		// If it's impossible to take given template, use the default one
		urlTemplate = "https:\u002F\u002Fgithub.com/createstructure/default-template";
	}

        // Return
        return urlTemplate;
}


#endif
