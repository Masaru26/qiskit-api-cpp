// Copyright by Benjamin Luxbacher
#ifndef _CREDENTIALS_H_
#define _CREDENTIALS_H_

#include <map>
#include <string.h>
#include <iostream>

// The Credential class to manage the tokens
class Credentials
{
private:
	Credentials(char* token, std::map<std::string, std::string> config = std::map<std::string, std::string>(), bool verify = true, char* proxy_urls = NULL, std::map<std::string, std::string> ntlm_credentials = std::map<std::string, std::string>());
	~Credentials();

	char* token_unique;
	bool verify;
	std::map<std::string, std::string> config;
	char* proxy_urls;
	std::map<std::string, std::string> ntlm_credentials;

	std::map<std::string, std::string> extra_args;
	std::map<std::string, std::string> data_credentials;
	std::map<std::string, std::string> config_base = {
		{ "url", "https://quantumexperience.ng.bluemix.net/api" }
	};

	void ObtainToken(std::map<std::string, std::string> config = std::map<std::string, std::string>());
	// Get Authenticated Token to connect with QX Platform
	std::string GetToken();
	// Get User Id in QX Platform
	std::string GetUserId();
	// Get Configuration setted to connect with QX Platform
	std::map<std::string, std::string> GetConfig();
	// Set Access Token to connect with QX Platform API
	void SetToken(std::string access_token);
	// Set User Id to connect with QX Platform API
	void SetUserId(std::string user_id);
};

#endif