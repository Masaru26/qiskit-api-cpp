#ifndef QGATEERROR_CPP_INCLUDED
#define QGATEERROR_CPP_INCLUDED

#include "QGateError.h"

QGateError::QGateError()
{
}

QGateError::QGateError(std::string date, double value)
{
	this->date = date;
	this->value = value;
}
#endif