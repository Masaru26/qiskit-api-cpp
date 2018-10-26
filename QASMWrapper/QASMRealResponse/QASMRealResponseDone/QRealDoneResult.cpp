#include "QRealDoneResult.h"

QRealDoneResult::QRealDoneResult(){};

QRealDoneResult::QRealDoneResult(std::string date, QRealDoneData data){
    QRealDoneResult::date = date;
    QRealDoneResult::data = data;
};