// Copyright by Benjamin Luxbacher
#ifndef _REGISTERSIZEEXCEPTION_H_
#define _REGISTERSIZEEXCEPTION_H_

#include "ApiException.h"

namespace Qiskit
{
	// Exception due to exceeding the maximum number of allowed qubits.
	class RegisterSizeException : private ApiException
	{
	public:
		RegisterSizeException(std::string usr_msg = "", std::string dev_msg = "");
	};
}

#endif