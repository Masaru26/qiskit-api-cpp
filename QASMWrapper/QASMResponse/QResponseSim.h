#ifndef QRESPONSESIM_H_INCLUDED__;
#define QRESPONSESIM_H_INCLUDED__;
#include "QResponse.h"
#include "QCode.h"

class QResponseSim : public QResponse {
	public:
		QResponseSim();
		QResponseSim(QCode, QParamsCustomize, double, std::string, std::string, long, int, bool, bool, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, QResult, QStatus, QIP, QCalibration, std::string);

		QCode code;
		QParamsCustomize paramsCustomize;
		double time;
		std::string deviceRunType;
};

#endif