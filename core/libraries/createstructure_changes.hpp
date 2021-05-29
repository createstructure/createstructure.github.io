/* createstructure_changes library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_CHANGES
// If not imported yet
# define CREATESTUCTURE_CHANGES

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Declared functions
vector< pair <string, string> > getChanges(json inputs, string changesFilename);
vector< pair <string, string> > getSpecialChanges(json inputs);

// Function(s)
vector< pair <string, string> > getChanges(json inputs, string changesFilename) {
        /* Get Changes: return the vector containing all the changes
         *
	 * inputs:
	 * 	- inputs: a json object containing the args given as input
	 *	- changesFilename: the Changes filename path
	 *
         * output:
         *      - a vector containing all the changes
         */
        // Local varible(s)
        vector <pair <string, string> > myChange;
        vector <pair <string, string> > mySpecialChange = getSpecialChanges(inputs);

        // Get file and convert to json
        ifstream t(changesFilename);
        string strChanges((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
        json jsonChanges = json::parse(strChanges);

        // Put changes to the vector
        for (auto& [key, value] : jsonChanges.items()) {
                myChange.push_back(make_pair(key, replace(value, mySpecialChange)));
#ifdef DEBUG
                cout << myChange[myChange.size() - 1].first << " -> " << myChange[myChange.size() - 1].second << endl;
#endif // DEBUG
        }

        return myChange;
}

vector< pair <string, string> > getSpecialChanges(json inputs) {
        /* Get Special Changes: return the vector containing all the special changes
         *
         * output:
         *      - a vector containing all the special changes
         */
        // Local varible(s)
        vector <pair <string, string> > myChange;

        myChange.push_back(make_pair("solnamesol", inputs["name"].get<string>()));
        myChange.push_back(make_pair("time__now", "2021-05-28"));

        return myChange;
}


#endif
