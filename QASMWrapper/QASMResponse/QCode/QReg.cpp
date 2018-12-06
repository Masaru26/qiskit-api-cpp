#include "QReg.h"

QReg::QReg()
{
}

QReg::QReg(std::string name, int size)
{
	this->name = name;
	this->size = size;
}
