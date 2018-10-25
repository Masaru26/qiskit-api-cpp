#include <string>
#include "QRealDoneData.h"
class QRealDoneResult{
    public:
        QRealDoneResult();
        QRealDoneResult(std::string); // data fehlt
        std::string date;
        QRealDoneData data;
};
