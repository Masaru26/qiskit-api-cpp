// Copyright by Benjamin Luxbacher
#ifndef _CREDENTIALS_H_
#define _CREDENTIALS_H_

#include <map>
#include <string.h>
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

#include "Qiskit.h"
#include "Config.h"
#include "Exceptions/ApiException.h"
#include "Exceptions/CredentialsException.h"

namespace Qiskit
{
	// The Credential class to manage the tokens
	class Credentials
	{
	public:
		Credentials();
		// The Credential class to manage the tokens
		Credentials(std::string token, Config config = Config(), bool verify = true, std::map<std::string, std::string> proxy_urls = std::map<std::string, std::string>(), std::map<std::string, std::string> ntlm_credentials = std::map<std::string, std::string>());
		~Credentials();

	private:
		std::string token_unique;
		bool verify;
		Config config;
		std::map<std::string, std::string> proxy_urls;
		std::map<std::string, std::string> ntlm_credentials;

		std::map<std::string, std::string> extra_args;
		std::map<std::string, std::string> data_credentials;

		Config config_base = Config("https://quantumexperience.ng.bluemix.net/api");

		// Obtain the token to access to QX Platform.
		// @raises CredentialsError : when token is invalid or the user has not accepted the license.
		// @raises ApiError : when the response from the server couldn't be parsed. 
		void ObtainToken(Config config);
		// Get Authenticated Token to connect with QX Platform
		std::string GetToken();
		// Get User Id in QX Platform
		std::string GetUserId();
		// Get Configuration setted to connect with QX Platform
		Config GetConfig();
		// Set Access Token to connect with QX Platform API
		void SetToken(std::string access_token);
		// Set User Id to connect with QX Platform API
		void SetUserId(std::string user_id);
	};
}

#endif