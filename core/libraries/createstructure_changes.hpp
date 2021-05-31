/* createstructure_changes library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_CHANGES
// If not imported yet
#define CREATESTRUCTURE_CHANGES

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
struct tm* initData ();
string getData(struct tm* data, string pattern);

// Function(s)
vector< pair <string, string> > getChanges (json inputs, string changesFilename) {
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
        // Function variable(s)
        vector <pair <string, string> > myChange;
	struct tm* data = initData();

        myChange.push_back(make_pair("username", inputs["username"].get<string>()));
        myChange.push_back(make_pair("solnamesol", inputs["answers"]["name"].get<string>()));
        myChange.push_back(make_pair("soldescrsol", inputs["answers"]["descr"].get<string>()));
        myChange.push_back(make_pair("solprefixsol", inputs["answers"]["prefix"].get<string>()));
        myChange.push_back(make_pair("solisorgsol", (inputs["answers"]["isOrg"].get<bool>() ? "true" : "false")));
        myChange.push_back(make_pair("solownersol", (inputs["answers"]["isOrg"].get<bool>() ?  inputs["answers"]["org"].get<string>() : inputs["username"].get<string>())));
        myChange.push_back(make_pair("solteamsol", inputs["answers"]["team"].get<string>()));
        myChange.push_back(make_pair("soltemplatesol", inputs["answers"]["template"].get<string>()));
        myChange.push_back(make_pair("solprivatesol", (inputs["answers"]["private"].get<bool>() ? "true" : "false")));
        myChange.push_back(make_pair("soltime-nowsol", getData(data, string("%Y-%m-%d"))));
        myChange.push_back(make_pair("soltime_nowsol", getData(data, string("%Y_%m_%d"))));
        myChange.push_back(make_pair("soltimenowsol", getData(data, string("%Y%m%d"))));

        return myChange;
}

struct tm* initData () {
        /* Init Data: initialize the data information
         *
         * output:
         *      - a data structure
         */
	// Function variabile(s)
	time_t rawtime;

	time (&rawtime);
	return localtime(&rawtime);
}

string getData(struct tm* data, string pattern) {
        /* Get Data: return the data info
         *
	 * inputs:
	 * 	- data: the data indicator
	 * 	- pattern: the data pattern
	 *
         * output:
         *      - the data in the given format
         */
	// Function variable(s)
	char buffer[255];

	strftime(buffer, sizeof(buffer), pattern.c_str(), data);

	return string(buffer);
}
#endif
