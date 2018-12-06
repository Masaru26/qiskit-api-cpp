#include "QTopology.h"

QTopology::QTopology()
{
}

QTopology::QTopology(std::list<QReg> cregs, std::list<QReg> qregs, std::string qasmHeader)
{
	this->cregs = cregs;
	this->qregs = qregs;
	this->qasmHeader = qasmHeader;
}
