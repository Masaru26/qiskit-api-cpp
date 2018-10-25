#include <string>;
#include "QSimData.h";

class QSimResult{
    public:
        QSimResult();
        QSimResult(std::string, QSimData);
        std::string date;
        QSimData data;
};

