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

class QResponse : public IFillable {

	public:
		QResponse();
		QResponse(std::string, long, int, bool, bool, std::string, std::string, std::string,
			std::string, std::string, std::string, std::string, std::string, std::string, QResult,
			QStatus, QIP);

		std::string startDate;
		long modificationDate;
		int shots;
		bool deleted;
		bool userDeleted;
		std::string userId;
		std::string jobId;
		std::string qasm;
		std::string endDate;
		std::string id;
		std::string deviceId;
		std::string deviceRunType; // Gehört in die Sim Klasse
		std::string codeId;
		QResult result;
		QStatus status;
		QIP ip;

		bool ParseJson(std::string[] json);
};

#endif