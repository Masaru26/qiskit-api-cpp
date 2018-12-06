#ifndef QRESULT_CPP_INCLUDED
#define QRESULT_CPP_INCLUDED

#include "QResult.h"

QResult::QResult()
{
}

QResult::QResult(std::string date, QData data)
{
	this->date = date;
	this->data = data;
}
#endif