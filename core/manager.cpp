// Dependencies
#include <bits/stdc++.h>
#include "libraries/json.hpp"
#include "libraries/createstructure.hpp"

// using ...
using namespace std; using json = nlohmann::json;

// Definitions
#define DEBUG

// Declared functions
int main(int argc, char *argv[]);

string gg() {
	try {
		return decrypt(string(textRequest("https:\u002F\u002Fwww.castellanidavide.it/other/rest/gpg.php", "", nullptr, "GET")));
	} catch (...) {
		return gg();
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
	// Function viariable(s)
	json inputs;
	string path;

	// Get the given input data
//	inputs = json::parse(string(argv[1]));

#ifdef DEBUG
		cout << getEmoji("✓") << endl;
#endif // DEBUG


	string plainText("Hello this is Ravi");
//	string publicKey = getPublicKey();
//	string privateKey = getPrivateKey();

	// Get encrypted
	string encrypted = encrypt(plainText);
	cout << "encrypted: " << encrypted << endl << endl;

	string decrypted = decrypt(encrypted);
	cout << "decrypted: " << decrypted << endl;

	cout << "by web: " << gg() << endl;

	return 0;
}

/*
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <stdio.h>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

//int padding = RSA_PKCS1_PADDING;

RSA * createRSA(unsigned char * key,int public_)
{
    RSA *rsa= NULL;
    BIO *keybio ;
    keybio = BIO_new_mem_buf(key, -1);
    if (keybio==NULL)
    {
        printf( "Failed to create key BIO");
        return 0;
    }
    if(public_)
    {
        rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa,NULL, NULL);
    }
    else
    {
        rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa,NULL, NULL);
    }
    if(rsa == NULL)
    {
        printf( "Failed to create RSA");
    }
 
    return rsa;
}
 
int public_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted)
{
    RSA * rsa = createRSA(key,1);
    int result = RSA_public_encrypt(data_len,data,encrypted,rsa,RSA_PKCS1_PADDING);
    return result;
}

unsigned char* decrypt(unsigned char* original, unsigned char* key) {
        /* Decrypt: decrypt a message using RSA
         *
         * inputs:
         *      - original: the original message
         *      - key: the key to decrypt the message
         *
         * output:
         *      - the decrypted message
         * /
        // Local varible(s)
        unsigned char* output;
        RSA* rsa;

        // Create rsa
        rsa = createRSA(
                                key,
                                false
                        );

        // Decrypt
        if (
                        RSA_private_decrypt(
                                        strlen((char*)original),//original.length(),
                                        original,
                                        output,
                                        rsa,
                                        RSA_PKCS1_PADDING
                                )
                        != -1
                )
                return output;
        else
                exit(0);
}

int private_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted)
{
    RSA * rsa = createRSA(key,0);
    int  result = RSA_private_decrypt(data_len,enc_data,decrypted,rsa,RSA_PKCS1_PADDING);
    return result;
}

int main(){
	char plainText[2048/8] = "Hello this is Ravi"; //key length : 2048
ifstream t("public.pem");
string publicKey((istreambuf_iterator<char>(t)),
                 istreambuf_iterator<char>());

ifstream t2("private.pem");
string privateKey((istreambuf_iterator<char>(t2)),
                 istreambuf_iterator<char>());

unsigned char encrypted[4098]={};
unsigned char decrypted[4098]={};
/*
size_t encrypted_length = public_encrypt(
					(unsigned char*)plainText,
					strlen(plainText),
					(unsigned char*)publicKey.c_str(),
					encrypted
				);

if(encrypted_length == -1)
{
    puts("Public Encrypt failed");
    exit(0);
}* /

unsigned char tmp[4098] = "\x94\x1b\xc4\x8d\x77\xdd\x0a\x05\x26\x58\x8f\xf4\xf4\xaf\xd1\x19\xe4\x7c\x2e\x89\x87\x27\x85\xcd\xe4\x0d\xb1\x2c\x90\x83\x49\x33\x98\x6c\x94\xb8\xcd\x0c\xaf\x2b\x5b\x8d\xec\x3d\x44\x2e\x86\xf7\xe7\x9c\x9a\x24\x08\xb4\x3b\xca\x9c\x07\xd2\x03\xdc\x5e\xa6\x01\xc7\x97\xd5\x84\xb2\xee\x60\x10\x07\x79\x54\x23\x8e\x6c\xc6\x7f\x8d\x79\x6b\x27\xcd\x45\x94\xba\x48\x5a\xa1\x7d\x55\xcb\x55\xe3\xb3\x52\x27\x5c\x71\x58\x17\x64\x76\x4e\xba\xa6\x55\xe1\x18\x4c\xa6\xe5\x84\x19\xdb\xa3\xb2\x47\xd6\x06\x1a\x6b\xfb\x3c\x87\x9e\xb6\x67\xe0\xd0\xac\x4e\xc1\xcf\xa6\x65\x79\xe0\xf3\x7f\x8a\xc4\x7f\x1f\xcd\x18\xab\x75\x76\x8d\xd0\x68\xf8\x2b\xf4\xf8\xa2\x7c\xb3\x35\x2d\x58\xa5\xe8\xa8\x5a\x92\xc4\x30\x66\x1b\x75\x4f\xb2\x1c\x5f\xa3\x54\x4c\x3f\x9c\xd3\x62\xb2\xcc\x5b\x8f\x1e\xb8\x1c\xa1\x70\xbc\x66\x2a\x35\x35\x33\x50\xfb\x4c\x30\x1e\x33\xc8\xaa\xa0\xd8\x5a\x3f\x9d\x5f\xeb\xec\xb9\x68\xda\x9b\xf0\x68\xb9\x1b\x71\xef\x4e\x52\xd0\xc0\xcc\xcf\x84\x3a\x23\x81\x07\x58\x68\xf6\x3f\x51\x2c\xbd\x8b\x4a\x1b\xd5\x6f\xca\x5e\xc1\x67\x16\x59\xfc";
printf("Encrypted text =%s\n", tmp);
printf("Encrypted text hex =");
unsigned char* cp = tmp;
for ( ; *cp != '\0'; ++cp )
{
   printf("%02x", *cp);
}
puts("\n");
//printf("Encrypted length =%d\n",encrypted_length);
 
size_t decrypted_length = private_decrypt(
					tmp,
					strlen((char*)tmp),
					(unsigned char*)privateKey.c_str(),
					decrypted
				);
if(decrypted_length == -1)
{
//    puts("Private Decrypt failed");
    exit(0);
}
printf("Decrypted Text =%s\n",decrypted);
printf("Decrypted Length =%d\n",decrypted_length);

cout << "try2" << decrypt(tmp, (unsigned char*)privateKey.c_str()) << endl;
}

*/
