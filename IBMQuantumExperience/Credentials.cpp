#include "Credentials.h"

char* token_unique;
bool verify;
std::map<string, string> config;
char* proxy_urls;
char* ntlm_credentials;

std::map<string, string> extra_args;
char* data_credentials;

std::map<string, string> config_base = {
	{ "url", "https://quantumexperience.ng.bluemix.net/api" }
};

Credentials::Credentials(char* token, std::map<string, string> config = null, bool verify = true, char* proxy_urls = null, std::map<string, string>ntlm_credentials = null)
{
	this.token_unique = token_unique;
	this.verify = verify;
	this.config = config;
	this.proxy_urls = proxy_urls;
	this.ntlm_credentials = ntlm_credentials;

	// Set the extra arguments to requests (proxy and auth).
	if (this.proxy_urls != null)
	{
		this.extra_args["proxies"] = this.proxy_urls;
	}
	if (this.ntlm_credentials != null)
	{
		this.extra_args["auth"] = HttpNtlmAuth(
			this.ntlm_credentials["username"],
			this.ntlm_credentials["password"]);
	}

	if (!verify)
	{
		// ToDo:
		// import requests.packages.urllib3 as urllib3
		// urllib3.disable_warnings()
		std::cout << "-- Ignoring SSL errors.  This is not recommended --" << std::endl;
	}
	if (this.config != null && this.config.count("url") == 0)
	{
		this.config["url"] = this.config_base["url"];
	}
	else if (this.config == null)
	{
		this.config = this.config_base;
	}

	// ToDo:
	// self.data_credentials = {}
	if (token != null)
	{
		this.ObtainToken(this.config);
	}
	else
	{
		char* access_token = this.config["access_token"];
		if (access_token != null)
		{
			char* user_id = this.config["user_id"];
			if (access_token != null)
			{
				this.SetToken(access_token);
			}
			if (user_id != null)
			{
				this.SetUserId(user_id);
			}
		}
		else
		{
			this.ObtainToken(this.config);
		}
	}
}

void Credentials::ObtainToken(std::map<string, string> config = null)
{

}

// Get Authenticated Token to connect with QX Platform
char* Credentials::GetToken()
{
	return this.data_credentials["id"];
}

// Get User Id in QX Platform
char* Credentials::GetUserId()
{
	return this.data_credentials["userId"];
}

// Get Configuration setted to connect with QX Platform
std::map<string, string> Credentials::GetConfig()
{
	return this.config;
}

// Set Access Token to connect with QX Platform API
void Credentials::SetToken(char* access_token)
{
	this.data_credentials["id"] = access_token;
}

// Set User Id to connect with QX Platform API
void Credentials::SetUserId(char* user_id)
{
	this.data_credentials["user_id"] = user_id;
}