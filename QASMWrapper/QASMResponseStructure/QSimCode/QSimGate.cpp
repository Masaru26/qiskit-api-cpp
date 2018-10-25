#include "QSimGate.h"

QSimGate::QSimGate(){}

QSimGate::QSimGate(std::string name, std::string qasm, int position, std::list<bool> affectedLines, QSimMeasureCreg measureCreg){
    QSimGate::name = name;
    QSimGate::qasm = qasm;
    QSimGate::position = position;
    QSimGate::affectedLines = affectedLines;
    QSimGate::measureCreg = measureCreg;
}