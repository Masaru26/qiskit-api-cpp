#ifndef _APIEXCEPTION_H_
#define _APIEXCEPTION_H_

#include <string>
#include <exception>

// IBMQuantumExperience API error handling base class.
// @param std::string usr_msg : Short user facing message describing error.
// @param std::string dev_msg : More detailed message to assist developer with resolving issue.
class ApiException : private std::exception
{
private:
	std::string usr_msg;
	std::string dev_msg;

public:
	ApiException(std::string usr_msg = "", std::string dev_msg = "");
	const char * what() const throw();
	const char * message() const throw();
};

#endif