#include <string>

class QRealIP{
    public:
        QRealIP();
        QRealIP(std::string, std::string, std::string);
        std::string ip;
        std::string country;
        std::string continent;
};
