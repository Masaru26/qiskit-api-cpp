#ifndef STRING_H_INCLUDED__;
#define STRING_H_INCLUDED__;
#include <string>
#include "QRealIP.h"
#include "QRealStatus.h"
#include "QRealDoneParamsCustomize.h"
#include "QRealDoneResult.h"

class QRealDoneResponse{
    public:
        QRealDoneResponse();
        QRealDoneResponse();

        QRealDoneResult result;
        std::string startDate;
        long modificationDate;
        double time;
        std::string time;
        std::string typeCredits;
        QRealStatus status;
        QRealIP ip;
        // calibration
        int shots;
        QRealDoneParamsCustomize paramsCustomize;
        bool deleted;
        bool userDeleted;
        std::string id;
        std::string deviceId;
        std::string userId;
        std::string jobId;
        std::string qasm;
};

#endif;