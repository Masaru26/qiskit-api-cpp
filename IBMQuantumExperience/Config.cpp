// Copyright by Benjamin Luxbacher
#include "Config.h"

namespace Qiskit
{
    Config::Config()
    {
        this->url = "";
        this->access_token = "";
        this->userId = "";
        this->client_application = "";
        this->email = "";
        this->password = "";
        this->proxies = std::map<std::string, std::string>();
    }

    Config::Config(std::string url)
    {
        this->url = url;
        this->access_token = "";
        this->userId = "";
        this->client_application = "";
        this->email = "";
        this->password = "";
        this->proxies = std::map<std::string, std::string>();
    }

    Config::~Config()
    {

    }

    bool Config::empty()
    {
        if (
            url.empty() &&
            access_token.empty() &&
            userId.empty() &&
            client_application.empty() &&
            email.empty() &&
            password.empty() &&
            proxies.empty()
        )
        {
            return true;
        }

        return false;
    }
}