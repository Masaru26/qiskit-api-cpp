#ifndef QRESPONSESIM_CPP_INCLUDED
#define QRESPONSESIM_CPP_INCLUDED

#include "QResponseSim.h"

QResponseSim::QResponseSim()
{
}

QResponseSim::QResponseSim(QCode code, QParamsCustomize paramsCustomize, double time, std::string deviceRunType, std::string startDate, long modificationDate, int shots, bool deleted, bool userDeleted, std::string userId, std::string jobId, std::string qasm, std::string endDDate, std::string id, std::string deviceId, std::string deviceRunType, std::string codeId, QResult result, QStatus status, QIP ip, QCalibration calibration, std::string typeCredits)
	:(startDate, modificationDate, shots, deleted, userDeleted, userId, jobId, qasm, endDDate, id, deviceId, deviceRunType, result, status, ip, calibration, typeCredits)
{
	this->code = code;
	this->paramsCustomize = paramsCustomize;
	this->time = time;
	this->deviceRunType = deviceRunType;
	this->codeId = codeId;
}
#endif