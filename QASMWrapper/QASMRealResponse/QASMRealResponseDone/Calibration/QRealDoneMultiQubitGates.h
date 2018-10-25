#include <string>
#include <list>
#include "QRealDoneGateError.h"

class QRealDoneMultiQubitGates{
    public:
        std::list<int> qubits;
        std::string type;
        QRealDoneGateError gateError;
        std::string name;
};
