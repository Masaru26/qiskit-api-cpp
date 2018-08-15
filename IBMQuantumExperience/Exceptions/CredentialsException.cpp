// Copyright by Benjamin Luxbacher
#include "CredentialsException.h"

namespace Qiskit
{
	CredentialsException::CredentialsException(std::string usr_msg, std::string dev_msg)
		: ApiException(usr_msg, dev_msg) { }
}