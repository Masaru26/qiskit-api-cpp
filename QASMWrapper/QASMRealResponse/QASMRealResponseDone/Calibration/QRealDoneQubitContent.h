#include <string>

class QRealDoneQubitContent{
    public:
        QRealDoneQubitContent();
        QRealDoneQubitContent(std::string, int);
        QRealDoneQubitContent(std::string, int, std::string);
        std::string date;
        int value;
        std::string unit;
};
