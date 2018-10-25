#include "QSimJsonQASM.h"

QSimJsonQASM::QSimJsonQASM(){}

QSimJsonQASM::QSimJsonQASM(std::string gateDefinitions, QSimTopology topology, std::list<QSimPlayground> playground, int numberGates, bool hasMeasures, int numberColumns, std::string include){
    QSimJsonQASM::gateDefinitions = gateDefinitions;
    QSimJsonQASM::topology = topology;
    QSimJsonQASM::playground = playground;
    QSimJsonQASM::numberGates = numberGates;
    QSimJsonQASM::hasMeasures = hasMeasures;
    QSimJsonQASM::numberColumns = numberColumns;
    QSimJsonQASM::include = include;
}