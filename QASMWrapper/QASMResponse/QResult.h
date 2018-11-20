#ifndef QRESULT_H_INCLUDED__;
#define QRESULT_H_INCLUDED__;
#include <string>
#include "QData.h"

class QResult {
public:
	QResult();
	QResult(std::string, QData);
	
	std::string date;
	QData data;
};

#endif