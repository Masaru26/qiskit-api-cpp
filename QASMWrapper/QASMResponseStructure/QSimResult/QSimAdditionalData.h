#include <string>
#include <list>

class QSimAdditionalData{
    public:
        QSimAdditionalData();
        QSimAdditionalData(std::string, std::list<std::string>);
        std::string seed;
        std::list<std::string> addData;
};
