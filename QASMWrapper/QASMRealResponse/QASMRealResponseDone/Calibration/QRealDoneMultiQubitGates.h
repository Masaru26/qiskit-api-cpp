#include <string>
#include <list>
#include "QRealDoneGateError.h"

class QRealDoneMultiQubitGates{
    public:
        QRealDoneMultiQubitGates();
        QRealDoneMultiQubitGates(std::list<int>, std::string, QRealDoneGateError, std::string);
    
        std::list<int> qubits;
        std::string type;
        QRealDoneGateError gateError;
        std::string name;
};
