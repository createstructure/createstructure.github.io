/* createstructure_rest library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_REST
// If not imported yet
#define CREATESTRUCTURE_REST

// Dependencies
#include <bits/stdc++.h>
#include <curl/curl.h> // Remember to compile adding curl (eg. g++ a.cpp -o a -lcurl)
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Declared functions
size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp);
string textRequest (string link, string token, json data, string dataType);
json jsonRequest (string link, string token, json data, string dataType);
void request (string link, string token, json data, string dataType);

// Function(s)
size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string textRequest (string link, string token, json data, string dataType) {
	/* Text Request: do a web call
         *
         * inputs:
         *      - link: the link of the web request
         *      - token: if necessary, the token for the auth
         *      - data: the data of the request in json format
         *      - dataType: the mode to send data (POST / GET)
         *
         * output:
         *      - the web response
         */

        // Function variable(s)
	CURL *curl;
        CURLcode res;
        string readBuffer;
        struct curl_slist *slist1;
	string d = data.dump();

//	cout << "POST: " << d << endl;

	// Setting header
        slist1 = NULL;
	if (token != "")
	        slist1 = curl_slist_append(slist1, (string("Authorization: token ") + token).c_str());
        slist1 = curl_slist_append(slist1, "Content-Type: application/json");

	// Setup curl call
        curl = curl_easy_init();
        if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, d.c_str());
                curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.38.0");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);
                curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, dataType.c_str());
                curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
        }

	// Return the output string
	return readBuffer;
}

json jsonRequest (string link, string token, json data, string dataType) {
	/* Text Request: do a web call
         *
         * inputs:
         *      - link: the link of the web request
         *      - token: if necessary, the token for the auth
         *      - data: the data of the request in json format
         *      - dataType: the mode to send data (POST / GET)
         *
         * output:
         *      - the web response in json format
         */

	return json::parse(textRequest(link, token, data, dataType));
}

void request (string link, string token, json data, string dataType) {
	/* Text Request: do a web call
         *
         * inputs:
         *      - link: the link of the web request
         *      - token: if necessary, the token for the auth
         *      - data: the data of the request in json format
         *      - dataType: the mode to send data (POST / GET)
         */
	textRequest(link, token, data, dataType);
}

#endif
