#ifndef _CREDENTIALSEXCEPTION_H_
#define _CREDENTIALSEXCEPTION_H_

#include "ApiException.h"

// Exception associated with bad server credentials.
class CredentialsException : private ApiException
{
	CredentialsException(std::string usr_msg, std::string dev_msg);
};

#endif