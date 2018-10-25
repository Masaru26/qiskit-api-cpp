#include <string>
#include "QRealDoneQubitContent.h"

class QRealDoneQubit{
    public:
        std::string name;
        QRealDoneQubitContent buffer;
        QRealDoneQubitContent gateTime;
        QRealDoneQubitContent T2;
        QRealDoneQubitContent T1;
        QRealDoneQubitContent frequency;
        QRealDoneQubitContent gateError;
        QRealDoneQubitContent readoutError;
};
