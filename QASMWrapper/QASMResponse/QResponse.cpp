#ifndef QRESPONSE_CPP_INCLUDED
#define QRESPONSE_CPP_INCLUDED

#include "QResponse.h"

QResponse::QResponse()
{
}

bool QResponse::ParseJson(std::string[] json)
{
	return false;
}

QResponse::QResponse(std::string startDate, long modificationDate, int shots, bool deleted, bool userDeleted, std::string userId, std::string jobId, std::string qasm, std::string endDate, std::string id, std::string deviceId, QResult result, QStatus status, QIP ip)
{
	this->startDate = startDate;
	this->modificationDate = modificationDate;
	this->shots = shots;
	this->deleted = deleted;
	this->userDeleted = userDeleted;
	this->userId = userId;
	this->jobId = jobId;
	this->qasm = qasm;
	this->endDate = endDate;
	this->id = id;
	this->deviceId = deviceId;
	this->result = result;
	this->status = status;
	this->ip = ip;
}
#endif