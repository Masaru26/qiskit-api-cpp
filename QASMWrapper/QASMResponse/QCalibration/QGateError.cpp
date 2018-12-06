#include "QGateError.h"

QGateError::QGateError()
{
}

QGateError::QGateError(std::string date, double value)
{
	this->date = date;
	this->value = value;
}
