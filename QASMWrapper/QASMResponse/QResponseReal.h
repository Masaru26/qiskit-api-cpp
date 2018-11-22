#ifndef QRESPONSEREAL_H_INCLUDED__;
#define QRESPONSEREAL_H_INCLUDED__;
#include "QResponse.h"

class QResponseReal : public QResponse {
	public:
		QResponseReal();
		QResponseReal(QCalibration, std::string);

		QCalibration calibration;
		std::string typeCredits;
};

#endif