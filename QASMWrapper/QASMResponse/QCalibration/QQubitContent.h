#ifndef QQUBITCONTENT_H_INCLUDED__;
#define QQUBITCONTENT_H_INCLUDED__;
#include <string>

class QQubitContent {
	public:
		QQubitContent();
		QQubitContent(std::string, double);
		QQubitContent(std::string, double, std::string);

		std::string date;
		double value;
		std::string unit;
};

#endif