#include "QSimCode.h"

QSimCode::QSimCode(){}

QSimCode::QSimCode(std::string type, bool active, int versionId, std::string idCode, std::string name, QSimJsonQASM jsonQASM, std::string qasm, std::string codeType, std::string creationDate, bool deleted, long orderDate, bool userDeleted, bool isPublic, std::string id, std::string userId){
    QSimCode::type = type;
    QSimCode::active = active;
    QSimCode::versionId = versionId;
    QSimCode::idCode = idCode;
    QSimCode::name = name;
    QSimCode::jsonQASM = jsonQASM;
    QSimCode::qasm = qasm;
    QSimCode::codeType = codeType;
    QSimCode::creationDate = creationDate;
    QSimCode::deleted = deleted;
    QSimCode::orderDate = orderDate;
    QSimCode::userDeleted = userDeleted;
    QSimCode::isPublic = isPublic;
    QSimCode::id = id;
    QSimCode::userId = userId;
}