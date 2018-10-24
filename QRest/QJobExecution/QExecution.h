// Copyright by Benjamin Luxbacher

#ifndef _QEXECUTION_H_
#define _QEXECUTION_H_

#include <stdio.h>
#include <string>

namespace QRest
{
    namespace QJobExecution
    {
        class QExecution
        {
        private:

        public:
            QExecution();
            QExecution(std::string qasm, std::string status, std::string executionId);
            ~QExecution();

            std::string qasm;
            std::string status;
            std::string executionId;
        };
    }
}

#endif