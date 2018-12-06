#include "QMultiQubitGates.h"

QMultiQubitGates::QMultiQubitGates()
{
}

QMultiQubitGates::QMultiQubitGates(std::list<int> qubits, std::string type, QGateError gateError, std::string name)
{
	this->qubits = qubits;
	this->type = type;
	this->gateError = gateError;
	this->name = name;
}
