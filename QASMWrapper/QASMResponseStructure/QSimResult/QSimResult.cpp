#include "QSimResult.h"

QSimResult::QSimResult(){}

QSimResult::QSimResult(std::string date, QSimData data){
    QSimResult::date = date;
    QSimResult::data = data;
}