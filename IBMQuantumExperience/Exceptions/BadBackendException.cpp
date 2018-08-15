// Copyright by Benjamin Luxbacher
#include "BadBackendException.h"

namespace Qiskit
{
	BadBackendException::BadBackendException(std::string backend) 
		: ApiException(
			std::string("Could not find backend ") + backend + std::string(" available. "), 
			std::string("Backend ") + backend + std::string(" does not exist. Please use \"AvailableBackends\" to see options. ")
		) { }
}