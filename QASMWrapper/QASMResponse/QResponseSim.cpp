#ifndef QRESPONSESIM_CPP_INCLUDED
#define QRESPONSESIM_CPP_INCLUDED

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
#endif