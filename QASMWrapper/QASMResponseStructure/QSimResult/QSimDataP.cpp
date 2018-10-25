#include "QSimDataP.h"

QSimDataP::QSimDataP(){}

QSimDataP::QSimDataP(std::list<int> qubits, std::list<std::string> labels, std::list<double> values){
    QSimDataP::qubits = qubits;
    QSimDataP::labels = labels;
    QSimDataP::values = values;
}