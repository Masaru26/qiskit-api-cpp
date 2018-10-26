#include "QRealDoneMultiQubitGates.h"

QRealDoneMultiQubitGates::QRealDoneMultiQubitGates(){};

QRealDoneMultiQubitGates::QRealDoneMultiQubitGates(std::list<int> qubits, std::string type, QRealDoneGateError gateError, std::string name){
      QRealDoneMultiQubitGates::qubits = qubits;
      QRealDoneMultiQubitGates::type = type;
      QRealDoneMultiQubitGates:: gateError = gateError;
      QRealDoneMultiQubitGates:: name = name;
};
