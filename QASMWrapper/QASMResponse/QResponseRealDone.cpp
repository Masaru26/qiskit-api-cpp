#ifndef QRESPONSEREALDONE_CPP_INCLUDED
#define QRESPONSEREALDONE_CPP_INCLUDED

#include "QResponseRealDone.h"

QResponseRealDone::QResponseRealDone()
{
}

QResponseRealDone::QResponseRealDone(std::string startDate, long modificationDate, int shots, bool deleted, bool userDeleted, std::string userId, std::string jobId, std::string qasm, std::string endDDate, std::string id, std::string deviceId, std::string deviceRunType, std::string codeId, QResult result, QStatus status, QIP ip, QCalibration calibration, std::string typeCredits, double time) 
	: QResponseReal(startDate, modificationDate, shots, deleted, userDeleted, userId, jobId, qasm, endDDate, id, deviceId, deviceRunType, codeId, result, status, ip, calibration, typeCredits)
{
	this->time = time;
}
#endif