#ifndef STRING_H_INCLUDED__;
#define STRING_H_INCLUDED__;
#include <string>
#include "QRealIP.h"
#include "QRealStatus.h"

class QRealUndoneResponse{
    public:
        QRealUndoneResponse();
        QRealUndoneResponse(std::string, long, std::string,
        QRealStatus, QRealIP, int, bool, bool,
        std::string, std::string, std::string,
        std::string);
        std::string startDate;
        long modificationDate;
        std::string typeCredits;
        QRealStatus status;
        QRealIP ip;
        int shots;
        bool deleted;
        bool userDeleted;
        std::string id;
        std::string userId;
        std::string jobId;
        std::string qasm;
};

#endif;