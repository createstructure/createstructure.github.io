// Dependencies
#include <bits/stdc++.h>
#include "libraries/json.hpp"
#include "libraries/createstructure.hpp"

// using ...
using namespace std;
using namespace std::this_thread;
using json = nlohmann::json;

// Definitions
#define DEBUG

// Declared functions
int main(int argc, char *argv[]);

void eraseAllSubStr(string &mainStr, const string toErase)
{
    size_t pos = string::npos;
    while ((pos = mainStr.find(toErase) )!= string::npos)
        mainStr.erase(pos, toErase.length());
}

void stressTest(int t) {
	for (size_t i = 0; i < t; ++i) {
		if (percentageMemory() > 50 || !okMemory())
			while (!okMemory()) {
				cout << "P: " << percentageMemory() << "%" << endl;
				sleep_for(1s);
			}
		json jData = getWork();
		string data = jData["data"].dump();
		eraseAllSubStr(data, "\\u0000");
		system((string("docker run test2:09.01 '") + data + "' > /dev/null &").c_str());
		cout << "Runned process n°" << i << endl;
		                // Set work as finished
                json finishJson;
                finishJson["server_id"] = jData["data"]["server_id"].get<string>();
                finishJson["server_code"] = jData["data"]["server_code"].get<string>();
                finishJson["work_id"] = jData["data"]["work_id"].get<string>();

                string link("https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/finished_work.php");
                cout << "Finished: " << textRequest(link, "", finishJson, "POST") << endl;
		sleep_for(500ms);
	}
}

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

/*
	// Memory info
	cout << getEmoji("information") << "\tTotal memory: \t" << totalMemory() << endl;
	cout << getEmoji("information") << "\tUsed memory: \t" << usedMemory() << endl;
	cout << getEmoji("information") << "\tFree memory: \t" << freeMemory() << endl;
	cout << getEmoji("information") << "\tTotal memory: \t" << percentageMemory() << "%" << endl;
	cout << getEmoji("information") << "\tOK memory: \t" << okMemory() << endl;
*/

	// Stree test(s)
//	stressTest(1); // 5s
//	stressTest(10); // 13s
//	stressTest(50); // 28s
//	stressTest(100); // 55s


	int i = 0;

	while (true) {
		if (percentageMemory() > 50 || !okMemory())
	                while (!okMemory()) {
	                        cout << "P: " << percentageMemory() << "%" << endl;
	                        sleep_for(1s);
	                }
	        json jData = getWork();
	        string data = jData["data"].dump();
	        eraseAllSubStr(data, "\\u0000");
	        system((string("docker run test2:09.01 '") + data + "' > /dev/null &").c_str());
	        cout << "Runned process n°" << i++ << endl;

		// Set work as finished
	        json finishJson;
	        finishJson["server_id"] = jData["data"]["server_id"].get<string>();
	        finishJson["server_code"] = jData["data"]["server_code"].get<string>();
	        finishJson["work_id"] = jData["data"]["work_id"].get<string>();

                string link("https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/finished_work.php");
	        request(link, "", finishJson, "POST");
	        sleep_for(500ms);
	}
	return 0;
}