#ifndef QIP_CPP_INCLUDED
#define QIP_CPP_INCLUDED

#include "QIP.h"

QIP::QSimIP()
{
}

QIP::QSimIP(std::string ip, std::string country, std::string continent)
{
	this->ip = ip;
	this->country = country;
	this->continent = continent;
}
#endif