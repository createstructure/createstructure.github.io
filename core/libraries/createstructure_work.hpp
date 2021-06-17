/* createstructure_work library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_WORK
// If not imported yet
#define CREATESTRUCTURE_WORK

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"
#include "createstructure_rest.hpp"
#include "createstructure_cryptation.hpp"

// using ...
using namespace std;
using namespace std::this_thread;
using json = nlohmann::json;

// Global types
enum class messageType
{
	newWork,
	noWork,
	superWork
};

map<string, messageType> messageTypeConvert =
{
	{ "work given", messageType::newWork },
	{ "no work to do", messageType::noWork },
	{ "super work", messageType::superWork }
};

// Definitions
//#define DEBUG

// Global variabile(s)
json settings;

// Declared functions
json decodeWork();
bool existsInJson(const json j, const string key);
json getWork();
void superWork(string work, json workInfo);
json getSettings();

// Function(s)
bool invalidChar(char c) {
        /* Invalid char: check if a char is valid or not
         *
         * input:
         *      - c: the char to analyze
         *
         * output:
         *      - true if the given char is invalid
         */
	return !(c >= 32 && c < 128);
}

void stripUnicode(string& str) {
        /* Strip Unicode: strip a string to the readible chars
         *
         * input:
         *      - the string to adjust
         */
	str.erase(remove_if(str.begin(),str.end(), invalidChar), str.end());
}

json decodeWork() {
        /* Decode Work: get decoded work instructions
         *
         * output:
         *      - decoded work instructions
         */
        // Local varible(s)
//	cout << "dec" << endl;
#ifdef DEBUG
	cout << textRequest(
                                                "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/give_work.php",
                                                "",
                                                getSettings(),
                                                "POST"
                                        ) << endl;
#endif // DEBUG

        try {
                json message( jsonRequest(
                                                "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/give_work.php",
                                                "",
                                                getSettings(),
                                                "POST"
                                        ));

#ifdef DEBUG
		cout << "--->" << message.dump() << endl;
#endif // DEBUG

		if (!existsInJson(message, "message"))
			return message;

		string decoded_message;
		json workInfo;

		switch (messageTypeConvert[message["message"].get<string>()]) {
			case messageType::newWork:
#ifdef DEBUG
				cout << "New work" << endl;
#endif // DEBUG
		                decoded_message = "";
		                for (auto& element : message["data"]) {
		                        decoded_message += decrypt(element.get<string>());
					//cout << decoded_message << endl;
		                }

				stripUnicode(decoded_message);

#ifdef DEBUG
				cout << "Decoded message: " << decoded_message << endl;
#endif // DEBUG

		                try {
		                        message["data"] = json::parse(decoded_message);
		                } catch (...) {
		                        message["data"] = decoded_message;
		                }

		                return message;
				break;

			case messageType::noWork:
#ifdef DEBUG
				cout << "No work" << endl;
#endif // DEBUG
				sleep_for(1s);
				throw "Try again";
				break;

			case messageType::superWork:
#ifdef DEBUG
				cout << "Superwork" << endl;
#endif // DEBUG
				workInfo["server_id"] = getSettings()["server_id"].get<string>();
				workInfo["server_code"] = getSettings()["server_code"].get<string>();
				workInfo["work_id"] = message["priority_id"].get<string>();
				superWork(message["priority_message"].get<string>(), workInfo);

				throw "Finished superwork";
				break;

			default:
#ifdef DEBUG
				cout << "Ununderstanded message" << endl;
#endif // DEBUG
				cout << "Unknown message: " << message["message"] << endl;
		}
        } catch (...) {
                return decodeWork();
        }

	cout << "Error taking job work" << endl;
	return nullptr;
}

bool existsInJson(const json j, const string key) {
        /* Exist In Json: check if key exist in json
         *
	 * input:
	 *	- j: the json object
	 *	- key: the key to search
	 *
         * output:
         *      - if disponible, work instructions
         */
	return j.find(key) != j.end();
}

json getWork() {
        /* Get Work: if disponible get work instructions
         *
         * output:
         *      - if disponible, work instructions
         */
        // Local varible(s)
	// Return if new work is assigned
        json d(decodeWork());
	if (d.empty()) {
		sleep_for(5s);
		return getWork();
	}
	return d;
}

void superWork(string work, json workInfo) {
        /* Get Work: if disponible get work instructions
         *
         * input:
         *      - work: the work tag
         *      - workInfo: the information(s) to set the work as done
         */
	// Local variabile(s)
	unordered_map <string, string> works = {
			{"test", "echo test"},				// Test print
			{"update", "apt update; apt full-upgrade -y"}, 	// Update apt packages
			{"shutdown", "sleep 1m; shutdown"},		// Wait and shudown the server
			{"reboot", "sleep 1m; reboot"}			// Wait and reboot the server
		};

	// Mark the instruction as done
        request(
                        "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/finished_priority.php",
                        "",
                        workInfo,
                        "POST"
                );

	// Run instruction
	system(works[work].c_str());
}

json getSettings() {
        /* Get Settings: return the server settings
         *
         * output:
         *      - the server settings
         */
	if (settings.empty()) {
		ifstream t("server.settings");
	        string tmp((istreambuf_iterator<char>(t)),
	                        istreambuf_iterator<char>());
		settings = json::parse(tmp);
#ifdef DEBUG
		cout << "Loaded settings: " << settings.dump() << endl;
#endif // DEBUG
	}

	assert(
			settings["server_id"].get<string>() != "" &&
			settings["server_code"].get<string>() != ""
		);

	return settings;
}

#endif
