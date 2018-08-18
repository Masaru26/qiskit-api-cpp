// Copyright by Benjamin Luxbacher

#include <iostream>
#include "../IBMQuantumExperience/Credentials.h"
#include "../IBMQuantumExperience/Exceptions/ApiException.h"
#include "../IBMQuantumExperience/Config.h"

int main(int argc, char* argv[])
{
	std::cout << "TEST PROGRAM FOR QISKIT-API-CPP" << std::endl << "BY BENJAMIN LUXBACHER" << std::endl << std::endl;

	int retVal = 0;
	char* token;

	if (argc == 1)
	{
		token = "41842da110b7eef0e492e40d49a128f87a1da085d7bfefc8c1170fcb49ba995142f61935701b88426614aa1f34391575de850efb61b51ccf0ff7a97b58b60725";
	}
	else
	{
		token = argv[1];
	}

	try
	{
		Qiskit::Credentials cred(token);
	}
	catch(const Qiskit::ApiException& e)
	{
		std::cout << e.what() << std::endl;
		retVal = -1;
	}

	std::cout << std::endl << "DONE!" << std::endl;
	std::cout << retVal << std::endl;
	
	return retVal;
}
/*
0x0000000000402a09

0x0000000000402a1c
0x0000000000402a37

0x0000000000402a69
0x0000000000402b77
*/
/*
#include <iostream>
#include <string>

#define CURL_STATICLIB
#include "curl\curl.h"

#ifdef _DEBUG
#pragma comment(lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment(lib, "curl/libcurl_a_.lib")
#endif


int main(int argc, char* argv[])
{
	CURL* curl = curl_easy_init();

	if (curl)
	{
		const char* jsonObj = "{ \"name\" : \"Pedro\" , \"age\" : \"22\" }";

		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, "Accept: application/json");
		headers = curl_slist_append(headers, "Content-Type: application/json");
		headers = curl_slist_append(headers, "charsets: utf-8");

		curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
		curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_HTTP | CURLPROTO_HTTPS);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonObj);
		CURLcode res = curl_easy_perform(curl);

		if (res != CURLE_OK)
		{
			curl_easy_strerror(res);
		}

		curl_easy_cleanup(curl);
	}



	system("PAUSE");

	return 0;
}
*/
