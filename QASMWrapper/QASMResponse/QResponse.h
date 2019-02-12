#ifndef QRESPONSE_H_INCLUDED__;
#define QRESPONSE_H_INCLUDED__;
#include <string>;
#include "QResult.h";
#include "QStatus.h";
#include "QIP.h";
#include "QCalibration.h";
#include "QParamsCustomize.h";
#include "QCode.h";
#include "IFillable.h";

class QResponse {

	public:
		QResponse();
		QResponse::QResponse(
			std::string startDate
			, long modificationDate
			, int shots
			, bool deleted
			, bool userDeleted
			, std::string userId
			, std::string qasm
			, std::string endDate
			, std::string id
			, std::string deviceId
			, QResult result
			, QStatus status
			, QIP ip
		);

		// Constructor for UndoneResponse
		QResponse::QResponse(
			std::string startDate
			, long modificationDate
			, int shots
			, bool deleted
			, bool userDeleted
			, std::string userId
			, std::string qasm
			, std::string id
			, QStatus status
			, QIP ip
		);

		std::string startDate;
		long modificationDate;
		int shots;
		bool deleted;
		bool userDeleted;
		std::string userId;
		std::string qasm;
		std::string endDate;
		std::string id;
		std::string deviceId;
		QResult result;
		QStatus status;
		QIP ip;
};

#endif