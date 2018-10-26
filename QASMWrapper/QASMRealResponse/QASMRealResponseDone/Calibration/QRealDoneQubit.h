#include <string>
#include "QRealDoneQubitContent.h"

class QRealDoneQubit{
    public:
        QRealDoneQubit();
        QRealDoneQubit(std::string, QRealDoneQubitContent, QRealDoneQubitContent, QRealDoneQubitContent, QRealDoneQubitContent, QRealDoneQubitContent, QRealDoneQubitContent, QRealDoneQubitContent);    
    
        std::string name;
        QRealDoneQubitContent buffer;
        QRealDoneQubitContent gateTime;
        QRealDoneQubitContent T2;
        QRealDoneQubitContent T1;
        QRealDoneQubitContent frequency;
        QRealDoneQubitContent gateError;
        QRealDoneQubitContent readoutError;
};
