#ifndef QRESPONSEREAL_CPP_INCLUDED
#define QRESPONSEREAL_CPP_INCLUDED

#include "QResponseReal.h"

QResponseReal::QResponseReal()
{
}

QResponseReal::QResponseReal(QCalibration calibration, std::string typeCredits)
{
	this->calibration = calibration;
	this->typeCredits = typeCredits;
}
#endif