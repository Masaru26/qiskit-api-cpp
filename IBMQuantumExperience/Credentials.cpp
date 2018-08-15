// Copyright by Benjamin Luxbacher
#include "Credentials.h"

namespace Qiskit
{
	Credentials::Credentials(std::string token, std::map<std::string, std::string> config, bool verify, char* proxy_urls, std::map<std::string, std::string>ntlm_credentials)
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
		if (!this->ntlm_credentials.empty())
		{
			/*
			ToDo:
			this->extra_args["auth"] = HttpNtlmAuth(
				this->ntlm_credentials["username"],
				this->ntlm_credentials["password"]);
			*/
			std::cout << "HttpNtlmAuth();" << std::endl;
		}

		if (!verify)
		{
			// ToDo:
			// import requests.packages.urllib3 as urllib3
			// urllib3.disable_warnings()
			std::cout << "-- Ignoring SSL errors.  This is not recommended --" << std::endl;
		}
		// if config does not contain url => use default url
		if (!this->config.empty() && this->config.count("url") == 0)
		{
			this->config["url"] = this->config_base["url"];
		}
		// if there is no config => use default config
		else if (this->config.empty())
		{
			this->config = this->config_base;
		}

		// ToDo:
		// self.data_credentials = {}
		// if no token => get token
		if (!token.empty())
		{
			this->ObtainToken(this->config);
		}
		else
		{
			std::string access_token = this->config["access_token"];
			// if token empty => get token
			if (!access_token.empty())
			{
				std::string user_id = this->config["userId"];

				this->SetToken(access_token);

				if (!user_id.empty())
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

	Credentials::~Credentials()
	{

	}

	static size_t writer(char* data, size_t size, size_t nmemb, std::ostringstream* stream)
	{
		size_t count = size * nmemb;

		stream->write(data, count);

		return count;
	}

	// Obtain the token to access to QX Platform.
	// @raises CredentialsError : when token is invalid or the user has not accepted the license.
	// @raises ApiError : when the response from the server couldn't be parsed. 
	void Credentials::ObtainToken(std::map<std::string, std::string> config)
	{
		std::string client_application = CLIENT_APPLICATION;

		// if client_application is in config
		if (!this->config.empty() && this->config.count("client_application") == 1)
		{
			client_application += (":" + this->config["client_application"]);
		}

		//std::map<std::string, std::string> headers;
		//headers["x-qx-client-application"] = client_application;

		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, "Accept: application/json");
		headers = curl_slist_append(headers, "Content-Type: application/json");
		headers = curl_slist_append(headers, "charsets: utf-8");
		headers = curl_slist_append(headers, ("x-qx-client-application: " + client_application).c_str());

		CURL* curl = curl_easy_init();

		if (curl)
		{
			std::ostringstream contentStream;

			curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_HTTP | CURLPROTO_HTTPS);
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &contentStream);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

			if (!this->token_unique.empty())
			{
				std::string data = "{ \"apiToken\" : \"" + std::string(this->token_unique) + "\" }";

				curl_easy_setopt(curl, CURLOPT_URL, (this->config["url"] + "/users/loginWithToken").c_str());
				//curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
				CURLcode res = curl_easy_perform(curl);

				if (res != CURLE_OK)
				{
					curl_easy_cleanup(curl);
					throw ApiException(std::string("error during login: ", curl_easy_strerror(res)));
				}

				/*
				ToDo:
				response = requests.post(
					str(self.config.get('url') + "/users/loginWithToken"),
					data = { 'apiToken': self.token_unique },
					verify = self.verify,
					headers = headers,
					**self.extra_args)
				*/
			}
			else if (!config.empty() && config.count("email") == 1 && config.count("password") == 1)
			{
				std::string credentials = "{ \"email\" : \"" + config["email"] + "\", \"password\" : \"" + config["password"] + "\" }";

				curl_easy_setopt(curl, CURLOPT_URL, (this->config["url"] + "/users/login").c_str());
				//curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, credentials.c_str());
				CURLcode res = curl_easy_perform(curl);

				if (res != CURLE_OK)
				{
					curl_easy_cleanup(curl);
					throw ApiException(std::string("error during login: ", curl_easy_strerror(res)));
				}
			}
			else
			{
				curl_easy_cleanup(curl);
				throw CredentialsException("invalid token");
			}

			long response_code;
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

			//std::cout << "HTTP RESPONSE: " << response_code << std::endl;

			std::string content = contentStream.str();

			Json::Reader jsonReader;
			Json::Value jsonObj;

			jsonReader.parse(content, jsonObj);

			curl_easy_cleanup(curl);

			if (response_code == 401)
			{
				// For 401: ACCEPT_LICENSE_REQUIRED, a detailed message is
				// present in the response and passed to the exception.

				std::string error_msg = jsonObj["error"]["message"].asString();

				if (!error_msg.empty())
				{
					throw CredentialsException("error during login: " + error_msg);
				}
				else
				{
					throw CredentialsException("invalid token");
				}
			}

			// 200 = http-ok
			if (response_code == 200)
			{
				// ToDo: improve?
				if (jsonObj["id"] == Json::nullValue || 
					jsonObj["ttl"] == Json::nullValue ||
					jsonObj["created"] == Json::nullValue ||
					jsonObj["userId"] == Json::nullValue)
				{
					throw ApiException("error during login: missing response values", 
					"id: " + jsonObj["id"].asString() + ", ttl: " + jsonObj["ttl"].asString() + ", created: " + jsonObj["created"].asString() + ", userId: " + jsonObj["userId"].asString());
				}

				// save response data
				this->data_credentials["id"] = jsonObj["id"].asString();
				this->data_credentials["ttl"] = jsonObj["ttl"].asString();
				this->data_credentials["created"] = jsonObj["created"].asString();
				this->data_credentials["userId"] = jsonObj["userId"].asString();
			}
			else
			{
				throw ApiException("error during login: HTTP-CODE " + response_code);
			}

			if (this->GetToken().empty())
			{
				throw CredentialsException("invalid token");
			}
		}
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
		this->data_credentials["userId"] = user_id;
	}
}