// Copyright by Benjamin Luxbacher
#include "ApiException.h"

ApiException::ApiException(std::string usr_msg, std::string dev_msg)
{
	this->usr_msg = usr_msg;
	this->dev_msg = dev_msg;
}

const char* ApiException::what() const throw ()
{
	return this->dev_msg.c_str();
}

const char* ApiException::message() const throw ()
{
	return this->usr_msg.c_str();
}