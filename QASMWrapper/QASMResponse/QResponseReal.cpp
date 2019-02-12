#ifndef QRESPONSEREAL_CPP_INCLUDED
#define QRESPONSEREAL_CPP_INCLUDED

#include "QResponseReal.h"

QResponseReal::QResponseReal()
{
}

QResponseReal::QResponseReal(std::string startDate, long modificationDate, int shots, bool deleted, bool userDeleted, std::string userId, std::string jobId, std::string qasm, std::string endDDate, std::string id, std::string deviceId, QResult result, QStatus status, QIP ip, QCalibration calibration, std::string typeCredits) 
	: QResponse(startDate, modificationDate, shots, deleted, userDeleted, userId, jobId, qasm, endDDate, id, deviceId, deviceRunType, result, status, ip)
{
	this->calibration = calibration;
	this->typeCredits = typeCredits;
	
}
#endif