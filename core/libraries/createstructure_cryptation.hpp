/* createstructure_cryptation library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_CRYPTATION
// If not imported yet
#define CREATESTRUCTURE_CRYPTATION

// Dependencies
#include <bits/stdc++.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Declared functions
string getKey(string filename);
string getPublicKey();
string getPrivateKey();
RSA* createRSA(string key, bool isPublic);
string encrypt(string original);
string decrypt(string original);

// Function(s)
string getKey(string filename) {
        /* Get Key: gives the key by the passed filename
         *
         * inputs:
         *      - filename: the filename of the key
         *
         * output:
         *      - the key of the selected file
         */
	// Get file content
	ifstream t(filename);
	string key((istreambuf_iterator<char>(t)),
			istreambuf_iterator<char>());

	// Return file content
	return key;
}

string getPublicKey() {
        /* Get Public Key: gives the public key
         *
	 * output:
         *      - the public key
         */
	return getKey("public.pem");
}

string getPrivateKey() {
        /* Get Private Key: gives the private key
         *
	 * output:
         *      - the private key
         */
	return getKey("private.pem");
}

RSA* createRSA(string key, bool isPublic) {
        /* create RSA: creates a RSA object
         *
         * inputs:
         *      - key: the public/ private key
         *      - isPublic: true if it's public, false if it's private
         *
         * output:
         *      - an RSA object rappresenting the passed key
         */
        // Local varible(s)
	RSA* rsa = NULL;
	BIO* keybio;

	// Create the bio
	keybio = BIO_new_mem_buf(
					(unsigned char*) key.c_str(),
					-1
				);
	if (keybio == NULL)
		throw invalid_argument("Error: failed to create key BIO");

	// Create rsa
	if(isPublic)
		rsa = PEM_read_bio_RSA_PUBKEY(
							keybio,
							&rsa,
							NULL,
							NULL
						);
	else
		rsa = PEM_read_bio_RSAPrivateKey(
							keybio,
							&rsa,
							NULL,
							NULL
						);

	if(rsa == NULL)
		throw invalid_argument("Error: failed to create RSA");

	// Return
	return rsa;
}

string encrypt(string original) {
        /* Encrypt: encrypt a message using RSA
         *
         * inputs:
         *      - original: the original message
         *
         * output:
         *      - the encrypted message
         */
	// Local varible(s)
	RSA* rsa;
	unsigned char output[4098] = {0};
	int output_length;

	// Create rsa
	rsa = createRSA(
				getPublicKey(),
				true
			);

	// Encrypt
    	if (
			(output_length =
				RSA_public_encrypt(
					strlen(original.c_str()),
					(unsigned char*) original.c_str(),
					output,
					rsa,
					RSA_PKCS1_PADDING
				)
			)
			!= -1
		) {

		// Convert to hex
		stringstream hexString;
		for(int i = 0; i < output_length; ++i) {
			hexString << hex << setfill('0') << setw(sizeof(unsigned char) * 2) << (int) output[i];
//			cout << hex << setfill('0') << setw(sizeof(unsigned char) *2) << (int) output[i] << endl;
		}

		// If encrypted is ok, send crypted text
		try {
			decrypt(hexString.str());// == original);
			return hexString.str();
		} catch (...) {
			return encrypt(original);
		}
	} else {
		// Error
		throw invalid_argument("Error: encryption failed");
	}
}


string decrypt(string original) {
        /* Decrypt: decrypt a message using RSA
         *
         * inputs:
         *      - original: the original message
         *
         * output:
         *      - the decrypted message
         */
	// Local varible(s)
	RSA* rsa;
	unsigned char original2[4098] = {0};
	unsigned char output[4098] = {0};
	int output_length;

	// Create rsa
	rsa = createRSA(
				getPrivateKey(),
				false
			);

	// Convert input to not hex
	{
		// Tmp variabile(s)
		unsigned int tmp;
		stringstream ss;
		size_t index = 0;

		//cout << "0)" << original << endl;
		//cout << "1)" << original.length() << endl;

		// For every char
		for (int i = 0; i < original.length() / 2; ++i) {
			// Clear stringsteam
			ss.str("");
			ss.clear();

			// Get not hex data
			ss << original.substr(i*2, 2).c_str();
			ss >> hex >> tmp;
			//cout << tmp;
			original2[index++] = (unsigned char) tmp;
			//cout << hex << tmp;
		}
	}

	// Decrypt
    	if (
			(output_length =
				RSA_private_decrypt(
					strlen((char*) original2),
					original2,
					output,
					rsa,
					RSA_PKCS1_PADDING
				)
			)
			!= -1
		) {

		// Return
		return string(output, output + sizeof(output) / sizeof(output[0]));
	} else {
		// Error
		throw invalid_argument("Error: decryption failed");
	}
}

#endif
