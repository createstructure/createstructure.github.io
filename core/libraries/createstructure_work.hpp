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

// Definitions
// #define DEBUG

// Declared functions
json decodeWork();
bool existsInJson(const json j, const string key);
json getWork();

// Function(s)
json decodeWork() {
        /* Decode Work: get decoded work instructions
         *
         * output:
         *      - decoded work instructions
         */
        // Local varible(s)
        json n;
	n["server_id"] = ""; // insert server_id
	n["server_code"] = ""; // insert server_code
	assert (n["server_id"] != "" && n["server_code"] != "");

        try {
                json message( jsonRequest(
                                                "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/give_work.php",
                                                "",
                                                n,
                                                "POST"
                                        ));

		if (!existsInJson(message, "data"))
			return n;

                string decoded_message = "";
                for (auto& element : message["data"]) {
                        decoded_message += decrypt(element.get<string>());
                }

                try {
                        message["data"] = json::parse(decoded_message);
                } catch (...) {
                        message["data"] = decoded_message;
                }

                return message;
        } catch (...) {
                return decodeWork();
        }
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
