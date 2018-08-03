#ifndef _CREDENTIALS_H_
#define _CREDENTIALS_H_

#include <stdio>

// The Credential class to manage the tokens
class Credentials
{
private:
	Credentials(char* token, std::map<string, string> config = null, bool verify = true, char* proxy_urls = null, std::map<string, string> ntlm_credentials = null);
	~Credentials();

	void ObtainToken(std::map<string, string> config = null);
	// Get Authenticated Token to connect with QX Platform
	char* GetToken();
	// Get User Id in QX Platform
	char* GetUserId();
	// Get Configuration setted to connect with QX Platform
	std::map<string, string> GetConfig();
	// Set Access Token to connect with QX Platform API
	void SetToken(char* access_token);
	// Set User Id to connect with QX Platform API
	void SetUserId(char* user_id);
};

#endif