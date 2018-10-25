#include "QSimTopology.h"

QSimTopology::QSimTopology(){}

QSimTopology::QSimTopology(std::list<QSimReg> cregs, std::list<QSimReg> qregs, std::string qasmHeader){
    QSimTopology::cregs = cregs;
    QSimTopology::qregs = qregs;
    QSimTopology::qasmHeader = qasmHeader;
}