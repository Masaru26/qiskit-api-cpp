#include <string>
#include <list>
#include "QRealDoneFridgeParameters.h"
#include "QRealDoneQubit.h"
#include "QRealDoneMultiQubitGates.h"

class QRealDoneCalibration{
    public:
        QRealDoneCalibration();
        QRealDoneCalibration(std::string, QRealDoneFridgeParameters, std::list<QRealDoneQubit>, std::list<QRealDoneMultiQubitGates>, std::string);
    
        std::string lastUpdateDate;
        QRealDoneFridgeParameters fridgeParameters;
        std::list<QRealDoneQubit> qubits;
        std::list<QRealDoneMultiQubitGates> multiQubitGates;
        std::string version;
};
