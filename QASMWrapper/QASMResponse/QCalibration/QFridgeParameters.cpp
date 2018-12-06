#ifndef QFRIDGEPARAMETERS_CPP_INCLUDED
#define QFRIDGEPARAMETERS_CPP_INCLUDED

#include "QFridgeParameters.h"

QFridgeParameters::QFridgeParameters()
{
}

QFridgeParameters::QFridgeParameters(std::string cooldownDate, QFridgeTemperature temperature)
{
	this->cooldownDate = cooldownDate;
	this->temperature = temperature;
}
#endif