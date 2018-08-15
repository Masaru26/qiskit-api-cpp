// Copyright by Benjamin Luxbacher
#ifndef _BADBACKENDEXCEPTION_H_
#define _BADBACKENDEXCEPTION_H_

#include "ApiException.h"

namespace Qiskit
{
	// Unavailable backend error.
	// @param std::string backend : Name of backend.
	class BadBackendException : private ApiException
	{
	public:
		BadBackendException(std::string backend);
	};
}

#endif