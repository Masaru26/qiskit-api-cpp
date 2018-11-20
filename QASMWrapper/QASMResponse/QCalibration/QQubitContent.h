#ifndef QQUBITCONTENT_H_INCLUDED__;
#define QQUBITCONTENT_H_INCLUDED__;
#include <string>

class QQubitContent {
	public:
		QQubitContent();
		QQubitContent(std::string, int);
		QQubitContent(std::string, int, std::string);

		std::string date;
		int value;
		std::string unit;
};

#endif