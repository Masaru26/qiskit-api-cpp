#include <string>
#include "QRealDoneFridgeTemperature.h"

class QRealDoneFridgeParameters{
    public:
        QRealDoneFridgeParameters();
        QRealDoneFridgeParameters(std::string, QRealDoneFridgeTemperature);
    
        std::string cooldownDate;
        QRealDoneFridgeTemperature temperature;
};
