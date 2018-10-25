#include "QRealUndoneResponse.h"

QRealUndoneResponse::QRealUndoneResponse(){

};

QRealUndoneResponse::QRealUndoneResponse(std::string startDate, long modificationDate, std::string typeCredits, QRealStatus status, QRealIP ip, int shots, bool deleted, bool userDeleted, std::string id, std::string userId, std::string jobId, std::string qasm){
    QRealUndoneResponse::startDate = startDate;
    QRealUndoneResponse::modificationDate = modificationDate;
    QRealUndoneResponse::typeCredits = typeCredits;
    QRealUndoneResponse::status = status;
    QRealUndoneResponse::ip = ip;
    QRealUndoneResponse::shots = shots;
    QRealUndoneResponse::deleted = deleted;
    QRealUndoneResponse::userDeleted = userDeleted;
    QRealUndoneResponse::id = id;
    QRealUndoneResponse::userId = userId;
    QRealUndoneResponse::jobId = jobId;
    QRealUndoneResponse::qasm = qasm;
    
};