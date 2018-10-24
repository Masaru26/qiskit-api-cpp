// Copyright by Benjamin Luxbacher

#include "QInfoQueue.h"

namespace QRest
{
    namespace QJobExecution
    {
        QInfoQueue::QInfoQueue()
        {

        }
        
        QInfoQueue::QInfoQueue(std::string status, int position)
        {
            this->status = status;
            this->position = position;
        }

        QInfoQueue::~QInfoQueue()
        {

        }
    }
}