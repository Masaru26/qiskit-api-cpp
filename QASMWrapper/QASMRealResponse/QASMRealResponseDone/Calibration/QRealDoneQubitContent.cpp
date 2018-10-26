#include "QRealDoneQubitContent.h"

QRealDoneQubitContent::QRealDoneQubitContent(){};

QRealDoneQubitContent::QRealDoneQubitContent(std::string date, int value){
    QRealDoneQubitContent::date = date;
    QRealDoneQubitContent::value = value;
};

QRealDoneQubitContent::QRealDoneQubitContent(std::string date, int value, std::string unit){
    QRealDoneQubitContent::date = date;
    QRealDoneQubitContent::value = value;
    QRealDoneQubitContent::unit = unit;
};
