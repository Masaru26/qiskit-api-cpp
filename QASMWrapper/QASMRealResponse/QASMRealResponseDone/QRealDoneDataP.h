#include <string>
#include <list>

class QRealDoneDataP{
    public:
        QRealDoneDataP();
        QRealDoneDataP(std::list<std::string>, std::list<double>);
        std::list<std::string> labels;
        std::list<double> values;
};
