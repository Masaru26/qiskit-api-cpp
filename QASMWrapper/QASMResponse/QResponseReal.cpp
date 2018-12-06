#include "QResponseReal.h"

QResponseReal::QResponseReal()
{
}

QResponseReal::QResponseReal(QCalibration calibration, std::string typeCredits)
{
	this->calibration = calibration;
	this->typeCredits = typeCredits;
}
