// Copyright by Benjamin Luxbacher

#ifndef _QINFOQUEUE_H_
#define _QINFOQUEUE_H_

#include <stdio.h>
#include <string>

namespace QRest
{
    namespace QJobExecution
    {
        class QInfoQueue
        {
        private:

        public:
            QInfoQueue();
            QInfoQueue(std::string status, int position);
            ~QInfoQueue();
            
            std::string status;
            int position;
        };
    }
}

#endif