#include "QResponseSim.h"

QResponseSim::QResponseSim()
{
}

QResponseSim::QResponseSim(QCode code, QParamsCustomize paramsCustomize, double time)
{
	this->code = code;
	this->paramsCustomize = paramsCustomize;
	this->time = time;
}
