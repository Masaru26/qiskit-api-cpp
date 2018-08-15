// Copyright by Benjamin Luxbacher
#include "Request.h"

// The Request class to manage the methods
Request::Request(std::string token, std::map<std::string, std::string> config = std::map<std::string, std::string>(), bool verify = true, int retries = 5, double timeout_interval = 1.0)
{

}

Request::~Request()
{

}

// Check is the user's token is valid
bool Request::CheckToken(int status_code)
{

}

// POST Method Wrapper of the REST API
std::map<std::string, std::string> Request::Post(std::string path, std::string params = "", std::string data = "")
{

}

// PUT Method Wrapper of the REST API
std::map<std::string, std::string> Request::Put(std::string path, std::string params = "", std::string data = "")
{

}

// GET Method Wrapper of the REST API
std::map<std::string, std::string> Request::Get(std::string path, std::string params = "", bool with_token = true)
{

}

// check response
// @param: std::string respond: HTTP response.
// @return: bool: true if the response is good, else false.
// @raises: ApiError: response isn't formatted properly.
bool Request::ResponseGood(HTTPResponse respond)
{

}

// parse text of response for HTTP errors
/*
    This parses the text of the response to decide whether to
    retry request or raise exception. At the moment this only
    detects an exception condition.
*/
// @param: Response respond: requests.Response object
// @return: bool: false if the request should be retried, true if not.
// @raises: RegisterSizeError
bool Request::ParseResponse(HTTPResponse respond)
{

}