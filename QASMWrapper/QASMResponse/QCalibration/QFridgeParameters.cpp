#include "QFridgeParameters.h"

QFridgeParameters::QFridgeParameters()
{
}

QFridgeParameters::QFridgeParameters(std::string cooldownDate, QFridgeTemperature temperature)
{
	this->cooldownDate = cooldownDate;
	this->temperature = temperature;
}
