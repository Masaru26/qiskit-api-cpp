#include <string>;
#include "QSimDataP.h";
#include "QSimAdditionalData.h";

class QSimData{
    public:
        QSimData();
        QSimData(std::string, QSimDataP, QSimAdditionalData, std::string, std::string, double);
        std::string creg_labels;
        QSimDataP p;
        QSimAdditionalData additionalData;
        std::string qasm;
        std::string serialNumberDevice;
        double time;
};
