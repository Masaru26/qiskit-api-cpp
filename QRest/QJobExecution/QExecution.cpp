// Copyright by Benjamin Luxbacher

#include "QExecution.h"

namespace QRest
{
    namespace QJobExecution
    {
        QExecution::QExecution()
        {

        }
        
        QExecution::QExecution(std::string qasm, std::string status, std::string executionId)
        {
            this->qasm = qasm;
            this->status = status;
            this->executionId = executionId;
        }

        QExecution::~QExecution()
        {

        }
    }
}