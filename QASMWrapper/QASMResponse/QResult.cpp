#include "QResult.h"

QResult::QResult()
{
}

QResult::QResult(std::string date, QData data)
{
	this->date = date;
	this->data = data;
}
