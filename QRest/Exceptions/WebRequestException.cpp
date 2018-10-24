// Copyright by Benjamin Luxbacher

#include "WebRequestException.h"

namespace QRest
{
	namespace Exceptions
    {
        WebRequestException::WebRequestException()
        {

        }

        WebRequestException::WebRequestException(std::string message)
        {
            this->message = message;
        }

        WebRequestException::WebRequestException(std::string message, std::exception* innerException)
        {
            this->message = message;
            this->innerException = innerException;
        }

        const char* WebRequestException::what() const throw ()
        {
            return this->message.c_str();
        }

        const std::exception* WebRequestException::GetInnerException() const throw()
        {
            return this->innerException;
        }
    }
}