// Dependencies
#include <bits/stdc++.h>
#include "libraries/json.hpp"
#include "libraries/createstructure.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
#define DEBUG

// Global viariabiles
json inputs;

// Declared functions
int main(int argc, char *argv[]);

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

	// Get the given input data
	inputs = json::parse(string(argv[1]));

#ifdef DEBUG
	cout << inputs.dump() << endl;
#endif // DEBUG

	if (inputCheck(inputs)) {
		download(chooseTemplate(inputs["answers"]["template"].get<string>(), inputs["token"].get<string>(), inputs["username"].get<string>()), (string("/media/createstructure/") + inputs["username"].get<string>() + string("???") + inputs["answers"]["name"].get<string>()).c_str());

		system("ls -R /media/createstructure");

		json o;
		o["name"] = inputs["answers"]["name"].get<string>();
		o["description"] = inputs["answers"]["descr"].get<string>();

		string link = string("https:\u002F\u002Fapi.github.com/") +
				(inputs["answers"]["isOrg"].get<bool>() ?
	                                (string("orgs/") + inputs["answers"]["org"].get<string>()) :
	                                "user") +
				string("/repos");
		string token = inputs["token"].get<string>();
		request(link, token, o, "POST");

		upload(string("https:\u002F\u002F") +
                        inputs["username"].get<string>() +
                        string(":") +
                        inputs["token"].get<string>() +
                        string("@github.com/") +
                        (inputs["answers"]["isOrg"].get<bool>() ?
				inputs["answers"]["org"].get<string>() :
				inputs["username"].get<string>()) +
                        string("/") +
                        inputs["answers"]["name"].get<string>(),

			string("/media/createstructure/") +
			inputs["username"].get<string>() +
			string("???") +
			inputs["answers"]["name"].get<string>()
			);

	} else {
		cout << "Given uncorrect data " << getEmoji("sad") << endl;
	}
/*
*/
	return 0;
}

