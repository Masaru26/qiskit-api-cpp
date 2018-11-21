#ifndef QRESPONSEREAL_H_INCLUDED__;
#define QRESPONSEREAL_H_INCLUDED__;
#include "QResponse.h"

class QResponseReal : public QResponse {
	public:
		QResponseReal();

		QCalibration calibration;
		std::string typeCredits;

};

#endif