#include "QRealDoneFridgeTemperature.h"

QRealDoneFridgeTemperature::QRealDoneFridgeTemperature(){};

QRealDoneFridgeTemperature::QRealDoneFridgeTemperature(std::string date, std::list<std::string> value, std::string unit){
      QRealDoneFridgeTemperature::date = date;
      QRealDoneFridgeTemperature::value = value;
      QRealDoneFridgeTemperature::unit = unit;
};
