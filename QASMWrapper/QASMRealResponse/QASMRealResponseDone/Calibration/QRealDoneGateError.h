#include <string>

class QRealDoneGateError{
    public:
        QRealDoneGateError();
        QRealDoneGateError(std::string, double);
        
        std::string date;
        double value;
};
