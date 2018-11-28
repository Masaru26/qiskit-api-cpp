#ifndef QRESPONSESIM_H_INCLUDED__;
#define QRESPONSESIM_H_INCLUDED__;
#include "QResponse.h"
#include "QCode.h"

class QResponseSim : public QResponse {
	public:
		QResponseSim();
		QResponseSim(QCode, QParamsCustomize, double);

		QCode code;
		QParamsCustomize paramsCustomize;
		double time;
};

#endif