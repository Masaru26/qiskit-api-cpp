#include "QSimAdditionalData.h"

QSimAdditionalData::QSimAdditionalData(){}

QSimAdditionalData::QSimAdditionalData(std::string seed, std::list<std::string> addData){
    QSimAdditionalData::seed = seed;
    QSimAdditionalData::addData = addData;

}