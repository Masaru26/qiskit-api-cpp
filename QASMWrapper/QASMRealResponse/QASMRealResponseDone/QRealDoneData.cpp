#include "QRealDoneData.h"

QRealDoneData::QRealDoneData(){};

QRealDoneData::QRealDoneData(QRealDoneDataP p , std::string qasm, std::string serialNumberDevice, double time){
    QRealDoneData::p = p;
    QRealDoneData::qasm = qasm;
    QRealDoneData::serialNumberDevice = serialNumberDevice;
    QRealDoneData::time = time;
};
