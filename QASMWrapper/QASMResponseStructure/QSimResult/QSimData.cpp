#include "QSimData.h"

QSimData::QSimData(){}

QSimData::QSimData(std::string creg_labels, QSimDataP p, QSimAdditionalData additionalData, std::string qasm, std::string serialNumberDevice, double time){
    QSimData::creg_labels = creg_labels;
    QSimData::p = p;
    QSimData::additionalData = additionalData;
    QSimData::qasm = qasm;
    QSimData::serialNumberDevice = serialNumberDevice;
    QSimData::time = time;
}