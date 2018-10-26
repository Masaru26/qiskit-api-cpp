#include "QRealDoneCalibration.h"

QRealDoneCalibration::QRealDoneCalibration(){};

QRealDoneCalibration::QRealDoneCalibration(std::string lastUpdateDate, QRealDoneFridgeParameters fridgeParameters, std::list<QRealDoneQubit> qubits, std::list<QRealDoneMultiQubitGates> multiQubitGates,std::string version){
      QRealDoneCalibration::lastUpdateDate = lastUpdateDate;
      QRealDoneCalibration::fridgeParameters = fridgeParameters;
      QRealDoneCalibration::qubits = qubits;
      QRealDoneCalibration::multiQubitGates = multiQubitGates;
      QRealDoneCalibration::version = version;
};
