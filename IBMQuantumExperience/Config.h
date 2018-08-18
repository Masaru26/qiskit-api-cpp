// Copyright by Benjamin Luxbacher
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>
#include <map>

namespace Qiskit
{
    class Config
    {
    public:
        Config();
        Config(std::string url);
        ~Config();

        std::string url;
        std::string access_token;
        std::string userId;
        std::string client_application;
        std::string email;
        std::string password;
        // keys: http, https, username_ntlm, password_ntlm
        std::map<std::string, std::string> proxies;

        bool empty();
    };
}

#endif