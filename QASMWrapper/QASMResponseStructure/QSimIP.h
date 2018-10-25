#include <string>

class QSimIP{
    public:
        QSimIP();
        QSimIP(std::string, std::string, std::string);
        std::string ip;
        std::string country;
        std::string continent;
};
