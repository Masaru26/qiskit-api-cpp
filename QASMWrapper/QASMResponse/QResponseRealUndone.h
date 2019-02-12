#ifndef QRESPONSEREALUNDONE_H_INCLUDED__;
#define QRESPONSEREALUNDONE_H_INCLUDED__;

#include "QResponseReal.h"

class QResponseRealUndone : public QResponseReal {
	public:
		QResponseRealUndone(std::string, long, int, bool, bool, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, QResult, QStatus, QIP, QCalibration, std::string);
};

#endif