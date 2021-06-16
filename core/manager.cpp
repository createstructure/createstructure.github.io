// Dependencies
#include <bits/stdc++.h>
#include "libraries/json.hpp"
#include "libraries/createstructure.hpp"

// using ...
using namespace std;
using namespace std::this_thread;
using json = nlohmann::json;

// Definitions
//#define DEBUG
//#define VIEW_OUTPUT // View the docker output
//#define ONCE

#ifdef DEBUG
	#define VIEW_OUTPUT
#endif // DEBUG

// Declared functions
int main(int argc, char *argv[]);
void eraseAllSubStr(string &mainStr, const string toErase);

// Code
int main(int argc, char *argv[]) {
	/* Main: the start point of the code
	 *
	 * inputs:
	 * 	- argc: the number of command-line arguments
	 *	- argv: an array containing all command-line arguments
 	 *
	 * output:
	 *	- a run code: if it works in the correct way it will return 0
	 */
	// Function variable(s)
	int i = 0;

#ifndef ONCE
	while (true) {
#endif // ONCE
		// Block if the PC if full of work
		if (percentageMemory() > 50 || !okMemory())
	                while (!okMemory()) {
	                        sleep_for(1s);
	                }

		// Get data
	        json jData = getWork();
	        string data = jData["data"].dump();
#ifdef DEFAULT
		cout << data << endl;
#endif // DEFAULT
	        eraseAllSubStr(data, "\\u0000");

		// Run job
	        system(
				(
					string("docker run test2:09.01 '") +
					data +
#ifdef VIEW_OUTPUT
					"' &"
#else // VIEW_OUTPUT
					"' > /dev/null &"
#endif // VIEW_OUTPUT
				).c_str()
			);
	        cout << "Runned process n°" << i++ << endl;

		// Set work as finished
	        json finishJson;
	        finishJson["server_id"] = jData["data"]["server_id"].get<string>();
	        finishJson["server_code"] = jData["data"]["server_code"].get<string>();
	        finishJson["work_id"] = jData["data"]["work_id"].get<string>();
                string link("https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/started_work.php");
	        request(link, "", finishJson, "POST");
	        sleep_for(500ms);
#ifndef ONCE
	}
#endif // ONCE

	return 0;
}

void eraseAllSubStr(string &mainStr, const string toErase) {
    size_t pos = string::npos;
    while ((pos = mainStr.find(toErase) )!= string::npos)
        mainStr.erase(pos, toErase.length());
}
