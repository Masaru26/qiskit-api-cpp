#ifndef STRING_H_INCLUDED__;
#define STRING_H_INCLUDED__;
#include <string>;
#include "QSimResult.h";
#include "QSimStatus.h";
#include "QSimIP.h";
#include "QSimCalibration.h";
#include "QSimParamCustomize.h";
#include "QSimCode.h";

class QSimResponse{

    public:
        QSimResponse();
        QSimResponse(QSimResult, std::string, long, double, std::string, QSimStatus, std::string,QSimIP, QSimCalibration,int, QSimParamCustomize, bool, bool, std::string, std::string, std::string, std::string, QSimCode);
        QSimResult result;
        std::string startDate;
        long modificationDate;
        double time;
        std::string endDate;
        QSimStatus status;
        std::string deviceRunType;
        QSimIP ip;
        QSimCalibration calibration;
        int shots;
        QSimParamCustomize paramCustomize;
        bool deleted;
        bool userDeleted;
        std::string id;
        std::string codeId;
        std::string deviceId;
        std::string userId;
        QSimCode code;
};

#endif