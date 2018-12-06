#ifndef QPLAYGROUND_CPP_INCLUDED
#define QPLAYGROUND_CPP_INCLUDED

#include "QPlayground.h"

QPlayground::QPlayground()
{
}

QPlayground::QPlayground(std::string name, int line, std::list<QGate> gates)
{
	this->name = name;
	this->line = line;
	this->gates = gates;
}
#endif