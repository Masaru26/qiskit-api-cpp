#include <string>
#include "QRealDoneDataP.h"

class QRealDoneData{
    public:
        QRealDoneData();
        QRealDoneData(QRealDoneDataP, std::string, std::string, double);
        QRealDoneDataP p;
        std::string qasm;
        std::string serialNumberDevice;
        double time;
};
