#include "Credentials.h"

Credentials::Credentials(char* token, std::map<std::string, std::string> config = std::map<std::string, std::string>(), bool verify = true, char* proxy_urls = NULL, std::map<std::string, std::string>ntlm_credentials = std::map<std::string, std::string>())
{
	this->token_unique = token;
	this->verify = verify;
	this->config = config;
	this->proxy_urls = proxy_urls;
	this->ntlm_credentials = ntlm_credentials;

	// Set the extra arguments to requests (proxy and auth).
	if (this->proxy_urls != NULL)
	{
		this->extra_args["proxies"] = this->proxy_urls;
	}
	if (!this->ntlm_credentials.empty)
	{
		/*this->extra_args["auth"] = HttpNtlmAuth(
			this->ntlm_credentials["username"],
			this->ntlm_credentials["password"]);*/
		std::cout << "HttpNtlmAuth();" << std::endl;
	}

	if (!verify)
	{
		// ToDo:
		// import requests.packages.urllib3 as urllib3
		// urllib3.disable_warnings()
		std::cout << "-- Ignoring SSL errors.  This is not recommended --" << std::endl;
	}
	if (!this->config.empty && this->config.count("url") == 0)
	{
		this->config["url"] = this->config_base["url"];
	}
	else if (this->config.empty)
	{
		this->config = this->config_base;
	}

	// ToDo:
	// self.data_credentials = {}
	if (token != NULL)
	{
		this->ObtainToken(this->config);
	}
	else
	{
		std::string access_token = this->config["access_token"];
		if (!access_token.empty)
		{
			std::string user_id = this->config["user_id"];
			if (!access_token.empty)
			{
				this->SetToken(access_token);
			}
			if (!user_id.empty)
			{
				this->SetUserId(user_id);
			}
		}
		else
		{
			this->ObtainToken(this->config);
		}
	}
}

// Obtain the token to access to QX Platform.
// @raises CredentialsError : when token is invalid or the user has not accepted the license.
// @raises ApiError : when the response from the server couldn't be parsed. 
void Credentials::ObtainToken(std::map<std::string, std::string> config = std::map<std::string, std::string>())
{

}

// Get Authenticated Token to connect with QX Platform
std::string Credentials::GetToken()
{
	return this->data_credentials["id"];
}

// Get User Id in QX Platform
std::string Credentials::GetUserId()
{
	return this->data_credentials["userId"];
}

// Get Configuration setted to connect with QX Platform
std::map<std::string, std::string> Credentials::GetConfig()
{
	return this->config;
}

// Set Access Token to connect with QX Platform API
void Credentials::SetToken(std::string access_token)
{
	this->data_credentials["id"] = access_token;
}

// Set User Id to connect with QX Platform API
void Credentials::SetUserId(std::string user_id)
{
	this->data_credentials["user_id"] = user_id;
}