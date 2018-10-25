#include "QSimResponse.h"

QSimResponse::QSimResponse(){

};

QSimResponse::QSimResponse(QSimResult result, std::string startDate, long modificationDate, double time, std::string endDate, QSimStatus status, std::string deviceRunType, QSimIP ip, QSimCalibration calibration, int shots, QSimParamCustomize paramCustomize, bool deleted, bool userDeleted, std::string id, std::string codeId, std::string deviceId, std::string userId, QSimCode code){
    QSimResponse::result = result;
    QSimResponse::startDate = startDate;
    QSimResponse::modificationDate = modificationDate;
    QSimResponse::time = time;
    QSimResponse::endDate = endDate;
    QSimResponse::status = status;
    QSimResponse::deviceRunType = deviceRunType;
    QSimResponse::ip = ip;
    QSimResponse::calibration = calibration;
    QSimResponse::shots = shots;
    QSimResponse::paramCustomize = paramCustomize;
    QSimResponse::deleted = deleted;
    QSimResponse::userDeleted = userDeleted;
    QSimResponse::id = id;
    QSimResponse::codeId = codeId;
    QSimResponse::deviceId = deviceId;
    QSimResponse::userId = userId;
    QSimResponse::code = code;
};