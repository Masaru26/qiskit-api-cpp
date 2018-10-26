#include "QRealDoneResponse.h"

QRealDoneResponse::QRealDoneResponse(){};

QRealDoneResponse::QRealDoneResponse(QRealDoneResult result, std::string startDate, long modificationDate, double time, std::string endDate
        , std::string typeCredits, QRealStatus status, QRealIP ip, QRealDoneCalibration calibration
        , int shots, QRealDoneParamsCustomize paramsCustomize, bool deleted, bool userDeleted, std::string id, std::string deviceId, std::string userId,std::string jobId,std::string qasm)
        {
    QRealDoneResponse::result = result;
    QRealDoneResponse::startDate = startDate;
    QRealDoneResponse::modificationDate = modificationDate;
    QRealDoneResponse::time = time;
    QRealDoneResponse::endDate = endDate;
    QRealDoneResponse::typeCredits = typeCredits;
    QRealDoneResponse::status = status;
    QRealDoneResponse::ip = ip;
    QRealDoneResponse::calibration = calibration;
    QRealDoneResponse::shots = shots;
    QRealDoneResponse::paramsCustomize = paramsCustomize;
    QRealDoneResponse::deleted = deleted;
    QRealDoneResponse::userDeleted = userDeleted;
    QRealDoneResponse::id = id;
    QRealDoneResponse::deviceId = deviceId;
    QRealDoneResponse::userId = userId;
    QRealDoneResponse::jobId = jobId;
    QRealDoneResponse::qasm = qasm;
};
