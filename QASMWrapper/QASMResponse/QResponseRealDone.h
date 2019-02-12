#ifndef QRESPONSEREALDONE_H_INCLUDED__;
#define QRESPONSEREALDONE_H_INCLUDED__;

#include "QResponseReal.h"

class QResponseRealDone : public QResponseReal {
	public:
		QResponseRealDone();
		QResponseRealDone(std::string, long, int, bool, bool, std::string, std::string, std::string, std::string, std::string, std::string, QResult, QStatus, QIP, QCalibration, std::string, double);
		double time;
};

#endif