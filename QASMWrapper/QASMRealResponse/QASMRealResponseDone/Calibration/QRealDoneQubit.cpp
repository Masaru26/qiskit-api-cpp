#include "QRealDoneQubit.h"

QRealDoneQubit::QRealDoneQubit(){};

QRealDoneQubit::QRealDoneQubit(std::string name, QRealDoneQubitContent buffer, QRealDoneQubitContent gateTime, QRealDoneQubitContent T2, QRealDoneQubitContent T1, QRealDoneQubitContent frequency, QRealDoneQubitContent gateError, QRealDoneQubitContent readoutError){
        QRealDoneQubit::name = name;
        QRealDoneQubit::buffer = buffer;
        QRealDoneQubit::gateTime = gateTime;
        QRealDoneQubit::T2 = T2;
        QRealDoneQubit::T1 = T1;
        QRealDoneQubit::frequency = frequency;
        QRealDoneQubit::gateError = gateError;
        QRealDoneQubit::readoutError = readoutError;
};
