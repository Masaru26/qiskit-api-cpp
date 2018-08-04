#ifndef _REGISTERSIZEEXCEPTION_H_
#define _REGISTERSIZEEXCEPTION_H_

#include "ApiException.h"

// Exception due to exceeding the maximum number of allowed qubits.
class RegisterSizeException : private ApiException
{
	RegisterSizeException(std::string usr_msg, std::string dev_msg);
};

#endif