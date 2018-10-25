#include <string>
#include <list>
#include "QSimTopology.h";
#include "QSimPlayground.h";

class QSimJsonQASM{
    public:
        QSimJsonQASM();
        QSimJsonQASM(std::string, QSimTopology, std::list<QSimPlayground>,int,bool,int,std::string);
        std::string gateDefinitions;
        QSimTopology topology;
        std::list<QSimPlayground> playground;
        int numberGates;
        bool hasMeasures;
        int numberColumns;
        std::string include;
};
