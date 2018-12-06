#include "QAdditionalData.h"

QAdditionalData::QAdditionalData()
{
}

QAdditionalData::QAdditionalData(std::string seed, std::list<std::string> addData)
{
	this->seed = seed;
	this->addData = addData;
}
