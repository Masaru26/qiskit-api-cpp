#include "QQubitContent.h"

QQubitContent::QQubitContent()
{
}

QQubitContent::QQubitContent(std::string date, int value)
{
	this->date = date;
	this->value = value;
}

QQubitContent::QQubitContent(std::string date, int value, std::string unit)
{
	this->date = date;
	this->value = value;
	this->unit = unit;
}
