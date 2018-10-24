// Copyright by Benjamin Luxbacher

#include "QQueueResult.h"

namespace QRest
{
    namespace QJobExecution
    {
        QQueueResult::QQueueResult()
        {
            
        }

        QQueueResult::QQueueResult(
            std::list<QExecution> qasms, 
            int shots, 
            QAvailableBackends::QBackend backend, 
            std::string status, 
            int maxCredits, 
            int usedCredits, 
            std::string creationDate, 
            std::string id, 
            std::string userId, 
            QInfoQueue infoQueue, 
            std::string json
        )
        {
            this->qasms = qasms;
            this->shots = shots;
            this->backend = backend;
            this->status = status;
            this->maxCredits = maxCredits;
            this->usedCredits = usedCredits;
            this->creationDate = creationDate;
            this->id = id;
            this->userId = userId;
            this->infoQueue = infoQueue;

            this->json = json;
        }

        QQueueResult::~QQueueResult()
        {
            
        }
    }
}