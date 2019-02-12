#ifndef QRESPONSEREAL_H_INCLUDED__;
#define QRESPONSEREAL_H_INCLUDED__;
#include "QResponse.h"

class QResponseReal : public QResponse {
	public:
		QResponseReal();
		QResponseReal::QResponseReal(
			std::string startDate
			, long modificationDate
			, int shots
			, bool deleted
			, bool userDeleted
			, std::string userId
			, std::string jobId
			, std::string qasm
			, std::string endDate
			, std::string id
			, std::string deviceId
			, QResult result
			, QStatus status
			, QIP ip
			, QCalibration calibration
			, std::string typeCredits
		)
			: QResponse(startDate, modificationDate, shots, deleted, userDeleted, userId, qasm, endDate, id, deviceId, result, status, ip);

		// Constructor for undone response
		QResponseReal::QResponseReal(
			std::string startDate
			, long modificationDate
			, int shots
			, bool deleted
			, bool userDeleted
			, std::string userId
			, std::string jobId
			, std::string qasm
			, std::string id
			, QStatus status
			, QIP ip
			, std::string typeCredits
		)
			: QResponse(startDate, modificationDate, shots, deleted, userDeleted, userId, qasm, id, status, ip);

		QCalibration calibration;
		std::string typeCredits;
		std::string jobId
};

#endif