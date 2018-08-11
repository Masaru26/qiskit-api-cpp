// Copyright by Benjamin Luxbacher
#include "Credentials.h"

Credentials::Credentials(char* token, std::map<std::string, std::string> config, bool verify, char* proxy_urls, std::map<std::string, std::string>ntlm_credentials)
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
	if (!this->config.empty() && this->config.count("url") == 0)
	{
		this->config["url"] = this->config_base["url"];
	}
	else if (this->config.empty())
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
		if (!access_token.empty())
		{
			std::string user_id = this->config["user_id"];
			if (!access_token.empty())
			{
				this->SetToken(access_token);
			}
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

// Obtain the token to access to QX Platform.
// @raises CredentialsError : when token is invalid or the user has not accepted the license.
// @raises ApiError : when the response from the server couldn't be parsed. 
void Credentials::ObtainToken(std::map<std::string, std::string> config)
{
	std::string client_application = CLIENT_APPLICATION;

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
		if (this->token_unique)
		{
			std::string data = "{ \"apiToken\" : \"" + std::string(this->token_unique) + "\" }";

			curl_easy_setopt(curl, CURLOPT_URL, (this->config["url"] + "/users/loginWithToken").c_str());
			//curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
			curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_HTTP | CURLPROTO_HTTPS);
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
			CURLcode res = curl_easy_perform(curl);

			if (res != CURLE_OK)
			{
				curl_easy_cleanup(curl);
				throw ApiException(std::string("error during login: ", curl_easy_strerror(res)));
			}

			/*
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
			curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_HTTP | CURLPROTO_HTTPS);
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
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

		std::cout << "HTTP RESPONSE: " << response_code << std::endl;

		if (response_code == 401)
		{
			
		}
	}

	/*
		if response.status_code == 401:
            error_message = None
            try:
                # For 401: ACCEPT_LICENSE_REQUIRED, a detailed message is
                # present in the response and passed to the exception.
                error_message = response.json()['error']['message']
            except:
                pass

            if error_message:
                raise CredentialsError('error during login: %s' % error_message)
            else:
                raise CredentialsError('invalid token')
        try:
            response.raise_for_status()
            self.data_credentials = response.json()
        except (requests.HTTPError, ValueError) as e:
            raise ApiError('error during login: %s' % str(e))

        if self.get_token() is None:
			raise CredentialsError('invalid token')
	*/


	curl_easy_cleanup(curl);
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