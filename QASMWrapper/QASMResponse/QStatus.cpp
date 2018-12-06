#ifndef QSTATUS_CPP_INCLUDED
#define QSTATUS_CPP_INCLUDED

#include "QStatus.h"

QStatus::QStatus()
{
}

QStatus::QStatus(std::string id)
{
	this->id = id;
}
#endif