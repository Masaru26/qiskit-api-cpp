// Copyright by Benjamin Luxbacher
#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <map>
#include <vector>
#include <string.h>

#include "Qiskit.h"
#include "Config.h"
#include "HTTPResponse.h"
#include "Credentials.h"

namespace Qiskit
{
    // The Request class to manage the methods
    class Request
    {
    public:
        // The Request class to manage the methods
        Request(std::string token, Config config = Config(), bool verify = true, int retries = 5, double timeout_interval = 1.0);
        ~Request();
    private:
        bool verify;
        std::string client_application;
        Config config;
        std::vector<int> errorsNotRetry;
        std::map<std::string, std::string> proxy_urls;
        std::map<std::string, std::string> ntlm_credentials;

        Credentials credential;
        int retries = retries;
        double timeout_interval = timeout_interval;
        int result = NULL;

        // Check is the user's token is valid
        bool CheckToken(int status_code);
        // POST Method Wrapper of the REST API
        std::map<std::string, std::string> Post(std::string path, std::string params = "", std::string data = "");
        // PUT Method Wrapper of the REST API
        std::map<std::string, std::string> Put(std::string path, std::string params = "", std::string data = "");
        // GET Method Wrapper of the REST API
        std::map<std::string, std::string> Get(std::string path, std::string params = "", bool with_token = true);
        // check response
        // @param: std::string respond: HTTP response.
        // @return: bool: true if the response is good, else false.
        // @raises: ApiError: response isn't formatted properly.
        bool ResponseGood(HTTPResponse respond);
        // parse text of response for HTTP errors
        /*
            This parses the text of the response to decide whether to
            retry request or raise exception. At the moment this only
            detects an exception condition.
        */
        // @param: Response respond: requests.Response object
        // @return: bool: false if the request should be retried, true if not.
        // @raises: RegisterSizeError
        bool ParseResponse(HTTPResponse respond);
    };
}

#endif