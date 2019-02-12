#ifndef QRESPONSEREAL_H_INCLUDED__;
#define QRESPONSEREAL_H_INCLUDED__;
#include "QResponse.h"

class QResponseReal : public QResponse {
	public:
		QResponseReal();
		QResponseReal(std::string, long, int, bool, bool, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, QResult, QStatus, QIP, QCalibration, std::string);

		QCalibration calibration;
		std::string typeCredits;
};

#endif