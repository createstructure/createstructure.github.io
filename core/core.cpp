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

	json empty;
	cout << chooseTemplate(inputs["answers"]["template"].get<string>(), inputs["token"].get<string>()) << endl;
	cout << isPositive("Y") << isPositive("a") << isPositive("n") << endl;
	cout << isNegative("Y") << isNegative("a") << isNegative("n") << endl;
	/*
	Thread(target = self.create_repo()).start()

			# Get template
			self.choose_template()

			# Get changes
			self.change_map()

			# Make all
			self.scan_and_elaborate()

			# Upload
	*/
/*
	json o;
	o["name"] = inputs["name"].get<string>();
	o["private"] = false;
	o["description"] = inputs["src"].get<string>();

	string link = string("https:/") + string("/api.github.com/orgs/CastellaniDavideTest/repos");
	string token = inputs["token"].get<string>();

	cout << jsonRequest(link, token, o, "POST").dump() << endl;

	// Clone my repo
	system(("git clone https:\u002F/github.com/createstructure/default-template /media/createstructure/" + inputs["name"].get<string>()).c_str());

	// Elaborate all
	elaborateAll("/media/createstructure/" + inputs["name"].get<string>(), getChanges(inputs, "/media/createstructure/" + inputs["name"].get<string>() + "/.createstructure/change.json"));

	// Upload
	system((
			string("cd /media/createstructure/") +
			inputs["name"].get<string>() +
			string("; ") +
			string("rm -rf .git; git init; git branch -M main; git add *; git commit -m \"createstructure\"; git push -f https:/") +
			string("/") +
			inputs["username"].get<string>() +
			string(":") +
                        inputs["token"].get<string>() +
                        string("@github.com/") +
			inputs["org"].get<string>() +
			string("/") +
                        inputs["name"].get<string>() +
			string(" -u main --set-upstream --force")
		).c_str());
#ifdef DEBUG
	system((string("cat /media/createstructure/") + inputs["name"].get<string>() + string("/docs/README.md")).c_str());
#endif // DEBUG
*/
	return 0;
}

