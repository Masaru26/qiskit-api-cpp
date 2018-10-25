#include "QSimPlayground.h"

QSimPlayground::QSimPlayground(){}

QSimPlayground::QSimPlayground(std::string name, int line, std::list<QSimGate> gates){
    QSimPlayground::name = name;
    QSimPlayground::line = line;
    QSimPlayground::gates = gates;
}