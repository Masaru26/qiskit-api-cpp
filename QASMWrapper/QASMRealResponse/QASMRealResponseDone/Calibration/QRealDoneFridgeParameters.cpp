#include "QRealDoneFridgeParameters.h"

QRealDoneFridgeParameters::QRealDoneFridgeParameters();

QRealDoneFridgeParameters::QRealDoneFridgeParameters(std::string cooldownDate, QRealDoneFridgeTemperature temperature){
      QRealDoneFridgeParameters::cooldownDate = cooldownDate;
      QRealDoneFridgeParameters::temperature = temperature;
};
