#ifndef QFRIDGETEMPERATURE_CPP_INCLUDED
#define QFRIDGETEMPERATURE_CPP_INCLUDED

#include "QFridgeTemperature.h"

QFridgeTemperature::QFridgeTemperature()
{
}

QFridgeTemperature::QFridgeTemperature(std::string date, std::list<std::string> value, std::string unit)
{
	this->date = date;
	this->value = value;
	this->unit = unit;
}
#endif