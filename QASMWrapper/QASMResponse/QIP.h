#ifndef QIP_H_INCLUDED__;
#define QIP_H_INCLUDED__;
#include <string>

class QIP {
public:
	QIP();
	QIP(std::string, std::string, std::string);
	std::string ip;
	std::string country;
	std::string continent;
};
#endif