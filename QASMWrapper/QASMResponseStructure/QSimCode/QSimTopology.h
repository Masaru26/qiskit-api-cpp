#include <string>
#include <list>
#include "QSimReg.h";

class QSimTopology{
    public:
        QSimTopology();
        QSimTopology(std::list<QSimReg>, std::list<QSimReg>, std::string);
        std::list<QSimReg> cregs;
        std::list<QSimReg> qregs;
        std::string qasmHeader;
};
