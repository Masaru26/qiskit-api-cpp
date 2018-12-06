#include "QGate.h"

QGate::QGate()
{
}

QGate::QGate(std::string name, std::string qasm, int position, std::list<bool> affectedLines, QMeasureCreg measureCreg)
{
	this->name = name;
	this->qasm = qasm;
	this->position = position;
	this->affectedLines = affectedLines;
	this->measureCreg = measureCreg;
}
