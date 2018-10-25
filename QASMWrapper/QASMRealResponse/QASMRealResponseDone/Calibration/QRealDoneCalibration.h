#include <string>
#include <list>
#include "QRealDoneFridgeParameters.h"
#include "QRealDoneQubit.h"
#include "QRealDoneMultiQubitGates.h"

class QRealDoneCalibration{
    public:
        std::string lastUpdateDate;
        QRealDoneFridgeParameters fridgeParameters;
        std::list<QRealDoneQubit> qubits;
        std::list<QRealDoneMultiQubitGates> multiQubitGates;
        std::string version;
};
