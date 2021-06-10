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
    noWork
};

map<string, messageType> messageTypeConvert =
{
    { "work given", messageType::newWork },
    { "no work to do", messageType::noWork }
};

// Definitions
// #define DEBUG

// Declared functions
json decodeWork();
bool existsInJson(const json j, const string key);
json getWork();

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

        json n;
	n["server_id"] = ""; // insert server_id
	n["server_code"] = ""; // insert server_code
	assert (n["server_id"] != "" && n["server_code"] != "");

/*
	cout << textRequest(
                                                "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/give_work.php",
                                                "",
                                                n,
                                                "POST"
                                        ) << endl;
*/

        try {
                json message( jsonRequest(
                                                "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/give_work.php",
                                                "",
                                                n,
                                                "POST"
                                        ));

//		cout << message.dump() << endl;

		if (!existsInJson(message, "message"))
			return n;

		string decoded_message;

		switch (messageTypeConvert[message["message"].get<string>()]) {
			case messageType::newWork:
		                decoded_message = "";
		                for (auto& element : message["data"]) {
		                        decoded_message += decrypt(element.get<string>());
		                }
				stripUnicode(decoded_message);
//				cout << decoded_message << endl;

		                try {
		                        message["data"] = json::parse(decoded_message);
		                } catch (...) {
		                        message["data"] = decoded_message;
		                }
		                return message;
				break;

			case messageType::noWork:
				sleep_for(1s);
				throw "Try again";
				break;

			default:
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

#endif
