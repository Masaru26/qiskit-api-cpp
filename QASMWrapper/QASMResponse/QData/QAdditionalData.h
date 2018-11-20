#ifndef QADDITIONALDATA_H_INCLUDED__;
#define QADDITIONALDATA_H_INCLUDED__;
#include <string>
#include <list>

class QAdditionalData {
public:
	QAdditionalData();
	QAdditionalData(std::string, std::list<std::string>);
	std::string seed;
	std::list<std::string> addData;
};
