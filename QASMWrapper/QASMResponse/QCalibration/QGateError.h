#ifndef QGATEERROR_H_INCLUDED__;
#define QGATEERROR_H_INCLUDED__;
#include <string>

class QGateError {
public:
	QGateError();
	QGateError(std::string, double);

	std::string date;
	double value;
};

#endif;