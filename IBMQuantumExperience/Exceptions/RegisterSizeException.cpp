// Copyright by Benjamin Luxbacher
#include "RegisterSizeException.h"

namespace Qiskit
{
	RegisterSizeException::RegisterSizeException(std::string usr_msg, std::string dev_msg)
		: ApiException(usr_msg, dev_msg) { }
}