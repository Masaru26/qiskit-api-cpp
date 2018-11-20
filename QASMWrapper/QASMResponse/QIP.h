#ifndef QIP_H_INCLUDED__;
#define QIP_H_INCLUDED__;
#include <string>

class QIP {
public:
	QSimIP();
	QSimIP(std::string, std::string, std::string);
	std::string ip;
	std::string country;
	std::string continent;
};
#endif