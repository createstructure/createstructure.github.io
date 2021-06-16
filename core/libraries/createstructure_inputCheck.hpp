/* createstructure_inputCheck library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_INPUTCHECK
// If not imported yet
#define CREATESTRUCTURE_INPUTCHECK

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Declared functions
bool inputCheck(json input);

// Function(s)
bool inputCheck(json input) {
        /* Input Check: split a string by a delimitator
         *
         * inputs:
         *      - input: the input to scan
         *
         * output:
         *      - true only if the input is ok
         */
	try {
		// Check if there are all the requirements
		input["username"].get<string>();
		input["token"].get<string>();
		input["server_id"].get<string>();
		input["server_code"].get<string>();
		input["work_id"].get<string>();
		input["answers"]["name"].get<string>();
		input["answers"]["descr"].get<string>();
		input["answers"]["prefix"].get<string>();
		if(input["answers"]["isOrg"].get<bool>())
			input["answers"]["org"].get<string>();
		input["answers"]["team"].get<string>();
		input["answers"]["template"].get<string>();
		input["answers"]["private"].get<bool>();
	} catch (...) {
		return false;
	}

	return true;
}


#endif
