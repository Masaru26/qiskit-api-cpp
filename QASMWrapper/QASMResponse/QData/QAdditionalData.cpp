#ifndef QADDITIONALDATA_CPP_INCLUDED
#define QADDITIONALDATA_CPP_INCLUDED

#include "QAdditionalData.h"

QAdditionalData::QAdditionalData()
{
}

QAdditionalData::QAdditionalData(std::string seed, std::list<std::string> addData)
{
	this->seed = seed;
	this->addData = addData;
}
#endif