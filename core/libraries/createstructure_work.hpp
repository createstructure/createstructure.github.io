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
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Declared functions
json decodeWork();
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

        try {
                json message (jsonRequest(
                                                "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/give_work.php",
                                                "",
                                                n,
                                                "POST"
                                        ));

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


json getWork() {
        /* Get Work: if disponible get work instructions
         *
         * output:
         *      - if disponible, work instructions
         */
        // Local varible(s)
        json data;

	// Avariability check
        if (
                 jsonRequest(
                                "https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/give_work.php",
                                "",
                                data,
                                "POST"
                )["code"].get<string>() != "assigned new work") {
		// Return if there is no new work to do
                return nullptr;
        }

	// Return if new work is assigned
        return decodeWork();
}

#endif
