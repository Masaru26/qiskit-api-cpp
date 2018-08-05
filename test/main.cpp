// Copyright by Benjamin Luxbacher
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
		CURLcode res;
		curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
		curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_HTTP | CURLPROTO_HTTPS);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "var1=value1&var2=value2");
		res = curl_easy_perform(curl);

		if (res != CURLE_OK)
		{
			curl_easy_strerror(res);
		}

		curl_easy_cleanup(curl);
	}



	system("PAUSE");

	return 0;
}